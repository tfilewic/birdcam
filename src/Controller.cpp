/**
 * @file Controller.cpp
 * 
 * @brief Main birdcam control loop.
 * 
 * Coordinates Camera, MotionDetector, ImageSaver, Logger, and Uploader.
 * Waits for motion events, triggers captures, saves images, and logs each event.
 * 
 * @author tfilewic
 * @date 2025-12-17
 */

 
#include "Camera.h"
#include "Controller.h"
#include "DetectionEvent.h"
#include "Frame.h"
#include "ImageSaver.h"
#include "Logger.h"
#include "MotionDetector.h"
#include "Uploader.h"
#include <ctime>
#include <string>
#include <unistd.h> 


const int COOLDOWN = 3;

/**
 * @brief Returns current local timestamp
 */
static std::string getTimestamp() {
    std::time_t now = std::time(nullptr);   //current POSIX system time

    char buffer[20];
    std::tm tm{};
    localtime_r(&now, &tm); //convert to local time and write to tm struct

    std::strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H-%M-%S", &tm);    //format
    return std::string(buffer);
}


Controller::Controller()
    : camera(),
      imageSaver(),
      logger(),
      motionDetector(),
      uploader()
{
}

void Controller::run() {

    while (true) {
        if (motionDetector.waitForMotion()) {
            Frame frame = camera.capture();
            std::string timestamp = getTimestamp();
            std::string path = imageSaver.save(&frame, timestamp);
            DetectionEvent event{timestamp, path};
            logger.logEvent(event);
            uploader.upload(event);
        }
        sleep(COOLDOWN);
    }

}