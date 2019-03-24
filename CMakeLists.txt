cmake_minimum_required(VERSION 2.4)

project(foo)

add_executable(foo foo.cpp)

# steps to run CMake
# mkdir build && cd build (if build dir doesn't exist yet. Separating build artifacts from source code is always better)
# cmake ..
# cmake --build .