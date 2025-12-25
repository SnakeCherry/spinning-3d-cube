cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

project(CUBE)
set(EXECUTABLE_NAME ${PROJECT_NAME})

#https://cmake.org/cmake/help/latest/prop_tgt/LINK_WARNING_AS_ERROR.html
set(CMAKE_COMPILE_WARNING_AS_ERROR True)

target_include_directories(${EXECUTABLE_NAME} PRIVATE
    ${CMAKE_SOURCE_DIRS}/include
)

add_subdirectory(src)

### SET OUTPUT DIRECTORY ###
# out/build/bin -> binary
set_target_properties(${EXECUTABLE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

