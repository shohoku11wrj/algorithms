#ifndef SLIST_H
#define SLIST_H
#include <cassert>

template <class T> class SList;

template <class T> class SList 
{
	public:
		class Iterator;
		friend class Iterator;
	protected:
		struct Node {
			T data;
			Node *next;
			Node() { next = 0; }
			Node(const T& a, Node *p = 0) { data = a; next = p; }
		};
		Node *head, *tail;
	public:
		SList() { head = tail = 0; }
		SList(const SList &aSList);
		const SList& operator=(const SList<T> &aSList);
		~SList() { SetToEmpty(); }
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
			firend SList;
			private:
				Node *nodePointer;
			// construct an iterator and set it to a given node
			Iterator(const Node *setPtr) {
				nodePointer = const_cast<Node *> ( setPtr);
			}
			public:
				// default constructor
				Iterator():nodePointer(0){}
				// return reference of the item pointed by Iterator
				T& operator*() const {
					assert( nodePointer != 0 );
					return ( *nodePointer ).data;
				}
				// point to the next position (prefix)
				Iterator& operator++() {
					assert( nodePointer != 0 );
					nodePointer = nodePointer->next;
					return *this;
				}
				// point to the next position (postfix)
				Iterator operator++(int) {
					assert( nodePointer != 0 );
					Iterator retval(*this);
					nodePointer = nodePointer->next;
					return retval;
				}
				// return true if the two iterators point to the same node
				bool operator != (const Iterator &i) const {
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
}; // end class SList

/***  IMPLEMENTATION OF LIST MEMBER FUNCTIONS  ***/

template <class T>
SList<T>::SList(const SList<T> &aSList) {
	head = tail = 0;
	Node *cur = aSList.head;
	while( cur ) {
		AddLast( cur->data );
		cur = cur->next;
	}
}

template <class T>
const SList<T>& SList<T>::operator=(const SList<T> &aSList) {
	if( this != &aSList) {
		SetToEmpty();
		Node *cur = aSList.head;
		while( cur ) {
			AddLast( cur->data );
			cur = cur->next;
		}
	}
	return *this;
}

template <class T>
void SList<T>::AddFirst(const T& a) {
	if( head == 0) { 
		head = tail = new Node(a);
	}
	else {
		head = new Node(a, head);
	}
}

template <class T>
void SList<T>::RemoveFirst() {
	assert( !IsEmpty());
	Node *tmp = head;
	head = head->next;
	delete tmp;
	if (head == 0) {
		tail = 0;
	}
}

template <class T>
void SList<T>::AddLast(const T& a) {
	if (head == 0) {
		head = tail = new Node(a);
	}
	else {
		tail->next = new Node(a);
		tail = tail->next;
	}		
}

template <class T>
bool SList<T>::IsEmpty() const {
	return (head == 0);
}

template <class T>
const T& SList<T>::ShowFirst() const {
	assert( !IsEmpty());
	return (head->data);
}

template <class T>
void SList<T>::SetToEmpty() {
	while( !IsEmpty()) {
		RemoveFirst();
	}
}

template <class T>
void SList<T>::AddAfter(SList<T>::Iterator i, const T& item) {
	assert( i.nodePointer != 0);
	i.nodePointer->next = new Node(item, i.nodePointer->next);
}

template <class T>
void SList<T>::RemoveAfter(SList<T>::Iterator i) {
	assert( i.nodePointer != 0 && i.nodePointer->next != 0 );
	Node *save = i.nodePointer->next;
	i.nodePointer->next = i.NodePointer->next->next;
	delete save;
}

// End of SList class functions implementation

#endif
