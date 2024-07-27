#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include "Person.h"

class Student : public Person {
public:
    Student(const std::string& fullName, int age, const std::string& country, const std::string& phoneNumber,
            const std::string& university, const std::string& faculty, int course, const std::vector <int>& grades);

    std::string info () const override;
    void courseUp () override;
    int scholarship () const;
    bool isStudent () const override {return  true;}
    bool isStudentWithScholarShip () const override;

private:
    std::string m_university, m_faculty;
    int m_course;
    std::vector <int> m_grades;
};

#endif //STUDENT_H
