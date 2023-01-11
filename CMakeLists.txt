cmake_minimum_required(VERSION 3.24)
project(RayTracerCH)

set(CMAKE_CXX_STANDARD 20)

add_executable(RayTracerCH tests/tupleTest.cpp tests/doctestMain.cpp include/Tuple.h src/Tuple.cpp include/Tick.h src/Canvas.cpp include/Canvas.h tests/canvasTest.cpp)
