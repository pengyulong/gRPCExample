#! /bin/bash
#
# protoc_cpp.sh
# Copyright (C) 2018 app <app@tencent.com>
#

protoc --cpp_out=. textfeature.proto
protoc --grpc_out=. --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin textfeature.proto

