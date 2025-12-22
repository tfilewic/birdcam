/**
 * @file Frame.h
 * @brief Data structure representing a single captured camera frame.
 * @author tfilewic
 * @version 2025-12-19
 */

#ifndef FRAME_H
#define FRAME_H

#include <vector>
#include <cstddef>
#include <cstdint>


struct Frame {
    std::vector<uint8_t> data;  //NV12 pixel map
    size_t width;
    size_t height;
    size_t stride;
};


#endif

