cmake_minimum_required(VERSION 3.10)
project(lsn6)

set(CMAKE_CXX_STANDARD 11)

add_executable(lsn6 main.cpp SafeQueue.h Ptr.h)