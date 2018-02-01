cmake_minimum_required(VERSION 3.7)
set(PROJECT Codex)
project(${PROJECT})
message("Start building project ${Codex}")

set(EXECUTABLE ${PROJECT})
set(SOURCE_ROOT ./src)
set(FILES_DIR ${CMAKE_BINARY_DIR})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

aux_source_directory(${SOURCE_ROOT} SOURCES)
aux_source_directory(${SOURCE_ROOT}/classes SUB_SOURCES)

set(SOURCES ${SOURCES} ${SUB_SOURCES})

file (GLOB HEADERS "${SOURCE_ROOT}/headers/*.h*")

source_group(Classes FILES ${SUB_SOURCES})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${EXECUTABLE} ${SOURCES} ${HEADERS})

include_directories(${SOURCE_ROOT}/headers)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/sandmark.umz
    ${CMAKE_CURRENT_BINARY_DIR}/sandmark.umz COPYONLY)
