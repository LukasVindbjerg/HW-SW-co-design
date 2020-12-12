#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <iostream>
#include <Windows.h>
#include <chrono>
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

        
        //sleep(100); //To get initial values.

        while(alarmState == Active){

            if(intrusion_check()){
                alarmState = Alarmed;
                break;
            //TODO: break loop with input PIN
            }
        }

        //TODO: Find something better than detach, as it probably terminate quit the thread...
        
        S1.turnoff = 1; //Turnoff to 1, so we make sure
        S2.turnoff = 1; //the  while loops will exit.
        C1.turnoff = 1;

        S1_thread.join();
        S2_thread.join();
        C1_thread.join();

        

        cout << "System alarmed!" << endl; 
        return systemAlarmed();
    }
    //________________________________________________________________________________________
        
        
        else{
            cout << "GET HERE HUH?!?!?" << endl;
            return;
        }
    }
    
    void userPIN(){
        int i;
        cin >> i;

        while(cin.fail()){
            cout << "Entered PIN is not a number" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> i;
        }

        cout << validPin(i) << endl;
        if(validPin(i)==true){
            char option;
            cout << "do you want to turn off the system? (Y/n) ";
            cin >> option;
            if(option == 'Y')
                alarmState = Inactive;
            else
                alarmState = Active;
            
            return;
        
        }   
        else{
            userPIN();
        }
    }

   void deactive(){
        char option;
        cout << "Do you want to start the system? (Y/n) " << endl;
        cin >> option;
        if (option == 'Y')
        activate();
        else
        exit(0);
   }

    void systemAlarmed(){
        thread input(&AlarmSystem::userPIN, this);

        /*wait 10s for input thread to finish or continue*/
        WaitForSingleObject(input.native_handle(), 10000);

        switch(alarmState){
            case Active:
            return active();

            case Inactive:
            return deactive();

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
        int PIN;
        cin >> PIN;

        while(cin.fail()){
            cout << "Entered PIN is not a number" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> PIN;
        }
        if(validPin(PIN))
            alarmState = Active;
            active();   
    }
};
