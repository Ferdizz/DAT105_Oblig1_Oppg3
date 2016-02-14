//
// Created by Ferdinand Forgaard on 14.02.2016.
//

#ifndef OBLIG1_OPPG3_MANAGER_H
#define OBLIG1_OPPG3_MANAGER_H


#include "Employee.h"

class Manager : public Employee{

private:

    int meetingsPerWeek;
    int holidaysPerYear;

public:

    Manager();
    Manager(string fn, string ln, double s, int meetings, int holidays);

    ~Manager();
    string toString();
    string toFile();

    int getMeetingsPerWeek();
    int getHolidaysPerYear();

    void setMeetingsPerWeek(int meetings);
    void setHolidaysPerYear(int holidays);

};


#endif //OBLIG1_OPPG3_MANAGER_H
