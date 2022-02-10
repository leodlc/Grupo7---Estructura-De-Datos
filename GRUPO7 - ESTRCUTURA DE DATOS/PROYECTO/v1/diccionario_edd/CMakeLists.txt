cmake_minimum_required(VERSION 3.0.0)
project(diccionario_edd VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/menu.h
    ${PROJECT_SOURCE_DIR}/menu_option.h
    ${PROJECT_SOURCE_DIR}/console.h
    ${PROJECT_SOURCE_DIR}/md5.h
    ${PROJECT_SOURCE_DIR}/auth.h
    ${PROJECT_SOURCE_DIR}/marquee.h
    ${PROJECT_SOURCE_DIR}/application.h

    ${PROJECT_SOURCE_DIR}/menu.cpp
    ${PROJECT_SOURCE_DIR}/menu_option.cpp
    ${PROJECT_SOURCE_DIR}/console.cpp
    ${PROJECT_SOURCE_DIR}/md5.cpp
    ${PROJECT_SOURCE_DIR}/marquee.cpp
    ${PROJECT_SOURCE_DIR}/application.cpp

    ${PROJECT_SOURCE_DIR}/main.cpp
)

add_executable(diccionario_edd ${PROJECT_SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)