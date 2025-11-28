#include "StructuralMaterial.hpp"
#include <iostream>
#include <iomanip>

// Реализация конструктора
StructuralMaterial::StructuralMaterial(const std::string& name, float width, float height, float length, int count)
    : Material(name), width(width), height(height), length(length), count(count) {
}

// Реализация деструктора
StructuralMaterial::~StructuralMaterial() {
    std::cout << "Вызван деструктор StructuralMaterial для: " << name << std::endl;
}

// Реализация геттеров
float StructuralMaterial::getWidth() const {
    return width;
}

float StructuralMaterial::getHeight() const {
    return height;
}

float StructuralMaterial::getLength() const {
    return length;
}

int StructuralMaterial::getCount() const {
    return count;
}

// Реализация сеттеров
void StructuralMaterial::setWidth(float width) {
    this->width = width;
}

void StructuralMaterial::setHeight(float height) {
    this->height = height;
}

void StructuralMaterial::setLength(float length) {
    this->length = length;
}

void StructuralMaterial::setCount(int count) {
    this->count = count;
}

// Добавление количества
void StructuralMaterial::addCount(int amount) {
    if (amount <= 0) return;
    count += amount;
    std::cout << "Добавлено " << amount << " шт. " << name
              << ". Новое количество: " << count << std::endl;
}

// Удаление количества
void StructuralMaterial::removeCount(int amount) {
    if (amount <= 0) return;
    if (amount > count) {
        std::cout << "Ошибка: Невозможно удалить " << amount << ". Доступно только " << count << std::endl;
        return;
    }
    count -= amount;
    std::cout << "Удалено " << amount << " шт. " << name
              << ". Осталось: " << count << std::endl;
}

// Вычисление объема одной единицы
float StructuralMaterial::calculateVolume() const {
    return width * height * length;
}

// Реализация функции отображения информации
void StructuralMaterial::displayInfo() const {
    std::cout << "=== Конструкционный материал ===" << std::endl;
    std::cout << "Название: " << name << std::endl;
    std::cout << "Размеры: " << std::fixed << std::setprecision(2)
              << width << " x " << height << " x " << length << " м" << std::endl;
    std::cout << "Количество: " << count << " шт." << std::endl;
    std::cout << "Объем единицы: " << std::fixed << std::setprecision(4)
              << calculateVolume() << " м3" << std::endl;
}
