cmake_minimum_required(VERSION 3.17)
project(eGLE)

set(CMAKE_CXX_STANDARD 14)

find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

#include_directories(/usr/local/include)
#link_directories(/usr/local/lib)

message(STATUS Set:${CMAKE_TOOLCHAIN_FILE})
message(STATUS ${CMAKE_SHARED_LIBRARY_PREFX}${PROJECT_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX})
message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
message(STATUS ${PROJECT_SOURCE_DIR})

file(GLOB INCLUDE_FILES
        "include/Bites/*.h"
        "include/Components/*.h"
        "include/Core/*.h"
        "include/IO/*.h"
        "include/Managers/*.h"
        )

file(GLOB SRC_FILES
        "src/Bites/*.cpp"
        "src/Components/*.cpp"
        "src/Core/*.cpp"
        "src/IO/*.cpp"
        "src/Managers/*.cpp"
        )

add_library(eGLE SHARED ${SRC_FILES})

target_link_libraries(eGLE
        glad::glad
        glm
        glfw
        )

message(STATUS Installing: ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_SHARED_LIBRARY_PREFX}
        ${PROJECT_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX})

# Copy lib to directory
#if(EXISTS ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}${PROJECT_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX})
#    file(COPY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}${PROJECT_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX}
#         DESTINATION ${PROJECT_SOURCE_DIR}/build)
#endif()

# Copy headers to directory
#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/include/
#        DESTINATION ${PROJECT_SOURCE_DIR}/build/include/eGLE/)

# Install
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_SHARED_LIBRARY_PREFX}${PROJECT_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX}
        DESTINATION ${PROJECT_SOURCE_DIR}/build)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION ${PROJECT_SOURCE_DIR}/build/include/eGLE/)

#thx to danielunderwood, hazel, vkramer