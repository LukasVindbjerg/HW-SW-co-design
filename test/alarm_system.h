#pragma once

#include <stdio.h>
#include <stdlib.h>
// #include <thread>
#include <iostream>
#include <hls_stream.h>
// #include <Windows.h>
// #include <time.h>
#include "camera.h"
#include "sensor.h"

using namespace std;

enum state {Inactive, Active, Alarmed};

class AlarmSystem{

  private:
    state alarmState; 
    Sensor S1;
    Sensor S2;
    Camera C1;

    bool intrusion_check();

    void active();
    
    void reset();

    void systemAlarmed();

    bool validPin();

    void control_loop();

  public:
    AlarmSystem() : alarmState(Inactive) {}

    //For user control outside the system
    void deactivate();

    //For user control outside the system
    void activate();
};
