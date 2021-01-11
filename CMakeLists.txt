cmake_minimum_required(VERSION 3.17)
project(eGLE)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)

#include_directories(/usr/local/include)
#link_directories(/usr/local/lib)

message(STATUS ${CMAKE_SHARED_LIBRARY_PREFX}${PROJECT_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX})
message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
message(STATUS ${PROJECT_SOURCE_DIR})

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

message(STATUS Installing: ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_SHARED_LIBRARY_PREFX}
        ${PROJECT_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX})

# Copy lib to directory
file(COPY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}${PROJECT_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX}
     DESTINATION ${PROJECT_SOURCE_DIR}/build)

# Copy headers to directory
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/include
        DESTINATION ${PROJECT_SOURCE_DIR}/build)

# Install
#install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#        DESTINATION ${PROJECT_SOURCE_DIR}/build
#        FILES_MATCHING PATTERN ${CMAKE_SHARED_LIBRARY_PREFX}${PROJECT_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX})

#install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
#        DESTINATION ${PROJECT_SOURCE_DIR}/include/eGLE/)