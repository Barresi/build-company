#include "Staff.hpp"
#include <iostream>
#include <algorithm>
#include <stdexcept>

// ============================================================
// ИНИЦИАЛИЗАЦИЯ СТАТИЧЕСКИХ ПОЛЕЙ
// ============================================================
int Staff::totalStaffCreated = 0;

// ============================================================
// РЕАЛИЗАЦИЯ СТАТИЧЕСКИХ МЕТОДОВ
// ============================================================

// Получить общее количество созданных сотрудников
int Staff::getTotalStaffCreated() {
    return totalStaffCreated;
}

// Сбросить счётчик сотрудников
void Staff::resetStaffCounter() {
    totalStaffCreated = 0;
    std::cout << "Счётчик сотрудников сброшен!" << std::endl;
}

// Проверить валидность зарплаты (статический метод)
bool Staff::isValidSalary(int salary) {
    return salary >= MIN_SALARY && salary <= MAX_SALARY;
}

// ============================================================
// РЕАЛИЗАЦИЯ КОНСТРУКТОРА С ОБРАБОТКОЙ ИСКЛЮЧЕНИЙ
// ============================================================

// Реализация конструктора с валидацией данных
Staff::Staff(const std::string& fullname, StaffRank rank, StaffSpecialization specialization,
             const std::string& telephone, const std::string& hiringDate, int salary)
    : fullname(fullname), rank(rank), specialization(specialization),
      telephone(telephone), hiringDate(hiringDate), salary(0) {

    // ДЕМОНСТРАЦИЯ throw: Валидация имени
    if (fullname.empty()) {
        throw std::invalid_argument("Ошибка: Имя сотрудника не может быть пустым!");
    }

    // ДЕМОНСТРАЦИЯ throw: Валидация телефона
    if (telephone.empty()) {
        throw std::invalid_argument("Ошибка: Телефон сотрудника не может быть пустым!");
    }

    // ДЕМОНСТРАЦИЯ throw с использованием статического метода: Валидация зарплаты
    if (!isValidSalary(salary)) {
        throw std::out_of_range(
            "Ошибка: Зарплата должна быть в диапазоне $" +
            std::to_string(MIN_SALARY) + " - $" + std::to_string(MAX_SALARY) +
            " (получено: $" + std::to_string(salary) + ")"
        );
    }

    // ДЕМОНСТРАЦИЯ this: Если всё валидно, устанавливаем зарплату через this
    this->salary = salary;

    // Увеличиваем статический счётчик
    totalStaffCreated++;

    std::cout << "✓ Сотрудник создан успешно. Всего сотрудников: " << totalStaffCreated << std::endl;
}

// Конструктор копирования
Staff::Staff(const Staff& other)
    : fullname(other.fullname), rank(other.rank), specialization(other.specialization),
      telephone(other.telephone), hiringDate(other.hiringDate), salary(other.salary),
      constructionObjects(other.constructionObjects) {

    // Увеличиваем статический счётчик при копировании
    totalStaffCreated++;

    std::cout << "Вызван конструктор копирования Staff для: " << fullname
              << " (Всего сотрудников: " << totalStaffCreated << ")" << std::endl;
}

// Реализация деструктора
Staff::~Staff() {
    // Уменьшаем статический счётчик
    totalStaffCreated--;
    std::cout << "Вызван деструктор Staff для: " << fullname
              << " (Осталось сотрудников: " << totalStaffCreated << ")" << std::endl;
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

const std::vector<std::shared_ptr<ConstructionObject>>& Staff::getConstructionObjects() const {
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

// ДЕМОНСТРАЦИЯ this и throw в сеттере
void Staff::setSalary(int salary) {
    // ДЕМОНСТРАЦИЯ throw: Валидация зарплаты через статический метод
    if (!isValidSalary(salary)) {
        throw std::out_of_range(
            "Ошибка: Зарплата должна быть в диапазоне $" +
            std::to_string(MIN_SALARY) + " - $" + std::to_string(MAX_SALARY) +
            " (получено: $" + std::to_string(salary) + ")"
        );
    }

    // ДЕМОНСТРАЦИЯ this: Устанавливаем зарплату для текущего объекта
    this->salary = salary;
    std::cout << "✓ Зарплата для " << this->fullname << " обновлена на $" << this->salary << std::endl;
}

// Назначить сотрудника на строительный объект
void Staff::assignToObject(std::shared_ptr<ConstructionObject> object) {
    if (object) {
        constructionObjects.push_back(object);
        std::cout << fullname << " назначен(а) на проект по адресу " << object->getAddress() << std::endl;
    }
}

// Удалить сотрудника со строительного объекта
void Staff::removeFromObject(std::shared_ptr<ConstructionObject> object) {
    auto it = std::find(constructionObjects.begin(), constructionObjects.end(), object);
    if (it != constructionObjects.end()) {
        constructionObjects.erase(it);
        std::cout << fullname << " удален(а) с проекта по адресу " << object->getAddress() << std::endl;
    }
}

// Перегрузка оператора < для сортировки по зарплате
bool Staff::operator<(const Staff& other) const {
    return this->salary < other.salary;
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

// ДРУЖЕСТВЕННАЯ ФУНКЦИЯ: Перегрузка оператора << для вывода сотрудника
std::ostream& operator<<(std::ostream& os, const Staff& staff) {
    os << staff.fullname << " (" << staffRankToString(staff.rank) << ") - $" << staff.salary;
    return os;
}
