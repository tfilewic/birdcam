/**
 * @file MotionDetector.cpp
 * 
 * @brief Motion sensor handler.
 * 
 * Manages the PIR sensor to detects motion events.
 * 
 * @author tfilewic
 * @date 2026-01-16
 */

#include "MotionDetector.h"
#include "Utilities.h"
#include <cstddef>
#include <gpiod.h>
#include <string>

const unsigned int OFFSETS[] = { 17 }; //sensor at BCM 17
const size_t SENSOR_COUNT = sizeof(OFFSETS) / sizeof(OFFSETS[0]);

bool MotionDetector::waitForMotion() {

    //open chip
    gpiod_chip* chip = gpiod_chip_open("/dev/gpiochip0");
    if (!chip) {
        logError("MotionDetector: failed to open /dev/gpiochip0");
        return false;
    }

    //create line settings
    gpiod_line_settings* settings = gpiod_line_settings_new();
    if (!settings) {
        logError("MotionDetector: failed to allocate line settings");
        gpiod_chip_close(chip);
        return false;
    }
    gpiod_line_settings_set_direction(settings, GPIOD_LINE_DIRECTION_INPUT);    //input line
    gpiod_line_settings_set_edge_detection(settings, GPIOD_LINE_EDGE_RISING);   //request rising edge events

    //create line configuration
    gpiod_line_config* config = gpiod_line_config_new();
    if (!config) {
        logError("MotionDetector: failed to allocate line config");
        gpiod_line_settings_free(settings);
        gpiod_chip_close(chip);
        return false;
    }

    //add line settings
    if (gpiod_line_config_add_line_settings(config, OFFSETS, SENSOR_COUNT, settings) < 0) {
        logError("MotionDetector: failed to add line settings");
        gpiod_line_config_free(config);
        gpiod_line_settings_free(settings);
        gpiod_chip_close(chip);
        return false; 
    }

    //create request configuration
    gpiod_request_config* reqcfg = gpiod_request_config_new();
    if (!reqcfg) {
        logError("MotionDetector: failed to allocate request config");
        gpiod_line_config_free(config);
        gpiod_line_settings_free(settings);
        gpiod_chip_close(chip);
        return false;
    }
    gpiod_request_config_set_consumer(reqcfg, "motion-detector");

    //create request
    gpiod_line_request* request = gpiod_chip_request_lines(chip, reqcfg, config);
    if (!request) {
        logError("MotionDetector: failed to request GPIO line");
        gpiod_request_config_free(reqcfg);
        gpiod_line_config_free(config);
        gpiod_line_settings_free(settings);
        gpiod_chip_close(chip);
        return false;
    }

    //block until event occurs on requested line
    if (gpiod_line_request_wait_edge_events(request, -1) < 0) {
        logError("MotionDetector: failed waiting for edge event");
        gpiod_line_request_release(request);
        gpiod_request_config_free(reqcfg);
        gpiod_line_config_free(config);
        gpiod_line_settings_free(settings);
        gpiod_chip_close(chip);
        return false;
    }

    //read event
    gpiod_edge_event_buffer* buffer = gpiod_edge_event_buffer_new(1);
    if (!buffer) {
        logError("MotionDetector: failed to allocate edge event buffer");
        gpiod_line_request_release(request);
        gpiod_request_config_free(reqcfg);
        gpiod_line_config_free(config);
        gpiod_line_settings_free(settings);
        gpiod_chip_close(chip);
        return false;
    }

    int num = gpiod_line_request_read_edge_events(request, buffer, 1);
    if (num < 0) {
        logError("MotionDetector: failed reading edge event");
        gpiod_edge_event_buffer_free(buffer);
        gpiod_line_request_release(request);
        gpiod_request_config_free(reqcfg);
        gpiod_line_config_free(config);
        gpiod_line_settings_free(settings);
        gpiod_chip_close(chip);
        return false;
    }

    //cleanup
    gpiod_edge_event_buffer_free(buffer);
    gpiod_line_request_release(request);
    gpiod_request_config_free(reqcfg);
    gpiod_line_config_free(config);
    gpiod_line_settings_free(settings);
    gpiod_chip_close(chip);

    return true;
}
