template <typename Object>
void Matrix<Object>::add(Matrix& mat) {
	int rows = numrows();
	int cols = numcols();

	if (rows != mat.numrows() || cols != mat.numcols()) {
		throw invalid_argument{"Matrix has incompatible dimensions"};
	}

	for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            array[i][j] = array[i][j] + mat[i][j];
		}
	}
}



template <typename Object>
Matrix<Object>& multiply(Matrix<Object>& a, Matrix<Object>& b) {
	if (a.numcols() != b.numrows()) {
		throw invalid_argument{"Matrix has incompatible dimensions"};
	}

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
/*
template <typename Object>
void Matrix<Object>::transpose(){
	Matrix<Object> *trans = new Matrix<Object>(numcols(), numrows());
	int cur_rows = numrows();
	int cur_cols = numcols();

	for (int i = 0; i < numrows(); ++i) {
    	for (int j = 0; j < numcols(); ++j) {
       	(*trans)[j][i] = array[i][j];
		}
    }

	array.resize(cur_cols);
	for(auto& r : array) {
		r.resize(cur_rows);
	}

	for (int i = 0; i < numrows(); ++i) {
    	for (int j = 0; j < numcols(); ++j) {
       	array[i][j] = (*trans)[i][j];
		}
    }
	delete trans;
}*/

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

