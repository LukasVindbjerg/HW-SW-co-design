#include "alarm_system.h"


bool AlarmSystem::intrusion_check(){
    if(S1.myReading == 0 && S2.myReading == 0){
        return false;
    }

    return C1.sum();

}


void AlarmSystem::control_loop(){

    while(alarmState == Active){
        active();
        systemAlarmed();
    }
    return;
}


void AlarmSystem::active(){  

    while(!intrusion_check()){
        S1.sensorReadData();
        S2.sensorReadData();
        C1.cameraReadData();
    }
}

void AlarmSystem::systemAlarmed(){
    alarmState = Alarmed;
    cout << "Intrusion detected system alarmed! You have 10s to enter PIN to reset: " << endl; 

    reset();

    return;
}


void AlarmSystem::reset(){
        bool i = validPin();
        if(i == 1){
            cout << "Shutting down."<<endl;
            alarmState = Active; //switch to inactive to prevent infinite loop
        }else if(i == 0){
            cout << "Alarm reset."<<endl;
            alarmState = Active;
        }
        else{
            cout << "Wrong input, staying active by default." << endl;
            alarmState = Active;
        }
        return;
}


bool AlarmSystem::validPin(/*int P*/){
    pin++;
    if(pin % 4 == 0){
    return false;
    }
    else return true;
}

void AlarmSystem::deactivate(){
    alarmState = Inactive;
}

void AlarmSystem::activate(){
    validPin();

    alarmState = Active;
    cout << "Access granted. " << endl;
    control_loop();
}
