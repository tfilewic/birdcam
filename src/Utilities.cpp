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

void logError(const std::string &message) {
    std::ofstream errorLog("error.log", std::ios::app);
    if (!errorLog) return;
    errorLog << message << "\n";
}
