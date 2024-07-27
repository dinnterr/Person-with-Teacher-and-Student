#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <sstream>

class Person
{
public:
    Person();
    Person(const std::string& fullName, int age, const std::string& country, const std::string& phoneNumber);

    const std::string& getFullName () const { return m_fullName; }
    int getAge () const { return m_age; }
    const std::string& getCountry () const { return m_country; }
    const std::string& getPhoneNumber () const { return m_phoneNumber; }

    virtual std::string info () const;

    void changePhoneNumber (const std::string& phoneNumber);
    bool isAdult() const;
    bool isFromUkraine() const;
    bool hasAnniversary() const;

    virtual bool isStudent () const {return false;}
    virtual bool isTeacher () const {return false;}
    virtual bool isStudentWithScholarShip () const {return false;}
    virtual void courseUp ();
    virtual double calculateVacationPay (int days) const;

private:
    std::string m_fullName, m_country, m_phoneNumber;
    int m_age;
};

#endif //PERSON_H
