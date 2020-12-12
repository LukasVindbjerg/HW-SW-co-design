#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
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
        Sleep(50);
        myReading = rand()%2;
        // cout << myReading << " ";
        }
    }

    bool reading(){
        return myReading;
    }
};