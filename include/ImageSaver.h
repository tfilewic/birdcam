/**
 * @file ImageSaver.h
 * @brief Writes images to persistent storage.
 * @author tfilewich
 * @version 2025-12-08
 */

#ifndef IMAGESAVER_H
#define IMAGESAVER_H

#include <string>
#include "Frame.h"


class ImageSaver {
    public:
        std::string save(const Frame* frame, const std::string& timestamp);
};


#endif