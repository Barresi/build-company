#include "Staff.hpp"
#include <iostream>
#include <algorithm>

// Реализация конструктора
Staff::Staff(const std::string& fullname, StaffRank rank, StaffSpecialization specialization,
             const std::string& telephone, const std::string& hiringDate, int salary)
    : fullname(fullname), rank(rank), specialization(specialization),
      telephone(telephone), hiringDate(hiringDate), salary(salary) {
}

// Реализация деструктора
Staff::~Staff() {
    std::cout << "Вызван деструктор Staff для: " << fullname << std::endl;
}

// Реализация геттеров
std::string Staff::getFullname() const {
    return fullname;
}

StaffRank Staff::getRank() const {
    return rank;
}

StaffSpecialization Staff::getSpecialization() const {
    return specialization;
}

std::string Staff::getTelephone() const {
    return telephone;
}

std::string Staff::getHiringDate() const {
    return hiringDate;
}

int Staff::getSalary() const {
    return salary;
}

const std::vector<ConstructionObject*>& Staff::getConstructionObjects() const {
    return constructionObjects;
}

// Реализация сеттеров
void Staff::setFullname(const std::string& fullname) {
    this->fullname = fullname;
}

void Staff::setRank(StaffRank rank) {
    this->rank = rank;
}

void Staff::setSpecialization(StaffSpecialization specialization) {
    this->specialization = specialization;
}

void Staff::setTelephone(const std::string& telephone) {
    this->telephone = telephone;
}

void Staff::setHiringDate(const std::string& hiringDate) {
    this->hiringDate = hiringDate;
}

void Staff::setSalary(int salary) {
    this->salary = salary;
}

// Назначить сотрудника на строительный объект
void Staff::assignToObject(ConstructionObject* object) {
    if (object != nullptr) {
        constructionObjects.push_back(object);
        std::cout << fullname << " назначен(а) на проект по адресу " << object->getAddress() << std::endl;
    }
}

// Удалить сотрудника со строительного объекта
void Staff::removeFromObject(ConstructionObject* object) {
    auto it = std::find(constructionObjects.begin(), constructionObjects.end(), object);
    if (it != constructionObjects.end()) {
        constructionObjects.erase(it);
        std::cout << fullname << " удален(а) с проекта по адресу " << object->getAddress() << std::endl;
    }
}

// Реализация функции отображения информации
void Staff::displayInfo() const {
    std::cout << "=== Сотрудник ===" << std::endl;
    std::cout << "ФИО: " << fullname << std::endl;
    std::cout << "Должность: " << staffRankToString(rank) << std::endl;
    std::cout << "Специализация: " << staffSpecializationToString(specialization) << std::endl;
    std::cout << "Телефон: " << telephone << std::endl;
    std::cout << "Дата приема: " << hiringDate << std::endl;
    std::cout << "Зарплата: $" << salary << std::endl;
    std::cout << "Назначен(а) на проектов: " << constructionObjects.size() << std::endl;
}
