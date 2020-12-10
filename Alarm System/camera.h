#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

#define ROWS		4
#define COLS		4

class Camera{
private:
    int array[ROWS][COLS];
    friend class AlarmSystem;

public:
    Camera(){cameraReadData();}

    void cameraReadData(){
        // sleep(20);
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                array[i][j] = rand()%10;
            }
        }
    }
    
};

