cmake_minimum_required(VERSION 3.5)
project(glad)

add_library(glad glad.c glad/glad.h KHR/khrplatform.h)
target_include_directories(glad PUBLIC ./)
