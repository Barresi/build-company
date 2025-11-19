#ifndef STAFF_HPP
#define STAFF_HPP

#include "Enums.hpp"
#include "ConstructionObject.hpp"
#include <string>
#include <vector>

// Класс, представляющий сотрудника
class Staff {
private:
    std::string fullname;
    StaffRank rank;
    StaffSpecialization specialization;
    std::string telephone;
    std::string hiringDate;
    std::vector<ConstructionObject*> constructionObjects;
    int salary;

public:
    // Конструктор
    Staff(const std::string& fullname, StaffRank rank, StaffSpecialization specialization,
          const std::string& telephone, const std::string& hiringDate, int salary);

    // Деструктор
    ~Staff();

    // Геттеры
    std::string getFullname() const;
    StaffRank getRank() const;
    StaffSpecialization getSpecialization() const;
    std::string getTelephone() const;
    std::string getHiringDate() const;
    int getSalary() const;
    const std::vector<ConstructionObject*>& getConstructionObjects() const;

    // Сеттеры
    void setFullname(const std::string& fullname);
    void setRank(StaffRank rank);
    void setSpecialization(StaffSpecialization specialization);
    void setTelephone(const std::string& telephone);
    void setHiringDate(const std::string& hiringDate);
    void setSalary(int salary);

    // Управление назначением на строительные объекты
    void assignToObject(ConstructionObject* object);
    void removeFromObject(ConstructionObject* object);

    // Отображение информации
    void displayInfo() const;
};

#endif // STAFF_HPP
