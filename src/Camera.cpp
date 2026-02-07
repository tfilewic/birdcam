/**
 * @file Camera.cpp
 * @brief Camera interface.
 *
 * Wraps low-level camera access.
 *
 * @author tfilewich
 * @version 2026-01-18
 */


#include "Camera.h"
#include "Utilities.h"
#include <iostream>
#include <time.h>

std::string Camera::capture(const std::string& timestamp) {
//TODO: replace std::system() with a fork and execvp() to avoid injection. 
//Currently safe because args are generated internally.
    std::string path = "/home/birdcam/images/" + timestamp + ".jpg";

    std::string cmd = "rpicam-still --nopreview -o " + path;

    int status = std::system(cmd.c_str());
    if (status != 0) {
        logError("Camera: rpicam-still failed");
        return "";
    }

    return path;
}


std::vector<std::string> Camera::burst(const std::string& timestamp, const int count) {
//TODO: replace std::system() with a fork and execvp() to avoid injection. 
//Currently safe because args are generated internally.
    std::vector<std::string> paths;
    paths.reserve(count); 

    for (int i = 1; i <= count; i++) {

        std::string path = "/home/birdcam/images/" + timestamp + "-" + std::to_string(i) + ".jpg";

        std::string cmd = "rpicam-still --nopreview -o " + path;

        int status = std::system(cmd.c_str());
        if (status != 0) {
            logError("Camera: rpicam-still failed");
            return paths;
        }

        //TODO log this
        std::cout << "CAMERA: " + path + " captured\n";

        paths.push_back(path);
    }

    return paths;
}