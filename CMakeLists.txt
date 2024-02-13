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
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /GR /std:c++17")
endif()
set(LINK_LIBS Qt6::Core Qt6::Widgets)
file(GLOB_RECURSE LIB_SOURCE_FILES src/*.cpp src/*.h)

add_library(EDJournalQT ${LIB_SOURCE_FILES})
include_directories(AFTER "src")
target_link_libraries(EDJournalQT ${LINK_LIBS})
