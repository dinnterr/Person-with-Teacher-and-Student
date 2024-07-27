#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include "Person.h"

class Teacher : public Person{
public:
    Teacher(const std::string& fullName, int age, const std::string& country,
            const std::string& phoneNumber, int experience, const std::string& category,
            double salary);

    int getExperience () const { return m_experience; }
    double getSalary () const { return m_salary; }

    std::string info () const override;

    double calculateSalary (double salary) const;
    double calculateVacationPay (int days) const override;
    bool isTeacher () const override{return true;}


private:
    std::string m_category;
    int m_experience;
    double m_salary;
};

#endif //TEACHER_H
