#include "People.h"

People::~People() {
    for (auto person: m_persons){
        delete person;
    }
}

void People::addPerson(Person *person) {
    m_persons.push_back(person);
}

void People::deletePerson(Person *person) {
    auto it = std::find(m_persons.begin(), m_persons.end(), person);
    if (it != m_persons.end()) {
        m_persons.erase(it);
    }
    std::cout << "The person has been successfully deleted." << std::endl;
}

Person *People::getPerson(int pos) const {
    return m_persons[pos-1];
}

void People::printPersons() const {
    int i = 1;
    for (const auto& person : m_persons)
    {
        std::cout << i++ << ") " << std::setprecision(2) << person->info() << std::endl;
    }
}


void People::printPersonsNames() const {
    int i = 1;
    for (const auto& person : m_persons)
    {
        std::cout << i++ << ") " << std::setprecision(2) << person->getFullName() << std::endl;
    }
}

bool People::isNoPerson() const {
    return  m_persons.empty();
}

bool People::isThereStudents() const {
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

bool People::isThereTeachers() const {
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

void People::printAllStudentsWithScholarship() const {
    int i = 1;
    for (const auto& person : m_persons){
        if (isThereStudents()) {
            if (person->isStudentWithScholarShip()) {
                std::cout << i++ << ") " << std::setprecision(2) << person->info() << std::endl;
            }
        }
    }
}

void People::printNameAndPhoneNumber() const {
    int i = 1;
    for (const auto& person : m_persons){
        std::cout << i++ << ") " << std::setprecision(2) << person->getFullName() <<
        ": " << person->getPhoneNumber() << std::endl;
    }
}

void People::printTeachersSortedByExperience() const {
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

void People::printTeacherWithMaxSalary() const {
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

void People::printVacationPayForTeacher(int pos, int days) const {
    Person* teacher = getSelectedTeacher(pos);
    if (teacher) {
        double vacationPay = teacher->calculateVacationPay(days);
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Vacation pay for " << teacher->getFullName() << " for " << days << " days is: " << vacationPay << std::endl;
        return;
    }
    std::cout << "Teacher not found." << std::endl;
}

void People::printAllStudents() const {
    int i = 0;
    for (const auto& person : m_persons) {
        i = &person - &m_persons[0];
        if (person->isStudent()) {
            std::cout << ++i << ") " << std::setprecision(2) << person->getFullName() << std::endl;
        }
    }
}

void People::printAllTeachers() const {
    int i = 0;
    for (const auto& person : m_persons) {
        i = &person - &m_persons[0];
        if (person->isTeacher()) {
            std::cout << ++i << ") " << std::setprecision(2) << person->getFullName() << std::endl;
        }
    }
}

/*int People::getStudentsNumber() const {
    int i = 0;
    for (const auto& person : m_persons){
        if (person->isStudent())
            i++;
    }
    return i;
}*/

Person* People::getSelectedStudent (int pos) const {
    for (int i = 1; i <= m_persons.size(); ){
        if(i == pos){
            return m_persons[i-1];
        }
        i++;
    }
}

Person* People::getSelectedTeacher (int pos) const {
    for (int i = 1; i <= m_persons.size(); ){
        if(i == pos){
            return m_persons[i-1];
        }
        i++;
    }
}


