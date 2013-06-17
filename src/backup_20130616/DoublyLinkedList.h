#ifndef DLIST_H
#define DLIST_H
#include <cassert>

template <class T> class DList;

template <class T> class DList
{
public:
	class Iterator;
	friend class Iterator;
protected:
	struct Node {
		T data;
		Node *last;
		Node *next;
		Node() { last = 0; next =0; }
		Node(const T& a, Node *p = 0, Node *q = 0) { data = a; last = p; next = q; }
	};
	Node *head, *tail;
public:
	DList() { head = tail = 0; }
	// copy constructor
	// which constructs a list and initialized it with copies of the items of list cObj
	DList(const DList<T> &cObj); 
	// assignment operator
	// which replaces the current list with a copy of list cObj
	const DList<T>& operator=(const DList<T> &cObj); 
	~DList();
	// add item as first item
	void AddFirst( const T& a); 
	// remove first item
	void RemoveFirst();
	// add item as last item
	void AddLast(const T& a); 
	bool IsEmpty() const;
	// show first item
	const T& ShowFirst() const;
	// reove all items from list
	void SetToEmpty();
	// add item following the position pointed by iterator
	void AddAfter(Iterator i, const T& item);
	// remove item following the position pointed by iterator
	void RemoveAfter(Iterator i); 
	
	class Iterator {
	private:
		Node *nodePointer;
	public:
		// construct an iterator and set it to a given node
		Iterator(const Node *setPtr) {
			nodePointer = const_cast<Node *> (setPtr);
		}
		// default constructor
		Iterator(){ nodePointer = 0; }
		// return reference of the item pointed by Iterator
		T& operator*() const {
			assert( nodePointer != 0);
			nodePointer = nodePointer->next;
			return *this;
		}
		// point to the next position (prefix)
		Iterator operator++(int) {
			assert( nodePointer != 0);
			Iterator retval(*this);
			nodePointer = nodePointer->next;
			return retval;
		}
		// point to the last position (prefix)
		Iterator operator--(int) {
			assert (nodePointer != 0);
			Iterator retval(*this);
			nodePointer  = nodePointer->last;
			return retval;
		}
		// return true if the two iterators point to the same node
		bool operator==(const Iterator &i) const {
			return nodePointer = i.nodePointer;
		}
		// return true if two iterators point to the different node
		bool operator!=(const Iterator &i) const {
			return nodePointer != i.nodePointer;
		}
	}; // end class Iterator

	// return iterator set to first node of the list
	Iterator Begin() {
		Iterator ret_Iter(head);
		return ret_Iter;
	}

	// return iterator set to end of the list
	Iterator End() {
		Iterator ret_Iter(0);
		return ret_Iter;
	}
}; // end class DList

/*** IMPLEMENTATION FOF DLIST MEMBER FUNCTIONS ***/

template <class T>
DList<T>::DList(const DList<T> &aDList) {
	head = tail = 0;
	Node *cur = aDList.head;
	while( cur ) {
		AddLast( cur->date );
		cur  = cur->next;
	}
}

template <class T>
const DList<T>& DList<T>::operator=(const DList<T> &aDList) {
	if(this != &aDList) {
		SetToEmpty();
		Node *cur = aDList.head;
		while(cur) {
			AddLast(cur->data);
			cur = cur->next;
		}
	}
	return *this;
}

template <class T>
void DList<T>::AddFirst(const T& a) {
	if(head == 0) {
		head = tail = new Node(a);
	}
	else {
		head = new Node(a, 0, head);
		(head->next)->last = head;
	}
}

template <class T>
bool DList<T>::IsEmpty() const {
	return (head == 0);
}

template <class T>
const T& DList<T>::ShowFirst() const {
	assert(!IsEmpty());
	return (head->data);
}

template <class T>
void DList<T>::SetToEmpty() {
	while(!IsEmpty()) {
		RemoveFirst();
	}
}

template <class T>
void DList<T>::AddAfter(DList<T>::Iterator i, const T& item) {
	assert(i.nodePointer != 0);
	Node *save = new Node(item, i.nodePointer, i.nodePointer->next);
	i.nodePointer->next = save.nodePointer;
	if(save->next != 0)
		save->next->last = save.nodePointer;
	delete save;
}

template <class T>
void DList<T>::RemoveAfter(DList<T>::Iterator i) {
	assert( i.nodePointer != 0 && i.nodePointer->next != 0);
	Node *save = i.nodePointer->next;
	i.nodePointer->next = save->next;
	if(save->next != 0)
		i.nodePointer->next->last = i.nodePointer;
}

/*** END OF DLIST CLASS FUNCTION IMPLEMENTATIONS ***/

#endif
