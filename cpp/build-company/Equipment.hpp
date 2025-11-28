#pragma once

#include <string>

// Абстрактный базовый класс для всего оборудования
class Equipment {
protected:
    std::string name;
    int count;

public:
    // Конструктор
    Equipment(const std::string& name, int count);

    // Виртуальный деструктор для правильной очистки памяти
    virtual ~Equipment();

    // Геттеры
    std::string getName() const;
    int getCount() const;

    // Сеттеры
    void setName(const std::string& name);
    void setCount(int count);

    // Добавить или удалить количество
    void addCount(int amount);
    void removeCount(int amount);

    // Чисто виртуальная функция для отображения информации об оборудовании
    virtual void displayInfo() const = 0;
};
