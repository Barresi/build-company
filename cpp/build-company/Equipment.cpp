#include "Equipment.hpp"
#include <iostream>

// Реализация конструктора
Equipment::Equipment(const std::string& name, int count)
    : name(name), count(count) {
}

// Реализация деструктора
Equipment::~Equipment() {
    std::cout << "Вызван деструктор Equipment для: " << name << std::endl;
}

// Реализация геттеров
std::string Equipment::getName() const {
    return name;
}

int Equipment::getCount() const {
    return count;
}

// Реализация сеттеров
void Equipment::setName(const std::string& name) {
    this->name = name;
}

void Equipment::setCount(int count) {
    this->count = count;
}

// Добавление количества
void Equipment::addCount(int amount) {
    if (amount > 0) {
        count += amount;
        std::cout << "Добавлено " << amount << " ед. " << name
                  << ". Новое количество: " << count << std::endl;
    }
}

// Удаление количества
void Equipment::removeCount(int amount) {
    if (amount > 0 && amount <= count) {
        count -= amount;
        std::cout << "Удалено " << amount << " ед. " << name
                  << ". Осталось: " << count << std::endl;
    } else if (amount > count) {
        std::cout << "Ошибка: Невозможно удалить " << amount << ". Доступно только " << count << std::endl;
    }
}
