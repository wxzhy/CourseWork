cmake_minimum_required(VERSION 3.25)
project(CourseWork)

set(CMAKE_CXX_STANDARD 17)

add_executable(CourseWork main.cpp User.cpp User.h Student.cpp Student.h Teacher.cpp Teacher.h Course.cpp Course.h Score.cpp Score.h AdminSystem.cpp AdminSystem.h Link.h StudentLink.cpp StudentLink.h TeacherLink.cpp TeacherLink.h Display.cpp Display.h main.h CourseLink.cpp CourseLink.h)
