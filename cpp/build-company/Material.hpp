#pragma once

#include <string>

// Абстрактный базовый класс для всех материалов
class Material {
protected:
    std::string name;

public:
    // Конструктор
    Material(const std::string& name);

    // Виртуальный деструктор для правильной очистки памяти
    virtual ~Material();

    // Геттеры
    std::string getName() const;

    // Сеттеры
    void setName(const std::string& name);

    // Чисто виртуальная функция для отображения информации о материале
    virtual void displayInfo() const = 0;
};
