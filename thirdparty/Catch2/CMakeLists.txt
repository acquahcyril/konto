cmake_minimum_required(VERSION 3.16)

# detect if Catch is being bundled,
# disable testsuite in that case
if(NOT DEFINED PROJECT_NAME)
  set(NOT_SUBPROJECT ON)
else()
  set(NOT_SUBPROJECT OFF)
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
include(CMakeDependentOption)

if(CMAKE_BINARY_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  message(FATAL_ERROR "Building in-source is not supported! Create a build dir and remove ${CMAKE_SOURCE_DIR}/CMakeCache.txt")
endif()

project(Catch2
  VERSION 3.11.0 # CML version placeholder, don't delete
  LANGUAGES CXX
  HOMEPAGE_URL "https://github.com/catchorg/Catch2"
  DESCRIPTION "A modern, C++-native, unit test framework."
)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake")

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(CatchConfigOptions)


if(CATCH_TEST_USE_WMAIN)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:wmainCRTStartup")
endif()

# Basic paths
set(CATCH_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SOURCES_DIR ${CATCH_DIR}/src/catch2)
set(SELF_TEST_DIR ${CATCH_DIR}/tests/SelfTest)

# We need to bring-in the variables defined there to this scope
add_subdirectory(src)

 
