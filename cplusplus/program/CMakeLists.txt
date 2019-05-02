#确定cmake版本
cmake_minimum_required(VERSION 3.0)

#设置环境变量
SET(current_dir  ${CMAKE_CURRENT_SOURCE_DIR})   #当前CMakeLists.txt所在文件夹
SET(code_dir     ${current_dir}/code)
SET(ft_dir       ${current_dir}/ft)
SET(3rd_dir      ${current_dir}/3rd)


#项目名称
PROJECT(cppliang)

#头文件路径
INCLUDE_DIRECTORIES(
    "${code_dir}/inc"
    "${ft_dir}/inc"
    "${3rd_dir}/inc"
)

#源文件路径
FILE(GLOB SRC_LIST
    "${code_dir}/src/*.cpp" 
    "${ft_dir}/src/*.cpp"
    "${ft_dir}/src/unittest/*.cpp"
)

#构建静态库libgtest.a
SET(source      ${3rd_dir}/inc/gtest/)
SET(headers     ${3rd_dir}/src/gtest/)

ADD_LIBRARY(gtest ${source} ${headers})

SET_TARGET_PROPERTIES(gtest PROPERTIES LINKER_LANGUAGE C)

#6.生成可执行文件
ADD_EXECUTABLE(cppliang ${SRC_LIST})

#7.链接库文件
TARGET_LINK_LIBRARIES(cppliang gtest pthread)
