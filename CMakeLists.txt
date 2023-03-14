cmake_minimum_required(VERSION 3.5)

project(cart_main LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cart_main main.cpp datamodel.h)

install(TARGETS cart_main
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
