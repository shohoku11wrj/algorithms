#include <fstream>
#include "MyString.h"
#include "PriorityQueue_SmallHead.h"

ofstream output;
int main () {
	output.open("../data/demo_PriorityQueue.out");

	// Create two MyString objects.
	PriorityQueue_SmallHead<int> int_q;
	PriorityQueue_SmallHead<MyString> str_q;
	
	// USING Insert FUNCTION
	output<< "Demonstrating Insert which adds a given integer" << endl
		<< "Add one after another the following integers "
		<< endl << "to int_q using the Insert function. " << endl
		<< endl << "10, 40, 50, 3, 5, 10" <<endl << endl;
	int_q.Insert(10);
	int_q.Insert(40);
	int_q.Insert(50);
	int_q.Insert(3);
	int_q.Insert(5);
	int_q.Insert(10);
	output<< "Demonstrating Insert which adds a given String object" << endl
		<< "Add one after another the following strings "
		<< endl << "to int_q using the Insert function. " << endl
		<< endl << " \"Hello:3\" , \"Hello:4\" ,\"Hello:1\" , \"Hello:2\" "
		<< endl << endl;
	str_q.Insert("Hello:3");
	str_q.Insert("Hello:4");
	str_q.Insert("Hello:1");
	str_q.Insert("Hello:2");
	output<< "Demonstrating DeleteMax which removes the largest string from str_q"
		<< endl << endl;
	while (! str_q.IsEmpty()) {
		output << str_q.DeleteMin() << endl;
	}
	output << endl;
	output << "str_q must now be empty" << endl;
	if ( str_q.IsEmpty() ) {
		output << "TRUE" << endl << endl;
	}
	output<< "Demonstrating DeleteMax which removes the largest integer from int_q"
		<< endl << endl;
	while (! int_q.IsEmpty()) {
		output << int_q.DeleteMin() << endl;
	}
	output << endl;
	output << "int_q must now be empty" << endl;
	if ( int_q.IsEmpty() ) {
		output << "TRUE" << endl << endl;
	}
	output.close();

	return 0;
}
