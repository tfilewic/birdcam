/**
 * @file Camera.h
 * @brief Camera interface.
 * @author tfilewic
 * @version 2025-12-09
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "Frame.h"

class Camera {

    public:
        Frame capture();
        
};


#endif