#include "../Headers/Teacher.h"

Teacher::Teacher(const std::string &fullName, int age, const std::string &country,
                 const std::string &phoneNumber, int experience, const std::string & category,
                 double salary) : Person(fullName, age, country, phoneNumber),
                 m_experience(experience), m_category(category), m_salary(calculateSalary(salary)){
    if (experience <= 0){
        throw std::invalid_argument ("Experience cannot be negative or equal to zero.");
    }
    if (experience > age){
        throw std::invalid_argument ("Experience cannot be more than age.");
    }
    if (salary <= 0){
        throw std::invalid_argument ("Salary cannot be negative or equal to zero.");
    }
}

std::string Teacher::info() const {
    std::stringstream ss;
    ss << Person::info() << Person::getFullName() << " is a "
    << m_category << " .\n" << "Experience: " << m_experience << " years."
    << "\nSalary: " << m_salary << ".";
    return ss.str();
}

// Функция для преобразования строки к нижнему регистру
std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c){ return std::tolower(c); });
    return lowerStr;
}

double Teacher::calculateSalary(double salary) const {
    if (toLower(m_category) == "first category teacher") {
        if (m_experience >= 20) {
            salary += salary * 0.2 + 3000;
        } else if (m_experience >= 10) {
            salary += salary * 0.2 + 2000;
        } else {
            salary += salary * 0.2;
        }
    } else if (toLower(m_category) == "teacher of the highest category") {
        if (m_experience >= 20) {
            salary += salary * 0.17 + 3000;
        } else if (m_experience >= 10) {
            salary += salary * 0.17 + 2000;
        } else {
            salary += salary * 0.17;
        }
    } else {
        if (m_experience >= 20) {
            salary += 3000;
        } else if (m_experience >= 10) {
            salary += 2000;
        }
    }
    return salary;
}


double Teacher::calculateVacationPay(int days) const {
    return m_salary/30*days;
}

