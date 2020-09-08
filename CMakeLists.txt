cmake_minimum_required(VERSION 3.10)

project(global-destruction-demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

# add_library(shared-lib STATIC
#    lib.hpp
#    lib.cpp
# )
add_library(shared-lib SHARED
   lib.hpp
   lib.cpp
)
target_compile_definitions(shared-lib PUBLIC -DLIB_SHARED=1)
target_link_libraries(shared-lib PUBLIC ${CMAKE_THREAD_LIBS_INIT})

add_executable(executable exe.cpp)

target_link_libraries(executable PRIVATE shared-lib)
