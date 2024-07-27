// #13 variant
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "People.h"
#include "Headers/Person.h"
#include "Headers/Teacher.h"
#include "Headers/Student.h"

using namespace std;

int main() {
    People people;
    Person * person = nullptr;
    cout << "Welcome! You are using a person creation program." << endl << endl;
    for (;;) {
        cout << "Now make your choice what do you want to do next (enter number):" << endl;
        cout << "1. Add person." << endl;
        cout << "2. Add student." << endl;
        cout << "3. Add teacher." << endl;
        cout << "4. Edit person`s phone number." << endl;
        cout << "5. Check persons." << endl;
        cout << "6. Delete person/student/teacher." << endl;
        cout << "7. Print information about all persons." << endl;
        cout << "8. Print all students receiving a scholarship." << endl;
        cout << "9. Print all teachers sorted by experience." << endl;
        cout << "10. Print teacher with Max salary." << endl;
        cout << "11. Print vacation pay for teacher." << endl;
        cout << "12. Transfer a student to the next course." << endl;
        int n;
        cin >> n;
        while (n < 1 || n > 12){
            cout << "You entered wrong number. Try again." << endl;
            cin >> n;
        }
        cout << endl;
        if (n == 4 && people.isNoPerson()){
            cout << "You cannot edit person`s phone number. No persons added. First add at least one." << endl << endl;
            continue;
        }
        if (n == 5 && people.isNoPerson()){
            cout << "You cannot check persons. No persons added. First add at least one." << endl << endl;
            continue;
        }
        if (n == 6 && people.isNoPerson()){
            cout << "You cannot delete the person. No persons added. First add at least one." << endl << endl;
            continue;
        }
        if (n == 7 && people.isNoPerson()){
            cout << "No persons added. First add at least one." << endl << endl;
            continue;
        }
        if (n == 8 && people.isNoPerson()){
            cout << "No persons added. First add at least one." << endl << endl;
            continue;
        }
        if (n == 8 && !people.isThereStudents()){
            cout << "No students added. First add at least one." << endl << endl;
            continue;
        }
        if (n == 9 && people.isNoPerson()){
            cout << "No persons added. First add at least one." << endl << endl;
            continue;
        }
        if (n == 9 && !people.isThereTeachers()){
            cout << "No teachers added. First add at least one." << endl << endl;
            continue;
        }
        if (n == 10 && people.isNoPerson()){
            cout << "No persons added. First add at least one." << endl << endl;
            continue;
        }
        if (n == 10 && !people.isThereTeachers()){
            cout << "No teachers added. First add at least one." << endl << endl;
            continue;
        }
        if (n == 11 && people.isNoPerson()){
            cout << "No persons added. First add at least one." << endl << endl;
            continue;
        }
        if (n == 11 && !people.isThereTeachers()){
            cout << "No teachers added. First add at least one." << endl << endl;
            continue;
        }
        if (n == 12 && people.isNoPerson()){
            cout << "No persons added. First add at least one." << endl << endl;
            continue;
        }
        if (n == 12 && !people.isThereStudents()){
            cout << "No students added. First add at least one." << endl << endl;
            continue;
        }
        if (n == 1) { //Add person
            try {
                cout << "You have chosen \"Add person\"." << endl << endl;
                string fullName, country, phoneNumber;
                int age;
                cout << "Enter full name of person." << endl;
                cin >> ws;
                getline(cin, fullName);
                cout << "Enter age." << endl;
                cin >> age;
                cout << "Enter country where person live." << endl;
                cin >> ws;
                getline(cin, country);
                cout << "Enter a phone number of person." << endl;
                cin >> ws;
                getline(cin, phoneNumber);
                person = new Person(fullName, age, country, phoneNumber);
                people.addPerson(person);
                cout << endl;
            }
            catch (const exception& ex){
                cerr << ex.what() << endl;
            }
        }
        if (n == 2){ //Add student
            try {
                cout << "You have chosen \"Add student\"." << endl << endl;
                    string fullName, country, phoneNumber, university, faculty;
                int age, course;
                vector <int> grades;
                cout << "Enter full name of student." << endl;
                cin >> ws;
                getline(cin, fullName);
                cout << "Enter age." << endl;
                cin >> age;
                cout << "Enter country where student live." << endl;
                cin >> ws;
                getline(cin, country);
                cout << "Enter a phone number of student." << endl;
                cin >> ws;
                getline(cin, phoneNumber);
                cout << "Enter the university where the student is studying." << endl;
                cin >> ws;
                getline(cin, university);
                cout << "Enter the course in which the student is studying (from 1 to 6)." << endl;
                cin >> course;
                cout << "Enter the faculty where the student is studying." << endl;
                cin >> ws;
                getline(cin, faculty);
                cout << "Enter the amount of exam grades." << endl;
                int amountOfGrades;
                cin >> amountOfGrades;
                while (amountOfGrades <= 0){
                    cout << "The amount cannot be 0 or negative. Try again." << endl;
                    cin >> amountOfGrades;
                }
                cout << "Enter all student`s grades for the exam." << endl;
                for (int i = 0; i < amountOfGrades; i++){
                    int grade;
                    cin >> grade;
                    grades.push_back(grade);
                }
                person = new Student(fullName, age, country, phoneNumber,
                                     university, faculty, course, grades);
                people.addPerson(person);
                cout << endl;
            }
            catch (const exception& ex){
                cerr << ex.what() << endl;
            }
        }
        if (n == 3){ //Add teacher
            try {
                cout << "You have chosen \"Add teacher\"." << endl << endl;
                string fullName, country, phoneNumber, category;
                int age, experience;
                double salary;
                cout << "Enter full name of teacher." << endl;
                cin >> ws;
                getline(cin, fullName);
                cout << "Enter age." << endl;
                cin >> age;
                cout << "Enter country where teacher live." << endl;
                cin >> ws;
                getline(cin, country);
                cout << "Enter a phone number of teacher." << endl;
                cin >> ws;
                getline(cin, phoneNumber);
                cout << "Enter teacher category." << endl;
                cin >> ws;
                getline(cin, category);
                cout << "Enter teacher`s experience (number of years)." << endl;
                cin >> experience;
                cout << "Enter teacher`s salary." << endl;
                cin >> salary;
                person = new Teacher(fullName, age, country, phoneNumber,
                                     experience, category, salary);
                people.addPerson(person);
                cout << endl;
            }
            catch (const exception& ex){
                cerr << ex.what() << endl;
            }
        }
        if (n == 4){ //Edit person`s phone number
            cout << "You have chosen \"Edit person`s phone number\"." << endl << endl;
            cout << "Choose person." << endl;
            people.printNameAndPhoneNumber();
            int p;
            cin >> p;
            while (p <= 0 || p > people.getPersonAmount()){
                cout << "You entered wrong number. Try again." << endl;
                cin >> p;
            }
            cout << "Enter a new phone number:" << endl;
            string newPhoneNumber;
            cin >> ws;
            getline(cin, newPhoneNumber);
            try {
                people.getPerson(p)->changePhoneNumber(newPhoneNumber);
            }
            catch (const exception& ex){
                cerr << ex.what() << endl;
            }
            cout << endl;
        }
        if (n == 5){ //Check persons
            cout << "You have chosen \"Check persons\"." << endl << endl;
            cout << "Choose what you want to check. (enter number)" << endl;
            cout << "1. Is person adult." << endl;
            cout << "2. Is person from Ukraine." << endl;
            cout << "3. Is person having an anniversary this year." << endl;
            int c;
            cin >> c;
            while (c < 1 || c > 3){
                cout << "You entered wrong number. Try again." << endl;
                cin >> c;
            }
            switch (c){
                case 1:
                {
                    cout << endl;
                    cout << "There are your persons:" << endl;
                    people.printPersonsNames();
                    cout << endl;
                    cout << "Make your choice (enter number)." << endl;
                    int p;
                    cin >> p;
                    while (p <= 0 || p > people.getPersonAmount()){
                        cout << "You entered wrong number. Try again." << endl;
                        cin >> p;
                    }
                    cout << endl;
                    if (people.getPerson(p)->isAdult()){
                        cout << people.getPerson(p)->getFullName() << " is adult.\n";
                    }
                    else{
                        cout << people.getPerson(p)->getFullName() << " is NOT adult.\n";
                    }
                    cout << endl;
                    break;
                }
                case 2:
                {
                    cout << endl;
                    cout << "There are your persons:" << endl;
                    people.printPersonsNames();
                    cout << endl;
                    cout << "Make your choice (enter number)." << endl;
                    int p;
                    cin >> p;
                    while (p <= 0 || p > people.getPersonAmount()){
                        cout << "You entered wrong number. Try again." << endl;
                        cin >> p;
                    }
                    cout << endl;
                    if (people.getPerson(p)->isFromUkraine()){
                        cout << people.getPerson(p)->getFullName() << " is from Ukraine.\n";
                    }
                    else{
                        cout << people.getPerson(p)->getFullName() << " is NOT from Ukraine.\n";
                    }
                    cout << endl;
                    break;
                }
                case 3:
                {
                    cout << endl;
                    cout << "There are your persons:" << endl;
                    people.printPersonsNames();
                    cout << endl;
                    cout << "Make your choice (enter number)." << endl;
                    int p;
                    cin >> p;
                    while (p <= 0 || p > people.getPersonAmount()){
                        cout << "You entered wrong number. Try again." << endl;
                        cin >> p;
                    }
                    cout << endl;
                    if (people.getPerson(p)->hasAnniversary()){
                        cout << people.getPerson(p)->getFullName() << " has anniversary this year.\n";
                    }
                    else{
                        cout << people.getPerson(p)->getFullName() << " has NOT anniversary this year.\n";
                    }
                    cout << endl;
                    break;
                }
            }
        }
        if (n == 6){ //Delete person
            cout << "You have chosen \"Delete person\"." << endl << endl;
            cout << "There are your persons:" << endl;
            people.printPersons();
            cout << endl;
            cout << "Make your choice (enter number)." << endl;
            int p;
            cin >> p;
            while (p <= 0 || p > people.getPersonAmount()){
                cout << "You entered wrong number. Try again." << endl;
                cin >> p;
            }
            people.deletePerson(people.getPerson(p));
            cout << endl;
        }
        if(n == 7){ //Print information about all persons
            cout << "Your persons: " << endl;
            people.printPersons();
            cout << endl;
        }
        if (n == 8){ //Print all students receiving a scholarship
            people.printAllStudentsWithScholarship();
            cout << endl;
        }
        if (n == 9){ //Print all teachers sorted by experience
            people.printTeachersSortedByExperience();
            cout << endl;
        }
        if (n == 10){ //Print teacher with Max salary
            people.printTeacherWithMaxSalary();
            cout << endl;
        }
        if (n == 11){ //Print vacation pay for teacher
            cout << "You have chosen \"Print vacation pay for teacher.\"." << endl << endl;
            cout << "Choose teacher." << endl;
            cout << "There are your teachers:" << endl;
            cout << endl;
            people.printAllTeachers();
            int s;
            cin >> s;
            while (s <= 0 || s > people.getPersonAmount()){
                cout << "You entered wrong number. Try again." << endl;
                cin >> s;
            }
            while (!people.getPerson(s)->isTeacher()){
                cout << "You entered wrong number. Try again." << endl;
                cin >> s;
            }
            cout << "Enter number of days for vacation." << endl;
            int days;
            cin >> days;
            while (days <= 0){
                cout << "You entered wrong number. Try again." << endl;
                cin >> days;
            }
            try {
                people.getSelectedTeacher(s)->calculateVacationPay(days);
            }
            catch (const exception& ex){
                cerr << ex.what() << endl;
            }
            people.printVacationPayForTeacher(s, days);
            cout << endl;
        }
        if (n == 12){ //Transfer a student to the next course.
            cout << "You have chosen \"Transfer a student to the next course.\"." << endl << endl;
            cout << "Choose student." << endl;
            cout << "There are your students:" << endl;
            cout << endl;
            people.printAllStudents();
            int s;
            cin >> s;
            while (s <= 0 || s > people.getPersonAmount()){
                cout << "You entered wrong number. Try again." << endl;
                cin >> s;
            }
            while (!people.getPerson(s)->isStudent()){
                cout << "You entered wrong number. Try again." << endl;
                cin >> s;
            }
            try {
                people.getSelectedStudent(s)->courseUp();
            }
            catch (const exception& ex){
                cerr << ex.what() << endl;
            }
            cout << endl;
        }
        cout << "Do you want to exit the program or continue working with the program?" << endl;
        cout << "1. Exit." << endl;
        cout << "2. Continue." << endl;
        int e;
        cin >> e;
        while (e < 1 || e > 2){
            cout << "You entered wrong number. Try again." << endl;
            cin >> e;
        }
        cout << endl;
        if (e == 1){
            cout << "You have chosen to exit. Are you sure?" << endl;
            cout << "1. Yes." << endl;
            cout << "2. No." << endl;
            int e2;
            cin >> e2;
            while (e2 < 1 || e2 > 2){
                cout << "You entered wrong number. Try again." << endl;
                cin >> e2;
            }
            if(e2 == 1){
                delete person;
                return  0;
            }
            if (e2 == 2){
                cout << endl;
                continue;
            }
        }
        if(e == 2){
            continue;
        }
    }
}