#ifndef TOOL_HPP
#define TOOL_HPP

#include "Equipment.hpp"
#include "Enums.hpp"

// Класс для инструментов и ручного оборудования
class Tool : public Equipment {
private:
    ToolType type;

public:
    // Конструктор
    Tool(const std::string& name, int count, ToolType type);

    // Деструктор
    ~Tool();

    // Геттеры
    ToolType getType() const;

    // Сеттеры
    void setType(ToolType type);

    // Переопределение функции отображения информации
    void displayInfo() const override;
};

#endif // TOOL_HPP
