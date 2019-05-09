cmake_minimum_required(VERSION 3.0)

SET(current_dir     ${CMAKE_CURRENT_SOURCE_DIR})   
SET(inc_dir         ${current_dir}/inc)
SET(src_dir         ${current_dir}/src)

INCLUDE_DIRECTORIES(
    "${inc_dir}"
    "${src_dir}/../"
)

FILE(GLOB source      "${src_dir}/*.cc")

#静态库输出路径
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${current_dir}/../../lib)

#生成库
ADD_LIBRARY(gtest ${source})

#链接语言
SET_TARGET_PROPERTIES(gtest PROPERTIES  LINKER_LANGUAGE CXX)
