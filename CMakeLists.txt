cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

find_package( OpenCV REQUIRED )

add_executable(image_processing main.cpp ImageProcessor.cpp HelpCommandProcessor.cpp LoadCommandProcessor.cpp StoreCommandProcessor.cpp BlurCommandProcessor.cpp ResizeCommandProcessor.cpp)
target_link_libraries(image_processing ${OpenCV_LIBS})
