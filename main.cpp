#include "menu.h"
#include "Date.h"
#include <list>

using namespace std;

//Function Prototypes
void testDate();

int main()
{
	cout << "DSProject1A: Homework Tracker\n";

	//testDate();
    mainMenu();
	system("pause");
	return 0;
}

void testDate()
{
	Date test1;//test default constructor
	Date test2 = "20150211";//test assignment from string constructor

	cout << "test1: " << test1 << '\n';
	//test stream insertion
		//Exp: 00000000
	cout << "test2: " << test2 << '\n';
	//test stream insertion
		//Exp: 20150211
	cout << "test1 > test2: " << (test1 > test2) << '\n';
	//test > operator
		//Exp: 1
	cout << "test1 < test2: " << (test1 < test2) << '\n';
	//test < operator
		//Exp: 0
	cout << "test1 >= test2: " << (test1 >= test2) << '\n';
	//test >= operator
		//Exp: 1
	cout << "test1 <= test2: " << (test1 <= test2) << '\n';
	//test <= operator
		//Exp: 0

	test1 = "20010911";
	//test assignment from string operator
	test2 = test1;
	//test assignment from Date operator
	cout << "test1: " << test1 << "\ntest2: " << test2 << '\n';
	//test for successful assignment
		// Exp: test1: 20010911
			  //test2: 20010911

	cout << "test1 > test2: " << (test1 > test2) << '\n';
	//test > operator
	//Exp: 0
	cout << "test1 < test2: " << (test1 < test2) << '\n';
	//test < operator
	//Exp: 0
	cout << "test1 >= test2: " << (test1 >= test2) << '\n';
	//test >= operator
	//Exp: 1
	cout << "test1 <= test2: " << (test1 <= test2) << '\n';
	//test <= operator
	//Exp: 1

	//Total expected output of testDate()
		//test1: 00000000
		//test2: 20150211
		//test1 > test2: 1
		//test1 < test2: 0
		//test1 >= test2: 1
		//test1 <= test2: 0
		//test1: 20010911
		//test2: 20010911
		//test1 > test2: 0
		//test1 < test2: 0
		//test1 >= test2: 1
		//test1 <= test2: 1
}
