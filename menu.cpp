#include <iostream>
#include <fstream>
#include <list>
#include "Assignment.h"
using namespace std;

void displaySubmenu();
void addSubmenu();
void editSubmenu();
void readFile(ifstream& fin, list <Assignment>& completed, list <Assignment>& assigned);

void mainMenu(){
     char menuSelection;
    string file;
    list <Assingment> completed;
    list <Assignment> assigned;
    
    cout << "enter name of file to read assignements from: ";
    getline(cin, file);
    ifstream fin (file);
    readFile(fin, completed, assigned);
    
  while (1){ //Dangerous retard code 
    cout << "\nMAIN MENU\n1. View assignments\t\t2. Add assignments\n"
      << "3. Edit assignments\t\t4. Complete assignments\n"
      << "5. Check late assignments\t6. Save\n"
      << "0. Exit\n";
    
    cin >> menuSelection;
    
      switch (menuSelection){
        case '1':
              displaySubmenu();
          break;
        case '2': 
              addSubmenu();
          break;
        case '3':
          editSubmenu();
          break;
        case '4':
              cout << "This is completeing assignments!\n";
              break;
        case '5':
              cout << "This is late assignments!\n";
              break;
        case '6':
              cout << "This is save!\n";
              break;
        case '0':
          return;
        default:
          cin.clear();
          cin.ignore(256, '\n');
          cout << "Invalid selection!\n";
          menuSelection = '0';
          break; //Restarts while(1) loop
    }
  }
}
void editSubmenu(){
  char menuSelection;
  
  while (1){//dangerous retard code    
    cout << "\nGENERIC SUBMENU:\n1. Edit due date\t\t2. Edit description\n"
      << "0. Back\n";
    
    cin >> menuSelection;
    
    switch (menuSelection){
      case '1':
        cout << "This is edit due date!\n";
        break;
    case '2':
            cout << "This is edit description";
            break;
      case '0':
        return;//exit to previous menu
      default:
          cin.clear();
          cin.ignore(256, '\n');
          cout << "Invalid selection!\n";
          menuSelection = '0';
          break; //restarts while(1) loop
    }
  }
}

void displaySubmenu(){
    char menuSelection;
    
    while (1){//dangerous retard code
        cout << "\nGENERIC SUBMENU:\n1. Display completed\t\t2. Display assigned\n"
        << "0. Back\n";
        
        cin >> menuSelection;
        
        switch (menuSelection){
            case '1':
                cout << "This is display completed!\n";
                break;
            case '2':
                cout << "This is display assigned!\n";
                break;
            case '0':
                return;//exit to previous menu
            default:
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid selection!\n";
                menuSelection = '0';
                break; //restarts while(1) loop
        }
    }
}

void addSubmenu(){/
    char menuSelection;
    
    while (1){//dangerous retard code
        cout << "\nGENERIC SUBMENU:\n1. Add completed\t\t2. Add assigned\n"
        << "0. Back\n";
        
        cin >> menuSelection;
        
        switch (menuSelection){
            case '1':
                cout << "This is add completed!\n";
                break;
            case '2':
                cout << "This is add assigned!\n";
                break;
            case '0':
                return;//exit to previous menu
            default:
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid selection!\n";
                menuSelection = '0';
                break; //restarts while(1) loop
        }
    }
}
void readFile(ifstream& fin, list <Assignment>& completed, list <Assignment>& assigned){
    //Get line, parse info, add to appropriate list
}