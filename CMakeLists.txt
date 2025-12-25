cmake_minimum_required(VERSION 3.10)

project(CUBE LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Create executable
add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

add_subdirectory(src)
target_link_libraries(${PROJECT_NAME} PUBLIC 
    cube_lib
)

#https://cmake.org/cmake/help/latest/prop_tgt/LINK_WARNING_AS_ERROR.html
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

### SET OUTPUT DIRECTORY ###
# out/build/bin -> binary
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

