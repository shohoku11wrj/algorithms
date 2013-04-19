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

ifstream input;
Vector<int> no_indegree_nodes; // nodes with indegree is 0
Vector<int> deleted_nodes; // assistant set of deleted nodes in Topological Sorting
int* sorted;

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

//		/*
//		 * Test
//		 */
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

	Vector< SList<int> > graph_adjacency;
	int nodes, edges;

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
	
	// print
	for(int i=0; i < graph_adjacency.NumberOfItems() ; i++) {
		cout << "Node " << i << " --> ";
		while(!graph_adjacency[i].IsEmpty()) {
			cout << graph_adjacency[i].ShowFirst();
			cout << " --> ";
			graph_adjacency[i].RemoveFirst();
		}
		cout << endl;
	}

	return 0;
}
