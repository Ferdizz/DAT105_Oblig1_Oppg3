//
// Created by Ferdinand Forgaard on 14.02.2016.
//

#include <iostream>
#include <sstream>
#include "Employee.h"


Employee::Employee() {
    //TODO
}

Employee::Employee(string firstname, string lastname, double salary) {
    this->firstname = firstname;
    this->lastname = lastname;
    this->salary = salary;
}

Employee::~Employee() {
    //TODO
    cout << "Employee destructed" << endl;
}


string Employee::getFirstName() {
    return firstname;
}

string Employee::getLastName() {
    return lastname;
}

double Employee::getSalary() {
    return salary;
}

void Employee::setFirstName(string fn) {
    firstname = fn;
}

void Employee::setLastName(string ln) {
    lastname = ln;
}

void Employee::setSalary(double s) {
    salary = s;
}


string Employee::toString() {
    ostringstream s;
    s << "First name: " << firstname << "\nLast name: " << lastname << "\nSalary: " << salary << endl;
    return s.str();
}

string Employee::toFile() {
    //TODO
    return "";
}
