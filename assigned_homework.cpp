#include "Date.h"
#include "Assignment.h"
#include <list>
#include <string>
#include <iostream>
#incldue <fstream>
using namespace std;

class assigned_homework{
    public:
    assigned_homework (){
        list <Assignments> a_list;
    }
    
    assigned_homework (list <Assignments> passed_list){
        list <Assignments> a_list;
        for(list<Assignments> :: iterator iter = passed_list.begin(); iter != passed_list.end(); iter++){
            a_list.push_back(*iter);
        }
    }
    
    void display (const list <Assignment> a_list){
        for(list <Assignment> :: iterator iter = a_list.begin(); iter != a_list.end(); iter++){
            cout << *iter << endl;
        }
    }
    
    void add (Assignment to_add, list <Assignment> a_list){
        a_list.push_back(to_add);
    }
    
    void move_to_completed (Assignment to_move);
    {
        
    }
    void edit (){
        
    }
    void late (){
        
    }
    void save (){
        
    }
    
  private:
    void order (){
        
    }
};


