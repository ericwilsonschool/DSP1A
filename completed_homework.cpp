#include "Date.h"
#include "Assignment.h"
#include <list>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class completed_homework {
  public:
    completed (){
        list <Assignment> c_list;
    }
    
    void display (const list <Assignment> c_list){
        for(list <Assignment> :: iterator iter = c_list.begin(); iter != c_list.end(); iter++){
            cout << *iter << endl;
        }
    }
    
    void add (Assignment to_add, list <Assignment> c_list){
        c_list.push_back(to_add);
    }
    void save (){
        
    }
    
  private:
    void order (){
        
    }
};
