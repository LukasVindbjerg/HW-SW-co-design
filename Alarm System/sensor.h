#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <thread>

using namespace std;

class Sensor
{
private:
    friend class AlarmSystem;



public:
    Sensor(){sensorReadData();}

    bool sensorReadData(){
        // sleep(10);
        return rand()%2;
    }
};