#include "sensor.h"

void Sensor::sensorReadData(){
    // srand(time(0));
    // Sleep(50);
    myReading = 1;//rand()%2;
    // std::cout << myReading << " ";
}

bool Sensor::reading(){
    return myReading;
}
