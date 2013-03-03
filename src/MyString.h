#include <iostream>
#include <cstring>

using namespace std;

class MyString 
{
	friend ostream& operator<<(ostream &, const String &);
	friend istream& operator>>(istrream &, const String &);

	private:
		char *rep;
	
	public: // mumber function declarations
		MyString(); // default constructor
		MyString(const char *); // constructor with C-String argument
		MyString(const MyString &); // copy constructor
		~MyString();
		MyString& operator=(const MyString &rhsObject); // assignment operator
		void showString();
		int Length();
		char& operator[](int); // returns reference to char
};

// member function definitions
MyString::MyString() {
	// creates an object with empty C-string
	rep = new char[1];
	rep[0]='\0';
}

MyString::MyString(char *str) {
	// create an object with C-string pointed to by str
	rep = new char[strlen(str)+1];
	strcpy(rep, str); // copy string, using pointer of a string
}

MyString::MyString(MyString &ob) {
	// create an object with C-string as in ob
	rep = new char[strlen(ob.rep)+1];
	strcpy(rep, ob.rep);
}

MyString::~MyString() {
	// releases the dynamic array pointed to by rep to freestore
	delete [] rep;
}

void MyString::operator=(MyString &ob) {
	// resets the value of calling object to the value of ob
	delete [] rep;
	rep = new char[strlen(ob.rep)+1];
	strcpy(rep, ob.rep);
}

void MyString::showString() {
	// outputs the C-string pointed to by rep
	cout<<rep;
}

/*
 * We will implement these operator functions as nonmember (friend) functions of
 * MyString class. Doing so will allow the left-hand side of the == operator to be a
 * C-style string or a MyString object
 */
// Friend function for output and input
ostream & operator<<(ostream &out, const String &ob) {
	out << ob.rep;
	return out;
}

istream& operator>>(istream &in, const String &ob) {
	char tmp[80];
	in >> tmp;
	ob = MyString(tmp);
	return in;
}
