/**
 * @file Logger.cpp
 * @brief Logs detection events
 *
 * Appends timestamped event records to a CSV log file.
 *
 * @author tfilewic
 * @version 2025-12-12
 */


#include "Logger.h"
#include "Utilities.h"
#include <filesystem>
#include <fstream>
#include <string>


void Logger::writeHeader() {
    std::ofstream file(CSV_FILE, std::ios::app);
    if (!file) {
        logError("Failed to open " + std::string(CSV_FILE));
        return;
    }

    file << CSV_HEADER << "\n";
}

void Logger::logDetection(const DetectionEvent &event) {
    const bool fileExists = std::filesystem::exists(CSV_FILE);
    if (!fileExists) {
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


