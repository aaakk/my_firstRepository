#!/bin/bash

if [ ! -d build  ];then
    mkdir build
else
    rm -rf build
    mkdir build
fi

cd build

cmake -DCMAKE_BUILD_TYPE=Debug ..

make

./cppliang
