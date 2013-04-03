#include <iostream>
#include "Vector.h"

struct tree_node {
	int leftchild;
	int rightchild;
	int parent;
};

struct symbol_info {
	char symbol;
	int frequency;
	int leaf;
};

struct forest_roots {
	int weight;
	int root;
	bool operator<(const forest_roots &a) {
		return weight < a.weight;
	}
	bool operator>(const forest_roots &a) {
		return weight > a.weight;
	}
};

Vector<tree_node> TREE;
Vector<symbol_info> ALPHABET;
Vector<forest_roots> FOREST;

template <class T>
T Vector<T>::DeleteMin() {
	T min= array[0];
	array[0] = array[number_of_items-1];
	int cur = 0;
	int lastPos = number_of_items - 1;
//	while( (2*cur + 1 < lastPos) && 
//			(array[cur] < array[2*cur + 1]
//			 || array[cur] < array[2*cur +2]) ) {
//		T temp = array[cur];
//		if(array[2*cur +1] < array[2*cur +2]) {
//			array[cur] = array[2*cur +2];
//			array[2*cur + 2] = temp;
//			cur = 2*cur +2;
//		}
//		else {
//			array[cur] = array[2*cur +1];
//			array[2*cur +1] = temp;
//			cur = 2*cur +1;
//		}
//	}
//	RemoveLast();
//	return min;

	for(int i=1; i<number_of_items; i++) {
		if(array[i] < array[lastPos]) { 
			T temp = array[i];
			array[i] = array[lastPos];
			array[lastPos] = temp;
		}
	}
	// delete the min
	min = array[lastPos];
	RemoveLast();
	return min;
}

void Huffman() {
	int lastnode = TREE.NumberOfItems(); // keep track of the number of nodes in the TREE
	forest_roots least, second;
	forest_roots newroot;
	while(FOREST.NumberOfItems() > 1) {
		least = FOREST.DeleteMin();
		second = FOREST.DeleteMin();
		lastnode = lastnode +1 ;
		TREE[lastnode].leftchild = least.root;
		TREE[lastnode].rightchild = second.root;
		TREE[lastnode].parent = 0;
		TREE[least.root].parent = lastnode;
		TREE[second.root].parent = lastnode;
		newroot.weight = least.weight + second.weight;
		newroot.root = lastnode;
		FOREST.AddLast(newroot);
	}
}


int main()
{
	tree_node tn;
	TREE.AddLast(tn);
	TREE.AddLast(tn);
	TREE.AddLast(tn);
	TREE.AddLast(tn);
	TREE.AddLast(tn);
	
	symbol_info si;
	si.symbol = 'b';
	si.frequency = 5;
	si.leaf = 2;
	ALPHABET.AddLast(si);
	si.symbol = 'a';
	si.frequency = 3;
	si.leaf = 1;
	ALPHABET.AddLast(si);
	si.symbol = 'c';
	si.frequency = 4;
	si.leaf = 3;
	ALPHABET.AddLast(si);
	si.symbol = 'd';
	si.frequency = 6;
	si.leaf = 4;
	ALPHABET.AddLast(si);
	si.symbol = 'e';
	si.frequency = 12;
	si.leaf = 5;
	ALPHABET.AddLast(si);
	
	forest_roots fr;
	fr.weight = 3;
	fr.root = 1;
	FOREST.AddLast(fr);
	fr.weight = 5;
	fr.root = 2;
	FOREST.AddLast(fr);
	fr.weight = 4;
	fr.root = 3;
	FOREST.AddLast(fr);
	fr.weight = 6;
	fr.root = 4;
	FOREST.AddLast(fr);
	fr.weight = 12;
	fr.root = 5;
	FOREST.AddLast(fr);

	Huffman();


}

























