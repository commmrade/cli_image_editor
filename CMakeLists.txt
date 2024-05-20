cmake_minimum_required(VERSION 3.5.0)
project(proj VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()
set (CMAKE_CXX_STANDARD 20)



add_executable(proj main.cpp image.cpp)


find_package (OpenCV 4.0.0 REQUIRED)
target_link_libraries(proj opencv_core)
target_link_libraries(proj opencv_imgproc)
target_link_libraries(proj opencv_highgui)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
