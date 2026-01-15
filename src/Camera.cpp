/**
 * @file Camera.cpp
 * @brief Camera interface.
 *
 * Wraps low-level camera access.
 *
 * @author tfilewich
 * @version 2025-12-09
 */


#include "Camera.h"
#include <iostream>

// TODO: implement stub
Frame Camera::capture() {
    static uint8_t pixel[3] = {255, 100, 200};

    Frame frame{};
    frame.data.assign(pixel, pixel + 3);
    frame.width = 1;
    frame.height = 1;
    frame.stride = 3;
    //frame.format = PixelFormat::RGB24;

    return frame;
}
