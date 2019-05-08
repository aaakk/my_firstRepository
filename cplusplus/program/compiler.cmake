cmake_minimum_required(VERSION 3.0)

#debug版本编译选项
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -Wall -g3 -ggdb")  # Debug模式下的编译指令

#release版本编译选项
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -Wall") 