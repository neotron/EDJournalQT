cmake_minimum_required(VERSION 3.5)
project(EDJournalQT)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /GR /std:c++latest")
endif()
set(LINK_LIBS Qt5::Core Qt5::Widgets)
file(GLOB_RECURSE LIB_SOURCE_FILES src/*.cpp src/*.h)

header_directories(INCLUDE_DIRS src/ "${PROJECT_SOURCE_DIR}")

add_library(EDJournalQT ${LIB_SOURCE_FILES})
include_directories(AFTER ${INCLUDE_DIRS})
target_link_libraries(EDJournalQT ${LINK_LIBS})
file(GLOB APP_SOURCE_FILES test/*.cpp test/*.h test/*.ui)

add_executable(TestApp ${APP_SOURCE_FILES})
target_link_libraries(TestApp EDJournalQT Qt5::Widgets)
target_include_directories(TestApp PUBLIC src)

