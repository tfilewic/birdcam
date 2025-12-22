#include "ImageSaver.h"


int main() {
    Frame frame;
    frame.width = 2;
    frame.height = 2;
    frame.stride = 2;
    const size_t y = frame.height * frame.stride;
    const size_t uv = (frame.height / 2) * frame.stride;
    frame.data.resize(y + uv);

    //y
    frame.data[0] = 240;
    frame.data[1] = 60;
    frame.data[2] = 240;
    frame.data[3] = 60;
    //uv
    frame.data[4] = 180;
    frame.data[5] = 120;

    ImageSaver saver;
    const std::string path = saver.save(&frame, "smoke_test");

    return 0;
}