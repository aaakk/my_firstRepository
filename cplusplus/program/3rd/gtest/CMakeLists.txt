cmake_minimum_required(VERSION 3.0)

SET(current_dir     ${CMAKE_CURRENT_SOURCE_DIR})   
SET(inc_dir         ${current_dir}/inc)
SET(src_dir         ${current_dir}/src)
SET(lib_dir         ${current_dir}/../../lib)

INCLUDE_DIRECTORIES(
    "${inc_dir}"
    "${src_dir}"
)

FILE(GLOB  source      "${src_dir}/*.cc")

ADD_LIBRARY(gtest ${source})

SET_TARGET_PROPERTIES(gtest PROPERTIES  LINKER_LANGUAGE             CXX 
                                        LIBRARY_OUTPUT_DIRECTORY    ${lib_dir})


