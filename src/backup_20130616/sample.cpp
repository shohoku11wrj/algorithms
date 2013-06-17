#include<fstream>
using namespace std;
const int ARRAY_SIZE = 5; // Global declaration - Step 1 implementation
int i;
template <class T> void fillArray( T [] ); // function declaration
// fills the array elements reading data from file
void outputResults( double [] ); // function declaration
// outputs to a file the array element values and the average

int main() {
	double myArray[ARRAY_SIZE]; // Step 2 implementation
	fillArray(myArray); // function call - Step 3 implementation
	outputResults(myArray); // function call - Steps 4 & 5 implementation
	return 0;
} // end main function

// function definitions
template <class T>
void fillArray( T a[] ) {
	ifstream in("input.dat");
	for (i = 0; i < ARRAY_SIZE; i++)
		in >> a[i];
} // end function fillArray

void outputResults( double a[] ) {
	ofstream out("output.dat");
	out << "The "<< ARRAY_SIZE << " array elements are:" << endl;
	for (i = 0; i < ARRAY_SIZE; i++) {
		out << a[i] << endl;
	}
	double sum = 0., ave;
	for (i = 0; i < ARRAY_SIZE; i++) {
		sum = sum + a[i];
	}
	ave = sum / ARRAY_SIZE;
	out << "The average of array element values is : " << ave << endl;
} // end function outputResults
