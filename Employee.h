//
// Created by Ferdinand Forgaard on 14.02.2016.
//

#include <string>

#ifndef OBLIG1_OPPG3_EMPLOYEE_H
#define OBLIG1_OPPG3_EMPLOYEE_H

using namespace std;

class Employee {

private:

    string firstname;
    string lastname;
    double salary;

public:

    Employee();
    Employee(string firstname, string lastname, double salary);

    virtual ~Employee();
    virtual string toString();
    virtual string toFile();

    string getFirstName();
    string getLastName();
    double getSalary();

    void setFirstName(string fn);
    void setLastName(string ln);
    void setSalary(double s);

};


#endif //OBLIG1_OPPG3_EMPLOYEE_H
