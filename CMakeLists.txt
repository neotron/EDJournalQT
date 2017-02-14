cmake_minimum_required(VERSION 3.5)
project(EDJournalQT)
include(cmake/lib.cmake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

EDJournalLibrary()

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
file(GLOB APP_SOURCE_FILES test/*.cpp test/*.h test/*.ui)

add_executable(TestApp ${APP_SOURCE_FILES})
target_link_libraries(TestApp EDJournalQT Qt5::Widgets)
target_include_directories(TestApp PUBLIC src)

