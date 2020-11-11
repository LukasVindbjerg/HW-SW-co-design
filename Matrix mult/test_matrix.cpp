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
#define FUCK		2

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

	Matrix<int> test(FUCK, FUCK);

	test[0][0] = 1;
	test[0][1] = 2;
	test[1][0] = 3;
	test[1][1] = 4;



	//TODO Make this as a function
	ofstream myFile;
    myFile.open("out.dat");
	myFile << mult;

    myFile << "mult=\n";

	for (int i = 0; i < ROWS; i++)
	{
		myFile <<"|\t";
		for (int j = 0; j < ROWS; j++)
		{
			myFile << mult[i][j] << "\t";
		}
		myFile <<"|\n";
	}
	
		myFile.close();

	return 0;
}



