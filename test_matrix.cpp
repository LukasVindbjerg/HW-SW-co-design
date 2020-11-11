#include <iostream>
#include <stdexcept>
#include "matrix_class.h"
#include "stdlib.h"
using namespace std;

#define ROWS		5
#define COLS		10
#define MAX 		100

int main(void) {
	Matrix<double> mat(ROWS, COLS), mat_(COLS, ROWS);
	srand(time(0));

	for (int i = 0; i < ROWS; i++) {             // randomize mat
		for (int j = 0; j < COLS; j++) {
			mat[i][j] = ((double) rand() / (RAND_MAX)) * MAX;
			mat_[j][i] = ((double) rand() / (RAND_MAX)) * MAX;
		}
	}
	
	try {
	Matrix<double>& mult = multiply(mat, mat_);
	cout << "mult=" << endl << mult << endl;
	} catch (exception& e) {
		cout << e.what() << endl;
	}


	return 0;
}
