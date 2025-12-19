/**
 * @file Frame.h
 * @brief Data structure representing a single captured camera frame.
 * @author tfilewic
 * @version 2025-12-18
 */

#ifndef FRAME_H
#define FRAME_H

#include <vector>
#include <cstdint>


enum class PixelFormat {
    YUYV,
    YUV420,
    RGB24,
    BGR24
};

struct Frame {
    ustd::vector<uint8_t> data;
    uint32_t width;
    uint32_t height;
    uint32_t stride;
    PixelFormat format;
};


#endif

