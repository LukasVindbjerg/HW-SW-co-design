#include <iomanip>
#include <vector>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <time.h>
#include <fstream>
#include "stdlib.h"

using namespace std;

#define ROWS		5
#define COLS		10
#define MAX 		100



template <typename Object>
class Matrix {
	private:
		vector<vector<Object>> array;

	public:
		Matrix() {};

		Matrix(int rows, int cols) : array(rows) {
			for(auto& r : array) {
				r.resize(cols);
			}
		}

		Matrix(vector<vector<Object>> v) : array{v} { }

		int numrows() const { return array.size( ); }

		int numcols() const {
			if (numrows() > 0) {
				return array[0].size();
			}
			return 0;
		}


		const vector<Object>& operator[](int row) const {
			return array[row];
		}

		vector<Object>& operator[](int row) {
			return array[row];
		}

		ostream& operator<<(ostream& t) {
			cout << fixed;
			cout.precision(2);
			for(int i = 0; i < numrows(); ++i) {
				cout << "|";
				for(int j = 0; j < numcols(); ++j) {
					cout << " " << setw(6) << array[i][j] << " ";
				}
				cout << "|" << endl;
			}
			return t;
		}

		ofstream& operator<<(ofstream& t) {
			t << fixed;
			for(int i = 0; i < numrows(); ++i) {
				t << "|";
				for(int j = 0; j < numcols(); ++j) {
					t << " " << setw(6) << array[i][j] << " ";
				}
				t << "|" << endl;
			}
			return t;
		}


		void add(Matrix& mat){	
            int rows = numrows();
	        int cols = numcols();

	        for(int i = 0; i < rows; ++i) {
                for(int j = 0; j < cols; ++j) {
                    array[i][j] = array[i][j] + mat[i][j];
		        }
	        }}

		void transpose();

		void resize(int rows, int cols);

		void printToFile(string fileName);
		
};



template <typename Object>
Matrix<Object>& multiply(Matrix<Object>& a, Matrix<Object>& b) {

	Matrix<Object> *mult = new Matrix<Object>(a.numrows(), b.numcols());

	for(int i = 0; i < a.numrows(); ++i) {
        for(int j = 0; j < b.numcols(); ++j) {
			(*mult)[i][j] = 0;
		}
	}

	for(int i = 0; i < a.numrows(); ++i) {
        for(int j = 0; j < b.numcols(); ++j) {
			for (int k = 0; k < b.numrows(); k++) {
				(*mult)[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return *mult;
}

template <typename Object>
ostream& operator<<(ostream& t, Matrix<Object> mat) {
	cout << fixed;
	cout.precision(2);
	for(int i = 0; i < mat.numrows(); ++i) {
		cout << "|";
		for(int j = 0; j < mat.numcols(); ++j) {
			cout << " " << setw(6) << mat[i][j] << " ";
		}
		cout << "|" << endl;
	}
	return t;
}


/* for this i will use the resize function from exercise (4), since i believe it improves readability */
template <typename Object>
void Matrix<Object>::transpose(){
	/* the idea is to take a N x M or M x N matrix and then resize it to be N x N or M x M.  	 *
	 * The point of this is that we the rows/cols we create in this process will just have the   *
	 * value 0. This means that if we start by resizeing the rows, after the transpose has been	 *
	 * executed, all the zeroes that was previously at the bottom rows are now at the right most *
	 * cols. Then we can resize by swapping the original values for rows/cols to get rid of the  *
	 * zeroes and have a propper transposed matrix.												 */

	Object temp;
	const int cur_rows = numrows();		
	const int cur_cols = numcols();

	if (numrows() > numcols()){			//in other words: if N > M, resize(N, N) so we have a N x N square matrix
		resize(numrows(), numrows());

	} else if(numrows() < numcols()){	//same here just if M > N, resize (M, M) so have a M x M square matrix
		resize(numcols(), numcols());
	}
	/*transpose loop, where we swap elements in the matrix around the diagonal*/
	for (int i = 0; i < numrows(); ++i) {
    	for (int j = i; j < numcols(); ++j) {	//j has to start at the same position as i
       	temp = array[i][j];
		array[i][j] = array[j][i];
		array[j][i] = temp;
		}
    }
		resize(cur_cols, cur_rows);		//finally we resize by swapping the rows and columns
}

template <typename Object>
void Matrix<Object>::resize(int rows, int cols){

	array.resize(rows);
	for(auto& r : array) {
		r.resize(cols);
	}
}


//TODO Jeg gad godt få den til at printe matricens navn også
template <typename Object>
void Matrix<Object>::printToFile(string fileName){
	ofstream t;
	t.open(fileName);

	t << fixed;
	for(int i = 0; i < numrows(); ++i) {
		t << "|";
		for(int j = 0; j < numcols(); ++j) {
			t << " " << setw(6) << array[i][j] << " ";
		}
		t << "|" << endl;
	}
	t.close();
}



int main() {
//	ifstream in;
//	in.open("in.dat", ios::in)

	int m, n;
	ifstream fA("inA.dat");
	fA >> m >> n;
	cout << "m = " << m << " and n = " << n << endl;
	Matrix<int> A(m, n);
	

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
  			fA >> A[i][j];

	ifstream fB("inB.dat");
	fB >> m >> n;
	Matrix<int> B(m, n);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fB >> B[i][j];

	Matrix<int>& mult = multiply(A, B);

	cout << "mult=" << endl << mult << endl;
	mult.printToFile("out.golden.dat");

	return 0;
}
