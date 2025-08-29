# Student-Record-Management
A C++ console-based Student Management System that allows adding, removing, searching, and sorting student records. Supports file I/O for saving and loading data, with a menu-driven interface for easy interaction. Demonstrates object-oriented programming, vectors, and basic file handling.

The project demonstrates:

- Object-oriented programming (classes, encapsulation, constructors, accessors/mutators)  
- Use of `vector` for dynamic data storage  
- File handling (reading/writing student records)  
- Lambda functions for searching  
- Sorting algorithms for different student attributes  

## Features

- Add students with first name, last name, student ID, phone number, and GPA.
- Remove students by student ID.
- Display students in a neat tabular format.
- Search students by:
  - First name
  - Last name
  - Student ID
  - Phone number
- Sort students by:
  - First name
  - Last name
  - ID
  - Phone number
  - GPA  
  (Both ascending and descending orders)
- Save and load student data to/from a file.
- Menu-driven interface for easy interaction. 

## Project Structure

- `main.cpp` — Contains the main function and menu logic.
- `student.h` / `student.cpp` — Defines the `Student` class, including input, output, file I/O, and getters/setters.
- `course.h` / `course.cpp` — Defines the `Course` class, including managing a list of students, sorting, searching, and file I/O.

## Usage

1. **Compile the code**:
   ```bash
   g++ main.cpp student.cpp course.cpp -o StudentManagement


2.  **Run the executable**:
    ```bash
    ./StudentManagement

3 **Follow the on-screen menu**:
```bash
      ==================== Student Management Menu ====================
    1. Add student
    2. Remove student by ID
    3. Display all students
    4. Search by first name
    5. Search by last name
    6. Search by ID
    7. Search by phone
    8. Sort students
    9. Save to file
   10. Load from file
    0. Exit
    =================================================================







