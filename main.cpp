#include "Course.h"
#include "Student.h"
#include <iostream>
using namespace std;

// Function prototypes
void displayMenu();
void addStudent(Course& c);
void removeStudent(Course& c);
void searchStudent(Course& c, int field);
void sortStudents(Course& c);
void fileOperations(Course& c, bool save);

int main() {
    Course myCourse("ENGL1130", 5);
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice; cin.ignore();

        switch (choice) {
        case 1: addStudent(myCourse); break;
        case 2: removeStudent(myCourse); break;
        case 3: myCourse.display(); break;
        case 4: case 5: case 6: case 7: searchStudent(myCourse, choice); break;
        case 8: sortStudents(myCourse); break;
        case 9: fileOperations(myCourse, true); break;
        case 10: fileOperations(myCourse, false); break;
        case 0: cout << "\nExiting program...\n"; break;
        default: cout << "\nInvalid choice, try again.\n"; break;
        }
    } while (choice != 0);

    return 0;
}

// Menu display
void displayMenu() {
    cout << "\n==================== Student Management Menu ====================\n";
    cout << "1. Add student\n";
    cout << "2. Remove student by ID\n";
    cout << "3. Display all students\n";
    cout << "4. Search by first name\n";
    cout << "5. Search by last name\n";
    cout << "6. Search by ID\n";
    cout << "7. Search by phone\n";
    cout << "8. Sort students\n";
    cout << "9. Save to file\n";
    cout << "10. Load from file\n";
    cout << "0. Exit\n";
    cout << "=================================================================\n";
}

// Add student
void addStudent(Course& c) {
    Student s;
    s.input();
    c.add(s);
}

// Remove student
void removeStudent(Course& c) {
    string id;
    cout << "Enter student ID to remove: ";
    getline(cin, id);
    c.removeByID(id);
}

// Search student
void searchStudent(Course& c, int field) {
    string val;
    switch (field) {
    case 4: {
        cout << "Enter first name: ";
        getline(cin, val);
        c.displayByFirst(val);
        break;
    }
    case 5: {
        cout << "Enter last name: ";
        getline(cin, val);
        c.displayByLast(val);
        break;
    }
    case 6: {
        cout << "Enter ID: ";
        getline(cin, val);
        c.displayByID(val);
        break;
    }
    case 7: {
        cout << "Enter phone: ";
        getline(cin, val);
        c.displayByPhone(val);
        break;
    }
    }
}

// Sort student
void sortStudents(Course& c) {
    cout << "Sort by:\n1.First Name 2.Last Name 3.ID 4.Phone 5.GPA\nChoice: ";
    int f; cin >> f;
    cout << "Sort order: 1.Ascending 2.Descending\nChoice: ";
    int o; cin >> o; cin.ignore();
    bool asc = (o == 1);
    switch (f) {
    case 1: asc ? c.sortByFirstAsc() : c.sortByFirstDes(); break;
    case 2: asc ? c.sortByLastAsc() : c.sortByLastDes(); break;
    case 3: asc ? c.sortByIDAsc() : c.sortByIDDes(); break;
    case 4: asc ? c.sortByPhoneAsc() : c.sortByPhoneDes(); break;
    case 5: asc ? c.sortByGPAAsc() : c.sortByGPADes(); break;
    default: cout << "Invalid sort choice\n"; break;
    }
}

// File operations
void fileOperations(Course& c, bool save) {
    string fname;
    cout << "Enter filename: "; getline(cin, fname);
    if (save) c.saveToFile(fname);
    else c.loadFromFile(fname);
}
