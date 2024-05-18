cmake_minimum_required(VERSION 3.29)
project(gpu-algorithms)

include(FetchContent)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 20)

if (DEFINED ENV{BOOST_ROOT_DIR})
  set(BOOST_ROOT $ENV{BOOST_ROOT_DIR})
  set(BOOST_INCLUDE_DIRS "${BOOST_ROOT}")
  set(BOOST_LIBRARY_DIRS "${BOOST_ROOT}/stage/lib")
else()
  message(FATAL_ERROR "Please set the BOOST_ROOT_DIR environment variable to the path of your Boost installation.")
endif()

if(DEFINED ENV{OPENCL_SDK_DIR})
  set(OPENCL_SDK_DIR $ENV{OPENCL_SDK_DIR})
  find_path(OPENCL_INCLUDE_DIR NAMES CL/cl.h PATHS ${OPENCL_SDK_DIR}/include)
  find_library(OPENCL_LIBRARY NAMES OpenCL PATHS ${OPENCL_SDK_DIR}/lib/x64)
else()
  message(FATAL_ERROR "Please set the OPENCL_SDK_DIR environment variable to the path of your OpenCL SDK.")
endif()

include_directories(${OPENCL_INCLUDE_DIR})
include_directories(${BOOST_INCLUDE_DIRS})
include_directories(compute/include)
include_directories(includes)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

link_directories(${BOOST_LIBRARY_DIRS})

find_package(Boost REQUIRED)

add_executable(gpu-algorithms main.cpp ${SOURCES})

# Link Boost libraries
target_link_libraries(gpu-algorithms ${Boost_LIBRARIES} ${OPENCL_LIBRARY})