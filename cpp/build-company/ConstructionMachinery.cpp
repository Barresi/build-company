#include "ConstructionMachinery.hpp"
#include <iostream>

// Реализация конструктора
ConstructionMachinery::ConstructionMachinery(const std::string& name, int count, VehicleType type, FuelType fuelType)
    : Equipment(name, count), type(type), fuelType(fuelType) {
}

// Реализация деструктора
ConstructionMachinery::~ConstructionMachinery() {
    std::cout << "Вызван деструктор ConstructionMachinery для: " << name << std::endl;
}

// Реализация геттеров
VehicleType ConstructionMachinery::getType() const {
    return type;
}

FuelType ConstructionMachinery::getFuelType() const {
    return fuelType;
}

// Реализация сеттеров
void ConstructionMachinery::setType(VehicleType type) {
    this->type = type;
}

void ConstructionMachinery::setFuelType(FuelType fuelType) {
    this->fuelType = fuelType;
}

// Реализация функции отображения информации
void ConstructionMachinery::displayInfo() const {
    std::cout << "=== Строительная техника ===" << std::endl;
    std::cout << "Название: " << name << std::endl;
    std::cout << "Тип: " << vehicleTypeToString(type) << std::endl;
    std::cout << "Тип топлива: " << fuelTypeToString(fuelType) << std::endl;
    std::cout << "Количество: " << count << " ед." << std::endl;
}
