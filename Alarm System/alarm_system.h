#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <iostream>
#include <Windows.h>
#include <time.h> 
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

    bool intrusion_check(){
        if(S1.myReading == 0 && S2.myReading == 0){
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

    void active(){
        
        if(alarmState == Alarmed)
            alarmState = Active;
        //____________________________________________________________________________
        if(alarmState == Active){
        S1.turnoff = 0; //Change the turnoff values to 0, so the while loop
        S2.turnoff = 0; //wil run.
        C1.turnoff = 0;


        thread S1_thread(&Sensor::sensorReadData, ref(S1));
        thread S2_thread(&Sensor::sensorReadData, ref(S2));
        thread C1_thread(&Camera::cameraReadData, ref(C1));

        
        Sleep(1000); //To get initial values.

        while(alarmState == Active){

            if(intrusion_check()){
                alarmState = Alarmed;
                break;
            }
        }
        
        S1.turnoff = 1; //Turnoff to 1, so we make sure
        S2.turnoff = 1; //the  while loops will exit.
        C1.turnoff = 1;

        S1_thread.join();
        S2_thread.join();
        C1_thread.join();

        return systemAlarmed();
    }
    //________________________________________________________________________________________
           
        else{
            return;
        }
    }
    
    void userPIN(){
        int i;
        cin >> i;

        while(cin.fail()){
            cout << "Entered PIN is not a number. Try again: " << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> i;
        }

        cout << validPin(i) << endl;
        if(validPin(i)==true){
            char option;
            cout << "Do you want to turn off the system? (Y/n) ";
            cin >> option;
            if(option == 'Y'){
                alarmState = Inactive;
            }else{
                alarmState = Active;
            }
            return;
        }   
        else{
            userPIN();
        }
    }

    void systemAlarmed(){
        cout << "Intrusion detected system alarmed! You have 10s to enter PIN to deactivate: " << endl; 
        thread input(&AlarmSystem::userPIN, this);

        /*wait 10s for input thread to finish or continue*/
        //WaitForSingleObject(input.native_handle(), 10000);
        input.join();

        switch(alarmState){
            case Active:
            return active();

            case Inactive:
            return;

            case Alarmed:
            return active();
        }
    }

    
    bool validPin(int P){
        srand(time(0));

        //Chance for false is 1/p
        int p = 2;
        return (rand() % p);
    }


  public:
    AlarmSystem() : alarmState(Inactive) {}

    //For user control outside the system
    void deactivate()
    {
        alarmState = Inactive;
    }

    //For user control outside the system
    void activate(){
        cout << "Enter PIN: ";
        int PIN;
        cin >> PIN;

        while(cin.fail()){
            cout << "Entered PIN is not a number. Try again: " << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> PIN;
        }
        if(validPin(PIN)){
            alarmState = Active;
            cout << "Access granted. " << endl;
            active();
        }       
        else{
            cout << "Wrong PIN."<<endl;
            return;
        }
    }
};
