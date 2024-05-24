cmake_minimum_required(VERSION 3.28)
project(wangdao_datastructure C)

set(CMAKE_C_STANDARD 11)

add_executable(wangdao_datastructure main.c)
add_executable(SqStack chapter3/Stack/SqStack/main.c)
add_executable(SharedStack chapter3/Stack/SharedStack/main.c)
add_executable(noHead chapter3/Stack/LiStack/noHead/main.c)
add_executable(withHead chapter3/Stack/LiStack/withHead/main.c)
