#include <fstream>
#include "MyString.h"
#include "SList.h"

ofstream output;

int main() {
    output.open("/home/ranger/algorithms/data/demo_SList.out");

    // Create two MyString objects.
    MyString item1("CS 590WS"), item2("Singly Linked");

    // USING THE DEFAULT CONSTRUCTOR
    output << "Create list1, an empty SList object using" << endl << " the default constructor." << endl << endl;

    SList<MyString> list1;

    // USING AddFirst AND AddLast FUNCTIONS
    output << "Demonstrating AddFirst which adds a given item" << endl << "as the first item of the sequence." << endl << endl << "Add one after another the following two string objects " << endl << "to list1 using the AddFirst function. " << endl << endl << "\"CS 590WS\" and \"Singly Linked\"." << endl << endl;

    list1.AddFirst(item2);
    list1.AddFirst(item1);

    output << "Demonstrating AddLast which adds a given item" << endl << " as the last item of the sequence." << endl << endl << "Add one after another the following two string objects " << endl << "to list1 using the AddLast function. " << endl << endl << "\"List Class\" and \"Functionality\"." << endl << endl;

    list1.AddLast("List Class");
    list1.AddLast("Functionality");

    // USING Add AND Remove FUNCTIONS WITH ITERATORS

    output << "Create an iterator object i1 of type SList::Iterator." << endl << endl;

    SList<MyString>::Iterator i1;

    output << "Show the sequence of items in list1 using i1." << endl << endl;

    for( i1 = list1.Begin(); i1 != list1.End(); i1++ )
        output << *i1 << " ";

    output << endl << endl;

    output << "Reset i1 to point to the first item of list1." << endl;
    i1 = list1.Begin();

    output << "Advance iterator i1 so that it points to the third item." << endl;

    i1++;
    i1++;

    output << "Show the item pointed by i1." << endl << endl;

    output << *i1 << endl << endl;

    output << "Demonstrating AddAfter which adds a given item" << endl << " to list1 at a position referred to by i1." << endl << "Add one after another the following two string objects." << endl << "to list1 using the AddAfter function. " << endl << endl << "\"SList\" and \"Class\"." << endl << endl;

    MyString item3("SList"), item4("Class");

    list1.AddAfter(i1, item3);
    list1.AddAfter(i1, item4);

    output << "Show the sequence of items in list1 using i1." << endl << endl;

    for( i1 = list1.Begin(); i1 != list1.End(); i1++ )
        output << *i1 << " ";

    output << endl << endl;

    output << "Reset i1 to point to the first item of list1." << endl;

    i1 = list1.Begin();

    output << "Advance iterator i1 so that it points to the third item." << endl << endl;

    i1++;
    i1++;

    output << "Demonstrating RemoveAfter which removes the item" << endl << "in list1 at the position referred to by i1." << endl << endl;

    list1.RemoveAfter(i1);

    output << "Show the sequence of items in list1." << endl << endl;

    for(i1 = list1.Begin(); i1 != list1.End(); i1++)
        output << *i1 << " ";

    output << endl << endl;

    // USING THE ASSIGNMENT OPERATOR
    output << "Create list2, an empty SList object." << endl << endl;

    SList<MyString> list2;

    output << "set list2 = list1." << endl << endl;

    list2 = list1;

    // USING ShowFirst, AND RemoveFirst FUNCTIONS

    output << "Show and delete the first item of list2 using " << endl << "ShowFirst and RemoveFirst functions." << endl << endl;

    output << list2.ShowFirst() << endl << endl;
    list2.RemoveFirst();

    // USING SetToEmpty FUNCTION
    output << "Remove all items in list2 using the SetToEmpty functions." << endl << endl;

    list2.SetToEmpty();

    // USING IsEmpty FUNCTION

    output << "Show list2 is empty using the IsEmpty function." << endl << endl;

    if(list2.IsEmpty())
        output << "list2 is empty." << endl << endl;

    // USING ITERATORS TO MODIFY ITEMS IN LIST OBJECTS
    
    output << "Replace the first item of list1 with the string " << endl << "\"Demonstrating\" using the iterator i1." << endl << endl;

    i1 = list1.Begin();
    *i1 = "Demonstrating";

    output << "Show the sequence of items in list1." << endl << endl;

    for(i1 = list1.Begin(); i1 != list1.End(); i1++)
        output << *i1 << " ";
    
    output << endl << endl;

    output.close();

    return 1;
}
