#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  
ULListStr test = ULListStr(); 

	test.push_back("oldfront");
	test.push_back("oldback");

	//EXPECT_TRUE(checkListContent(&list, {"oldfront", "oldback"}));
  cout << test.get(0) << " " << test.get(1) << endl;
	// this should create an empty slot at the front of the list, and the new element can be put there
	test.pop_front();
	test.push_front("newfront");

	//EXPECT_TRUE(checkListContent(&list, {"newfront", "oldback"}));

  cout << test.get(0) << " " << test.get(1) << endl;
	// now, a new element struct should get created at the front
	test.pop_back();
	test.push_front("cloudfront");

	//EXPECT_TRUE(checkListContent(&list, {"cloudfront", "newfront"}));

  cout << test.get(0) << " " << test.get(1) << endl;

	// now, the original head should get deleted
	test.pop_back();

	//EXPECT_TRUE(checkListContent(&list, {"cloudfront"}));
    cout << test.get(0) << endl;

	test.pop_front();

	//EXPECT_TRUE(checkListContent(&list, {}));

	test.push_front("newback");

	//EXPECT_TRUE(checkListContent(&list, {"newback"}));

    cout << test.get(0) << endl;

/*


test.push_back("");
cout << "size= " << test.size() << endl;
cout << "get= " << test.get(0) << "." << endl;

test.push_front("zero");

test.push_front("one");

test.push_front("two");

test.push_front("three");

test.push_front("four");

test.push_front("five");

test.push_front("six");

test.push_front("seven");

test.push_front("eight");

test.push_front("nine");

test.push_front("ten");

test.push_front("eleven");

cout << "the size of list is now " << test.size() << endl;

cout << test.get(0) << endl; 
cout << test.get(1) << endl;
cout << test.get(2) << endl; 
cout << test.get(3) << endl;
cout << test.get(4) << endl;
cout << test.get(5) << endl;
cout << test.get(6) << endl;
cout << test.get(7) << endl;
cout << test.get(8) << endl;
cout << test.get(9) << endl;
cout << test.get(10) << endl;
cout << test.get(11) << endl; */



}
