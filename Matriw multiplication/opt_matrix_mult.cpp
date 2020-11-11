using namespace std;

#include <climits>
#include "matrix_class.h"

/**
* Compute optimal ordering of matrix multiplication.
* c[0] is the number of rows in matrix 1, next entries contain
* the number of columns for each of the n matrices.
* The minimum number of multiplications is returned.
* Actual ordering is computed via another procedure using lastChange.
* For simplicity, m and lastChange are indexed starting at 1, instead of 0.
*
* Note: Entries below main diagonals of m and lastChange
* are meaningless and uninitialized.
*/
int optMatrix(const vector<int>&c, Matrix<int>&M, Matrix<int>&change) {
	int left, right, cost, i, j, k, n = c.size() - 1;

	for (left = 1; left <= n; ++left)
		M[left][left] = 0;

	for (k = 1; k < n; ++k) {
		// k is right - left
		for (left = 1; left <= n - k; ++left) {
			// For each position
			right = left + k;
			M[left][right] = INT_MAX;
			for (i = left; i < right; ++i) {
				cost = M[left][i] + M[i + 1][right] +
					c[left - 1] * c[i] * c[right];
				if (cost < M[left][right]) { // Update min
					M[left][right] = cost;
					change[left][right] = i;
				}
			}
		}
	}
	return M[1][n];
}

int main(int argc, char *argv[]) {
	vector<int> input = {50, 10, 40, 30, 5};
	Matrix<int> m(5, 5), change(5, 5);

	cout << optMatrix(input, m, change) << endl;
}
