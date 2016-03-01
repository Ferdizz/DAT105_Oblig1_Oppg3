//
// Created by Ferdinand Forgaard on 14.02.2016.
//

#include <iostream>
#include <sstream>
#include "Engineer.h"

Engineer::Engineer() {

}

Engineer::Engineer(string fn, string ln, double s, bool cpp, int experience, string discipline) : Employee(fn, ln, s) {
    this->knowsCPlusPlus = cpp;
    this->yearsOfExperience = experience;
    this->discipline = discipline;
}

Engineer::~Engineer() {
    cout << "Engineer destructed" << endl;
}

string Engineer::toString() {
    ostringstream s;
    s << Employee::toString() << "Knows C++? " << (knowsCPlusPlus ? "Yes" : "No") << "\nYears of experience: " << yearsOfExperience << "\nDiscipline: " << discipline << endl;
    return s.str();
}

string Engineer::toFile() {
    ostringstream s;
    s << Employee::toFile() << "engineer\n" << (knowsCPlusPlus ? "yes" : "no") << endl << yearsOfExperience << endl <<
    discipline << endl;
    return s.str();
}


bool Engineer::knowsCplusPlus() {
    return knowsCPlusPlus;
}

int Engineer::getYearsOfExperience() {
    return yearsOfExperience;
}

string Engineer::getDiscipline() {
    return discipline;
}

void Engineer::setKnowsCPlusPlus(bool cpp) {
    knowsCPlusPlus = cpp;
}

void Engineer::setYearsOfExperience(int experience) {
    yearsOfExperience = experience;
}

void Engineer::setDiscipline(string discipline) {
    this->discipline = discipline;
}
