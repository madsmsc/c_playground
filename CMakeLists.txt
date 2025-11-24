cmake_minimum_required(VERSION 4.1.2)

SET(PROJECTNAME c_playground)
project(${PROJECTNAME} C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)
set(CMAKE_VERBOSE_MAKEFILE ON)

ENABLE_LANGUAGE(C)
set(CMAKE_EXECUTABLE_SUFFIX_C ".out")

SET(CMAKE_C_FLAGS "-O0 -g -ffunction-sections -fdata-sections -Wall -std=c99")

SET(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections")

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME}
               ${CMAKE_SOURCE_DIR}/src/main.c
               ${CMAKE_SOURCE_DIR}/src/book.c
               ${CMAKE_SOURCE_DIR}/src/list.c
               ${CMAKE_SOURCE_DIR}/src/mem.c
               ${CMAKE_SOURCE_DIR}/src/string.c
              )
