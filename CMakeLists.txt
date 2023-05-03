cmake_minimum_required(VERSION 3.25)
project(CourseWork)

set(CMAKE_CXX_STANDARD 17)

add_executable(CourseWork main.cpp User.cpp User.h Student.cpp Student.h Teacher.cpp Teacher.h Course.cpp Course.h Score.cpp Score.h Link.h StudentLink.cpp StudentLink.h TeacherLink.cpp TeacherLink.h Display.cpp Display.h CourseLink.cpp CourseLink.h ScoreLink.cpp ScoreLink.h LoginUtils.cpp LoginUtils.h TeacherMenu.cpp TeacherMenu.h StudentMenu.cpp StudentMenu.h Database.cpp Database.h AdminMenu.cpp AdminMenu.h StudentManager.cpp StudentManager.h TeacherManager.cpp TeacherManager.h CourseManager.cpp CourseManager.h ScoreManager.cpp ScoreManager.h)
