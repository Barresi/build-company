#pragma once

#include "Enums.hpp"
#include <string>

// Класс, представляющий строительный проект/объект
class ConstructionObject {
private:
    std::string address;
    ObjectType objectType;
    ProjectStatus status;

public:
    // Конструктор
    ConstructionObject(const std::string& address, ObjectType objectType, ProjectStatus status);

    // Деструктор
    ~ConstructionObject();

    // Геттеры
    std::string getAddress() const;
    ObjectType getObjectType() const;
    ProjectStatus getStatus() const;

    // Сеттеры
    void setAddress(const std::string& address);
    void setObjectType(ObjectType objectType);
    void setStatus(ProjectStatus status);

    // Отображение информации
    void displayInfo() const;
};
