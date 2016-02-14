//
// Created by Ferdinand Forgaard on 14.02.2016.
//

#include <string>
#include "Employee.h"

#ifndef OBLIG1_OPPG3_ENGINEER_H
#define OBLIG1_OPPG3_ENGINEER_H

using namespace std;

class Engineer : public Employee{

private:

    bool knowsCPlusPlus;
    int yearsOfExperience;
    string discipline;

public:

    Engineer();
    Engineer(string fn, string ln, double s, bool cpp, int experience, string discipline);

    ~Engineer();
    string toString();
    string toFile();

    bool knowsCplusPlus();
    int getYearsOfExperience();
    string getDiscipline();

    void setKnowsCPlusPlus(bool cpp);
    void setYearsOfExperience(int experience);
    void setDiscipline(string discipline);

};


#endif //OBLIG1_OPPG3_ENGINEER_H
