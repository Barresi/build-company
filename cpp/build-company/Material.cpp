#include "Material.hpp"
#include <iostream>

// Реализация конструктора
Material::Material(const std::string& name) : name(name) {
}

// Реализация деструктора
Material::~Material() {
    std::cout << "Вызван деструктор Material для: " << name << std::endl;
}

// Реализация геттера
std::string Material::getName() const {
    return name;
}

// Реализация сеттера
void Material::setName(const std::string& name) {
    this->name = name;
}
