#include "camera.h"

void Camera::cameraReadData(){
    srand(time(0));
    Sleep(100);
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            array[i][j] = rand() % 10;
            // cout << array[i][j] << " ";
        }
    }
}
