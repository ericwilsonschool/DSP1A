#include "menu.h"

void mainMenu(){
	char menuSelection;
	string file;
	//create lists
	list<Assignment> completed;
	list <Assignment> assigned;
	//open file
	cout << "enter name of file to read assignements from: \n";
	getline(cin, file);
	ifstream fin (file);
	if (fin.good())
		cout << "File " << file << "opened successfully!";
	else
	{
		cout << "File " << file << "could not be opened.";
		return;
	}
	//populate lists from file
	readFile(fin, completed, assigned);

 while (1){ //infinite loop. exits when user selects 0
 	cout << "\nMAIN MENU\n1. View assignments\t\t2. Add assignments\n"
 	<< "3. Edit assignments\t\t4. Complete assignments\n"
 	<< "5. Check late assignments\t6. Save\n"
 	<< "0. Exit\n";

 	cin >> menuSelection;

 	switch (menuSelection){
 		case '1'://View assignments
 		displaySubmenu(completed, assigned);
 		break;
 		case '2': //Add Assignments
 		addSubmenu();
 		break;
 		case '3': //Edit assignments
 		editSubmenu();
 		break;
 		case '4': //Complete Assignments
 		cout << "This is completeing assignments!\n";
 		break;
 		case '5': //Check late assignments
 		cout << "This is late assignments!\n";
 		break;
 		case '6': //Save
 		cout << "This is save!\n";
 		break;
 		case '0': //Exit
 		return;
 		default: //Invalid selection
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

void displaySubmenu(list<Assignment> & completed, list<Assignment>& assigned){
	char menuSelection;

    while (1){//dangerous retard code
    	cout << "\nDISPLAY MENU:\n1. Display completed\t\t2. Display assigned\n"
    	<< "0. Back\n";

    	cin >> menuSelection;

    	switch (menuSelection){
    		case '1':
    		printList(completed);
    		break;
    		case '2':
    		printList(assigned);
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

void addSubmenu(){
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
    string dueDate, description, assignedDate, status;
	string rawString;
//Maybe insert a thing that clears out the lists just in case there's stuff in them for some reason.
    while (!fin.eof())
    {
		getline(fin, rawString);
		parseInput(dueDate, description, assignedDate, status, rawString);

	Date newDue = dueDate;
	Date newAss = assignedDate;
	if (status == "assigned")//decide which list to add to.
	{
		Assignment newAssignment(newAss, newDue, description, Assignment::Status::ASSIGNED);
		assigned.push_back(newAssignment);
	}
	else if (status == "completed")
	{
		Assignment newAssignment(newAss, newDue, description, Assignment::Status::COMPLETED);
		completed.push_back(newAssignment);
	}
	else if (status == "late")
	{
		Assignment newAssignment(newAss, newDue, description, Assignment::Status::LATE);
		completed.push_back(newAssignment);
	}
	else //Print error to console if weird status value is found.
	{
		cout << "File read unsuccessful!\nCould not parse item with status " << status << "!\n";
		return;
	}
}
return;
}

void printList(list<Assignment> assList)//teehee
{
	//check if the list is empty
	if (assList.empty())
	{
		cout << "No assignments found.\n";
		return;
	}
	else
	{	//print collumn headers
		cout << "ASSIGNED   DESCRIPTION             COMPLETED  STATUS\n";
		//iterate through list printing and stuff.
		for (list<Assignment>::iterator iter = assList.begin(); iter != assList.end(); ++iter)
		{
			//Print assigned date and description
			cout << iter->assigned << "   "
			<< setfill(' ') << left
			<< setw(24) << iter->description;
			//print completed date
			if (iter->completed == 0)
				cout << "N/A        ";
			else
				cout << iter->completed << "   ";
			//Print status
			if (iter->status == 0)
				cout << "ASSIGNED";
			else if (iter->status == 1)
				cout << "COMPLETED";
			else if (iter->status == 2)
				cout << "LATE";
			cout << '\n';

		}
	}
}
void parseInput(string& dueDate, string& description, string& assignedDate, string& status, string line)
{
	string tempDate;
	//get the date from the line
	tempDate = line.substr(0, line.find_first_of(','));
	dueDate = parseDate(tempDate);
	//delete first date and ", " from string
	line.erase(0, line.find_first_of(',') + 2);
	//get the description
	description = line.substr(0, line.find_first_of(','));
	
	line.erase(0, line.find_first_of(',') + 2);
	//get the other date
	tempDate = line.substr(0, line.find_first_of(','));
	assignedDate = parseDate(tempDate);
	line.erase(0, line.find_first_of(',') + 2);
	//get the status
	status = line;
	
	return;
	
}

string parseDate(string date)
{
	//create temp variables
	string year, month, day, returnDate;
	month = date.substr(0, date.find_first_of('-'));
	date.erase(0, date.find_first_of('-')+1);
	day = date.substr(0, date.find_first_of('-'));
	date.erase(0, date.find_first_of('-')+1);
	year = date;
	
	if (month.length() < 2)
		month = '0' + month;
	if (day.length() < 2)
		day = '0' + day;
	returnDate = year + month + day;
	cout << returnDate;

	return returnDate; //returns format YYYYMMDD
}