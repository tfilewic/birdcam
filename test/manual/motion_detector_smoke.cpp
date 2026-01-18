#include "MotionDetector.h"
#include <iostream>
#include <unistd.h> 



int main() {
    std::cout << "running motion_detector_smoke...\n" << std::flush;
    MotionDetector motionDetector;

    for (int i = 1; i <= 5; i++) {
        motionDetector.waitForMotion();
        std::cout << "motion detected  " << i << "/5\n" << std::flush;
        sleep(2);
    }

    return 0;
}