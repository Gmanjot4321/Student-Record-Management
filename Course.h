#pragma once
#ifndef COURSE_H
#define COURSE_H

#include "Student.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Course {
private:
    string code;
    int section;
    vector<Student> students;

public:
    // Constructors
    Course(string c = "CMPT", int s = 1);

    // Getters/Setters
    string getCode() const;
    int getSection() const;
    int getNumStudents() const;
    void setCode(const string& a);
    void setSection(int b);

    // Student management
    void add(const Student& a);
    void display() const;

    // Generic search
    template <typename Func>
    void displayIf(Func condition, const string& msg) const;

    void displayByFirst(const string& x) const;
    void displayByLast(const string& x) const;
    void displayByID(const string& x) const;
    void displayByPhone(const string& x) const;

    void removeByID(const string& id);

    // Sorting
    void sortByFirstAsc();
    void sortByFirstDes();
    void sortByLastAsc();
    void sortByLastDes();
    void sortByIDAsc();
    void sortByIDDes();
    void sortByPhoneAsc();
    void sortByPhoneDes();
    void sortByGPAAsc();
    void sortByGPADes();

    // File I/O
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif
