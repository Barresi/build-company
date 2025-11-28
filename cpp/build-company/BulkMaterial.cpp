#include "BulkMaterial.hpp"
#include <iostream>
#include <iomanip>

// Реализация конструктора
BulkMaterial::BulkMaterial(const std::string& name, MeasureType measureUnit, float count)
    : Material(name), measureUnit(measureUnit), count(count) {
}

// Конструктор копирования (вызов конструктора базового класса)
BulkMaterial::BulkMaterial(const BulkMaterial& other)
    : Material(other.name), measureUnit(other.measureUnit), count(other.count) {
    std::cout << "Вызван конструктор копирования BulkMaterial для: " << name << std::endl;
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
    if (amount <= 0) return;
    count += amount;
    std::cout << "Добавлено " << amount << " " << measureTypeToString(measureUnit)
              << " к " << name << ". Новое количество: " << count << std::endl;
}

// Удаление количества
void BulkMaterial::removeCount(float amount) {
    if (amount <= 0) return;
    if (amount > count) {
        std::cout << "Ошибка: Невозможно удалить " << amount << ". Доступно только " << count << std::endl;
        return;
    }
    count -= amount;
    std::cout << "Удалено " << amount << " " << measureTypeToString(measureUnit)
              << " из " << name << ". Осталось: " << count << std::endl;
}

// Реализация функции отображения информации
void BulkMaterial::displayInfo() const {
    std::cout << "=== Сыпучий материал ===" << std::endl;
    std::cout << "Название: " << name << std::endl;
    std::cout << "Количество: " << std::fixed << std::setprecision(2) << count << " "
              << measureTypeToString(measureUnit) << std::endl;
}

// Перегрузка оператора + для сложения количества материалов
BulkMaterial BulkMaterial::operator+(const BulkMaterial& other) const {
    if (this->name != other.name || this->measureUnit != other.measureUnit) {
        std::cout << "Предупреждение: Попытка сложить разные материалы или единицы измерения!" << std::endl;
        return *this;
    }
    return BulkMaterial(this->name, this->measureUnit, this->count + other.count);
}

// Перегрузка оператора += для добавления количества
BulkMaterial& BulkMaterial::operator+=(const BulkMaterial& other) {
    if (this->name == other.name && this->measureUnit == other.measureUnit) {
        this->count += other.count;
    } else {
        std::cout << "Предупреждение: Попытка добавить разный материал или единицу измерения!" << std::endl;
    }
    return *this;
}

// Перегрузка оператора == для сравнения
bool BulkMaterial::operator==(const BulkMaterial& other) const {
    return this->name == other.name &&
           this->measureUnit == other.measureUnit &&
           this->count == other.count;
}
