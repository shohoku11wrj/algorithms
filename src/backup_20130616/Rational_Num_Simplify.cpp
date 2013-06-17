#include <iostream>
#include <cstdlib>
using namespace std;

class RationalNum
{
	private:
		// data members
		int number;
		int denom;
	
	public:
		// member functions
		RationalNum();
		RationalNum(int , int);
		void setRationalNum(int, int);
		void outputRationalNum();
		int getNumber() {
			return number;
		}
		int getDenom() {
			return denom;
		}
		void simplify();
	
		// friend function declarations
		friend RationalNum operator+(RationalNum,RationalNum);
		friend ostream& operator<<(ostream&,RationalNum&);
		friend istream& operator>>(istream&,RationalNum&);
};

// structor function definitions
RationalNum::RationalNum() {number=0; denom=1;}
RationalNum::RationalNum(int x, int y){	number = x;	denom = y; }

// member function definitions
void RationalNum::setRationalNum(int n, int d)
{
	number = n;
	denom = d;
}

void RationalNum::outputRationalNum()
{
	cout<<number<<" / "<<denom<<endl;
}

void RationalNum::simplify()
{
	int p = abs(number);
	int q = abs(denom);
	int small, large, remainder;

	if(p>=q) {
		large=p;
		small=q;
	} else {
		large=q;
		small=p;
	}

	while(large % small > 0) {
		remainder = large % small;
		large = small;
		small = remainder;
	}

	number = number / small;
	denom = denom / small;
}

RationalNum addRationalNums(RationalNum, RationalNum);
RationalNum operator+(RationalNum lhs, RationalNum rhs);
ostream& operator<<(ostream&, RationalNum&);
istream& operator>>(istream&, RationalNum&);

int main()
{
	cout<<"How many rational numbers for input? ";
	int arraySize;
	cin >> arraySize;

	RationalNum *ptr = new RationalNum[arraySize];

	int i;
	cout << "For each rational type numerator/denominator <enter>\n";

	for(i=0;i<arraySize;i++) {
		cout << "Input rational number " << i+1 <<": ";
		cin >> ptr[i];
	}
	cout << "The " << arraySize << " input rationals are:" << endl;

	for(i=0;i<arraySize;i++) {
		cout << ptr[i] << endl;
	}

	RationalNum sum;
	for(i=0;i<arraySize;i++) {
		sum = sum + ptr[i];
	}
	cout<<"Two fractions sum is: "<< sum << endl;
	
	delete [] ptr; // returns dynamic memory to freestore !!!!
	return 1;
}

RationalNum addRationalNums(RationalNum x, RationalNum y)
{
	int numerator = (x.getNumber()*y.getDenom())
					+ (y.getNumber()*x.getDenom());
	int denominator = x.getDenom()*y.getDenom();
	RationalNum r;
	r.setRationalNum(numerator, denominator);
	r.simplify();
	return r;
}

RationalNum operator+(RationalNum lhs, RationalNum rhs)
{
	int numerator = (lhs.number * rhs.denom)
					+ (rhs.number * lhs.denom);
	int denominator = lhs.denom * rhs.denom;
	RationalNum r(numerator, denominator);
	r.simplify();
	return r;
}

ostream& operator<<(ostream &out, RationalNum &ob)
{
	out << ob.number << " / " << ob.denom;
	return out;
}

istream& operator>>(istream &in, RationalNum &ob)
{
	char divisionSign;
	in >> ob.number >> divisionSign >> ob.denom;
	return in;
}
