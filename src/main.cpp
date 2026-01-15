/**
 * @file main.cpp
 * 
 * @brief Contains main function
 * 
 * 
 * @author tfilewic
 * @date 2026-01-14
 */

#include <iostream>
#include "Controller.h"


/**
 * @brief Main function.
 */
int main() {
    std::cout << "birdcam: initialized";
    Controller controller;
    controller.run();
    return 0;
}
