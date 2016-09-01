cmake_minimum_required(VERSION 3.6)
project(LibrarySelectionTool)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# include wxWidgets package
find_package(wxWidgets REQUIRED core base)
include(${wxWidgets_USE_FILE})

find_package(Boost REQUIRED filesystem system)
include_directories(${Boost_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp MyFrame.cpp MyFrame.h MyListSwapWidget.cpp MyListSwapWidget.h file_info.cpp file_info.h)
add_executable(LibrarySelectionTool ${SOURCE_FILES})

target_link_libraries(LibrarySelectionTool ${wxWidgets_LIBRARIES} ${Boost_LIBRARIES})