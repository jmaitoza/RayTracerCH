# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.

cmake_minimum_required(VERSION 3.24)
project(RayTracerCH)

set(CMAKE_CXX_STANDARD 20)


# Add tasks subprojects
include(cmake/utils.cmake)
add_subprojects(${CMAKE_SOURCE_DIR})