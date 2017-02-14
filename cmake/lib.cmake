
macro(EDJournalLibrary)
find_package(Qt5Core REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(LINK_LIBS Qt5::Core )
file(GLOB LIB_SOURCE_FILES src/*.cpp src/*.h src/*.ui)
add_library(EDJournalQT ${LIB_SOURCE_FILES})
target_link_libraries(EDJournalQT ${LINK_LIBS})
endmacro()
