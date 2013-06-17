#include <iostream>

template <class T>
class BinarySearchTree {
	private:
		T data;
		BinarySearchTree *lch, *rch;
	public:
		BinarySearchTree();
		BinarySearchTree(T);
		BinarySearchTree(T, BinarySearchTree *, BinarySearchTree *);
		//~BinarySearchTree();
		void LTR_recu(BinarySearchTree *root);
		void AddNode(T newData);
		BinarySearchTree& operator=(BinarySearchTree &);
		void Print();
};

template <class T>
BinarySearchTree<T>::BinarySearchTree() {
	data = 0;
	lch = rch = 0;
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(T nodeData) {
	data = nodeData;
	lch = rch = 0;
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(T nodeData,
		BinarySearchTree *leftChild, BinarySearchTree *rightChild) {
	data = nodeData;
	lch = *leftChild;
	rch = *rightChild;
}

//template <class T>
//BinarySearchTree<T>::~BinarySearchTree() {
//	delete &data;
//	delete lch, rch;
//}

template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree<T> &ob) {
	if(this != &ob) {
		data = ob.data;
		lch = ob.lch;
		rch = ob.rch;
	}

	return *this;
}

template <class T>
void BinarySearchTree<T>::AddNode(T newData) {
	if(this == 0) {
		BinarySearchTree *newNode = new BinarySearchTree(newData);
		(*newNode).lch = 0;
		(*newNode).rch = 0;
		*this = *newNode;
	}
	else {
		if(newData < data) {
			if(lch == 0) {
				BinarySearchTree *newNode = new BinarySearchTree(newData);
				(*newNode).lch = 0;
				(*newNode).rch = 0;
				lch = newNode;
			} else {
				(*lch).AddNode(newData);
			}
		}
		else if(newData > data) {
			if(rch == 0) {
				BinarySearchTree *newNode = new BinarySearchTree(newData);
				(*newNode).lch = 0;
				(*newNode).rch = 0;
				rch = newNode;
			} else {
				(*rch).AddNode(newData);
			}
		}
	}
}

template <class T>
void BinarySearchTree<T>::Print() {
	if(this == 0) {
		return;
	}
	if( (*this).lch != 0) {
		(*(*this).lch).Print();
	}
	std::cout << data << " ";
	if( (*this).rch != 0) {
		(*(*this).rch).Print();
	}
}

int main() {
	BinarySearchTree<int> root(8);
	root.AddNode(4);
	root.AddNode(2);
	root.AddNode(5);
	root.AddNode(3);
	root.AddNode(6);
	root.AddNode(2);
	root.AddNode(4);
	root.AddNode(5);
	root.AddNode(2);

	root.Print();
	std::cout << std::endl;
	return 0;
}
