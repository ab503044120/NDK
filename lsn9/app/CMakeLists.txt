# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)


add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp )


#设置一个变量
# CMAKE_CXX_FLAGS c++的参数 会传给编译器
# CMAKE_C_FLAGS c的参数 会传给编译器
# CMAKE_CXX_FLAGS=--sysroot=XX
# 重新定义  CMAKE_CXX_FLAGS 变量  +
# CMAKE_SOURCE_DIR 的值是当前这个文件的地址
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/src/main/jniLibs/armeabi-v7a")


#add_library(Test SHARED IMPORTED)
#set_target_properties(Test PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/armeabi-v7a/libTest.so)

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )