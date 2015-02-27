#ifndef MENU_CPP
#define MENU_CPP

#include <iostream>
#include <fstream>
#include <list>
#include "Assignment.h"
using namespace std;

void mainMenu();
void displaySubmenu(list<Assignment> & completed, list<Assignment>& assigned);
void addSubmenu();
void editSubmenu();
void readFile(ifstream& fin, list <Assignment>& completed, list <Assignment>& assigned);
void printList(list<Assignment> assList);
void parseInput(string& dueDate, string& description, string& assignedDate, string& status, const string line);
string parseDate(string date);//accepts input of form M-D-Y and returns YYYYMMDD

#endif