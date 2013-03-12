#include <iostream>
#include "MyString.h"
#include "Vector.h"

using namespace std;

//void Swap (Vector<T> &a, Vector<T> &b) {
//	int save_number_of_items = a.number_of_items;
//	int save_size = a.size;
//	T * save_array = a.array;
//		
//	a.number_of_items = b.number_of_items;
//	a.size = b.size;
//	a.array = b.array;
//		
//	b.number_of_items = b.save_number_of_items;
//	b.size = save_size;
//	b.array = save_array;
//}
//template <class U>
void printVector(Vector<int> &v, int number) {
	for(int i=0; i<number; i++) {
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	Vector<int> a(3),b(2);
	a.AddLast(4);
	a.AddLast(9);
	a.AddLast(2);
	b.AddLast(8);
	b.AddLast(1);
	printVector(a,a.NumberOfItems());
	printVector(b,b.NumberOfItems());
	Swap<int> (a, b) ;
	printVector(a,a.NumberOfItems());
	printVector(b,b.NumberOfItems());
	return 0;
}

