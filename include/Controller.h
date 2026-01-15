/**
 * @file Controller.h
 * @brief Main birdcam control loop.
 * @author tfilewic
 * @date 2025-12-18
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Camera.h"
#include "ImageSaver.h"
#include "Logger.h"
#include "MotionDetector.h"
#include "Uploader.h"


class Controller {

    public:
        Controller();
        void run();

    private:
        Camera camera;
        ImageSaver imageSaver;
        Logger logger;
        MotionDetector motionDetector;
        Uploader uploader;
};


#endif
