#include "Warehouse.hpp"
#include <iostream>
#include <algorithm>

// Реализация конструктора
Warehouse::Warehouse(const std::string& address) : address(address) {
}

// Реализация деструктора
Warehouse::~Warehouse() {
    std::cout << "Вызван деструктор Warehouse для: " << address << std::endl;
}

// Реализация геттеров
std::string Warehouse::getAddress() const {
    return address;
}

const std::vector<std::shared_ptr<Material>>& Warehouse::getMaterials() const {
    return materials;
}

const std::vector<std::shared_ptr<Equipment>>& Warehouse::getEquipment() const {
    return equipment;
}

// Реализация сеттера
void Warehouse::setAddress(const std::string& address) {
    this->address = address;
}

// Добавление материала
void Warehouse::addMaterial(std::shared_ptr<Material> material) {
    if (material) {
        materials.push_back(material);
        std::cout << "Добавлен материал '" << material->getName() << "' на склад по адресу " << address << std::endl;
    }
}

// Добавление оборудования
void Warehouse::addEquipment(std::shared_ptr<Equipment> equipment) {
    if (equipment) {
        this->equipment.push_back(equipment);
        std::cout << "Добавлено оборудование '" << equipment->getName() << "' на склад по адресу " << address << std::endl;
    }
}

// Удаление материала
void Warehouse::removeMaterial(std::shared_ptr<Material> material) {
    auto it = std::find(materials.begin(), materials.end(), material);
    if (it != materials.end()) {
        materials.erase(it);
        std::cout << "Удален материал '" << material->getName() << "' со склада" << std::endl;
    }
}

// Удаление оборудования
void Warehouse::removeEquipment(std::shared_ptr<Equipment> equipment) {
    auto it = std::find(this->equipment.begin(), this->equipment.end(), equipment);
    if (it != this->equipment.end()) {
        this->equipment.erase(it);
        std::cout << "Удалено оборудование '" << equipment->getName() << "' со склада" << std::endl;
    }
}

// Реализация функции отображения информации
void Warehouse::displayInfo() const {
    std::cout << "=== Склад ===" << std::endl;
    std::cout << "Адрес: " << address << std::endl;
    std::cout << "Всего материалов: " << materials.size() << std::endl;
    std::cout << "Всего оборудования: " << equipment.size() << std::endl;
}

// Перегрузка оператора [] для доступа к материалам по индексу
std::shared_ptr<Material> Warehouse::operator[](size_t index) {
    if (index < materials.size()) {
        return materials[index];
    }
    std::cout << "Ошибка: Индекс материала вне диапазона!" << std::endl;
    return nullptr;
}

const std::shared_ptr<Material> Warehouse::operator[](size_t index) const {
    if (index < materials.size()) {
        return materials[index];
    }
    std::cout << "Ошибка: Индекс материала вне диапазона!" << std::endl;
    return nullptr;
}

// Отображение полного инвентаря
void Warehouse::displayInventory() const {
    std::cout << "\n=== Инвентарь склада по адресу " << address << " ===" << std::endl;

    std::cout << "\n--- Материалы ---" << std::endl;
    if (materials.empty()) {
        std::cout << "Материалы отсутствуют" << std::endl;
    } else {
        for (const auto& material : materials) {
            material->displayInfo();
            std::cout << std::endl;
        }
    }

    std::cout << "--- Оборудование ---" << std::endl;
    if (equipment.empty()) {
        std::cout << "Оборудование отсутствует" << std::endl;
    } else {
        for (const auto& equip : equipment) {
            equip->displayInfo();
            std::cout << std::endl;
        }
    }
}
