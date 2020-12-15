#pragma once

#include <stdio.h>
#include <stdlib.h>
// #include <time.h>
// #include <Windows.h>
//#include <thread>

//using namespace std;

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
