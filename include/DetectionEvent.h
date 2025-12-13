/**
 * @file DetectionEvent.h
 * @brief Data structure representing a single detection event.
 * @author tfilewich
 * @version 2025-12-12
 */

#ifndef DETECTIONEVENT_H
#define DETECTIONEVENT_H

#include <string>


struct DetectionEvent {
    std::string timestamp;
    std::string imagePath;  
};


#endif