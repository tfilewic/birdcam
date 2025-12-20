/**
 * @file Uploader.h
 * @brief Uploads images and metadata to a remote server.
 * @author tfilewich
 * @version 2025-12-18
 */

#ifndef UPLOADER_H
#define UPLOADER_H

#include "DetectionEvent.h"


class Uploader {

    public:
        bool upload(const DetectionEvent &event);

};


#endif