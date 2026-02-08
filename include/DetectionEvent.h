/**
 * @file DetectionEvent.h
 * @brief Data structure representing a single detection event.
 * @author tfilewic
 * @version 2026-02-07
 */

#ifndef DETECTIONEVENT_H
#define DETECTIONEVENT_H

#include <string>
#include <vector>


struct DetectionEvent {
    std::string timestamp;
    std::vector<std::string> paths;
};


#endif