cmake_minimum_required(VERSION 3.24)
project(Asg)

set(CMAKE_CXX_STANDARD 17)

add_executable(Asg main.cpp UserDictionary.cpp UserDictionary.h User.h Topic.h Topic.cpp Forum.cpp Forum.h Post.h)
