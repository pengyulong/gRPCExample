## gRPC简介(什么是gRPC)
<p> RPC的全称是(Remote Procedure Call)即远程过程调用，它的目的是使得调用远程服务的接口，就像调用本地函数一样简单易用。gRPC是Google开源的基于Protobuf和Http2.0协议的RPC框架，Google深度学习框架tensorflow底层的RPC通信就完全依赖于gRPC库。</p>

## gRPC安装教程
<p> gPPC支持跨平台，并支持C,Go,C++,Java,Python,PHP,Ruby等各种语言，但现在还没有一个正式的release版本，现针对centos 7复现了如下可用的安装教程。</p>

1. 安装gRPC依赖库：
```
sudo yum install autoconf,libtool,curl,git
```
2. 克隆gRPC创库到本地文件夹,并利用git更新依赖库
```
git clone https://github.com/grpc/grpc.git
cd grpc
git submodule update --init
```
3. 安装protobuf
```
cd third_party/protobuf/
./autogen.sh
./configure
```
注意这里可能会出现"WARNING:no configuration information is in third_party/googletest 这时，只需下载`googletest`的release包，解压到`./third_party/googeltest`下，然后重新执行：
```
./autogen.sh
./configure
make
sudo make install
ldconfig
protoc --version #如果没报错，就说明protobuf安装成功
````
4. 安装gRPC
```
cd ../..
make
sudo make install
```
5. 测试并添加激活环境变量文件
```
cd /example/cpp/helloworld
make
```
此时可能会出现如下的错误:
```
Package grpc++ was not found in the pkg-config search path.
Perhaps you should add the directory containing `grpc++.pc'
to the PKG_CONFIG_PATH environment variable
No package 'grpc++' found
Package grpc was not found in the pkg-config search path.
Perhaps you should add the directory containing `grpc.pc'
to the PKG_CONFIG_PATH environment variable
```
如果碰到这种情况,说明没有找到PKG_CONFIG_PATH,此时只需贴上如下的代码，命名为`activate.sh`，然后再每次执行gRPC的时候，`source activate.sh`:
```
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
export PATH=$PATH:$DIR/bins/opt:$DIR/bins/opt/protobuf
export CPATH=$DIR/include:$DIR/third_party/protobuf/src
export LIBRARY_PATH=$DIR/libs/opt:$DIR/libs/opt/protobuf
export PKG_CONFIG_PATH=$DIR/libs/opt/pkgconfig:$DIR/third_party/protobuf
export LD_LIBRARY_PATH=$DIR/libs/opt
```
6. 验证:
```
source activate.sh
cd examples/cpp/helloworld/
make
./greeter_server
./greeter_client
```
此时如果出现`hello,world`说明已安装成功，可以正常使用了。

## 快速开始(使用流程)
<p> 下面以搭建一个中文文本关键词抽取算法服务为例，来说明怎么使用gRPC快速搭建分布式服务程序，为了更好地描述框架的使用过程，这里仅以python-grpc为例，如果想换成其他语言，按照此过程文档，稍微查下相关语言的api，应该可以快速完成。
</p>

1. 定义接口描述语言(IDL)
```
// testfeature.proto

syntax = "proto3";

package textfeature;
service TextFeature{
    // 简单RPC
    rpc SimpleRPC(textRequest) returns (keyResponse) {}
    // 服务端流式RPC
    rpc ServerStreamRPC (sentenceRequest) returns (stream orderkeyResponse) {}
    // 客户端流式RPC
    rpc ClientStreamRPC(stream docsRequest) returns (SummaryKeyWords){}
    // 双向流式RPC
    rpc BidirectionalStreamRPC(stream docsRequest) returns (stream orderkeyResponse){}
}
message textRequest{
    string text = 1;
}
message keyResponse{
    string keywords = 1;
}
message orderkeyResponse{
    int32 id = 1;
    string keywords = 2;
}
message docsRequest{
    int32 id = 1;
    string text = 2;
}
message SummaryKeyWords{
    repeated string keywords = 1;
}
message sentenceRequest{
    repeated string text = 1;
}
```
2. 使用protoc工具编译IDL,生成目标语言的服务接口文件
```
python -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. textfeature.proto
```
3. 根据服务接口文件，编写服务器具体逻辑实现
```
from __future__ import print_function
from __future__ import division

from concurrent import futures
import jieba
import grpc
import time

import textfeature_pb2
import textfeature_pb2_grpc

_ONE_DAY_IN_SECONDS = 60*60*24

def extract_feature(text):
    res = jieba.analyse.extract_tags(text,topK=3,allowPOS=('ns','n','vn','v'))
    return ','.join(res)

class TextFeatureServicer(textfeature_pb2_grpc.TextFeatureServicer):
    def __init__(self):
        self.text_list,self.docs_list = text_feature_src.read_text_feature_db()

    def SimpleRPC(self, request, context):
        if request.text is None:
            return textfeature_pb2.keyResponse(keywords='NULL')
        else:
            res = extract_feature(request.text)
            return textfeature_pb2.keyResponse(keywords=res)

    def ServerStreamRPC(self, request, context):
        for i,text in enumerate(request.text):
            print("text:{}".format(text))
            keywords = extract_feature(text)
            print("keywords:{}".format(keywords))
            response = textfeature_pb2.orderkeyResponse(id=i,keywords=keywords)
            yield response

    def ClientStreamRPC(self, request_iterator, context):
        result = []
        for req in request_iterator:
            #print("req:{}".format(req))
            i,text = req.id,req.text
            keywords = extract_feature(text)
            result.append('id:{},keywords:{}'.format(i,keywords))
        return textfeature_pb2.SummaryKeyWords(keywords=result)

    def BidirectionalStreamRPC(self, request_iterator, context):
        for req in request_iterator:
            i,text = req.id,req.text
            keywords = extract_feature(text)
            response = textfeature_pb2.orderkeyResponse(id=i,keywords=keywords)
            yield response

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    Servicer = TextFeatureServicer()
    textfeature_pb2_grpc.add_TextFeatureServicer_to_server(Servicer,server)
    server.add_insecure_port('[::]:50051')
    server.start()
    try:
        while True:
            time.sleep(_ONE_DAY_IN_SECONDS)
    except KeyboardInterrupt:
        server.stop(0)

if __name__ == '__main__':
    serve()

```
4. 编写客户端交互代码：
```
from __future__ import print_function
import grpc
import json
import textfeature_pb2
import textfeature_pb2_grpc

def read_text_list():
    text_list,docs_list = [],[]
    with open('text_feature_db.json',encoding='utf-8') as outfile:
        for item in json.load(outfile):
            id,text = item['id'],item['text']
            text_list.append(text)
            docs_list.append({'id':id,'text':text})
    return text_list,docs_list

#模拟测试数据
sentence_list,docs_list = read_text_list()

#A simple RPC,同步模式
def guide_get_one_feature(stub,text):
    print("text:{}".format(text))
    keywords = stub.SimpleRPC(textfeature_pb2.textRequest(text=text))
    print("keywords:{}".format(keywords.keywords))

def guide_get_feature(stub):
    guide_get_one_feature(stub,"小明毕业于清华大学计算机专业,在网易工作5年了.")

#服务端流式RPC
def guide_list_features(stub):
    request = textfeature_pb2.sentenceRequest(text=sentence_list)
    response_iter = stub.ServerStreamRPC(request)
    for response in response_iter:
        print("the {}th text:\n{}".format(response.id,sentence_list[response.id]))
        print("keywords:{}".format(response.keywords))

def generate_list(text_list):
    for item in text_list:
        i,text = item['id'],item['text']
        yield textfeature_pb2.docsRequest(id=i,text=text)

#客户端流式RPC
def guide_record_feature(stub):
    request_iter = generate_list(docs_list)
    response = stub.ClientStreamRPC(request_iter)
    for item in response.keywords:
        print(item)

#双向流式RPC
def guide_chat_feature(stub):
    request_iter = generate_list(docs_list)
    response_iter = stub.BidirectionalStreamRPC(request_iter)
    for response in response_iter:
        print("id:{},keywords:{}".format(response.id,response.keywords))
        
def run():
    with grpc.insecure_channel('localhost:50051') as channel:
        stub = textfeature_pb2_grpc.TextFeatureStub(channel)
        print("---- A simple model ----")
        guide_get_feature(stub)
        print("---- A server-stream model -----")
        guide_list_features(stub)
        print("---- A client-stream model ----")
        guide_record_feature(stub)
        print("---- A Bi-directional stream model ----")
        guide_chat_feature(stub)

if __name__ == "__main__":
    run()
```
5. 在gRPC安装环境下分别运行客户端和服务端代码:
```
nohup python textfeature_server.py &
python textfeature_client.py
```
