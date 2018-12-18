#! /bin/bash
#
# protoc_cpp.sh
#

protoc --cpp_out=. textfeature.proto
protoc --grpc_out=. --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin textfeature.proto

