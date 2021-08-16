cmake_minimum_required(VERSION 3.17)
project(eGame)

set(CMAKE_CXX_STANDARD 14)
message(STATUS ${CMAKE_TOOLCHAIN_FILE})

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

include_directories("../eGLE/build/include")
link_directories("../eGLE/build")

file(GLOB INCLUDE_FILES
        "include/*.h"
        )

file(GLOB SRC_FILES
        "src/*.cpp"
        )

add_executable(eGame ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} eGLE glm glad::glad)