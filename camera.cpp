#include "camera.h"

void Camera::cameraReadData(){

    cameraReadData_label2:for(int i = 0; i < ROWS; i++){
        cameraReadData_label3:for(int j = 0; j < COLS; j++){
            array[i][j] = i;//rand() % 10;
        }
    }
}


bool Camera::sum(){
    sum_label4:for(int i = 0; i < 4; i++){
        sum_label5:for(int j = 0; j < 4; j++){

            if(array[i][j] > 0) //if one is > 0, the sum is > 0.

                return true;
        }
    }
    return false;

}
