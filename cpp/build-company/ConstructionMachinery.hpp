#ifndef CONSTRUCTION_MACHINERY_HPP
#define CONSTRUCTION_MACHINERY_HPP

#include "Equipment.hpp"
#include "Enums.hpp"

// Класс для строительной техники и транспортных средств
class ConstructionMachinery : public Equipment {
private:
    VehicleType type;
    FuelType fuelType;

public:
    // Конструктор
    ConstructionMachinery(const std::string& name, int count, VehicleType type, FuelType fuelType);

    // Деструктор
    ~ConstructionMachinery();

    // Геттеры
    VehicleType getType() const;
    FuelType getFuelType() const;

    // Сеттеры
    void setType(VehicleType type);
    void setFuelType(FuelType fuelType);

    // Переопределение функции отображения информации
    void displayInfo() const override;
};

#endif // CONSTRUCTION_MACHINERY_HPP
