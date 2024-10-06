cmake_minimum_required(VERSION 3.29)
project(StoicOS)

set(CMAKE_CXX_STANDARD 14)

include_directories(root/modules)
include_directories(root/modules_root)

add_executable(StoicOS
    root/modules/example_module.cpp
    root/modules/example_module.h
    root/modules_root/module_loader.cpp
    root/modules_root/module_loader.h
    root/main.cpp)
