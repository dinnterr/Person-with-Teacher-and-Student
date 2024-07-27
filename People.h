#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Headers/Person.h"
#include "Headers/Student.h"
#include "Headers/Teacher.h"
#include "Headers/Scholarships.h"

class People {
public:
    People() = default;
    ~People();

    void addPerson (Person* person);
    void deletePerson (Person* person);

    Person* getPerson (int pos) const;

    void printPersons() const;
    void printPersonsNames () const;

    bool isNoPerson () const;
    bool isThereStudents () const;
    bool isThereTeachers () const;
    auto getPersonAmount () const {return m_persons.size();}

    void printAllStudentsWithScholarship () const;
    void printNameAndPhoneNumber () const;
    void printTeachersSortedByExperience() const;
    void printTeacherWithMaxSalary() const;
    void printVacationPayForTeacher(int pos, int days) const;
    void printAllStudents () const;
    void printAllTeachers () const;

    //int getStudentsNumber () const;
    Person* getSelectedStudent (int pos) const;
    Person* getSelectedTeacher (int pos) const;

private:
    std::vector <Person*> m_persons;
};


#endif //PEOPLE_H
