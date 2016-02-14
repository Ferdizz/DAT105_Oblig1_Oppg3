#include <iostream>
#include <vector>
#include "Employee.h"
#include "Manager.h"
#include "Engineer.h"
#include "Researcher.h"

using namespace std;

void addEmployee();
void deleteEmployee();
void saveDatabase();
void restoreDatabase();
void listEmployees();

vector<Employee> db;

int main() {

    bool quit = false;
    int choice = 6;

    while(!quit){

        cout << "\nEmployee database - Home:\n" << "1) Add an Employee\n"
        << "2) Delete an Employee\n" << "3) Save database\n" << "4) Restore database\n"
        << "5) List Employees\n" << "6) Exit\n" << endl << "Select an action: ";

        cin >> choice;

        switch (choice){
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                saveDatabase();
                break;
            case 4:
                restoreDatabase();
                break;
            case 5:
                listEmployees();
                break;
            case 6:
                quit = true;
                break;
        }

    }

    return 0;
}

void addEmployee(){
    char choice = 'd';
    string fn, ln;
    double s;

    cout << "\nEmployee database - Add Employee:\n" << "a) Add a Manager\n"
    << "b) Add an Engineer\n" << "c) Add a Researcher\n" << "d) Cancel\n" << endl
            << "Select an action: ";

    cin >> choice;

    if(choice == 'd'){
        return;
    }

    cout << "\nEnter the following information:\n" << "First name: ";
    cin >> fn;
    cout << "Last name: ";
    cin >> ln;
    cout << "Salary: ";
    cin >> s;

    if(choice == 'a'){

        int meetings, holidays;
        cout << "Number of meetings per week: ";
        cin >> meetings;
        cout << "Number of holiday-days per year: ";
        cin >> holidays;

        Employee *manager = new Manager(fn, ln, s, meetings, holidays);
        db.push_back(*manager);

        cout << "Manager added to database!" << endl;

    }else if(choice == 'b'){

        char cpp;
        int experience;
        string discipline;
        cout << "Knows C++? (Y or N): ";
        cin >> cpp;
        cout << "Years of experience: ";
        cin >> experience;
        cout << "Discipline: ";
        cin >> discipline;

        Employee *engineer = new Engineer(fn, ln, s, (cpp == 'Y' ? true : false),
                                          experience, discipline);
        db.push_back(*engineer);

        cout << "Engineer added to database!" << endl;

    }else if(choice == 'c'){

        string graduatedAt, thesisTitle;
        cout << "Graduated at: ";
        cin >> graduatedAt;
        cout << "Thesis title: ";
        cin >> thesisTitle;

        Employee *researcher = new Researcher(fn, ln, s, graduatedAt, thesisTitle);
        db.push_back(*researcher);

        cout << "Researcher added to database!" << endl;

    }else{
        return;
    }
}

void deleteEmployee(){

    bool deleted = false;
    string ln;
    cout << "Enter the last name of the employee you want to delete: ";
    cin >> ln;

    for(int i = 0; i < db.size(); i++){
        if(db[i].getLastName() == ln){
            delete db[i];
            db.erase(db.begin() + i);
            deleted = true;
            cout << "Employee deleted!" << endl;
            break;
        }
    }

    if(!deleted){
        cout << "Did not find an employee with the given last name." << endl;
    }

};

void saveDatabase(){

};

void restoreDatabase(){

};

void listEmployees(){
    for(int i = 0; i < db.size(); i++){
        db[i].toString();
    }
};