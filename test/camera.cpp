#include "camera.h"

void Camera::cameraReadData(){
    srand(time(0));
    Sleep(100);
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            array[i][j] = rand() % 10;
        }
    }
}


bool Camera::sum(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){

            if(array[i][j] > 0) //if one is > 0, the sum is > 0.

                return true;
        }
    }
    return false;

}
