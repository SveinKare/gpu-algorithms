cmake_minimum_required(VERSION 3.29)
project(gpu-algorithms)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 20)

set(BOOST_ROOT "C:/Users/svein/boost_1_85_0")
set(BOOST_INCLUDE_DIRS "${BOOST_ROOT}")
set(BOOST_LIBRARY_DIRS "${BOOST_ROOT}/stage/lib")

set(CUDA_ROOT "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.4")
set(CUDA_INCLUDE_DIRS "${CUDA_ROOT}/include")
set(CUDA_LIBRARY_DIRS "${CUDA_ROOT}/lib/x64")

# Include Boost headers
include_directories(${BOOST_INCLUDE_DIRS})

include_directories(compute/include)

include_directories(${CUDA_INCLUDE_DIRS})

link_directories(${BOOST_LIBRARY_DIRS})

find_package(Boost REQUIRED)

find_library(OpenCL_LIBRARIES OpenCL HINTS ${CUDA_LIBRARY_DIRS})

add_executable(gpu-algorithms main.cpp)

# Link Boost libraries
target_link_libraries(gpu-algorithms ${Boost_LIBRARIES} ${OpenCL_LIBRARIES})