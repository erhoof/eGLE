cmake_minimum_required(VERSION 3.17)
project(eGLE)

set(CMAKE_CXX_STANDARD 14)

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

add_library(eGLE SHARED ${INCLUDE_FILES} ${SRC_FILES})

# Copy lib to directory
file(COPY ${CMAKE_CURRENT_BINARY_DIR}/build
       DESTINATION ${PROJECT_SOURCE_DIR})