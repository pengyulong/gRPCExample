
#include <thread>
#include <iostream>
#include <string>
#include <vector>
#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>
#include "textfeature.grpc.pb.h"
#include <time.h>

using grpc::Status;
using textfeature::textRequest;
using textfeature::keyResponse;
using textfeature::sentenceRequest;
using textfeature::orderkeyResponse;
using textfeature::docsRequest;
using textfeature::SummaryKeyWords;

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;

using textfeature::TextFeature;
using namespace std;

string getTime()
{
    time_t timep;
    time(&timep);
    char tmp[64];
    strftime(tmp,sizeof(tmp),"%Y-%m-%d %H:%M:%S",localtime(&timep));
    return tmp;
}

class TextFeatureClient {
public:
	TextFeatureClient(std::shared_ptr<Channel> channel) :stub_(TextFeature::NewStub(channel)) {
		text_test_ = "小明来自清华大学，在网易工作5年了。";
		text_list_ = { "您好这里是微众银行工作人员给您致电请问您是张金国先生吗。",
		"好的先生感谢您使用微粒贷产品本次来电主要给您确认借款相关信息请问您现在通话方便吗。",
		"嗯好的保证服务质量本次通话可能会被录音请您了解为确认您账户安全呃先生您这旁边是有点吵啊你可不可以换个安静点的地方。",
		"嗯好的为了保证服务质量本次通话可能会被录音请您了解为确认您账户安全跟您核对一下身份证号码最后四位请问是多少。",
		"好的谢谢那请问本次微粒贷申请需要您亲自操作的吗。",
		"谢谢您请问您尾号八六八六的申请手机是您本人使用。",
		"好的谢谢您温馨提醒您给您借款合同规定您申请的这笔微粒贷借款将不能用于购买住房和股票证券投资的请您知晓。",
		"嗯好的感谢您的申请和配合稍后请您对本次服务进行评价我们会帮您尽快处理的好祝您生活愉快再见。",
		"可以的您这块今天借明天就可以一次性还清了。好的这边的话祝您生活愉快再见。" };
	}

	bool GuidGetFeature()
	{
		ClientContext context;
		textRequest request;
		request.set_text(text_test_.c_str());
		keyResponse response;
		Status status = stub_->SimpleRPC(&context, request, &response);
		if (status.ok())
		{
			std::cout << "keywords: " << response.keywords() << std::endl;
			return true;
		}
		else
		{
			std::cout << status.error_code() << ": " << status.error_message()<< std::endl;
			return false;
		}
	}

	bool GuidListFeature(int id)
	{   
        bool flag=false;
        printf("thread id: %d,begin time:%s\n",id,getTime().c_str());
		ClientContext context;
		sentenceRequest request;
		for (size_t idx = 0; idx < text_list_.size(); ++idx)
		{
			request.add_text(text_list_[idx]);
		}
		orderkeyResponse response;
		unique_ptr<ClientReader<orderkeyResponse> > response_ptr(stub_->ServerStreamRPC(&context,request));
		while (response_ptr->Read(&response))
		{
			printf("thread:%d keywords: %s \n",id, response.keywords().c_str());
		}
		Status status = response_ptr->Finish();
		if (status.ok())
		{
			printf("thread:%d ServerStream RPC succeed!\n",id);
			flag=true;
		}
		else
		{
            printf("thread id:%d ServerStream RPC failed.\n",id);
			flag=false;
		}
        printf("thread id: %d,end time :%s\n",id,getTime().c_str());
		return flag;
	}
	bool GuidRecordFeature()
	{
		//构建流式请求
		ClientContext context;
		SummaryKeyWords response;
		unique_ptr<ClientWriter<docsRequest> > writer(stub_->ClientStreamRPC(&context, &response));
		for (size_t i = 0; i < text_list_.size(); ++i)
		{
			docsRequest req;
			req.set_id(i);
			req.set_text(text_list_[i].c_str());
			writer->Write(req);
		}
		writer->WritesDone();
		Status status = writer->Finish();
		if (status.ok())
		{
			cout << "Finished complete " << text_list_.size() << "requests." << endl;
			for (int i = 0; i < response.keywords_size(); ++i)
			{
				cout << "id: " << i << " " << response.keywords(i) << endl;
			}

		}
		else
		{
			std::cout << status.error_code() << ": " << status.error_message() << std::endl;
			cout << "Run ClientStreamServer Failed." << endl;
		}
	}
	bool GuidChatFeature()
	{
		// 构建流式请求和响应
		ClientContext context;
		shared_ptr<ClientReaderWriter<docsRequest,orderkeyResponse> > stream(stub_->BidirectionalStreamRPC(&context));
		
		vector<string> feature_list = text_list_;
		thread writer([stream,feature_list]() {
			for (size_t idx = 0; idx <feature_list.size(); ++idx)
			{
				cout << "the " << idx << "th text: " << feature_list[idx] << endl;
				docsRequest req;
				req.set_id(idx);
				req.set_text(feature_list[idx].c_str());
				stream->Write(req);
			}
			stream->WritesDone();
		});
		orderkeyResponse response;
		while (stream->Read(&response))
		{
			cout << "Got " << response.id() << "th message: " << response.keywords() << endl;
		}
		writer.join();
		Status status = stream->Finish();
		if (!status.ok())
		{
			std::cout << status.error_code() << ": " << status.error_message() << std::endl;
			cout << "textfeature chat rpc failed." << endl;
		}
	}
private:
	std::unique_ptr<TextFeature::Stub> stub_;
	vector<string> text_list_;
	string text_test_;

};




void run_test(int iter,int thread_num)
{
    int j = 0;
    while(j<iter)
    {    
        printf("Main %d thread begin time:%s\n",j,getTime().c_str());
        thread thread_rpc[thread_num];
        for (int i = 0;i<thread_num;++i)
        {
            thread_rpc[i] = thread(&TextFeatureClient::GuidListFeature,TextFeatureClient(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials())),i);       
        }
        for(int i = 0;i < thread_num;++i)
            thread_rpc[i].join();
        j++;
        printf("Main thread end time:%s\n",getTime().c_str());
    }
}

int main(int argc, char** argv)
{
    const int thread_num = 20;
    run_test(100,20);
    //thread thread_rpc[thread_num];
	//TextFeatureClient guid(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
	//std::cout << "---- A simple RPC ----" << std::endl;
	//bool flag=guid.GuidGetFeature();
    //for (int i = 0;i<thread_num;++i)
    //{
    //    thread_rpc[i] = thread(&TextFeatureClient::GuidListFeature,TextFeatureClient(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials())),i);
        //thread_rpc[i].join();
    //}
    //for (int j = 0;j < thread_num;++j)
    //    thread_rpc[j].join();
	//cout << "---- A Server Stream RPC ----" << endl;
	//bool res = guid.GuidListFeature();
	//cout << "----A client stream RPC -----" << endl;
	//guid.GuidRecordFeature();
	//cout << "----A bi-directional stream RPC ----" << endl;
	//guid.GuidChatFeature();
	return 0;
}
