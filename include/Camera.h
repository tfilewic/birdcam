/**
 * @file Camera.h
 * @brief Camera interface.
 * @author tfilewich
 * @version 2026-01-18
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "Frame.h"

class Camera {

    public:
        std::string capture(const std::string& timestamp);

}

#endif