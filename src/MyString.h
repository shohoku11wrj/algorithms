#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class MyString 
{
	friend ostream& operator<<(ostream&, const MyString &);
	friend istream& operator>>(istream&, MyString &);
	friend MyString operator+(const MyString&, const MyString&);
	friend bool operator==(const MyString&, const MyString&);
	friend bool operator!=(const MyString&, const MyString&);
	friend bool operator<(const MyString&, const MyString&);
	friend bool operator>(const MyString&, const MyString&);
	friend bool operator<=(const MyString&, const MyString&);
	friend bool operator>=(const MyString&, const MyString&);

	private:
		char *rep;
	public: // mumber function declarations
		MyString(); // default constructor
		MyString(const char *); // constructor with C-String argument
		MyString(const MyString &); // copy constructor
		~MyString();
		const MyString& operator=(const MyString &) ; // assignment operator
		void showString();
		
		int Length() const;
		char& operator[](int); // returns reference to char
		char operator[](int) const;
		MyString subString(const int, const int); 
};

// member function definitions
MyString::MyString() {
	// creates an object with empty C-string
	rep = new char[1];
	rep[0]='\0';
}

MyString::MyString(const char *str) {
	// create an object with C-string pointed to by str
	rep = new char[strlen(str)+1];
	strcpy(rep, str); // copy string, using pointer of a string
}

MyString::MyString(const MyString &ob) {
	// create an object with C-string as in ob
	rep = new char[strlen(ob.rep)+1];
	strcpy(rep, ob.rep);
}

MyString::~MyString() {
	// releases the dynamic array pointed to by rep to freestore
	delete [] rep;
}

const MyString& MyString::operator=(const MyString &ob) {
	// resets the value of calling object to the value of ob
//	if(this != &ob) {
//		delete [] rep;
//		rep = new char[strlen(ob.rep)+1];
//		strcpy(rep, ob.rep);
//	}
//	return *this;
	// not use Cstring functions like strcpy, see following
	if(this!=&ob) {
		char *tmp = ob.rep;
		int len=0;
		while(*tmp) {
			++len;
			++tmp;
		}
		delete [] rep;
		rep = new char[len+1];
		for(int i=0; i<=len; ++i){
			rep[i]=ob.rep[i];
		}
	}
	return *this; // return a reference to itself
}

int MyString::Length() const {
	return strlen(rep);
}

char& MyString::operator[](int index) {
	assert( index>=0 && index<strlen(rep) );
	return rep[index];
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
ostream & operator<<(ostream &out, const MyString &ob) {
	out << ob.rep;
	return out;
}

//istream& operator>>(istream &in, MyString &ob) {
//	char tmp[80];
//	in >> tmp;
//	ob = MyString(tmp);
//	return in;
//}

MyString operator+(const MyString &lhs, const MyString &rhs) {
	int strLength = strlen(lhs.rep) + strlen(rhs.rep) + 1;
	char *tmpStr = new char[strLength];
	strcpy(tmpStr, lhs.rep);
	strcat(tmpStr, rhs.rep);
	MyString retStr(tmpStr);
	delete [] tmpStr;
	return retStr;
}

bool operator==(const MyString& lhs, const MyString& rhs) {
//	return ( strcmp(lhs.rep, rhs.rep) == 0 ) ;
	if(lhs.Length() == 0) {
		if(rhs.Length() == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		int shorter = lhs.Length();
		if(rhs.Length() < shorter) {
			shorter = rhs.Length();
		}
		for (int i=0; i<shorter; i++) {
			if(lhs.rep[i]==rhs.rep[i]) {
				continue;
			}
			else {
				return false;
			}
		}
		if(lhs.Length() == rhs.Length()) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool operator!=(const MyString& lhs, const MyString& rhs) {
//	return ( !operator==(lhs,rhs) ) ;
	return !(lhs==rhs);
//	return ( strcmp(lhs.rep, rhs.rep) != 0 );
}
bool operator<(const MyString& lhs, const MyString& rhs) {
//	return ( strcmp(lhs.rep, rhs.rep) < 0 ) ;
	if(lhs.Length() == 0) {
		if(rhs.Length() ==0) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		if(rhs.Length()==0) {
			return false;
		}
		else {
			int shorter = lhs.Length();
			if(rhs.Length() < shorter) {
				shorter = rhs.Length();
			}
			for (int i=0; i<shorter; i++) {
				if(lhs.rep[i] < rhs.rep[i]) {
					return true;
				}
				else if(lhs.rep[i] > rhs.rep[i]) {
					return false;
				}
				else {
					continue;
				}
			}
			if(lhs.Length() == rhs.Length()) {
				return false;
			}
			else if(lhs.Length()==shorter) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}
bool operator>(const MyString& lhs, const MyString& rhs) {
//	return ( strcmp(lhs.rep, rhs.rep) > 0 ) ;
//	return ( operator<(lhs,rhs) !=true && operator!=(lhs,rhs)==true);
	return (rhs < lhs);
}
bool operator<=(const MyString& lhs, const MyString& rhs) {
//	return ( strcmp(lhs.rep, rhs.rep) <= 0 ) ;
	return (lhs<rhs || lhs==rhs);
}
bool operator>=(const MyString& lhs, const MyString& rhs) {
//	return ( strcmp(lhs.rep, rhs.rep) >= 0 ) ;
	return !(lhs<rhs);
}

MyString MyString::subString(const int start, const int len) {
	int strLength = Length();
	assert(start < strLength && start >= 0);
	if (start+len <= strLength) {
		char *tmpStr = new char[len];
		cout<<(*this).rep<<endl;
		for (int i=0; i<len; i++) {
			tmpStr[i] = (*this).rep[i+start];
		}
		MyString retStr(tmpStr);
		cout<<tmpStr<<endl;
		delete [] tmpStr;
		return retStr;
	}
	else {
		char *tmpStr = new char[strLength-start];
		for (int i=0; i<strLength; i++) {
			tmpStr[i] = rep[i+start];
			MyString retStr(tmpStr);
			delete [] tmpStr;
			return retStr;
		}
	}
}
