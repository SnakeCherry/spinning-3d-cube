cmake_policy(SET CMP0079 NEW)

set (SRC_FILES
    Vector.cpp
    Quaternion.cpp
    Cube.cpp
)

set(LIBRARY_NAME cube_lib)
add_library(${LIBRARY_NAME} STATIC ${SRC_FILES})

target_include_directories(${LIBRARY_NAME} PUBLIC
    ${CMAKE_SOURCE_DIRS}/include
)
