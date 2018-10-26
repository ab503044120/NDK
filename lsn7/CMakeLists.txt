cmake_minimum_required(VERSION 3.10)
project(lsn7)

set(CMAKE_CXX_STANDARD 11)

include_directories("/Library/Java/JavaVirtualMachines/jdk1.8.0_162.jdk/Contents/Home/include")
include_directories("/Library/Java/JavaVirtualMachines/jdk1.8.0_162.jdk/Contents/Home/include/darwin")

#生成一个库  so动态库
add_library(lsn7 SHARED main.cpp)

#将源添加到此项目的可执行文件
#add_executable(lsn7 main.cpp)