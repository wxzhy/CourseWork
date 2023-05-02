cmake_minimum_required(VERSION 3.25)
project(CourseWork)

set(CMAKE_CXX_STANDARD 17)

add_executable(CourseWork main.cpp User.cpp User.h Student.cpp Student.h Teacher.cpp Teacher.h Course.cpp Course.h Score.cpp Score.h fileUtils.cpp fileUtils.h AdminSystem.cpp AdminSystem.h)
