# Purpose
The code examples in this repository demonstrates different ways of omptimizing mathematical algorithms. 
This was done as part of a project to demonstrate the advantages of parallelism, both by using CPU multithreading and by running the algorithms on a GPU. 
# Prerequisites
- gcc
- CMake
- Boost
- Boost.Compute
- An OpenCL SDK for your GPU (for example CUDA for Nvidia)
# Setup
1. Clone the repo to a directory of your choosing
2. Go into the root directory, and clone Boost.Compute here
3. Set the following environment variables:
    - OPENCL_SDK_DIR: The directory of your OpenCL SDK installation
    - BOOST_ROOT_DIR: The directory of your Boost installation
4. It should now be possible to build and run the project with CMake
