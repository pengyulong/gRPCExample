/*
 * textfeature_server.cc
 * Copyright (C) 2018 app <app@VM_127_26_centos>
 *
 */

#include <iostream>
#include <string>
#include <vector>

#include <grpc/grpc.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>


#include "textfeature.grpc.pb.h"
#include "cppjieba/Jieba.hpp"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerWriter;
using grpc::Status;
using grpc::ServerReaderWriter;


using textfeature::textRequest;
using textfeature::keyResponse;
using textfeature::sentenceRequest;
using textfeature::orderkeyResponse;
using textfeature::TextFeature;
using textfeature::SummaryKeyWords;
using textfeature::docsRequest;

using namespace std;

const char* const DICT_PATH = "./dict/jieba.dict.utf8";
const char* const HMM_PATH = "./dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "./dict/user.dict.utf8";
const char* const IDF_PATH = "./dict/idf.utf8";
const char* const STOP_WORD_PATH = "./dict/stop_words.utf8";


bool ExtractKeywords(const string& sentence,string& result)
{
    cppjieba::Jieba jieba(DICT_PATH,HMM_PATH,USER_DICT_PATH,IDF_PATH,STOP_WORD_PATH);
    vector<string> words;
    vector<cppjieba::Word> jiebawords;
    const size_t topk = 3;
    vector<cppjieba::KeywordExtractor::Word> keywordres;
    jieba.extractor.Extract(sentence, keywordres, topk);
    result = "";
    for (auto p : keywordres)
        result += p.word + ",";
    return true;
}

class TextFeatureImp final :public TextFeature::Service {
public:
	explicit TextFeatureImp(){}
	Status SimpleRPC(ServerContext* context, const textRequest* request, keyResponse* response) override {
		string text = request->text();
        cout << "text : " << text <<endl;
		string result = " ";
		ExtractKeywords(text, result);
		cout << "keywords:" << result << endl;
		response->set_keywords(result.c_str());
		return Status::OK;
	}
	Status ServerStreamRPC(ServerContext* context,const sentenceRequest* request, ServerWriter<orderkeyResponse >* writer) override 
	{
		cout << "text's length is "<<request->text_size() << endl;
		for (size_t i = 0; i < request->text_size(); ++i)
		{
			string result;
			string text = request->text(i);
			bool res = ExtractKeywords(text,result);
			orderkeyResponse response;
			response.set_id(i);
			response.set_keywords(result);
			writer->Write(response);

		}
		return Status::OK;
	}
	Status ClientStreamRPC(ServerContext* context, ServerReader<docsRequest>* reader, SummaryKeyWords* response) override
	{
		docsRequest request;
		vector<string> keywords_list;
		while (reader->Read(&request))
		{
			int id =request.id();
			string text = request.text();
			string result;
			bool res = ExtractKeywords(text, result);
			string result_string = "id: " + to_string(id) + ",keywords:" + result;
			cout << result_string << endl;
			response->add_keywords(result_string.c_str());
		}
		return Status::OK;
	}
	Status BidirectionalStreamRPC(ServerContext* context, ServerReaderWriter<orderkeyResponse, docsRequest>* stream) override
	{
		//vector<orderkeyResponse> response_list;
		vector<docsRequest> request_list;
		docsRequest req;
		while (stream->Read(&req))
		{
			for (auto p : request_list)
			{
				int id = p.id();
				string text = p.text();
				string result;
				ExtractKeywords(text, result);
				orderkeyResponse response;
				response.set_id(id);
				response.set_keywords(result.c_str());
				stream->Write(response);
			}
			request_list.push_back(req);

		}
		return Status::OK;

	}
};

void RunServer()
{
	std::string server_address("0.0.0.0:50051");
	TextFeatureImp service;
	ServerBuilder builder;
	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
	builder.RegisterService(&service);
	std::unique_ptr<Server> server(builder.BuildAndStart());
	std::cout << "Server listening on " << server_address << std::endl;
	server->Wait();

}
int main(int argc, char** argv)
{
	RunServer();
	return 0;
}
