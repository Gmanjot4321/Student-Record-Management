#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    string studentID;
    string phoneNumber;
    double gpa;

public:
    // Constructors
    Student();
    Student(string a, string b = "Williams", string c = "3456789545",
        string d = "6004-555-5555", double e = 4.0);

    // Getters
    string getFirstName() const;
    string getLastName() const;
    string getStudentID() const;
    string getPhoneNumber() const;
    double getGpa() const;

    // Setters
    void setFirstName(const string& a);
    void setLastName(const string& b);
    void setStudentID(const string& c);
    void setPhoneNumber(const string& d);
    void setGpa(double e);

    // I/O
    void input();
    void output() const;
    void save(ofstream& out) const;
    void load(ifstream& in);
};

#endif
