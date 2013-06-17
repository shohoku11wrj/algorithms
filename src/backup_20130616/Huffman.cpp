#include <iostream>
#include <cstring>
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

Vector<tree_node> TREE(10);
Vector<symbol_info> ALPHABET(10);
PriorityQueue<forest_roots> FOREST;

/*
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

*/

void Huffman() {
	int lastnode = TREE.NumberOfItems(); // keep track of the number of nodes in the TREE
	forest_roots least, second;
	forest_roots newroot;
	while(FOREST.container.NumberOfItems() > 1) {
		least = FOREST.DeleteMin();
		cout << "last:root=" << least.root << ",weight=" << least.weight << endl;
		second = FOREST.DeleteMin();
		cout << "second:root=" << second.root << ",weight=" << second.weight << endl;
		lastnode = lastnode +1 ;
		tree_node tn;
		TREE.AddLast(tn);
		TREE[lastnode-1].leftchild = least.root;
		TREE[lastnode-1].rightchild = second.root;
		TREE[lastnode-1].parent = 0;
		TREE[least.root-1].parent = lastnode;
		TREE[second.root-1].parent = lastnode;
		newroot.weight = least.weight + second.weight;
		newroot.root = lastnode;
		FOREST.container.AddLast(newroot);
	}
}

void printHuffman() {
	cout << endl;
	for(int i=0; i < FOREST.container.NumberOfItems(); i++ ) {
		cout << "node " << i;
		cout << ":root= " << FOREST.container[i].root; 
		cout << ",weight=" << FOREST.container[i].weight << endl;
	}
}

string printTreeNodeCode(int);

void printTREE() {
	 cout << "TREE:" << endl;
	 cout << "S P L R Code" << endl;
//	 while(!TREE.IsEmpty()) {
//		tree_node temp = TREE.ShowLast();
//		cout << temp.parent << " ";
//		cout << temp.leftchild << " ";
//		cout << temp.rightchild << " ";
//		cout << endl;
//		TREE.RemoveLast();
//	 }
	 for(int i=0; i < TREE.NumberOfItems(); i++) {
		if(i<5) {
			cout << ALPHABET[i].symbol << " ";
		} else {
			cout << "  ";
		}
		cout << TREE[i].parent << " ";
		cout << TREE[i].leftchild << " ";
		cout << TREE[i].rightchild << " ";
		string code = printTreeNodeCode(i);
		cout << code << endl;
	 }
}

string printTreeNodeCode(int i) {
	if(TREE[i].parent == 0) {
		return "";
	}

	if(TREE[TREE[i].parent - 1].leftchild - 1 == i) {
		return printTreeNodeCode(TREE[i].parent-1) + "0";
	}
	else {
		return printTreeNodeCode(TREE[i].parent-1) + "1"; 
	}
}

int main()
{
	tree_node tn;
	tn.leftchild = 0;
	tn.rightchild = 0;
	tn.rightchild = 0;
	TREE.AddLast(tn);
	TREE.AddLast(tn);
	TREE.AddLast(tn);
	TREE.AddLast(tn);
	TREE.AddLast(tn);
	
	symbol_info si;
	si.symbol = 'b';
	si.frequency = 3;
	si.leaf = 1;
	ALPHABET.AddLast(si);
	si.symbol = 'a';
	si.frequency = 5;
	si.leaf = 2;
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
	FOREST.container.AddLast(fr);
	fr.weight = 5;
	fr.root = 2;
	FOREST.container.AddLast(fr);
	fr.weight = 4;
	fr.root = 3;
	FOREST.container.AddLast(fr);
	fr.weight = 6;
	fr.root = 4;
	FOREST.container.AddLast(fr);
	fr.weight = 12;
	fr.root = 5;
	FOREST.container.AddLast(fr);

	printHuffman();

	Huffman();

	printHuffman();
	
	printTREE();
}
