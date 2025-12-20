/**
 * @file ImageSaver.cpp
 * @brief Writes images to persistent storage.
 *
 * Generates filenames and saves image files.
 * Keeps all filesystem details isolated from Controller.
 *
 * @author tfilewich
 * @version 2025-12-19
 */


#include "ImageSaver.h"
#include "Utilities.h"
#include <fstream>


std::string ImageSaver::save(const Frame* frame, const std::string& timestamp) {
    std::string path = timestamp + ".nv12";

    if (!frame) {
        logError("Failed to save " + path + " - Image save failed: null frame");
    return "";
    }

    if (frame->data.empty()) {
        logError("Failed to save " + path + " - Image save failed: empty frame data");
        return "";
    }

    std::ofstream out(path, std::ios::binary);
    if (!out.is_open()) {
        logError("Failed to save " + path + " - Image save failed: could not open output file");
        return "";
    }

    out.write(reinterpret_cast<const char*>(frame->data.data()),
            static_cast<std::streamsize>(frame->data.size()));

    if (!out.good()) {
        logError("Failed to save " + path + " - Image save failed: write failed");
        return "";
    }

    return path;
}
