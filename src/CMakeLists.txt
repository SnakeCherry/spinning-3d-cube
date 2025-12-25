set (SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Quaternion.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Cube.cpp
)

set(LIBRARY_NAME cube_lib)
add_library(${LIBRARY_NAME} STATIC ${SRC_FILES})

target_include_directories(${LIBRARY_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
