/**
 * @file Controller.cpp
 * 
 * @brief Main birdcam control loop.
 * 
 * Coordinates Camera, MotionDetector, Logger, and Uploader.
 * Waits for motion events, triggers captures, saves images, and logs each event.
 * 
 * @author tfilewic
 * @date 2026-12-17
 */

 
#include "Camera.h"
#include "Controller.h"
#include "DetectionEvent.h"
#include "Logger.h"
#include "MotionDetector.h"
#include "Uploader.h"
#include "Utilities.h"
#include <ctime>
#include <iostream>
#include <string>
#include <unistd.h> 



const int COOLDOWN = 10;



Controller::Controller()
    : camera(),
      logger(),
      motionDetector(),
      uploader()
{
}

void Controller::run() {



    //TODO log this with ts
    std::cout << "====== birdcam started ====== \n";

    while (true) {

        if (motionDetector.waitForMotion()) {
            std::string timestamp = getTimestamp();
            // std::string path = camera.capture(timestamp);
            // DetectionEvent event{timestamp, path};
            // logger.logDetection(event);

            std::vector<std::string> paths = camera.burst(timestamp, 3);
            
            //uploader.upload(event);
        }
        sleep(COOLDOWN);
    }

}