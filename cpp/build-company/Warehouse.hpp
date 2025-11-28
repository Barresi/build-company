#pragma once

#include "Material.hpp"
#include "Equipment.hpp"
#include <string>
#include <vector>

// Класс, представляющий склад для материалов и оборудования
class Warehouse {
private:
    std::string address;
    std::vector<Material*> materials;
    std::vector<Equipment*> equipment;

public:
    // Конструктор
    Warehouse(const std::string& address);

    // Деструктор
    ~Warehouse();

    // Геттеры
    std::string getAddress() const;
    const std::vector<Material*>& getMaterials() const;
    const std::vector<Equipment*>& getEquipment() const;

    // Сеттеры
    void setAddress(const std::string& address);

    // Добавление материалов и оборудования
    void addMaterial(Material* material);
    void addEquipment(Equipment* equipment);

    // Удаление материалов и оборудования
    void removeMaterial(Material* material);
    void removeEquipment(Equipment* equipment);

    // Отображение информации
    void displayInfo() const;
    void displayInventory() const;
};
