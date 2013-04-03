// file name: PriorityQueue.h
#ifndef ___PRIORITY_QUEUE___
#define ___PRIORITY_QUEUE___
#include<assert.h>
#include "Vector.h"

template <class T>
class PriorityQueue {
	Vector<T> container;
	public:
		T DeleteMax();
		void Insert(const T &a);
		bool IsEmpty() { return container.IsEmpty();}
		int GetSize() { return container.NumberOfItems(); }
};

template <class T>
T PriorityQueue<T>::DeleteMax()
{
	assert(container.NumberOfItems() > 0);
	T maxElement = container[0];
	//move the last element to the begining
	container[0] = container[container.NumberOfItems() - 1];
	int cur = 0;
	int lastPos = container.NumberOfItems() - 1;
	while ( (2*cur + 1 < lastPos) &&
			(container[cur] < container[2*cur + 1]
			 || container[cur] < container[2*cur + 2]) )
	{
		T tempItem = container[cur];
		if ( container[2*cur + 1] < container[2*cur + 2] )
		{
			container[cur] = container[2*cur + 2];
			container[2*cur + 2] = tempItem;
			cur = 2*cur + 2;
		}
		else
		{
			container[cur] = container[2*cur + 1];
			container[2*cur + 1] = tempItem;
			cur = 2*cur + 1;
		}
	}
	container.RemoveLast();
	return maxElement;
}//End function DeleteMax

template <class T>
void PriorityQueue<T>::Insert(const T &a)
{
	container.AddLast(a);
	T temp;
	int cur = container.NumberOfItems() - 1; // cur is the index of
	// current position
	while ( (cur > 0) && (container[cur] > container[(cur - 1)/2]) )
	{
		//push element up the tree by swapping it with
		// its parent of smaller priority
		temp = container[cur];
		container[cur] = container[(cur - 1)/2];
		container[(cur - 1)/2] = temp;
		cur = (cur - 1)/2;
	}
}// End function Insert
// End of PriorityQueue class functions implementation
#endif
