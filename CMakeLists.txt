cmake_minimum_required(VERSION 3.17)
project(eGLE)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

message(STATUS ${glfw3_INCLUDE_DIR})

file(GLOB INCLUDE_FILES
        "include/Bites/*.h"
        "include/Core/*.h"
        "include/IO/*.h"
        "include/Managers/*.h"
        )

file(GLOB SRC_FILES
        "src/Bites/*.cpp"
        "src/Core/*.cpp"
        "src/IO/*.cpp"
        "src/Managers/*.cpp"
        )

add_library(eGLE SHARED ${SRC_FILES})

target_link_libraries(eGLE
        ${OPENGL_LIBRARIES}
        ${glm_LIBRARY}
        ${glew_LIBRARY}
        ${glfw3_LIBRARY}
        )

# Copy lib to directory
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/build
        DESTINATION ${PROJECT_SOURCE_DIR})

# Copy headers
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION ${PROJECT_SOURCE_DIR}/build/include/eGLE/)