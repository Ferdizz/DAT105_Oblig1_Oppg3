//
// Created by Ferdinand Forgaard on 14.02.2016.
//

#include <iostream>
#include <sstream>
#include "Researcher.h"

Researcher::Researcher() {

}

Researcher::Researcher(string fn, string ln, double s, string graduatedAt, string thesisTitle) : Employee(fn, ln, s) {
    this->graduatedAt = graduatedAt;
    this->thesisTitle = thesisTitle;
}

Researcher::~Researcher() {
    cout << "Researcher destructed" << endl;
}


string Researcher::toString() {
    ostringstream s;
    s << Employee::toString() << "Graduated at: " << graduatedAt << "\nThesis title: " << thesisTitle << endl;
    return s.str();
}

string Researcher::toFile() {
    //TODO
    return Employee::toString();
}


string Researcher::getGraduatedAt() {
    return graduatedAt;
}

string Researcher::getThesisTitle() {
    return thesisTitle;
}

void Researcher::setGraduatedAt(string graduatedAt) {
    this->graduatedAt = graduatedAt;
}

void Researcher::setThesisTitle(string thesisTitle) {
    this->thesisTitle = thesisTitle;
}
