#include "menu.h"

void mainMenu(){
     char menuSelection;
    string file;
    list<Assignment> completed;
    list <Assignment> assigned;
    
    cout << "enter name of file to read assignements from: ";
    getline(cin, file);
    ifstream fin (file);
	if (fin.good())
		cout << "File " << file << "opened successfully!";
	else
	{
		cout << "File " << file << "could not be opened.";
		return;
	}

    readFile(fin, completed, assigned);
    
 while (1){ //Dangerous retard code 
    cout << "\nMAIN MENU\n1. View assignments\t\t2. Add assignments\n"
      << "3. Edit assignments\t\t4. Complete assignments\n"
      << "5. Check late assignments\t6. Save\n"
      << "0. Exit\n";
    
    cin >> menuSelection;
    
      switch (menuSelection){
        case '1':
              displaySubmenu(completed, assigned);
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
	//Maybe insert a thing that clears out the lists just in case there's stuff in them for some reason.
	while (!fin.eof())
	{
		fin >> dueDate >> description >> assignedDate >> status;//read in line of data
		cout << dueDate << ' ' << description << ' ' << assignedDate << ' ' << status << '\n';

		Date newDue = dueDate;
		Date newAss = assignedDate;
		if (status == "ASSIGNED")
		{
			Assignment newAssignment(newAss, newDue, description, Assignment::Status::ASSIGNED);
			assigned.push_back(newAssignment);
		}
		else if (status == "COMPLETED")
		{
			Assignment newAssignment(newAss, newDue, description, Assignment::Status::COMPLETED);
			completed.push_back(newAssignment);
		}
		else if (status == "LATE")
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

void printList(list<Assignment> assList)
{
	if (assList.empty())
	{
		cout << "No assignments found.\n";
		return;
	}
	else
	{
		cout << "ASSIGNED   DESCRIPTION             COMPLETED  STATUS\n";
		for (list<Assignment>::iterator iter = assList.begin(); iter != assList.end(); ++iter)
		{
			//setfill and stuff doesn't work on my date class at the moment
			cout << iter->assigned << "   "
				<< setfill(' ') << left
				<< setw(24) << iter->description;
			if (iter->completed == 0)
				cout << "N/A        ";
			else
				cout << iter->completed << "   ";
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