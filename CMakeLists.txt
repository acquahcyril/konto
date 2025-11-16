cmake_minimum_required(VERSION 3.20)

set(PROJECT "konto")
project(${PROJECT} VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE
        "Debug"
        CACHE
        STRING
        "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
        FORCE)
endif()

set(GLFW_INSTALL OFF)
set(GLFW_BUILD_DOCS OFF)

add_subdirectory(thirdparty/glfw)
add_subdirectory(thirdparty/glad)

add_executable(${PROJECT}
  src/main.cpp
)
target_link_libraries(${PROJECT} glad glfw)
