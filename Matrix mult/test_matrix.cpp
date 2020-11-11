#include <iostream>
#include <stdexcept>
#include <time.h>
#include <fstream>
#include "matrix_class.h"
#include "stdlib.h"
using namespace std;

#define ROWS		5
#define COLS		10
#define MAX 		100

int main() {
//	ifstream in;
//	in.open("in.dat", ios::in)
	Matrix<int> mat(ROWS, COLS); 
	Matrix<int> mat_(COLS, ROWS);
	srand(time(0));

	for (int i = 0; i < ROWS; i++) {             // randomize mat
		for (int j = 0; j < COLS; j++) {
			mat[i][j] = ((double) rand() / (RAND_MAX)) * MAX;
			mat_[j][i] = ((double) rand() / (RAND_MAX)) * MAX;
		}
	}

	Matrix<int>& mult = multiply(mat, mat_);
	cout << "mult=" << endl << mult << endl;


	ofstream myFile;
    myFile.open("out.dat");
    myFile << "Test...";
    myFile.close();

	return 0;
}


