#include "BulkMaterial.hpp"
#include <iostream>
#include <iomanip>

// Реализация конструктора
BulkMaterial::BulkMaterial(const std::string& name, MeasureType measureUnit, float count)
    : Material(name), measureUnit(measureUnit), count(count) {
}

// Реализация деструктора
BulkMaterial::~BulkMaterial() {
    std::cout << "Вызван деструктор BulkMaterial для: " << name << std::endl;
}

// Реализация геттеров
MeasureType BulkMaterial::getMeasureUnit() const {
    return measureUnit;
}

float BulkMaterial::getCount() const {
    return count;
}

// Реализация сеттеров
void BulkMaterial::setMeasureUnit(MeasureType measureUnit) {
    this->measureUnit = measureUnit;
}

void BulkMaterial::setCount(float count) {
    this->count = count;
}

// Добавление количества
void BulkMaterial::addCount(float amount) {
    if (amount > 0) {
        count += amount;
        std::cout << "Добавлено " << amount << " " << measureTypeToString(measureUnit)
                  << " к " << name << ". Новое количество: " << count << std::endl;
    }
}

// Удаление количества
void BulkMaterial::removeCount(float amount) {
    if (amount > 0 && amount <= count) {
        count -= amount;
        std::cout << "Удалено " << amount << " " << measureTypeToString(measureUnit)
                  << " из " << name << ". Осталось: " << count << std::endl;
    } else if (amount > count) {
        std::cout << "Ошибка: Невозможно удалить " << amount << ". Доступно только " << count << std::endl;
    }
}

// Реализация функции отображения информации
void BulkMaterial::displayInfo() const {
    std::cout << "=== Сыпучий материал ===" << std::endl;
    std::cout << "Название: " << name << std::endl;
    std::cout << "Количество: " << std::fixed << std::setprecision(2) << count << " "
              << measureTypeToString(measureUnit) << std::endl;
}
