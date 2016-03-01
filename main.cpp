#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Employee.h"
#include "Manager.h"
#include "Engineer.h"
#include "Researcher.h"

using namespace std;

void addEmployee();

void addEmployee(vector<string> data);
void deleteEmployee();
void saveDatabase();
void restoreDatabase();
void listEmployees();

vector<Employee*> db;

int main() {

    bool quit = false;
    int choice = 6;

    while(!quit){

        cout << "\nEmployee database - Home:\n" << "1) Add an Employee\n"
        << "2) Delete an Employee\n" << "3) Save database\n" << "4) Restore database\n"
        << "5) List Employees\n" << "6) Exit\n" << endl << "Select an action: ";

        cin >> choice;
        cout << endl;

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

    cout << "Employee database - Add Employee:\n" << "a) Add a Manager\n"
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
        db.push_back(manager);

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
        db.push_back(engineer);

        cout << "Engineer added to database!" << endl;

    }else if(choice == 'c'){

        string graduatedAt, thesisTitle;
        cout << "Graduated at: ";
        cin >> graduatedAt;
        cout << "Thesis title: ";
        cin >> thesisTitle;

        Employee *researcher = new Researcher(fn, ln, s, graduatedAt, thesisTitle);
        db.push_back(researcher);

        cout << "Researcher added to database!" << endl;

    }else{
        return;
    }
}

void addEmployee(vector<string> data) {
    string fname, lname, employeeClass;
    double salary;

    fname = data.at(0);
    lname = data.at(1);

    stringstream(data.at(2)) >> salary;
    employeeClass = data.at(3);

    if (employeeClass == "manager") {

        int meetings = stoi(data.at(4));
        int holidays = stoi(data.at(5));

        Employee *manager = new Manager(fname, lname, salary, meetings, holidays);
        db.push_back(manager);
        return;

    } else if (employeeClass == "engineer") {

        string knowsCPlusPlus = data.at(4);
        int yearsOfExperience = stoi(data.at(5));
        string discipline = data.at(6);

        Employee *engineer = new Engineer(fname, lname, salary, (knowsCPlusPlus == "yes" ? true : false),
                                          yearsOfExperience, discipline);
        db.push_back(engineer);
        return;

    } else if (employeeClass == "researcher") {

        string graduatedAt = data.at(4);
        string thesisTitle = data.at(5);

        Employee *researcher = new Researcher(fname, lname, salary, graduatedAt, thesisTitle);
        db.push_back(researcher);
        return;

    } else {

        cout << "ERROR: Something went wrong while adding employee from datafile!" << endl;
        return;

    }

}

void deleteEmployee(){

    bool deleted = false;
    string ln;
    cout << "Enter the last name of the employee you want to delete: ";
    cin >> ln;

    for(int i = 0; i < db.size(); i++){
        if(db[i]->getLastName() == ln){
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
    string filename = "db.txt";

    cout << "Save database as: ";
    cin >> filename;

    ofstream db_file(filename);

    if (db_file.is_open()) {

        for (int i = 0; i < db.size(); i++) {
            db_file << db[i]->toFile() << ";;\n";
        }

        db_file.close();

        cout << "Database successfully saved to " << filename << "!" << endl;

    } else {
        cout << "Unable to open file!" << endl;
    }

};

void restoreDatabase(){

    string line, filename;
    vector<string> employeeData;

    cout << "Enter filename: ";
    cin >> filename;

    ifstream db_file(filename);

    if (db_file.is_open()) {

        while (getline(db_file, line)) {

            if (line == ";;") {
                addEmployee(employeeData);
                employeeData.clear();
            } else {
                employeeData.push_back(line);
            }

        }
        db_file.close();

    } else {
        cout << "Unable to open file!" << endl;
    }

};

void listEmployees(){
    if (!db.empty()) {
        cout << "List of registered employees:\n-----------------------------" << endl;
        for (int i = 0; i < db.size(); i++) {
            cout << "Employee #" << (i + 1) << ":\n";
            cout << db[i]->toString() << endl;
        }
    } else {
        cout << "No employees saved in database!" << endl;
    }
};