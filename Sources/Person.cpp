#include "../Headers/Person.h"

Person::Person() : m_fullName("Petrenko Petro Petrovich"), m_age(25), m_country("Ukraine"),
m_phoneNumber("+380(97)-341-23-15"){}

Person::Person(const std::string& fullName, int age,
              const std::string& country, const std::string& phoneNumber) :
               m_fullName(fullName), m_age(age),
               m_country(country), m_phoneNumber(phoneNumber){
    if (age < 0){
    throw std::invalid_argument ("Age cannot be less than zero.");
    }
}

std::string Person::info() const {
    std::stringstream ss;
    ss << m_fullName << ".\n"
       << "Age: " << m_age << '.' << "\nLive in " << m_country << '.'
       << "\nPhone number: " << m_phoneNumber << ".\n";
    return ss.str();
}

void Person::changePhoneNumber(const std::string &phoneNumber)
{
    m_phoneNumber = phoneNumber;
    std::cout << "The phone number has been successfully changed." << std::endl;
}

bool Person::isAdult() const {
    return m_age>=18;
}

bool Person::isFromUkraine() const {
    return (m_country == "Ukraine" || m_country == "ukraine");
}

bool Person::hasAnniversary() const {
    return (m_age%5)==0;
}

void Person::courseUp() {}

double Person::calculateVacationPay(int days) const{}
