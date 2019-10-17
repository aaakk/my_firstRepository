#!/bin/bash

if [ ! -d build  ];then
    mkdir build
fi

if [ ! -d lib ];then
    mkdir lib
fi

if [ ! -d ccache_dir ];then
    mkdir ccache_dir
    mkdir ccache_log
fi

cd build

export CCACHE_DIR=./ccache
export CCACHE_LOGFILE=./ccache_log

if [[ $@ = "fast" ]];then
    cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER:FILEPATH=/usr/lib/ccache/g++  ..
else
    cd ..
    rm -rf build
    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER:FILEPATH=/usr/lib/ccache/g++  ..
fi

make

./cppliang
