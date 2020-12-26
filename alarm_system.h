#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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
    int pin;

    bool intrusion_check();

    void active();
    
    void reset();

    void systemAlarmed();

    bool validPin();

    void control_loop();

  public:
    AlarmSystem() : alarmState(Inactive), pin(0) {}

    //For user control outside the system
    void deactivate();

    //For user control outside the system
    void activate();
};
