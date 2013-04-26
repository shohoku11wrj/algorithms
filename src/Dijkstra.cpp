#include "Vector.h"
#include "PriorityQueue_SmallHead.h"

struct node {
	int cost;
	int at;
};

Vector<node> start;

bool operator<(const node &leftNode, const node &rightNode) {
	if (leftNode.const != rightNode.cost) 
		return leftNode.cost < rightNode.cost;
	if (leftNode.at != rightNode.at) 
		return leftNode.at < rightNode.at;
	return false;
}

bool operator>(const node &leftNode, const node &rightNode) {
	if (leftNode.const != rightNode.cost) 
		return leftNode.cost > rightNode.cost;
	if (leftNode.at != rightNode.at) 
		return leftNode.at > rightNode.at;
	return false;
}

void dijkstra(node start) {
	PriorityQueue_SmallHead<node> s;
	s.Insert(start);
	while (s.empty() == false) {
		top = s.GetTop();
		s.DeleteMin();
		mark top as visited;
	}
}

int main() {
	node temp;
	temp.cost = 10;
	temp.at = 2;
	start.AddLast(temp);
}

