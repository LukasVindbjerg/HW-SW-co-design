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
    //alarmState = Active;
    //Sleep(1000); //To get initial values.
    while(!intrusion_check()){
        S1.sensorReadData();
        S2.sensorReadData();
        C1.cameraReadData();
    }
}

void AlarmSystem::systemAlarmed(){
    alarmState = Alarmed;
    cout << "Intrusion detected system alarmed! You have 10s to enter PIN to reset: " << endl; 

    userPIN();

    return;
    // switch(alarmState){
    //     case Active:
    //     return active();

    //     case Inactive:
    //     return;

    //     case Alarmed:
    //     return active();
    // }
}


void AlarmSystem::userPIN(){
    cout << "Enter PIN: ";
//     int PIN;
//     cin >> PIN;

//    while(cin.fail()){
//        cout << "Entered PIN is not a number. Try again: " << endl;
//        cin.clear();
//        cin.ignore(256,'\n');
//        cin >> PIN;
//    }
//     int PIN;
//     while(!validPin(PIN)){
//     cout << "Wrong PIN try again."<<endl;
//     cout << "Enter PIN: ";
//     cin >> PIN;    
// }
        validPin();

        int option;
        cout << "Do you want to turn off the system? " << endl << "Type 1 for: Yes" <<endl << "Type 0 for: No"<<endl;
        cin >> option;

        // while(cin.fail()){
        //    cout << "Entered number is not an option. Try again: " << endl;
        //    cin.clear();
        //    cin.ignore(256,'\n');
        //    cin >> option;
        // }
        if(option == 1){
            cout << "Shutting down."<<endl;
            alarmState = Inactive;
        }else if(option == 0){
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
    // srand(time(0));
    int P;
    cin >> P;
    //Chance for false is 1/p
    // int p = 2;
    return P;//(rand() % p);
}

void AlarmSystem::deactivate(){
    alarmState = Inactive;
}

void AlarmSystem::activate(){
    cout << "Enter PIN: ";
    validPin();
    // int PIN;
    
    // cin >> PIN;

    // while(cin.fail()){
    //     cout << "Entered PIN is not a number. Try again: " << endl;
    //     cin.clear();
    //     cin.ignore(256,'\n');
    //     cin >> PIN;
    // }
    // while(!validPin(PIN)){
    //     cout << "Wrong PIN try again."<<endl;
    //     cout << "Enter PIN: ";
    //     cin >> PIN;    
    // }
        alarmState = Active;
        cout << "Access granted. " << endl;
        control_loop();
}
