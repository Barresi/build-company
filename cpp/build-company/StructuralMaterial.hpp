#ifndef STRUCTURAL_MATERIAL_HPP
#define STRUCTURAL_MATERIAL_HPP

#include "Material.hpp"

// Класс для конструкционных материалов (кирпичи, балки, панели и т.д.)
class StructuralMaterial : public Material {
private:
    float width;
    float height;
    float length;
    int count;

public:
    // Конструктор
    StructuralMaterial(const std::string& name, float width, float height, float length, int count);

    // Деструктор
    ~StructuralMaterial();

    // Геттеры
    float getWidth() const;
    float getHeight() const;
    float getLength() const;
    int getCount() const;

    // Сеттеры
    void setWidth(float width);
    void setHeight(float height);
    void setLength(float length);
    void setCount(int count);

    // Добавить или удалить количество
    void addCount(int amount);
    void removeCount(int amount);

    // Вычислить объем одной единицы
    float calculateVolume() const;

    // Переопределение функции отображения информации
    void displayInfo() const override;
};

#endif // STRUCTURAL_MATERIAL_HPP
