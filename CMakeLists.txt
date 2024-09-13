cmake_minimum_required(VERSION 3.14)
project(dnd-sound-master
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(
  Qt5
  COMPONENTS Core Gui Widgets Multimedia
  REQUIRED)

message(STATUS "Qt version: ${Qt5Core_VERSION}")

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build_cmake)
# Compile command export for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(COMPILE_COMMANDS_OUTPUT_DIR ${CMAKE_SOURCE_DIR})


set(SOURCES
    main.cpp
    src/MainWindow.cpp
    src/TrackWidget.cpp
)

set(HEADERS
    src/MainWindow.h
    src/TrackWidget.h
)

set(RESOURCES res/res.qrc)

set(ALL_SOURCES ${SOURCES} ${HEADERS} ${RESOURCES})

add_executable(dnd-sound-master ${ALL_SOURCES})

target_include_directories(dnd-sound-master PRIVATE src ${Qt5Multimedia_INCLUDE_DIRS})

target_link_libraries(dnd-sound-master Qt5::Widgets Qt5::Multimedia)

add_custom_target(
  copy_compile_commands ALL
  COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${COMPILE_COMMANDS_OUTPUT_DIR}/compile_commands.json
  DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json
  COMMENT "Coping compile_commands.json")
