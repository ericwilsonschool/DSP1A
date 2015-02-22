#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "Date.h"
#include <string>
using namespace std;

struct Assignment{
    Date assigned;
    Date dueDate;
    Date completed;//The assignment doesn't specifically call for this
    string description;
	enum Status {ASSIGNED, COMPLETED, LATE};
	Status status;

	Assignment()
	{
		assigned = "20150101";
		dueDate = "20151231";
		completed = "20150817";
		description = "Empty constructor";
		status = ASSIGNED;
	}
	Assignment(Date p_assigned, Date p_due, string p_description, Assignment::Status p_status)
	{
		assigned = p_assigned;
		dueDate = p_due;
		description = p_description;
		status = p_status;
	}
};
#endif