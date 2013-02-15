#include <iostream> // this line for standard I/O
#include <fstream> // this line for file I/O
using namespace std;
int main() {
	ofstream outfile ("myoutput.dat"); // for output file
	ifstream infile ("myinput.dat"); // for input file
	if ( infile.fail() ) {
		cout << "Input file \"myinput.dat\" opening failed" << endl;
		return 1;
	}
	int length, width, area;
	infile >> length >> width;
	if (length > 0 && width > 0) {
		area = length * width;
		outfile << "Area of a rectangle with ";
		outfile << "length = " << length << " and width = " << width;
		outfile << " is " << area;
	}
	infile.close(); // this line closes the input file
	outfile.close(); // this line closes the output file
	return 0;
} // end of main
