cmake_minimum_required(VERSION 4.1)
set(EXECUTABLE_NAME "EXE_NAME")
set(PROJECTNAME "PROJECT_NAME")

Project("${PROJECTNAME}")
find_package(SDL3 REQUIRED)

add_executable("${EXECUTABLE_NAME}" src/main.cpp def/functions.cpp src/processes.cpp)

target_include_directories(
  "${EXECUTABLE_NAME}"
  PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/headers/"
)

target_link_libraries("${EXECUTABLE_NAME}" SDL3)
