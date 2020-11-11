#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

#include <iostream>
#include <iomanip>
#include <vector>

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
			if (row < 0 || row >= array.size())
				throw out_of_range("Invalid row.");
			return array[row];
		}

		vector<Object>& operator[](int row) {
			if (row < 0 || row >= array.size())
				throw out_of_range("Invalid row.");
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


		void add(Matrix& mat);

		void transpose();

		void resize(int rows, int cols);

		void printToFile(string fileName);
		
};

#include "matrix_class.tpp"

#endif
