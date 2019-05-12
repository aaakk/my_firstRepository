#确定cmake版本
cmake_minimum_required(VERSION 3.0)

#设置环境变量
SET(current_dir     ${CMAKE_CURRENT_SOURCE_DIR})   #当前CMakeLists.txt所在文件夹
SET(code_dir        ${current_dir}/code)
SET(ft_dir          ${current_dir}/ft)
SET(lib_dir         ${current_dir}/lib)
SET(3rd_dir         ${current_dir}/3rd)


#项目名称
PROJECT(cppliang)

#包含其他cmake文件路径
INCLUDE(
    #头文件
    "${current_dir}/include.cmake" 
    #编译选项
    "${current_dir}/compiler.cmake"
)

#源文件路径
FILE(GLOB SRC_LIST
    "${code_dir}/src/*.cpp"
    "${code_dir}/src/visitor/*.cpp" 
    "${ft_dir}/src/*.cpp"
    "${ft_dir}/src/unittest/*.cpp"
)

#生成库文件
FIND_LIBRARY(lianglib NAMES gtest PATHS ${lib_dir})
IF(lianglib)
MESSAGE("libgtest exist")
ELSE(NOT lianglib)
add_subdirectory(${3rd_dir}/gtest)
ENDIF(lianglib)

#链接库路径
LINK_DIRECTORIES(${lib_dir})

#生成可执行文件
ADD_EXECUTABLE(cppliang ${SRC_LIST})

#链接库文件
TARGET_LINK_LIBRARIES(cppliang gtest pthread)
