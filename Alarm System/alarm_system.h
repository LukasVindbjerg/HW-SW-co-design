#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <thread>
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

    bool intrusion(){
        if(S1.sensorReadData() == 0 && S2.sensorReadData() == 0){
            return false;
        }

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(C1.array[i][j] > 0) //if one is > 0, the sum is > 0.
                    return true;
            }
        }
        return false;
    }

    
    //TODO: Make the function work properly
    bool validPin(int P){
        int t = rand() % 2;
        return t;
    }


  public:  
    AlarmSystem() : alarmState(Inactive) {}
    bool activate(int pin){
        if(validPin(pin))
            alarmState = Active;

        while(alarmState == Active){
            // thread C1_thread(C1.cameraReadData());
            std::thread S1_thread(S1.sensorReadData());
            std::thread S2_thread(S2.sensorReadData());

            S1_thread.join();
            S2_thread.join();       
            // C1_thread.join();

            if(intrusion())
            alarmState = Alarmed;
            /*10 sec to enter pin*/
        }
    }

};
