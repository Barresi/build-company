#pragma once

#include "Enums.hpp"
#include "ConstructionObject.hpp"
#include <string>
#include <vector>
#include <memory>
#include <iostream>

// Класс, представляющий сотрудника
class Staff {
private:
    std::string fullname;
    StaffRank rank;
    StaffSpecialization specialization;
    std::string telephone;
    std::string hiringDate;
    std::vector<std::shared_ptr<ConstructionObject>> constructionObjects;
    int salary;

public:
    // Конструктор
    Staff(const std::string& fullname, StaffRank rank, StaffSpecialization specialization,
          const std::string& telephone, const std::string& hiringDate, int salary);

    // Конструктор копирования
    Staff(const Staff& other);

    // Деструктор
    ~Staff();

    // Геттеры
    std::string getFullname() const;
    StaffRank getRank() const;
    StaffSpecialization getSpecialization() const;
    std::string getTelephone() const;
    std::string getHiringDate() const;
    int getSalary() const;
    const std::vector<std::shared_ptr<ConstructionObject>>& getConstructionObjects() const;

    // Сеттеры
    void setFullname(const std::string& fullname);
    void setRank(StaffRank rank);
    void setSpecialization(StaffSpecialization specialization);
    void setTelephone(const std::string& telephone);
    void setHiringDate(const std::string& hiringDate);
    void setSalary(int salary);

    // Управление назначением на строительные объекты
    void assignToObject(std::shared_ptr<ConstructionObject> object);
    void removeFromObject(std::shared_ptr<ConstructionObject> object);

    // Перегрузка оператора < для сортировки по зарплате
    bool operator<(const Staff& other) const;

    // Отображение информации
    void displayInfo() const;

    // ДРУЖЕСТВЕННАЯ ФУНКЦИЯ: Перегрузка оператора << для вывода сотрудника
    friend std::ostream& operator<<(std::ostream& os, const Staff& staff);
};
