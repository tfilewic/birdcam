/**
 * @file Uploader.cpp
 * @brief Uploads images and metadata to a remote server.
 *
 * Handles network communication, retries, and errors.
 *
 * @author tfilewich
 * @version 2025-12-18
 */


#include <iostream>
#include "Uploader.h"
#include "DetectionEvent.h"


// TODO: implement stub
bool Uploader::upload(const DetectionEvent& event) {
    std::cout << "Uploaded: " << event.timestamp << " " << event.imagePath << "\n"; 
    return true; 
}
