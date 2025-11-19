#include "Tool.hpp"
#include <iostream>

// Реализация конструктора
Tool::Tool(const std::string& name, int count, ToolType type)
    : Equipment(name, count), type(type) {
}

// Реализация деструктора
Tool::~Tool() {
    std::cout << "Вызван деструктор Tool для: " << name << std::endl;
}

// Реализация геттера
ToolType Tool::getType() const {
    return type;
}

// Реализация сеттера
void Tool::setType(ToolType type) {
    this->type = type;
}

// Реализация функции отображения информации
void Tool::displayInfo() const {
    std::cout << "=== Инструмент ===" << std::endl;
    std::cout << "Название: " << name << std::endl;
    std::cout << "Тип: " << toolTypeToString(type) << std::endl;
    std::cout << "Количество: " << count << " ед." << std::endl;
}
