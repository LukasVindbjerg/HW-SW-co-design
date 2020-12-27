#include "sensor.h"

void Sensor::sensorReadData(){
    myReading = 1;

}

bool Sensor::reading(){
    for(int k = 0; k < 200000000; k++);
    return myReading;
}
