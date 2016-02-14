//
// Created by Ferdinand Forgaard on 14.02.2016.
//

#include <iostream>
#include <sstream>
#include "Manager.h"

Manager::Manager() {

}

Manager::Manager(string fn, string ln, double s, int meetings, int holidays) : Employee(fn, ln, s) {
    meetingsPerWeek = meetings;
    holidaysPerYear = holidays;
}

Manager::~Manager() {
    cout << "Manager destructed" << endl;
}

string Manager::toString() {
    ostringstream s;
    s << Employee::toString() << "Meetings per week: " << meetingsPerWeek << "\nHoliday-days per year: " << holidaysPerYear << endl;
    return s.str();
}

string Manager::toFile() {
    //TODO
    return Employee::toFile();
}

int Manager::getMeetingsPerWeek() {
    return meetingsPerWeek;
}

int Manager::getHolidaysPerYear() {
    return holidaysPerYear;
}

void Manager::setMeetingsPerWeek(int meetings) {
    meetingsPerWeek = meetings;
}

void Manager::setHolidaysPerYear(int holidays) {
    holidaysPerYear = holidays;
}
