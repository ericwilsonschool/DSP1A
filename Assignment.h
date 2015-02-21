#include "Date.h"
#include <string>
using namespace std;

struct Assignment{
    Date assigned;
    Date due;
    Date completed;
    string description;
    bool isLate;
    
    Assignment() : assigned(1,1,2015), due(12,30,2015), completed(8,17,2015), description("Empty constructor"), isLate(false)
    Assignment(Date p_assigned, Date p_due, Date p_completed, string p_description, bool p_isLate) : assigned(p_assigned), due(p_due), completed(p_completed), description(p_description), isLate(p_isLate)
};

