cmake_minimum_required(VERSION 3.0)

project(FLTK_Test VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ..)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ..)

#add_library(Fl_Single_Choice_Question STATIC Fl_Question.hpp Fl_Question.cpp Fl_Single_Choice_Question.hpp Fl_Single_Choice_Question.cpp)

add_executable(main main.cpp Fl_Question.hpp Fl_Question.cpp Fl_Single_Choice_Question.hpp Fl_Single_Choice_Question.cpp)

target_link_libraries(main fltk )