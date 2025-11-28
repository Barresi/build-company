#pragma once

#include <string>
#include <iostream>

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

    // Перегрузка оператора == для сравнения материалов по имени
    bool operator==(const Material& other) const;

    // ДРУЖЕСТВЕННАЯ ФУНКЦИЯ: Перегрузка оператора << для вывода материала
    friend std::ostream& operator<<(std::ostream& os, const Material& material);
};
