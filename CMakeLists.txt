cmake_minimum_required(VERSION 3.5)
project(EDJournalQT)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(LINK_LIBS Qt5::Core )

file(GLOB LIB_SOURCE_FILES src/*.cpp src/*.h src/*.ui)

add_library(EDJournalQT ${LIB_SOURCE_FILES})
target_link_libraries(EDJournalQT ${LINK_LIBS})
file(GLOB APP_SOURCE_FILES test/*.cpp test/*.h test/*.ui)

add_executable(TestApp ${APP_SOURCE_FILES})
target_link_libraries(TestApp EDJournalQT Qt5::Widgets)
target_include_directories(TestApp PUBLIC src)

