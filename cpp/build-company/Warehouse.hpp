#pragma once

#include "Material.hpp"
#include "Equipment.hpp"
#include <string>
#include <vector>
#include <memory>

// Класс, представляющий склад для материалов и оборудования
class Warehouse {
private:
    std::string address;
    std::vector<std::shared_ptr<Material>> materials;
    std::vector<std::shared_ptr<Equipment>> equipment;

public:
    // Конструктор
    Warehouse(const std::string& address);

    // Деструктор
    ~Warehouse();

    // Геттеры
    std::string getAddress() const;
    const std::vector<std::shared_ptr<Material>>& getMaterials() const;
    const std::vector<std::shared_ptr<Equipment>>& getEquipment() const;

    // Сеттеры
    void setAddress(const std::string& address);

    // Добавление материалов и оборудования
    void addMaterial(std::shared_ptr<Material> material);
    void addEquipment(std::shared_ptr<Equipment> equipment);

    // Удаление материалов и оборудования
    void removeMaterial(std::shared_ptr<Material> material);
    void removeEquipment(std::shared_ptr<Equipment> equipment);

    // Перегрузка оператора [] для доступа к материалам по индексу
    std::shared_ptr<Material> operator[](size_t index);
    const std::shared_ptr<Material> operator[](size_t index) const;

    // Отображение информации
    void displayInfo() const;
    void displayInventory() const;
};
