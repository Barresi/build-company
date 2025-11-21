#include "ConstructionCompany.hpp"
#include <iostream>

// Реализация конструктора
ConstructionCompany::ConstructionCompany(const std::string& companyName)
    : companyName(companyName) {
    std::cout << "Создана строительная компания '" << companyName << "'" << std::endl;
}

// Реализация деструктора
ConstructionCompany::~ConstructionCompany() {
    std::cout << "Вызван деструктор ConstructionCompany для: " << companyName << std::endl;
}

// Реализация геттеров
std::string ConstructionCompany::getCompanyName() const {
    return companyName;
}

const std::vector<Staff*>& ConstructionCompany::getStaff() const {
    return staff;
}

const std::vector<Warehouse*>& ConstructionCompany::getWarehouses() const {
    return warehouses;
}

const std::vector<ConstructionObject*>& ConstructionCompany::getConstructionObjects() const {
    return constructionObjects;
}

// Реализация сеттера
void ConstructionCompany::setCompanyName(const std::string& companyName) {
    this->companyName = companyName;
}

// Добавление сотрудника
void ConstructionCompany::addStaff(Staff* person) {
    if (person != nullptr) {
        staff.push_back(person);
        std::cout << "Добавлен сотрудник: " << person->getFullname() << std::endl;
    }
}

// Удаление сотрудника по индексу
void ConstructionCompany::deleteStaff(int staffId) {
    if (staffId >= 0 && staffId < static_cast<int>(staff.size())) {
        std::cout << "Удален сотрудник: " << staff[staffId]->getFullname() << std::endl;
        staff.erase(staff.begin() + staffId);
    } else {
        std::cout << "Ошибка: Неверный ID сотрудника" << std::endl;
    }
}

// Добавление склада
void ConstructionCompany::addWarehouse(Warehouse* warehouse) {
    if (warehouse != nullptr) {
        warehouses.push_back(warehouse);
        std::cout << "Добавлен склад по адресу: " << warehouse->getAddress() << std::endl;
    }
}

// Удаление склада по индексу
void ConstructionCompany::deleteWarehouse(int warehouseId) {
    if (warehouseId >= 0 && warehouseId < static_cast<int>(warehouses.size())) {
        std::cout << "Удален склад по адресу: " << warehouses[warehouseId]->getAddress() << std::endl;
        warehouses.erase(warehouses.begin() + warehouseId);
    } else {
        std::cout << "Ошибка: Неверный ID склада" << std::endl;
    }
}

// Добавление строительного объекта
void ConstructionCompany::buildNewObject(ConstructionObject* object) {
    if (object != nullptr) {
        constructionObjects.push_back(object);
        std::cout << "Начат новый строительный проект по адресу: " << object->getAddress() << std::endl;
    }
}

// Удаление строительного объекта по индексу
void ConstructionCompany::sellObject(int objectId) {
    if (objectId >= 0 && objectId < static_cast<int>(constructionObjects.size())) {
        std::cout << "Продан/Завершен проект по адресу: " << constructionObjects[objectId]->getAddress() << std::endl;
        constructionObjects.erase(constructionObjects.begin() + objectId);
    } else {
        std::cout << "Ошибка: Неверный ID объекта" << std::endl;
    }
}

// Отображение информации о компании
void ConstructionCompany::displayInfo() const {
    std::cout << "\n========================================" << std::endl;
    std::cout << "=== Информация о строительной компании ===" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Название компании: " << companyName << std::endl;
    std::cout << "Всего сотрудников: " << staff.size() << std::endl;
    std::cout << "Всего складов: " << warehouses.size() << std::endl;
    std::cout << "Всего строительных проектов: " << constructionObjects.size() << std::endl;
    std::cout << "========================================\n" << std::endl;
}

// Отображение всех сотрудников
void ConstructionCompany::displayAllStaff() const {
    std::cout << "\n=== Все сотрудники ===" << std::endl;
    if (staff.empty()) {
        std::cout << "Сотрудники не зарегистрированы" << std::endl;
    } else {
        for (size_t i = 0; i < staff.size(); ++i) {
            std::cout << "Сотрудник #" << i << ":" << std::endl;
            staff[i]->displayInfo();
            std::cout << std::endl;
        }
    }
}

// Отображение всех складов
void ConstructionCompany::displayAllWarehouses() const {
    std::cout << "\n=== Все склады ===" << std::endl;
    if (warehouses.empty()) {
        std::cout << "Склады не зарегистрированы" << std::endl;
    } else {
        for (size_t i = 0; i < warehouses.size(); ++i) {
            std::cout << "Склад #" << i << ":" << std::endl;
            warehouses[i]->displayInfo();
            std::cout << std::endl;
        }
    }
}

// Отображение всех строительных объектов
void ConstructionCompany::displayAllObjects() const {
    std::cout << "\n=== Все строительные проекты ===" << std::endl;
    if (constructionObjects.empty()) {
        std::cout << "Строительные проекты не зарегистрированы" << std::endl;
    } else {
        for (size_t i = 0; i < constructionObjects.size(); ++i) {
            std::cout << "Проект #" << i << ":" << std::endl;
            constructionObjects[i]->displayInfo();
            std::cout << std::endl;
        }
    }
}
