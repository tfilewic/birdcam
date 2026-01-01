/**
 * @file MotionDetector.cpp
 * 
 * @brief Motion sensor handler.
 * 
 * Manages the PIR sensor to detects motion events.
 * 
 * @author tfilewic
 * @date 2025-12-31
 */


#include "MotionDetector.h"
#include "Utilities.h"
#include <gpiod.h>
#include <string>

const int GPIO_OFFSET = 17;  //physical pin 11 / offset 17

void MotionDetector::waitForMotion() {
    gpiod_chip* chip = gpiod_chip_open_by_name("gpiochip0");
    if (!chip) {
        logError("MotionDetector: failed to open gpiochip0");
        return;
    }

    gpiod_line* line = gpiod_chip_get_line(chip, GPIO_OFFSET);
    if (!line) {
        logError("MotionDetector:  GPIO " + std::to_string(GPIO_OFFSET) + " not available");
        return;
    }

    if (gpiod_line_request_rising_edge_events(line, "motion-detector") < 0) {
        logError("MotionDetector: failed to request rising edge events");
        gpiod_chip_close(chip);
        return;
    }

    gpiod_line_event event;
    int result = gpiod_line_event_read(line, &event);    //wait for event
    if (result < 0) {
        logError("MotionDetector: failed to read GPIO event");
        gpiod_chip_close(chip);
        return;
    }

    gpiod_chip_close(chip);
}


/* stub

#include <unistd.h>

void MotionDetector::waitForMotion() {
    sleep(5);
    return;    
}
*/