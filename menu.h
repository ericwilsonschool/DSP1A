#ifndef MENU_CPP
#define MENU_CPP

#include <iostream>
#include <fstream>
#include <list>
#include "Assignment.h"
using namespace std;

void mainMenu(); //First thing user sees after opening file
void displaySubmenu(list<Assignment> & completed, list<Assignment>& assigned);//used to view saved assignments
void addSubmenu();
void editSubmenu();
void readFile(ifstream& fin, list <Assignment>& completed, list <Assignment>& assigned);
void printList(list<Assignment> assList);
//splits line from file into its various parts.
void parseInput(string& dueDate, string& description, string& assignedDate, string& status, const string line);
string parseDate(string date);//accepts input of form M-D-Y and returns YYYYMMDD

#endif