#include <fstream>
#include "MyString.h"
#include <queue>
using namespace std;

ofstream output;
int main () {
	output.open("../data/demo_PriorityQueue.out");

	// Create two MyString objects.
	priority_queue<int> int_q;
	priority_queue<MyString> str_q;
	
	// USING Insert FUNCTION
	output<< "Demonstrating Insert which adds a given integer" << endl
		<< "push one after another the following integers "
		<< endl << "to int_q using the Insert function. " << endl
		<< endl << "10, 40, 50, 3, 5, 10" <<endl << endl;
	int_q.push(10);
	int_q.push(40);
	int_q.push(50);
	int_q.push(3);
	int_q.push(5);
	int_q.push(10);
	output<< "Demonstrating push which adds a given String object" << endl
		<< "push one after another the following strings "
		<< endl << "to int_q using the push function. " << endl
		<< endl << " \"Hello:3\" , \"Hello:4\" ,\"Hello:1\" , \"Hello:2\" "
		<< endl << endl;
	str_q.push("Hello:3");
	str_q.push("Hello:4");
	str_q.push("Hello:1");
	str_q.push("Hello:2");
	output<< "Demonstrating pop which removes the largest string from str_q"
		<< endl << endl;
	while (! str_q.empty()) {
		output << str_q.top() << endl;
		str_q.pop();
	}
	output << endl;
	output << "str_q must now be empty" << endl;
	if ( str_q.empty() ) {
		output << "TRUE" << endl << endl;
	}
	output<< "Demonstrating pop which removes the largest integer from int_q"
		<< endl << endl;
	while (! int_q.empty()) {
		output << int_q.top() << endl;
		int_q.pop();
	}
	output << endl;
	output << "int_q must now be empty" << endl;
	if ( int_q.empty() ) {
		output << "TRUE" << endl << endl;
	}
	output.close();

	return 0;
}
