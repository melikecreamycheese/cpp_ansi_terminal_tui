cmake_minimum_required(VERSION 3.10)
project(grapmain VERSION 1.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp grappos.cpp c_colours.h)
