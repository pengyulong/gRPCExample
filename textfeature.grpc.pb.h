// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: textfeature.proto
#ifndef GRPC_textfeature_2eproto__INCLUDED
#define GRPC_textfeature_2eproto__INCLUDED

#include "textfeature.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace textfeature {

class TextFeature final {
 public:
  static constexpr char const* service_full_name() {
    return "textfeature.TextFeature";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // 简单RPC
    virtual ::grpc::Status SimpleRPC(::grpc::ClientContext* context, const ::textfeature::textRequest& request, ::textfeature::keyResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::textfeature::keyResponse>> AsyncSimpleRPC(::grpc::ClientContext* context, const ::textfeature::textRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::textfeature::keyResponse>>(AsyncSimpleRPCRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::textfeature::keyResponse>> PrepareAsyncSimpleRPC(::grpc::ClientContext* context, const ::textfeature::textRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::textfeature::keyResponse>>(PrepareAsyncSimpleRPCRaw(context, request, cq));
    }
    // 服务端流式RPC
    std::unique_ptr< ::grpc::ClientReaderInterface< ::textfeature::orderkeyResponse>> ServerStreamRPC(::grpc::ClientContext* context, const ::textfeature::sentenceRequest& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::textfeature::orderkeyResponse>>(ServerStreamRPCRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::textfeature::orderkeyResponse>> AsyncServerStreamRPC(::grpc::ClientContext* context, const ::textfeature::sentenceRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::textfeature::orderkeyResponse>>(AsyncServerStreamRPCRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::textfeature::orderkeyResponse>> PrepareAsyncServerStreamRPC(::grpc::ClientContext* context, const ::textfeature::sentenceRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::textfeature::orderkeyResponse>>(PrepareAsyncServerStreamRPCRaw(context, request, cq));
    }
    // 客户端流式RPC
    std::unique_ptr< ::grpc::ClientWriterInterface< ::textfeature::docsRequest>> ClientStreamRPC(::grpc::ClientContext* context, ::textfeature::SummaryKeyWords* response) {
      return std::unique_ptr< ::grpc::ClientWriterInterface< ::textfeature::docsRequest>>(ClientStreamRPCRaw(context, response));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::textfeature::docsRequest>> AsyncClientStreamRPC(::grpc::ClientContext* context, ::textfeature::SummaryKeyWords* response, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::textfeature::docsRequest>>(AsyncClientStreamRPCRaw(context, response, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::textfeature::docsRequest>> PrepareAsyncClientStreamRPC(::grpc::ClientContext* context, ::textfeature::SummaryKeyWords* response, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::textfeature::docsRequest>>(PrepareAsyncClientStreamRPCRaw(context, response, cq));
    }
    // 双向流式RPC
    std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>> BidirectionalStreamRPC(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>>(BidirectionalStreamRPCRaw(context));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>> AsyncBidirectionalStreamRPC(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>>(AsyncBidirectionalStreamRPCRaw(context, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>> PrepareAsyncBidirectionalStreamRPC(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>>(PrepareAsyncBidirectionalStreamRPCRaw(context, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      // 简单RPC
      virtual void SimpleRPC(::grpc::ClientContext* context, const ::textfeature::textRequest* request, ::textfeature::keyResponse* response, std::function<void(::grpc::Status)>) = 0;
      // 服务端流式RPC
      virtual void ServerStreamRPC(::grpc::ClientContext* context, ::textfeature::sentenceRequest* request, ::grpc::experimental::ClientReadReactor< ::textfeature::orderkeyResponse>* reactor) = 0;
      // 客户端流式RPC
      virtual void ClientStreamRPC(::grpc::ClientContext* context, ::textfeature::SummaryKeyWords* response, ::grpc::experimental::ClientWriteReactor< ::textfeature::docsRequest>* reactor) = 0;
      // 双向流式RPC
      virtual void BidirectionalStreamRPC(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::textfeature::docsRequest,::textfeature::orderkeyResponse>* reactor) = 0;
    };
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::textfeature::keyResponse>* AsyncSimpleRPCRaw(::grpc::ClientContext* context, const ::textfeature::textRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::textfeature::keyResponse>* PrepareAsyncSimpleRPCRaw(::grpc::ClientContext* context, const ::textfeature::textRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientReaderInterface< ::textfeature::orderkeyResponse>* ServerStreamRPCRaw(::grpc::ClientContext* context, const ::textfeature::sentenceRequest& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::textfeature::orderkeyResponse>* AsyncServerStreamRPCRaw(::grpc::ClientContext* context, const ::textfeature::sentenceRequest& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::textfeature::orderkeyResponse>* PrepareAsyncServerStreamRPCRaw(::grpc::ClientContext* context, const ::textfeature::sentenceRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientWriterInterface< ::textfeature::docsRequest>* ClientStreamRPCRaw(::grpc::ClientContext* context, ::textfeature::SummaryKeyWords* response) = 0;
    virtual ::grpc::ClientAsyncWriterInterface< ::textfeature::docsRequest>* AsyncClientStreamRPCRaw(::grpc::ClientContext* context, ::textfeature::SummaryKeyWords* response, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncWriterInterface< ::textfeature::docsRequest>* PrepareAsyncClientStreamRPCRaw(::grpc::ClientContext* context, ::textfeature::SummaryKeyWords* response, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientReaderWriterInterface< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>* BidirectionalStreamRPCRaw(::grpc::ClientContext* context) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>* AsyncBidirectionalStreamRPCRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>* PrepareAsyncBidirectionalStreamRPCRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status SimpleRPC(::grpc::ClientContext* context, const ::textfeature::textRequest& request, ::textfeature::keyResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::textfeature::keyResponse>> AsyncSimpleRPC(::grpc::ClientContext* context, const ::textfeature::textRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::textfeature::keyResponse>>(AsyncSimpleRPCRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::textfeature::keyResponse>> PrepareAsyncSimpleRPC(::grpc::ClientContext* context, const ::textfeature::textRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::textfeature::keyResponse>>(PrepareAsyncSimpleRPCRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReader< ::textfeature::orderkeyResponse>> ServerStreamRPC(::grpc::ClientContext* context, const ::textfeature::sentenceRequest& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::textfeature::orderkeyResponse>>(ServerStreamRPCRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::textfeature::orderkeyResponse>> AsyncServerStreamRPC(::grpc::ClientContext* context, const ::textfeature::sentenceRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::textfeature::orderkeyResponse>>(AsyncServerStreamRPCRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::textfeature::orderkeyResponse>> PrepareAsyncServerStreamRPC(::grpc::ClientContext* context, const ::textfeature::sentenceRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::textfeature::orderkeyResponse>>(PrepareAsyncServerStreamRPCRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientWriter< ::textfeature::docsRequest>> ClientStreamRPC(::grpc::ClientContext* context, ::textfeature::SummaryKeyWords* response) {
      return std::unique_ptr< ::grpc::ClientWriter< ::textfeature::docsRequest>>(ClientStreamRPCRaw(context, response));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriter< ::textfeature::docsRequest>> AsyncClientStreamRPC(::grpc::ClientContext* context, ::textfeature::SummaryKeyWords* response, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncWriter< ::textfeature::docsRequest>>(AsyncClientStreamRPCRaw(context, response, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriter< ::textfeature::docsRequest>> PrepareAsyncClientStreamRPC(::grpc::ClientContext* context, ::textfeature::SummaryKeyWords* response, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncWriter< ::textfeature::docsRequest>>(PrepareAsyncClientStreamRPCRaw(context, response, cq));
    }
    std::unique_ptr< ::grpc::ClientReaderWriter< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>> BidirectionalStreamRPC(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriter< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>>(BidirectionalStreamRPCRaw(context));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>> AsyncBidirectionalStreamRPC(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>>(AsyncBidirectionalStreamRPCRaw(context, cq, tag));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>> PrepareAsyncBidirectionalStreamRPC(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>>(PrepareAsyncBidirectionalStreamRPCRaw(context, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void SimpleRPC(::grpc::ClientContext* context, const ::textfeature::textRequest* request, ::textfeature::keyResponse* response, std::function<void(::grpc::Status)>) override;
      void ServerStreamRPC(::grpc::ClientContext* context, ::textfeature::sentenceRequest* request, ::grpc::experimental::ClientReadReactor< ::textfeature::orderkeyResponse>* reactor) override;
      void ClientStreamRPC(::grpc::ClientContext* context, ::textfeature::SummaryKeyWords* response, ::grpc::experimental::ClientWriteReactor< ::textfeature::docsRequest>* reactor) override;
      void BidirectionalStreamRPC(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::textfeature::docsRequest,::textfeature::orderkeyResponse>* reactor) override;
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::textfeature::keyResponse>* AsyncSimpleRPCRaw(::grpc::ClientContext* context, const ::textfeature::textRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::textfeature::keyResponse>* PrepareAsyncSimpleRPCRaw(::grpc::ClientContext* context, const ::textfeature::textRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientReader< ::textfeature::orderkeyResponse>* ServerStreamRPCRaw(::grpc::ClientContext* context, const ::textfeature::sentenceRequest& request) override;
    ::grpc::ClientAsyncReader< ::textfeature::orderkeyResponse>* AsyncServerStreamRPCRaw(::grpc::ClientContext* context, const ::textfeature::sentenceRequest& request, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReader< ::textfeature::orderkeyResponse>* PrepareAsyncServerStreamRPCRaw(::grpc::ClientContext* context, const ::textfeature::sentenceRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientWriter< ::textfeature::docsRequest>* ClientStreamRPCRaw(::grpc::ClientContext* context, ::textfeature::SummaryKeyWords* response) override;
    ::grpc::ClientAsyncWriter< ::textfeature::docsRequest>* AsyncClientStreamRPCRaw(::grpc::ClientContext* context, ::textfeature::SummaryKeyWords* response, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncWriter< ::textfeature::docsRequest>* PrepareAsyncClientStreamRPCRaw(::grpc::ClientContext* context, ::textfeature::SummaryKeyWords* response, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientReaderWriter< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>* BidirectionalStreamRPCRaw(::grpc::ClientContext* context) override;
    ::grpc::ClientAsyncReaderWriter< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>* AsyncBidirectionalStreamRPCRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReaderWriter< ::textfeature::docsRequest, ::textfeature::orderkeyResponse>* PrepareAsyncBidirectionalStreamRPCRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_SimpleRPC_;
    const ::grpc::internal::RpcMethod rpcmethod_ServerStreamRPC_;
    const ::grpc::internal::RpcMethod rpcmethod_ClientStreamRPC_;
    const ::grpc::internal::RpcMethod rpcmethod_BidirectionalStreamRPC_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // 简单RPC
    virtual ::grpc::Status SimpleRPC(::grpc::ServerContext* context, const ::textfeature::textRequest* request, ::textfeature::keyResponse* response);
    // 服务端流式RPC
    virtual ::grpc::Status ServerStreamRPC(::grpc::ServerContext* context, const ::textfeature::sentenceRequest* request, ::grpc::ServerWriter< ::textfeature::orderkeyResponse>* writer);
    // 客户端流式RPC
    virtual ::grpc::Status ClientStreamRPC(::grpc::ServerContext* context, ::grpc::ServerReader< ::textfeature::docsRequest>* reader, ::textfeature::SummaryKeyWords* response);
    // 双向流式RPC
    virtual ::grpc::Status BidirectionalStreamRPC(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::textfeature::orderkeyResponse, ::textfeature::docsRequest>* stream);
  };
  template <class BaseClass>
  class WithAsyncMethod_SimpleRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_SimpleRPC() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_SimpleRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SimpleRPC(::grpc::ServerContext* context, const ::textfeature::textRequest* request, ::textfeature::keyResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSimpleRPC(::grpc::ServerContext* context, ::textfeature::textRequest* request, ::grpc::ServerAsyncResponseWriter< ::textfeature::keyResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_ServerStreamRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_ServerStreamRPC() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_ServerStreamRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ServerStreamRPC(::grpc::ServerContext* context, const ::textfeature::sentenceRequest* request, ::grpc::ServerWriter< ::textfeature::orderkeyResponse>* writer) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestServerStreamRPC(::grpc::ServerContext* context, ::textfeature::sentenceRequest* request, ::grpc::ServerAsyncWriter< ::textfeature::orderkeyResponse>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_ClientStreamRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_ClientStreamRPC() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_ClientStreamRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ClientStreamRPC(::grpc::ServerContext* context, ::grpc::ServerReader< ::textfeature::docsRequest>* reader, ::textfeature::SummaryKeyWords* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestClientStreamRPC(::grpc::ServerContext* context, ::grpc::ServerAsyncReader< ::textfeature::SummaryKeyWords, ::textfeature::docsRequest>* reader, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncClientStreaming(2, context, reader, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_BidirectionalStreamRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_BidirectionalStreamRPC() {
      ::grpc::Service::MarkMethodAsync(3);
    }
    ~WithAsyncMethod_BidirectionalStreamRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BidirectionalStreamRPC(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::textfeature::orderkeyResponse, ::textfeature::docsRequest>* stream)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestBidirectionalStreamRPC(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::textfeature::orderkeyResponse, ::textfeature::docsRequest>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(3, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_SimpleRPC<WithAsyncMethod_ServerStreamRPC<WithAsyncMethod_ClientStreamRPC<WithAsyncMethod_BidirectionalStreamRPC<Service > > > > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_SimpleRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_SimpleRPC() {
      ::grpc::Service::experimental().MarkMethodCallback(0,
        new ::grpc::internal::CallbackUnaryHandler< ExperimentalWithCallbackMethod_SimpleRPC<BaseClass>, ::textfeature::textRequest, ::textfeature::keyResponse>(
          [this](::grpc::ServerContext* context,
                 const ::textfeature::textRequest* request,
                 ::textfeature::keyResponse* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->SimpleRPC(context, request, response, controller);
                 }, this));
    }
    ~ExperimentalWithCallbackMethod_SimpleRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SimpleRPC(::grpc::ServerContext* context, const ::textfeature::textRequest* request, ::textfeature::keyResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void SimpleRPC(::grpc::ServerContext* context, const ::textfeature::textRequest* request, ::textfeature::keyResponse* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_ServerStreamRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_ServerStreamRPC() {
    }
    ~ExperimentalWithCallbackMethod_ServerStreamRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ServerStreamRPC(::grpc::ServerContext* context, const ::textfeature::sentenceRequest* request, ::grpc::ServerWriter< ::textfeature::orderkeyResponse>* writer) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_ClientStreamRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_ClientStreamRPC() {
    }
    ~ExperimentalWithCallbackMethod_ClientStreamRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ClientStreamRPC(::grpc::ServerContext* context, ::grpc::ServerReader< ::textfeature::docsRequest>* reader, ::textfeature::SummaryKeyWords* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_BidirectionalStreamRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_BidirectionalStreamRPC() {
    }
    ~ExperimentalWithCallbackMethod_BidirectionalStreamRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BidirectionalStreamRPC(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::textfeature::orderkeyResponse, ::textfeature::docsRequest>* stream)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  typedef ExperimentalWithCallbackMethod_SimpleRPC<ExperimentalWithCallbackMethod_ServerStreamRPC<ExperimentalWithCallbackMethod_ClientStreamRPC<ExperimentalWithCallbackMethod_BidirectionalStreamRPC<Service > > > > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_SimpleRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_SimpleRPC() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_SimpleRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SimpleRPC(::grpc::ServerContext* context, const ::textfeature::textRequest* request, ::textfeature::keyResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_ServerStreamRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_ServerStreamRPC() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_ServerStreamRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ServerStreamRPC(::grpc::ServerContext* context, const ::textfeature::sentenceRequest* request, ::grpc::ServerWriter< ::textfeature::orderkeyResponse>* writer) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_ClientStreamRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_ClientStreamRPC() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_ClientStreamRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ClientStreamRPC(::grpc::ServerContext* context, ::grpc::ServerReader< ::textfeature::docsRequest>* reader, ::textfeature::SummaryKeyWords* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_BidirectionalStreamRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_BidirectionalStreamRPC() {
      ::grpc::Service::MarkMethodGeneric(3);
    }
    ~WithGenericMethod_BidirectionalStreamRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BidirectionalStreamRPC(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::textfeature::orderkeyResponse, ::textfeature::docsRequest>* stream)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_SimpleRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_SimpleRPC() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_SimpleRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SimpleRPC(::grpc::ServerContext* context, const ::textfeature::textRequest* request, ::textfeature::keyResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSimpleRPC(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_ServerStreamRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_ServerStreamRPC() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_ServerStreamRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ServerStreamRPC(::grpc::ServerContext* context, const ::textfeature::sentenceRequest* request, ::grpc::ServerWriter< ::textfeature::orderkeyResponse>* writer) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestServerStreamRPC(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncWriter< ::grpc::ByteBuffer>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_ClientStreamRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_ClientStreamRPC() {
      ::grpc::Service::MarkMethodRaw(2);
    }
    ~WithRawMethod_ClientStreamRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ClientStreamRPC(::grpc::ServerContext* context, ::grpc::ServerReader< ::textfeature::docsRequest>* reader, ::textfeature::SummaryKeyWords* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestClientStreamRPC(::grpc::ServerContext* context, ::grpc::ServerAsyncReader< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* reader, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncClientStreaming(2, context, reader, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_BidirectionalStreamRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_BidirectionalStreamRPC() {
      ::grpc::Service::MarkMethodRaw(3);
    }
    ~WithRawMethod_BidirectionalStreamRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BidirectionalStreamRPC(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::textfeature::orderkeyResponse, ::textfeature::docsRequest>* stream)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestBidirectionalStreamRPC(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(3, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_SimpleRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_SimpleRPC() {
      ::grpc::Service::experimental().MarkMethodRawCallback(0,
        new ::grpc::internal::CallbackUnaryHandler< ExperimentalWithRawCallbackMethod_SimpleRPC<BaseClass>, ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this](::grpc::ServerContext* context,
                 const ::grpc::ByteBuffer* request,
                 ::grpc::ByteBuffer* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->SimpleRPC(context, request, response, controller);
                 }, this));
    }
    ~ExperimentalWithRawCallbackMethod_SimpleRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SimpleRPC(::grpc::ServerContext* context, const ::textfeature::textRequest* request, ::textfeature::keyResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void SimpleRPC(::grpc::ServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_ServerStreamRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_ServerStreamRPC() {
    }
    ~ExperimentalWithRawCallbackMethod_ServerStreamRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ServerStreamRPC(::grpc::ServerContext* context, const ::textfeature::sentenceRequest* request, ::grpc::ServerWriter< ::textfeature::orderkeyResponse>* writer) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_ClientStreamRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_ClientStreamRPC() {
    }
    ~ExperimentalWithRawCallbackMethod_ClientStreamRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ClientStreamRPC(::grpc::ServerContext* context, ::grpc::ServerReader< ::textfeature::docsRequest>* reader, ::textfeature::SummaryKeyWords* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_BidirectionalStreamRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_BidirectionalStreamRPC() {
    }
    ~ExperimentalWithRawCallbackMethod_BidirectionalStreamRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BidirectionalStreamRPC(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::textfeature::orderkeyResponse, ::textfeature::docsRequest>* stream)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_SimpleRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_SimpleRPC() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::textfeature::textRequest, ::textfeature::keyResponse>(std::bind(&WithStreamedUnaryMethod_SimpleRPC<BaseClass>::StreamedSimpleRPC, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_SimpleRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status SimpleRPC(::grpc::ServerContext* context, const ::textfeature::textRequest* request, ::textfeature::keyResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSimpleRPC(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::textfeature::textRequest,::textfeature::keyResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_SimpleRPC<Service > StreamedUnaryService;
  template <class BaseClass>
  class WithSplitStreamingMethod_ServerStreamRPC : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithSplitStreamingMethod_ServerStreamRPC() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::SplitServerStreamingHandler< ::textfeature::sentenceRequest, ::textfeature::orderkeyResponse>(std::bind(&WithSplitStreamingMethod_ServerStreamRPC<BaseClass>::StreamedServerStreamRPC, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithSplitStreamingMethod_ServerStreamRPC() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status ServerStreamRPC(::grpc::ServerContext* context, const ::textfeature::sentenceRequest* request, ::grpc::ServerWriter< ::textfeature::orderkeyResponse>* writer) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with split streamed
    virtual ::grpc::Status StreamedServerStreamRPC(::grpc::ServerContext* context, ::grpc::ServerSplitStreamer< ::textfeature::sentenceRequest,::textfeature::orderkeyResponse>* server_split_streamer) = 0;
  };
  typedef WithSplitStreamingMethod_ServerStreamRPC<Service > SplitStreamedService;
  typedef WithStreamedUnaryMethod_SimpleRPC<WithSplitStreamingMethod_ServerStreamRPC<Service > > StreamedService;
};

}  // namespace textfeature


#endif  // GRPC_textfeature_2eproto__INCLUDED