#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;

#define ROWS		4
#define COLS		4

class Camera
{
private:
    int array[ROWS][COLS];
    int turnoff;
    friend class AlarmSystem;

public:
    Camera() : turnoff(0){/*cameraReadData();*/}

    void cameraReadData(){
        srand(time(0));
        Sleep(100);
        while(turnoff == 0){
            for(int i = 0; i < ROWS; i++){
                for(int j = 0; j < COLS; j++){
                    array[i][j] = rand() % 10;
                    // cout << array[i][j] << " ";
                }
            }
        }
    }


};

