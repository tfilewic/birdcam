cmake_minimum_required(VERSION 3.23)
project(birdcam)
set(CMAKE_CXX_STANDARD 17)


add_executable(
    birdcam 
    src/main.cpp
    src/Camera.cpp
    src/Controller.cpp
    src/ImageSaver.cpp
    src/Logger.cpp
    src/MotionDetector.cpp
    src/Uploader.cpp
    src/Utilities.cpp
)
target_include_directories(
    birdcam PRIVATE include
)
target_link_libraries(
    birdcam PRIVATE gpiod
)


add_executable(
    logger_smoke
    test/smoke/logger_smoke.cpp
    src/Logger.cpp
    src/Utilities.cpp
)
target_include_directories(
    logger_smoke PRIVATE include
)


add_executable(
    image_saver_smoke
    test/smoke/image_saver_smoke.cpp
    src/ImageSaver.cpp
    src/Utilities.cpp
)
target_include_directories(
    image_saver_smoke PRIVATE include
)


add_executable(
    motion_detector_smoke
    test/manual/motion_detector_smoke.cpp
    src/MotionDetector.cpp
    src/Utilities.cpp
)
target_include_directories(
    motion_detector_smoke PRIVATE include
)
target_link_libraries(
    motion_detector_smoke PRIVATE gpiod
)