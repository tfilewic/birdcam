/**
 * @file Logger.h
 * @brief Logs detection events and system activity.
 * @author tfilewich
 * @version 2025-12-12
 */

#ifndef LOGGER_H
#define LOGGER_H

#include "DetectionEvent.h"


class Logger {

    public:
        Logger();
        void logEvent(const DetectionEvent &event);

    private:
        static constexpr const char* CSV_FILE = "detections.csv";
        static constexpr const char* CSV_HEADER = "timestamp,path";
        bool headerWritten;
        void writeHeader();
};


#endif