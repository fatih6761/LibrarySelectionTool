cmake_minimum_required(VERSION 3.6)
project(LibrarySelectionTool)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# include wxWidgets package
set(wxWidgets_USE_STATIC_LIB ON)
find_package(wxWidgets REQUIRED core base)
include(${wxWidgets_USE_FILE})

# include Boost package
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost REQUIRED filesystem system)
include_directories(${Boost_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp FileSelectionFrame.cpp FileSelectionFrame.h MyListSwapWidget.cpp MyListSwapWidget.h file_info.cpp file_info.h ListFileHelper.cpp ListFileHelper.h ToolSelectionDialog.cpp ToolSelectionDialog.h DuplicateDetectionFrame.cpp DuplicateDetectionFrame.h)
add_executable(LibrarySelectionTool ${SOURCE_FILES})

target_link_libraries(LibrarySelectionTool ${wxWidgets_LIBRARIES} ${Boost_LIBRARIES})