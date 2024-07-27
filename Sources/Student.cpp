#include "../Headers/Student.h"
#include "../Headers/Scholarships.h"

Student::Student(const std::string &fullName, int age, const std::string &country,
                 const std::string &phoneNumber, const std::string &university,
                 const std::string &faculty, int course, const std::vector<int> &grades) :
                 Person(fullName, age, country, phoneNumber), m_university(university), m_faculty(faculty),
                 m_course(course), m_grades(grades){
    if (course <= 0 || course > 6){
        throw std::invalid_argument("Cannot create a student. Incorrect course.");
    }
    for (const auto& grade : grades){
        if (grade < 0 || grade > 100){
            throw std::invalid_argument("Cannot create a student. Incorrect grades.");
        }
    }
}

std::string Student::info() const {
    std::stringstream ss;
    ss << Person::info() << Person::getFullName() << " is a student of " << m_university <<
    ".\nFaculty: " << m_faculty << ". Course: " << m_course << ".\nExam grades: ";
    for (const auto& grade : m_grades){
        ss << grade << ' ';
    }
    ss << "\nScholarship: " << scholarship() << ".\n";
    return ss.str();
}

void Student::courseUp() {
    int countFailed = 0;
    for (const auto& grade : m_grades){
        if (grade < 60){
            countFailed++;
        }
    }
    if(countFailed == 0 && m_course != 6){
        m_course++;
        m_grades = std::vector<int>{0};
        std::cout << "Student is successfully transferred on the next course." << std::endl << std::endl;
    }
    else if (m_course == 6){
        throw std::invalid_argument("Student cannot be transferred on the next course. He//She is on the last course already.");
    }
    else
        throw std::invalid_argument("Student cannot be transferred on the next course.");
}

int Student::scholarship() const {
    int total = 0;
    int count = 0;
    bool isExcellent = true;
    for (const auto& grade : m_grades){
        total += grade;
        count++;
        if (grade < 90){
            isExcellent = false;
        }
    }
    int average = total/count;
    if (average >= 75){
        return normalScholarship;
    }
    else if (isExcellent){
        return upperScholarship;
    }
    else
        return 0;
}

bool Student::isStudentWithScholarShip() const {
    return (scholarship() != 0);
}



