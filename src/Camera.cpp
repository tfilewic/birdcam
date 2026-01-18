/**
 * @file Camera.cpp
 * @brief Camera interface.
 *
 * Wraps low-level camera access.
 *
 * @author tfilewich
 * @version 2026-12-18
 */


#include "Camera.h"
#include <iostream>



std::string Camera::capture(const std::string& timestamp) {
//TODO: replace std::system() with a fork and execvp() to avoid injection. 
//Currently safe because args are generated internally.
    std::string path = timestamp + ".jpg";

    std::string cmd = "rpicam-still --nopreview -o " + path;

    int status = std::system(cmd.c_str());
    if (status != 0) {
        logError("Camera: rpicam-still failed");
        return "";
    }

    return path;
}
