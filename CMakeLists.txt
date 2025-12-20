cmake_minimum_required(VERSION 3.23)
project(birdcam)
set(CMAKE_CXX_STANDARD 17)
#add_executable(birdcam src/controller.cpp)


add_executable(
    logger_smoke
    test/smoke/logger_smoke.cpp
    src/Logger.cpp
    src/Utilities.cpp
)

target_include_directories(
    logger_smoke PRIVATE include

)
