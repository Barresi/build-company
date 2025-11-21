#include "ConstructionObject.hpp"
#include <iostream>

// Реализация конструктора
ConstructionObject::ConstructionObject(const std::string& address, ObjectType objectType, ProjectStatus status)
    : address(address), objectType(objectType), status(status) {
}

// Реализация деструктора
ConstructionObject::~ConstructionObject() {
    std::cout << "Вызван деструктор ConstructionObject для: " << address << std::endl;
}

// Реализация геттеров
std::string ConstructionObject::getAddress() const {
    return address;
}

ObjectType ConstructionObject::getObjectType() const {
    return objectType;
}

ProjectStatus ConstructionObject::getStatus() const {
    return status;
}

// Реализация сеттеров
void ConstructionObject::setAddress(const std::string& address) {
    this->address = address;
}

void ConstructionObject::setObjectType(ObjectType objectType) {
    this->objectType = objectType;
}

void ConstructionObject::setStatus(ProjectStatus status) {
    this->status = status;
    std::cout << "Статус проекта по адресу " << address << " изменен на: "
              << projectStatusToString(status) << std::endl;
}

// Реализация функции отображения информации
void ConstructionObject::displayInfo() const {
    std::cout << "=== Строительный объект ===" << std::endl;
    std::cout << "Адрес: " << address << std::endl;
    std::cout << "Тип: " << objectTypeToString(objectType) << std::endl;
    std::cout << "Статус: " << projectStatusToString(status) << std::endl;
}
