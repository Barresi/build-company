#pragma once

#include "Staff.hpp"
#include "Warehouse.hpp"
#include "ConstructionObject.hpp"
#include <string>
#include <vector>
#include <memory>

// Главный класс, представляющий строительную компанию
class ConstructionCompany {
private:
    std::string companyName;
    std::vector<std::shared_ptr<Staff>> staff;
    std::vector<std::shared_ptr<Warehouse>> warehouses;
    std::vector<std::shared_ptr<ConstructionObject>> constructionObjects;

public:
    // Конструктор
    ConstructionCompany(const std::string& companyName);

    // Деструктор
    ~ConstructionCompany();

    // Геттеры
    std::string getCompanyName() const;
    const std::vector<std::shared_ptr<Staff>>& getStaff() const;
    const std::vector<std::shared_ptr<Warehouse>>& getWarehouses() const;
    const std::vector<std::shared_ptr<ConstructionObject>>& getConstructionObjects() const;

    // Сеттеры
    void setCompanyName(const std::string& companyName);

    // Управление персоналом
    void addStaff(std::shared_ptr<Staff> person);
    void deleteStaff(int staffId);

    // Управление складами
    void addWarehouse(std::shared_ptr<Warehouse> warehouse);
    void deleteWarehouse(int warehouseId);

    // Управление строительными объектами
    void buildNewObject(std::shared_ptr<ConstructionObject> object);
    void sellObject(int objectId);

    // Отображение информации
    void displayInfo() const;
    void displayAllStaff() const;
    void displayAllWarehouses() const;
    void displayAllObjects() const;
};
