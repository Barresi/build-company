#pragma once

#include "Material.hpp"
#include "Enums.hpp"

// Класс для сыпучих материалов (цемент, песок, щебень и т.д.)
class BulkMaterial : public Material {
private:
    MeasureType measureUnit;
    float count;

public:
    // Конструктор
    BulkMaterial(const std::string& name, MeasureType measureUnit, float count);

    // Конструктор копирования
    BulkMaterial(const BulkMaterial& other);

    // Деструктор
    ~BulkMaterial();

    // Геттеры
    MeasureType getMeasureUnit() const;
    float getCount() const;

    // Сеттеры
    void setMeasureUnit(MeasureType measureUnit);
    void setCount(float count);

    // Добавить или удалить количество
    void addCount(float amount);
    void removeCount(float amount);

    // Переопределение функции отображения информации
    void displayInfo() const override;

    // Перегрузка оператора + для сложения количества материалов
    BulkMaterial operator+(const BulkMaterial& other) const;

    // Перегрузка оператора += для добавления количества
    BulkMaterial& operator+=(const BulkMaterial& other);

    // Перегрузка оператора == для сравнения
    bool operator==(const BulkMaterial& other) const;
};
