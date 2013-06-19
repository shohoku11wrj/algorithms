#include<iostream>

using namespace std;

struct Lnode
{
    int element;
    struct Lnode *next;
};

// the reverse list function code by Renjie Weng
void reverse(Lnode *head, Lnode *tail) {
    Lnode *p, *q;
    tail = head->next;

	p = head->next;
	head->next = 0;
    while( p != 0 ) {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }

	// output reversed list elements:
	cout << "The reversed list elemets are:"  << endl;

	Lnode * cur = head->next; // Changed by Renjie , tail
	while (cur != 0) {
	   cout << cur->element << " ";
	   cur = cur->next;
	}
	cout << endl;
} // end function reverse

int main ()
{
  // create a linked list of 3 nodes with element values 3, 9, 4
	Lnode * head = new Lnode; // Added by Renjie
	head->element = 0; // Added by Renjie
    Lnode * node1_ptr = head->next = new Lnode;
    node1_ptr->element = 3;
    Lnode * node2_ptr = node1_ptr->next = new Lnode;
    node2_ptr->element = 9;
    Lnode * node3_ptr = node2_ptr->next = new Lnode;
    node3_ptr->element = 4;
	node3_ptr->next = 0;

   // output list elements:
    cout << "The list elements are:"  << endl;

    Lnode * cur = head->next; // Changed by Renjie , node1_ptr
    while ( cur != 0 ) {
	    cout << cur->element << " ";
	    cur = cur->next;
    }
    cout << endl;

	// reverse the list using Renjie Weng function
    reverse(head, node3_ptr);

	return 0;
}
