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
    bool myReading;
    int turnoff;



public:
    Sensor() : turnoff(0) {/*sensorReadData();*/}

    void sensorReadData(){
        srand(time(0));
        while(turnoff == 0){
            // sleep(10);
        myReading = rand()%2;
        }
    }

    bool reading(){
        return myReading;
    }
};