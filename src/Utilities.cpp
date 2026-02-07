/**
 * @file Utilities.cpp
 * @brief Utility helpers.
 *
 * Utility helpers.
 *
 * @author tfilewic
 * @version 2025-12-19
 */


#include "Utilities.h"
#include <fstream>
#include <ctime>


void logError(const std::string &message) {
    std::ofstream errorLog("error.log", std::ios::app);
    if (!errorLog) return;
    errorLog << message << "\n";
}


/**
 * @brief Returns current local timestamp
 */
std::string getTimestamp() {
    time_t now = time(nullptr);   //current POSIX system time

    char buffer[20];
    tm tm{};
    localtime_r(&now, &tm); //convert to local time and write to tm struct

    std::strftime(buffer, sizeof(buffer), "%Y%m%dT%H%M%S", &tm);    //format
    return std::string(buffer);
}



#include <iostream>
#include <thread>
#include <chrono>

void fakeLoadingBar(int steps = 20, int delay_ms = 100) {
    std::cout << "[";
    for (int i = 0; i < steps; i++) {
        std::cout << "#" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
    std::cout << "]\n";
}