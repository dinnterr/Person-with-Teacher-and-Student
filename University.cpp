#include "University.h"

University::~University() {
    for (auto person: m_persons){
        delete person;
    }
}

void University::addPerson(Person *person) {
    m_persons.push_back(person);
}

void University::deletePerson(Person *person) {
    auto it = std::find(m_persons.begin(), m_persons.end(), person);
    if (it != m_persons.end()) {
        m_persons.erase(it);
    }
    std::cout << "The person has been successfully deleted." << std::endl;
}

Person *University::getPerson(int pos) const {
    return m_persons[pos-1];
}

void University::printPersons() const {
    int i = 1;
    for (const auto& person : m_persons)
    {
        std::cout << i++ << ") " << std::setprecision(2) << person->info() << std::endl;
    }
}


void University::printPersonsNames() const {
    int i = 1;
    for (const auto& person : m_persons)
    {
        std::cout << i++ << ") " << std::setprecision(2) << person->getFullName() << std::endl;
    }
}

bool University::isNoPerson() const {
    return  m_persons.empty();
}

bool University::isThereStudents() const {
    int count = 0;
    for (const auto& person : m_persons){
        if (!person->isStudent()){
            count++;
        }
    }
    if (count == m_persons.size()){
        return false;
    }
    else
        return true;
}

bool University::isThereTeachers() const {
    int count = 0;
    for (const auto& person : m_persons){
        if (!person->isTeacher()){
            count++;
        }
    }
    if (count == m_persons.size()){
        return false;
    }
    else
        return true;
}

void University::printAllStudentsWithScholarship() const {
    int i = 1;
    for (const auto& person : m_persons){
        if (isThereStudents()) {
            if (person->isStudentWithScholarShip()) {
                std::cout << i++ << ") " << std::setprecision(2) << person->info() << std::endl;
            }
        }
    }
}

void University::printNameAndPhoneNumber() const {
    int i = 1;
    for (const auto& person : m_persons){
        std::cout << i++ << ") " << std::setprecision(2) << person->getFullName() <<
        ": " << person->getPhoneNumber() << std::endl;
    }
}

void University::printTeachersSortedByExperience() const {
    std::vector<Teacher*> teachers;

    // Фильтрация учителей
    for (const auto& person : m_persons) {
        if (person->isTeacher()) {
            teachers.push_back(static_cast<Teacher*>(person));
        }
    }
    if (teachers.empty()) {
        std::cout << "No teachers available." << std::endl;
        return;
    }
    // Сортировка учителей по стажу
    std::sort(teachers.begin(), teachers.end(), [](const Teacher* a, const Teacher* b) {
        return a->getExperience() > b->getExperience();
    });
    for (const auto& teacher : teachers) {
        std::cout << teacher->info() << std::endl;
    }
}

void University::printTeacherWithMaxSalary() const {
    std::vector<Teacher*> teachers;
    // Фильтрация учителей
    for (const auto& person : m_persons) {
        if (person->isTeacher()) {
            teachers.push_back(static_cast<Teacher*>(person));
        }
    }
    if (teachers.empty()) {
        std::cout << "No teachers available." << std::endl;
        return;
    }
    // Поиск учителя с максимальной зарплатой
    auto maxSalaryTeacher = std::max_element(teachers.begin(), teachers.end(), [](const Teacher* a, const Teacher* b) {
        return a->getSalary() < b->getSalary();
    });
    std::cout << "Teacher with maximum salary:\n" << (*maxSalaryTeacher)->info() << std::endl;
}

void University::printVacationPayForTeacher(int pos, int days) const {
    Person* teacher = getSelectedTeacher(pos);
    if (teacher) {
        double vacationPay = teacher->calculateVacationPay(days);
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Vacation pay for " << teacher->getFullName() << " for " << days << " days is: " << vacationPay << std::endl;
        return;
    }
    std::cout << "Teacher not found." << std::endl;
}

void University::printAllStudents() const {
    int i = 0;
    for (const auto& person : m_persons) {
        i = &person - &m_persons[0];
        if (person->isStudent()) {
            std::cout << ++i << ") " << std::setprecision(2) << person->getFullName() << std::endl;
        }
    }
}

void University::printAllTeachers() const {
    int i = 0;
    for (const auto& person : m_persons) {
        i = &person - &m_persons[0];
        if (person->isTeacher()) {
            std::cout << ++i << ") " << std::setprecision(2) << person->getFullName() << std::endl;
        }
    }
}


Person* University::getSelectedStudent (int pos) const {
    for (int i = 1; i <= m_persons.size(); ){
        if(i == pos && m_persons[i-1]->isStudent()){
            return m_persons[i-1];
        }
        i++;
    }
}

Person* University::getSelectedTeacher (int pos) const {
    for (int i = 1; i <= m_persons.size(); ){
        if(i == pos && m_persons[i-1]->isTeacher()){
            return m_persons[i-1];
        }
        i++;
    }
}


