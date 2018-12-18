#! /bin/bash
#
# run.sh
#

g++ -std=c++11 -pthread -I../3rdparty/include  -c -o textfeature.pb.o textfeature.pb.cc
g++ -std=c++11 -pthread -I../3rdparty/include  -c -o textfeature.grpc.pb.o textfeature.grpc.pb.cc
g++ -std=c++11 -pthread -I../3rdparty/include  -c -o textfeature_client.o textfeature_client.cc
g++ textfeature.pb.o textfeature.grpc.pb.o textfeature_client.o -L../3rdparty/lib -pthread -L../3rdparty/lib -lprotobuf -lgrpc++ -Wl,--no-as-needed -lgrpc++_reflection -lpthread -Wl,--as-needed -ldl -o textfeature_client
g++ -std=c++11 -pthread -I../3rdparty/include  -c -o textfeature_server.o textfeature_server.cc
g++ textfeature.pb.o textfeature.grpc.pb.o textfeature_server.o -L../3rdparty/lib -pthread -L../3rdparty/lib -lprotobuf -lgrpc++ -Wl,--no-as-needed -lgrpc++_reflection -lpthread -Wl,--as-needed -ldl -o textfeature_server

