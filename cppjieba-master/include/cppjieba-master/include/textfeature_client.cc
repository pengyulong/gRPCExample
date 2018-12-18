
#include <thread>

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "textfeature.grpc.pb.h"
using grpc::Status;
using textfeature::textRequest;
using textfeature::keyResponse;
using grpc::Channel;
using grpc::ClientContext;
using textfeature::TextFeature;

class TextFeatureClient {
public:
	TextFeatureClient(std::shared_ptr<Channel> channel) :stub_(TextFeature::NewStub(channel)) {}

	void GuidGetFeature()
	{
		std::string test_text = "小明来自清华大学，在网易工作5年了。";
		ClientContext context;
		textRequest request;
		request.text = test_text;
		keyResponse* response;
		Status status = stub_->SimpleRPC(&context, request, response);
		std::cout << "keywords: " << response->keywords << std::endl;
	}
private:
	std::unique_ptr<TextFeature::Stub> stub_;

};

int main(int argc, char** argv)
{
	TextFeatureClient guid(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
	std::cout << "---- A simple RPC ----" << std::endl;
	guid.GuidGetFeature();
	return 0;
}