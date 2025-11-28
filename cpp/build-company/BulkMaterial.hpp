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
};
