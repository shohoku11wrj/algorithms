#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class Vector;

template <class T>
void Swap(Vector<T>& a, Vector<T>& b);

template <class T>
class Vector {

	friend void Swap <> (Vector<T>& a, Vector<T>& b);

	public:
		Vector(int capacity=10); // default constructor
		Vector(const Vector &); // copy constructor
		const Vector& operator=(const Vector &); // operator=
		~Vector(); // destructor

		bool IsEmpty() const;
		int NumberOfItems() const;
		void AddLast(const T&);
		void RemoveLast();
		const T& ShowLast() const;

		T& operator[](int);
		const T& operator[](int) const; // this means pointer and the value are both constant

		void Resize(int);
		void RemoveAll();
	
	private:
		T *array;
		int number_of_items;
		int size;
}; // end of class vector declaration

// Vector class member functions implementation

template <class T>
Vector<T>::Vector(int capacity) {
	assert(capacity>0);
	array = new T[capacity];
	size = capacity;
	number_of_items = 0;
}

template <class T>
Vector<T>::Vector(const Vector &ob) {
	array =  new T[ob.size];
	for (int i=0; i<ob.number_of_items; i++) {
		array[i] = ob.array[i];
	}
	size = ob.size;
	number_of_items = ob.number_of_items;
}

template <class T>
const Vector<T>& Vector<T>::operator=(const Vector<T> &ob) {
	if(this != &ob) {
		delete [] array;
		array = new T[ob.size];
		for (int i=0; i<ob.number_of_items; i++) {
			array[i] = ob.array[i];
			size = ob.size;
			number_of_items = ob.number_of_items;
		}
	}
	return *this;
}

template <class T>
Vector<T>::~Vector() {
	delete [] array;
}

template <class T>
bool Vector<T>::IsEmpty() const {
	return (number_of_items == 0);
}

template <class T>
int Vector<T>::NumberOfItems() const {
	return number_of_items;
}

template <class T>
void Vector<T>::AddLast(const T &newItem) {
	if(number_of_items == size) {
		Resize(2*size);
	}
	array[number_of_items++] = newItem;
}

template <class T>
void Vector<T>::RemoveLast() {
	assert(number_of_items > 0);
	--number_of_items;
}

template <class T>
const T& Vector<T>::ShowLast() const {
	assert(number_of_items>0);
	return array[number_of_items-1];
}

template <class T>
T& Vector<T>::operator[](int index) {
//	assert(index < number_of_items && index>=0);
	return array[index];
}

template <class T>
const T& Vector<T>::operator[](int index) const {
	assert(index < number_of_items && index>=0);
	return array[index];
}

template <class T>
void Vector<T>::Resize(int capacity) {
	T* newArray = new T[capacity];
	int saveNumberOfItems = number_of_items;
	if(number_of_items > capacity) {
		saveNumberOfItems = capacity;
	}
	for(int i=0; i<saveNumberOfItems; i++) {
		newArray[i] = array[i];
	}
	delete [] array;
	array = newArray;
	number_of_items = saveNumberOfItems;
	size = capacity;
}

template <class T>
void Vector<T>::RemoveAll() {
	while(!IsEmpty()) {
		RemoveLast();
	}
}

template <class T>
void Swap (Vector<T>& a, Vector<T>& b) {
	int save_number_of_items = a.number_of_items;
	int save_size = a.size;
	T * save_array = a.array;
		
	a.number_of_items = b.number_of_items;
	a.size = b.size;
	a.array = b.array;
		
	b.number_of_items = save_number_of_items;
	b.size = save_size;
	b.array = save_array;
}

void printVector(Vector<int> &v, int number) {
	    for(int i=0; i<number; i++) {
			cout<<v[i]<<" ";
		}   
		cout<<endl;
}

template <class T>
class PriorityQueue {
	public:
		Vector<T> container;
		T DeleteMin();
};

template <class T>
T PriorityQueue<T>::DeleteMin() {
	T min = container[0];
//	container[0] = container[container.NumberOfItems() -1];
//	int cur = 0;
	int lastPos = container.NumberOfItems() -1;
	for(int i = 0; i < container.NumberOfItems() - 1; i++) {
		if(container[i] < container[lastPos]) {
			T temp = container[i];
			container[i] = container[lastPos];
			container[lastPos] = temp;
		}
	}

	min = container[lastPos];
	container.RemoveLast();
	return min;
}
