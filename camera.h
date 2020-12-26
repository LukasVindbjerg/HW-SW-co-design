#pragma once

#include <stdio.h>
#include <stdlib.h>

#define ROWS		4
#define COLS		4

class Camera
{
private:
    int array[ROWS][COLS];
    friend class AlarmSystem;
    void cameraReadData();
    bool sum();


public:
    Camera(){/*cameraReadData();*/}
};

