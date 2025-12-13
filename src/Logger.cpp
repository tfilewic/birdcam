/**
 * @file Logger.cpp
 * @brief Logs detection events and system activity.
 *
 * Appends timestamped event records to a CSV log file.
 *
 * @author tfilewich
 * @version 2025-12-12
 */


#include "Logger.h"
#include <fstream>
#include <string>

Logger::Logger() : headerWritten(false) { 
}

static void logError(const std::string &message) {
    std::ofstream errorLog("error.log", std::ios::app);
    if (!errorLog) return;
    errorLog << message << "\n";
}

void Logger::writeHeader() {
    std::ofstream file(CSV_FILE, std::ios::app);
    if (!file) {
        logError("Failed to open " + std::string(CSV_FILE));
        return;
    }

    file << CSV_HEADER << "\n";
    headerWritten = true;
}

void Logger::logEvent(const DetectionEvent &event) {
    if (!headerWritten) {
        writeHeader();
    }

    std::ofstream file(CSV_FILE, std::ios::app);
    if (!file) {
        logError("Failed to open " + std::string(CSV_FILE));
        return;
    }

    file << event.timestamp;
    file << ",";
    file << event.imagePath;
    file << "\n";
}


