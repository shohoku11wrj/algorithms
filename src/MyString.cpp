#include <iostream>
#include <cstring>

using namespace std;

class MyString 
{
	private:
		char *rep;

	public: // mumber function declarations
		MyString(); // default constructor
		MyString(char *); // constructor with C-String argument
		MyString(MyString &); // copy constructor
		~MyString();
		void operator=(MyString &rhsObject);
		void showString();
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
