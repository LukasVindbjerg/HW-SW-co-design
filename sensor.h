#pragma once

#include <stdio.h>
#include <stdlib.h>

class Sensor
{
private:
    friend class AlarmSystem;
    bool myReading;



public:
    Sensor() {myReading = 0;}

    void sensorReadData();

    bool reading();
};
