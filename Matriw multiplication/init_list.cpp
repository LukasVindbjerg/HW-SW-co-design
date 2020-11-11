#include <iostream>
using namespace std;

class X {
	private:
    	int a, b, i, j;
	public:
    	const int& r;

	    X(int i)
	      : r(a) // initializes X::r to refer to X::a
	      , b{i} // initializes X::b to the value of the parameter i
	      , i(i) // initializes X::i to the value of the parameter i
	      , j(this->i) // initializes X::j to the value of X::i
		  , a{i} // initializes X::a to the value of b
	    { }
};

int main(int argc, char *argv[]) {
	X someX(10);
	X *anotherX = new X(5);

	cout << someX.r << endl;
	cout << anotherX->r << endl;
	delete anotherX;
}
