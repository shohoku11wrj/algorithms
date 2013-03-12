#include "MyString.h"
using namespace std;

int main () {
	MyString A; // MyString object A is created and A contains the null string
	MyString B("Hello"); // MyString object B is created and B contains
	// the string "Hello"
	MyString C = " CS 115 class"; // MyString object C is created and C contains
	// the string " CS 115 class"
	MyString D(B); // MyString object D is created and D contains
	// the string "Hello"
	MyString E = C; // MyString object E is created and E contains
	//the string " CS 115 class"
	A = B; // resets the value of A to that of B
	cout << A << " " << B << endl; // outputs: Hello Hello
	A[0] = 'M';
	cout << A << " " << B << endl; // outputs: Mello Hello
	cout << "operator= and [] are working" << endl;
	D[0] = 'M';
	cout << D << " " << B << endl; // outputs: Mello Hello
	cout << "copy constructor is working" << endl;
	C = B + C;
	cout << C << endl; // outputs: Hello CS 115 class
	C = "MyString Class " + B + E;
	cout << C << endl; // outputs: MyString Class Hello CS 115 class
	if ( A < B )
		cout << "MyString has a bug in operator< function" << endl;
	else if ( A <= B )
		cout << "MyString has a bug in operator<= function" << endl;
	else if ( A == B )
		cout << "MyString has a bug in operator== function" << endl;
	else
		cout << "MyString comparison operators are working so far" << endl;
	if ( A != B && A > B && A >= B )
		cout << "All my comparison operators are working" << endl;

	MyString sub = C.subString(-1,2);
	cout<< "SubString of C is " << sub << endl;
	return 0;
}
