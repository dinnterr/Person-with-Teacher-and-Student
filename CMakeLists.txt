cmake_minimum_required(VERSION 3.25)
project(coursework)

set(CMAKE_CXX_STANDARD 17)

add_executable(coursework main.cpp Sources/Person.cpp Headers/Person.h Sources/Teacher.cpp Headers/Teacher.h Sources/Student.cpp Headers/Student.h Headers/Scholarships.h People.h People.cpp)
