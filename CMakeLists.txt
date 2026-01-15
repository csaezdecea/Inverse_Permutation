cmake_minimum_required(VERSION 3.10)
project(CompleteExample)

set(CMAKE_CXX_STANDARD 17)

# Library A
add_library(heap src/heap.cpp)
target_include_directories(heap PUBLIC include)

# Library B (depends on A)
add_library(InversePerm src/InversePerm.cpp)
target_include_directories(InversePerm PUBLIC include)
target_link_libraries(InversePerm PUBLIC heap)

# Executable using only A
add_executable(InverseON2 apps/InverseON2.cpp)
target_link_libraries(InverseON2 InversePerm)

# Executable using B (and transitively A)
add_executable(InverseMK apps/InverseMK.cpp)
target_link_libraries(InverseMK InversePerm)

# Executable using B (and transitively A)
add_executable(Test apps/Test.cpp)
target_link_libraries(Test InversePerm)