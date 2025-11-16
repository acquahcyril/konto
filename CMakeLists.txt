cmake_minimum_required(VERSION 3.20)

set(PROJECT "konto")
project(${PROJECT} VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(ENABLE_TESTING "Build test programs" OFF)

add_subdirectory(thirdparty/glm)
add_subdirectory(thirdparty/glfw)
add_subdirectory(thirdparty/glad)

add_executable(${PROJECT}
  src/main.cpp
  src/renderer/shader.cpp
  src/renderer/texture.cpp
  src/renderer/renderer.cpp
)
target_link_libraries(${PROJECT} glm glad glfw)
target_include_directories(${PROJECT} PRIVATE src thirdparty/stb)

if(ENABLE_TESTING)
  enable_testing()
  set(TEST_MAIN "main_test")
  add_subdirectory(thirdparty/Catch2)
  add_executable(${TEST_MAIN} tests/main_test.cpp)
  target_link_libraries(${TEST_MAIN} PUBLIC glm Catch2::Catch2WithMain)
  target_include_directories(${TEST_MAIN} PRIVATE src tests)
  add_test(NAME ${TEST_MAIN} COMMAND ${TEST_MAIN})
endif()

