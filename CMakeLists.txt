cmake_minimum_required(VERSION 3.10)
project(SystemTelemetry)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(common)
add_subdirectory(producer)
add_subdirectory(consumer)