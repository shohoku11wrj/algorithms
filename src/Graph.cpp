/*
 * This could both be used for graph and digraph,
 * depends on line "graph_adjacency[edge_end_node_2].AddLast(edge_end_node_1);" is existed or not. 
 * existed -- graph ; un-existed -- digraph.
 */

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "Vector.h"
#include "SList.h"
#include <stack>
#include <queue>

static int nodes, edges;

ifstream input;
Vector<int> no_indegree_nodes; // nodes with indegree is 0
Vector<int> deleted_nodes; // assistant set of deleted nodes in Topological Sorting
int* sorted;
Vector< SList<int> > graph_adjacency;
void Print(Vector< SList<int> > digraph);
void DepthFirstSearch(Vector< SList<int> > digraph);
void BreadthFirstSearch(Vector< SList<int> > digraph);

void TopologicalSort(Vector< SList<int> > digraph) {
	sorted = new int[digraph.NumberOfItems()]();
	int i = 0; // sorting sequence number
	//int nodes[4] = {0,0,0,0}; // assistant list to mark indegree value of each node
	SList<int>::Iterator it;
	while (i<digraph.NumberOfItems()) {
		int* nodes = new int[digraph.NumberOfItems()]();
		// find a node u with indegree == 0;
			// construct the assitant list
		for(int j=0; j < digraph.NumberOfItems(); j++) {
			if ( (!digraph[j].IsEmpty()) && (sorted[j] == 0) ) { // sorted[j] == 0 , for exclude outdegree of sorted nodes(having sorted value != 0)
				for (it = digraph[j].Begin(); 
						it != digraph[j].End(); it++) {
					nodes[*it]++;
				}
			}
		}

//		Test

//		cout << "nodes[j]" << endl;
//		for (int j=0; j<4; j++) {
//			cout << nodes[j] << " ";
//		}
//		cout << endl;

			// find indegree is 0 nodes from assistant list
			// , and add them to no_indegree_nodes set
		for(int j=0; j < digraph.NumberOfItems(); j++) {
			if( (nodes[j] == 0) && (sorted[j] == 0) ) { // sorted[j] == 0 , for exclude sorted nodes
				no_indegree_nodes.AddLast(j);
			}
		}

		if(no_indegree_nodes.NumberOfItems() == 0) {
			cout << "This is not acyclic." << endl;
			return;
		}
		i = i + 1;
		// delete node u, and all arcs directed out of u as well
		//deleted_nodes.AddLast(no_indegree_nodes.)
		// topological order number of u = i;
		sorted[no_indegree_nodes.ShowLast()] = i;
		no_indegree_nodes.RemoveLast();
	}
}

int main(int argc, char **argv) // char *argv[] 
{
	if(argc != 3) {
		cout << "argc=" << argc << endl;
		cout << "Only 2 argument allowed: input file directory & Is Digraph or not?" << endl;
		return 1;
	}

	cout << "input file: " << argv[1] << endl;
	input.open(argv[1]);
	int ISDIGRAPH = atoi(argv[2]);



	input >> nodes >> edges;

	for(int i=0; i < nodes; i++) {
		graph_adjacency.AddLast(SList<int>());
	}

	int edge_end_node_1, edge_end_node_2;

	// digraph or not
	if (ISDIGRAPH == 0) {
		for(int i=0; i < edges; i++) {
			input >> edge_end_node_1 >> edge_end_node_2;
			graph_adjacency[edge_end_node_1].AddLast(edge_end_node_2);
			graph_adjacency[edge_end_node_2].AddLast(edge_end_node_1);
		}
	}
	else if (ISDIGRAPH == 1) {
		for(int i=0; i < edges; i++) {
			input >> edge_end_node_1 >> edge_end_node_2;
			graph_adjacency[edge_end_node_1].AddLast(edge_end_node_2);
		}
	}

	input.close();
	
	// topological sort
	TopologicalSort(graph_adjacency);
	for (int i=0; i < graph_adjacency.NumberOfItems(); i++) {
		cout<< "Node " << i << ": sort=" << sorted[i] << endl;
	}
	
	Print(graph_adjacency);

	DepthFirstSearch(graph_adjacency);

	BreadthFirstSearch(graph_adjacency);

	return 0;
}

// print
void Print(Vector< SList<int> > digraph) {
	for(int i=0; i < digraph.NumberOfItems() ; i++) {
		cout << "Node " << i << " --> ";
		while(! digraph[i].IsEmpty()) {
			cout << digraph[i].ShowFirst();
			cout << " --> ";
			digraph[i].RemoveFirst();
		}
		cout << endl;
	}
}

// Exploreform(s) , depth first search
void DepthFirstSearch(Vector< SList<int> > digraph) {
	Vector<bool> S(nodes); // visited nodes, nodes is static int = node count
	stack<int> _s; // visited nodes still have outgoing unused edges 
	// Mark all edges "unused"
	for(int i=0; i<nodes; i++) {
		S[i] = false;
	}
	int startNode = 0;
	_s.push(startNode);
	S[0] = true;

	cout << "depth search: " << startNode << " ";
//	while(! digraph[startNode-1].IsEmpty()) {
//		_s.push(digraph[startNode-1].ShowFirst());
//		digraph[startNode-1].RemoveFirst();
//	}

	while(! _s.empty()) { // _s is not empty
		int curNode = _s.top(); // choose some node v in _s
//	while(! digraph[curNode-1].IsEmpty()) {
//		_s.push(digraph[curNode-1].ShowFirst());
//		digraph[curNode-1].RemoveFirst();
		SList<int>::Iterator it;
		if(!digraph[curNode].IsEmpty()) {
			it = digraph[curNode].Begin(); // VecIter[v]
//		}
//		if(it != digraph[curNode-1].End() ) { // if there is no "unused" edge out of v
			// let (v,w) be the next unused edge out of v
			int w = *it; // w = *(VecIter[v])
			//it++;
			if (S[w] == false) { // if w is not in S
				S[w] = true; // add w to S
				_s.push(w); // add w to _s
				cout << w << " ";
			}
			digraph[curNode].RemoveFirst();
		}
		else {
			_s.pop(); // delete v from _s
		}
//	}
	} // end while
	cout << endl;
} // end Depth First Search


// Exploreform(s) , breadth first search
void BreadthFirstSearch(Vector< SList<int> > digraph) {
	Vector<bool> S(6); // visited nodes
	queue<int> _s; // visited nodes still have outgoing unused edges 
	// Mark all edges "unused"
	for(int i=0; i<6; i++) {
		S[i] = false;
	}
	int startNode = 0;
	_s.push(startNode);
	S[0] = true;
	// Mark all edges "unused"
	cout << "breadth search: " << startNode << " ";

	while(! _s.empty()) { // _s is not empty
		int curNode = _s.front(); // choose some node v in _s
		SList<int>::Iterator it;
		if(! digraph[curNode].IsEmpty()) { // if there is no "unused" edge out of v
			it = digraph[curNode].Begin(); // VecIter[v]
			// let (v,w) be the next unused edge out of v
			int w = *it; // w = *(VecIter[v])
			if (S[w] == false) { // if w is not in S
				S[w] = true; // add w to S
				_s.push(w); // add w to _s
				cout << w << " ";
			}
			digraph[curNode].RemoveFirst();
		}
		else {
			_s.pop(); // delete v from _s
		}
	} // end while
	cout << endl;
} // end Breadth First Search

//// Exploreform(s) , breadth first search
//void BreadthFirstSearch_too2(Vector< SList<int> > digraph) {
//	Vector<bool> S(6); // visited nodes
//	queue<int> _s; // visited nodes still have outgoing unused edges 
//	int startNode = 1;
//	cout << "Start node = " << startNode << ", ";
//	S[0] = true;
//	// Mark all edges "unused"
//	cout << "breadth search: ";
//	while(! digraph[startNode-1].IsEmpty()) {
//		_s.push(digraph[startNode-1].ShowFirst());
//		digraph[startNode-1].RemoveFirst();
//	}
//
//	while(! _s.empty()) { // _s is not empty
//		int curNode = _s.front(); // choose some node v in _s
//		SList<int>::Iterator it;
//		it = digraph[curNode].Begin(); // VecIter[v]
//		while(it != digraph[curNode].End() ) { // if there is no "unused" edge out of v
//			// let (v,w) be the next unused edge out of v
//			int w = *it; // w = *(VecIter[v])
//			it++;
//			if (S[w] == false) { // if w is not in S
//				S[w] = true; // add w to S
//				_s.push(w); // add w to _s
//			}
//		}
//		cout << _s.front() << " ";
//		_s.pop(); // delete v from _s
//	} // end while
//	cout << endl;
//} // end Depth First Search
