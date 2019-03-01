#1.cmake verson
cmake_minimum_required(VERSION 3.0)

#2.set environment variable
SET(current_dir  ${CMAKE_CURRENT_SOURCE_DIR})
SET(code_dir     ${current_dir}/../code)
SET(ft_dir       ${current_dir})


#3.project name
PROJECT(cppliang)

#4.head file path
#INCLUDE_DIRECTORIES(
#    "${code_dir}/inc"
#  "${ft_dir}/inc"
#)

#5.source directory
FILE(GLOB SRC_LIST "${ft_dir}/src/*.cpp")

#6.add executable file
ADD_EXECUTABLE(cppliang ${SRC_LIST})

#7.add link library
#TARGET_LINK_LIBRARIES(${PROJECT_NAME} m)
