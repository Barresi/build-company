#ifndef CONSTRUCTION_COMPANY_HPP
#define CONSTRUCTION_COMPANY_HPP

#include "Staff.hpp"
#include "Warehouse.hpp"
#include "ConstructionObject.hpp"
#include <string>
#include <vector>

// Главный класс, представляющий строительную компанию
class ConstructionCompany {
private:
    std::string companyName;
    std::vector<Staff*> staff;
    std::vector<Warehouse*> warehouses;
    std::vector<ConstructionObject*> constructionObjects;

public:
    // Конструктор
    ConstructionCompany(const std::string& companyName);

    // Деструктор
    ~ConstructionCompany();

    // Геттеры
    std::string getCompanyName() const;
    const std::vector<Staff*>& getStaff() const;
    const std::vector<Warehouse*>& getWarehouses() const;
    const std::vector<ConstructionObject*>& getConstructionObjects() const;

    // Сеттеры
    void setCompanyName(const std::string& companyName);

    // Управление персоналом
    void addStaff(Staff* person);
    void deleteStaff(int staffId);

    // Управление складами
    void addWarehouse(Warehouse* warehouse);
    void deleteWarehouse(int warehouseId);

    // Управление строительными объектами
    void buildNewObject(ConstructionObject* object);
    void sellObject(int objectId);

    // Отображение информации
    void displayInfo() const;
    void displayAllStaff() const;
    void displayAllWarehouses() const;
    void displayAllObjects() const;
};

#endif // CONSTRUCTION_COMPANY_HPP
