#include "Student.h"

// Constructors
Student::Student() : firstName(""), lastName(""), studentID(""), phoneNumber(""), gpa(0.0) {}
Student::Student(string a, string b, string c, string d, double e)
    : firstName(a), lastName(b), studentID(c), phoneNumber(d), gpa(e) {
}

// Getters
string Student::getFirstName() const { return firstName; }
string Student::getLastName() const { return lastName; }
string Student::getStudentID() const { return studentID; }
string Student::getPhoneNumber() const { return phoneNumber; }
double Student::getGpa() const { return gpa; }

// Setters
void Student::setFirstName(const string& a) { firstName = a; }
void Student::setLastName(const string& b) { lastName = b; }
void Student::setStudentID(const string& c) { studentID = c; }
void Student::setPhoneNumber(const string& d) { phoneNumber = d; }
void Student::setGpa(double e) { gpa = e; }

// Input/output
void Student::input() {
    cout << "Enter student details:\n";
    cout << "First Name: "; getline(cin, firstName);
    cout << "Last Name: "; getline(cin, lastName);
    cout << "Student ID: "; getline(cin, studentID);
    cout << "Phone Number: "; getline(cin, phoneNumber);
    cout << "GPA: "; cin >> gpa; cin.ignore();
}

void Student::output() const {
    cout << setw(12) << firstName
        << setw(16) << lastName
        << setw(16) << studentID
        << setw(16) << phoneNumber
        << setw(8) << gpa << endl;
}

// File I/O
void Student::save(ofstream& out) const {
    out << firstName << '\n' << lastName << '\n'
        << studentID << '\n' << phoneNumber << '\n'
        << gpa << '\n';
}

void Student::load(ifstream& in) {
    getline(in, firstName);
    getline(in, lastName);
    getline(in, studentID);
    getline(in, phoneNumber);
    in >> gpa;
    in.ignore();
}
