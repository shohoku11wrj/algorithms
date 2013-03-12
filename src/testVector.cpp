#include <fstream>
#include "MyString.h"
#include "Vector.h"

ofstream output;

int main() 
{
	output.open("../data/demo_Vector.out");

	// Create two String objects
	MyString items1("CS 590WS"), items("Course Material");

	// Using the Default Constructor
	output << "Create array1, an empty Vector object with a default"
		<< endl << "storage capacity = 10, using the default"
		<< " constructor." << endl << endl;

	Vector<MyString> array1;

	// Using AddLast Function
	output << "Demonstrating AddLast, a useful member function, which"
		<< endl << "adds a given item as the last item of the"
		<< endl << "sequence." << endl << endl
		<< "Add one after another the following four string objects"
		<< endl << "to array1 using the AddLast function. "
		<< endl
		<< "CS 590WS, Course Material, Using, Vectors."
		<< endl;

	array1.AddLast(items1);
	array1.AddLast(items);
	array1.AddLast("Using");
	array1.AddLast("Vectors");

	// Using the subscript operator (operator[])
	output << "Show the sequence of items in array1 using operator []."
		<< endl << endl;
	
	output << array1.NumberOfItems() << endl <<endl;

	// Creating Vector objects of specified capacity
	output << "Create array2, an empty Vector object" << endl
		<< "of a specified storage capacity, say 5."
		<< endl << endl;

	Vector<MyString> array2(5);

	// Using the assignment operator (operator=)
	output << "set array2=array1." << endl << endl;

	array2 = array1;

	// USING GetLast AND RemoveLast FUNCTIONS
	output << "Show and delete the last item of array 2 using "
		<< endl << "ShowLast and RemoveLast functions."
		<< endl << endl;

	output << array2.ShowLast() << endl << endl;

	array2.RemoveLast();

	output << "Show the number of items in array2 using NumberOfItems."
		<< endl << endl;
	output << array2.NumberOfItems() << endl << endl;

	// Using RemoveAll function
	output << "Remove all items in array2 using RemoveAll."
		<< endl << endl;

	array2.RemoveAll();

	// USING IsEmpty FUNCTION
	output << "Show array2 is empty using IsEmpty."
		<< endl << endl;

	if ( array2.IsEmpty() )
		output << "array2 is empty." << endl << endl;

	output << "reset array2 = array1." << endl << endl;

	array2 = array1;

	// USING Resize FUNCTION
	output << "Resize array2 so that its storage capacity = 2." << endl
		<< "Thus array2 gets truncated retaining its" << endl
		<< "first 2 items only." << endl << endl;
	
	array2.Resize(2);
	
	output << "Show number of items in array2 using NumberOfItems."
		<< endl << endl;
	
	output << array2.NumberOfItems() << endl << endl;
	
	output.close();

	return 0;
}
