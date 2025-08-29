#include "Course.h"
#include <algorithm>

// Constructors
Course::Course(string c, int s) : code(c), section(s) {}

// Getters/Setters
string Course::getCode() const { return code; }
int Course::getSection() const { return section; }
int Course::getNumStudents() const { return students.size(); }
void Course::setCode(const string& a) { code = a; }
void Course::setSection(int b) { section = b; }

// Student management
void Course::add(const Student& a) { students.push_back(a); }

void Course::display() const {
    cout << "\nList of Students in " << code << " (Section " << section << "):\n\n";
    cout << setw(12) << "First Name"
        << setw(16) << "Last Name"
        << setw(16) << "Student ID"
        << setw(16) << "Phone Number"
        << setw(8) << "GPA" << endl;
    cout << string(70, '-') << endl;
    for (const auto& s : students) s.output();
    cout << endl;
}

// Remove by ID
void Course::removeByID(const string& id) {
    auto it = remove_if(students.begin(), students.end(),
        [&](const Student& s) { return s.getStudentID() == id; });
    if (it != students.end()) {
        students.erase(it, students.end());
        cout << "Removed student with ID " << id << endl;
    }
    else {
        cout << "No student found with ID " << id << endl;
    }
}

// Search 
void Course::displayByFirst(const string& x) const 
{ displayIf([&](const Student& s) { return s.getFirstName() == x; }, "first name " + x); }
void Course::displayByLast(const string& x) const 
{ displayIf([&](const Student& s) { return s.getLastName() == x; }, "last name " + x); }
void Course::displayByID(const string& x) const 
{ displayIf([&](const Student& s) { return s.getStudentID() == x; }, "ID " + x); }
void Course::displayByPhone(const string& x) const 
{ displayIf([&](const Student& s) { return s.getPhoneNumber() == x; }, "phone " + x); }

// Sorting
void Course::sortByFirstAsc() { sort(students.begin(), students.end(), [](auto& a, auto& b) { return a.getFirstName() < b.getFirstName(); }); }
void Course::sortByFirstDes() { sort(students.begin(), students.end(), [](auto& a, auto& b) { return a.getFirstName() > b.getFirstName(); }); }

void Course::sortByLastAsc() { sort(students.begin(), students.end(), [](auto& a, auto& b) { return a.getLastName() < b.getLastName(); }); }
void Course::sortByLastDes() { sort(students.begin(), students.end(), [](auto& a, auto& b) { return a.getLastName() > b.getLastName(); }); }

void Course::sortByIDAsc() { sort(students.begin(), students.end(), [](auto& a, auto& b) { return a.getStudentID() < b.getStudentID(); }); }
void Course::sortByIDDes() { sort(students.begin(), students.end(), [](auto& a, auto& b) { return a.getStudentID() > b.getStudentID(); }); }

void Course::sortByPhoneAsc() { sort(students.begin(), students.end(), [](auto& a, auto& b) { return a.getPhoneNumber() < b.getPhoneNumber(); }); }
void Course::sortByPhoneDes() { sort(students.begin(), students.end(), [](auto& a, auto& b) { return a.getPhoneNumber() > b.getPhoneNumber(); }); }

void Course::sortByGPAAsc() { sort(students.begin(), students.end(), [](auto& a, auto& b) { return a.getGpa() < b.getGpa(); }); }
void Course::sortByGPADes() { sort(students.begin(), students.end(), [](auto& a, auto& b) { return a.getGpa() > b.getGpa(); }); }

// File I/O
void Course::saveToFile(const string& filename) const {
    ofstream out(filename);
    if (!out) { cerr << "Error opening file for writing\n"; return; }
    out << code << '\n' << section << '\n' << students.size() << '\n';
    for (const auto& s : students) s.save(out);
}

void Course::loadFromFile(const string& filename) {
    ifstream in(filename);
    if (!in) { cerr << "Error opening file for reading\n"; return; }
    students.clear();
    size_t n;
    in >> code >> section >> n;
    in.ignore();
    for (size_t i = 0;i < n;++i) {
        Student s;
        s.load(in);
        students.push_back(s);
    }
}

// Template for search
template <typename Func>
void Course::displayIf(Func condition, const string& msg) const {
    bool found = false;
    for (const auto& s : students) {
        if (condition(s)) { s.output(); found = true; }
    }
    if (!found) cout << "No record found for " << msg << endl;
}
