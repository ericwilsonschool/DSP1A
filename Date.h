////AVAILABLE OPERATORS:{=Date, =string, >, <, <=, >=, <<, ==int}
#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
class Date{
private:
	int y, m, d;
public:
	Date();//Default constructor
	Date(const string& str);//Only assigns if string passed is valid date in YYYYMMDD format, requires filtering
		//could use isValidDate() function in Assignment class
	Date(const Date& rhs);
	int toInt()const;//Converts Date object to integer in the form of YYYYMMDD
		//Used in inequality operator functions
	bool isValidString(const string str);//tests validity of date passed as string.

////OPERATORS////{=Date, =string, >, <, <=, >=, <<}
	Date& operator=(const Date& rhs);
	Date& operator=(const string& other);
	bool operator>(const Date& rhs);
	bool operator<(const Date& rhs);
	bool operator<=(const Date& rhs);
	bool operator>=(const Date& rhs);
	friend ostream& operator<< (ostream& out, Date& date);
	bool operator==(const int& other);
};
#endif