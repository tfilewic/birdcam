/**
 * @file Uploader.cpp
 * @brief Uploads images and metadata to a remote server.
 *
 * Handles network communication, retries, and errors.
 *
 * @author tfilewich
 * @version 2025-12-18
 */


//#include <curl/curl.h>
#include <iostream>
#include "Uploader.h"
#include "DetectionEvent.h"



// TODO: implement stub
    //build request
    //enqueue
bool Uploader::upload(const DetectionEvent& event) {
    
    std::cout << "Uploading event: " << event.timestamp << "\n";
    for (const auto& path : event.paths) {
        std::cout << "  " << path << "\n";
    }

    return true; 
}
