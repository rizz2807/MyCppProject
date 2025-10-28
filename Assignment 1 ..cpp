#include <iostream>
#include <string>
using namespace std;

struct Subject {
    string name;
    double mark;
    char grade;
};

struct Student {
    string name;
    int age;
    Subject subjects[5];
    int subjectCount;
    float cpa;
};


char getGrade(float mark) {
    if (mark >= 80) return 'A';
    else if (mark >= 70) return 'B';
    else if (mark >= 60) return 'C';
    else if (mark >= 50) return 'D';
    else return 'F';
}


void inputStudent(Student &s) {
    cout << "Enter student name: ";
    getline(cin, s.name);
    cout << "Enter age: ";
    cin >> s.age;
    cout << "Enter number of subjects (max 5): ";
    cin >> s.subjectCount;

    while (s.subjectCount < 1 || s.subjectCount > 5) {
        cout << "Invalid! Enter between 1 - 5: ";
        cin >> s.subjectCount;
    }

    float total = 0;
    for (int i = 0; i < s.subjectCount; i++) {
        cin.ignore();
        cout << "\nEnter subject " << i + 1 << " name: ";
        getline(cin, s.subjects[i].name);

        cout << "Enter mark (0 - 100): ";
        cin >> s.subjects[i].mark;

        
        while (s.subjects[i].mark < 0 || s.subjects[i].mark > 100) {
            cout << "Invalid mark! Please enter again (0 - 100): ";
            cin >> s.subjects[i].mark;
        }

        s.subjects[i].grade = getGrade(s.subjects[i].mark);
        total += s.subjects[i].mark;
    }

    s.cpa = total / s.subjectCount;
    cin.ignore();
}


void showStudent(Student s) {
    cout << "\n-----------------------------\n";
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "CPA: " << s.cpa << endl;
    cout << "Subjects:\n";
    for (int i = 0; i < s.subjectCount; i++) {
        cout << "  " << s.subjects[i].name
             << " - Mark: " << s.subjects[i].mark
             << " - Grade: " << s.subjects[i].grade << endl;
    }
    cout << "-----------------------------\n";
}

int main() {
    Student students[10];
    int totalStudents;

    cout << "Enter number of students (max 10): ";
    cin >> totalStudents;
    cin.ignore();

    if (totalStudents > 10) totalStudents = 10;

    for (int i = 0; i < totalStudents; i++) {
        cout << "\n--- Enter details for student " << i + 1 << " ---\n";
        inputStudent(students[i]);
    }

    cout << "\n===== STUDENT DETAILS =====\n";
    for (int i = 0; i < totalStudents; i++) {
        showStudent(students[i]);
    }

    return 0;
}
