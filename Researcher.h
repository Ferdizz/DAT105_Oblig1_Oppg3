//
// Created by Ferdinand Forgaard on 14.02.2016.
//

#include <string>
#include "Employee.h"

#ifndef OBLIG1_OPPG3_RESEARCHER_H
#define OBLIG1_OPPG3_RESEARCHER_H

using namespace std;

class Researcher : public Employee {

private:

    string graduatedAt;
    string thesisTitle;

public:

    Researcher();
    Researcher(string fn, string ln, double s, string graduatedAt, string thesisTitle);
    ~Researcher();

    string toString();
    string toFile();

    string getGraduatedAt();
    string getThesisTitle();

    void setGraduatedAt(string graduatedAt);
    void setThesisTitle(string thesisTitle);

};


#endif //OBLIG1_OPPG3_RESEARCHER_H
