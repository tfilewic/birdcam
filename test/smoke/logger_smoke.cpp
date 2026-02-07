#include "Logger.h"

int main() {
    DetectionEvent event1 {
        "2025-12-17T19:02:55", 
        "img_00001.jpg"
    };
    DetectionEvent event2 {
        "2025-12-18T05:33:10", 
        "img_00002.jpg"
    };
    Logger logger;


    logger.logDetection(event1);
    logger.logDetection(event2);
    
    return 0;
}