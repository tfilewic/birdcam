/**
 * @file Controller.cpp
 * 
 * @brief Motion sensor handler.
 * 
 * Manages the PIR sensor to detects motion events.
 * 
 * @author tfilewic
 * @date 2025-12-17
 */


#include "MotionDetector.h"
#include <unistd.h>

// TODO: implement stub
bool MotionDetector::waitForMotion() {
    sleep(5);
    return true;    
}