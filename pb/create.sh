#!/bin/bash

# PROTOC_DIR=$VCPKGROOT/installed/x64-osx/tools/protobuf/protoc
PROTOC_DIR=../src/3rd-party/lib/bin/protoc
DST_DIR=../src/chatkit/cim/pb

${PROTOC_DIR} --cpp_out=${DST_DIR} CIM.Def.proto
${PROTOC_DIR} --cpp_out=${DST_DIR} CIM.Friend.proto
${PROTOC_DIR} --cpp_out=${DST_DIR} CIM.Group.proto
${PROTOC_DIR} --cpp_out=${DST_DIR} CIM.List.proto
${PROTOC_DIR} --cpp_out=${DST_DIR} CIM.Login.proto
${PROTOC_DIR} --cpp_out=${DST_DIR} CIM.Message.proto
${PROTOC_DIR} --cpp_out=${DST_DIR} CIM.Voip.proto