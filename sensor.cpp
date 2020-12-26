#include "sensor.h"

void Sensor::sensorReadData(){
    myReading = 1;

}

bool Sensor::reading(){
    return myReading;
}
