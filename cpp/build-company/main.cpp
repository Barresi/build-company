#include <iostream>
#include <vector>
#include <Windows.h>
#include "ConstructionCompany.hpp"
#include "BulkMaterial.hpp"
#include "StructuralMaterial.hpp"
#include "Tool.hpp"
#include "ConstructionMachinery.hpp"

using namespace std;

// Функция для демонстрации работы со ссылками
void displayMaterialByReference(const Material& material) {
    cout << "\n=== Демонстрация работы со ссылками ===" << endl;
    material.displayInfo();
}

// Функция для демонстрации работы с указателями
void displayStaffByPointer(const Staff* staff) {
    cout << "\n=== Демонстрация работы с указателями ===" << endl;
    if (staff != nullptr) {
        staff->displayInfo();
    }
}

int main() {

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "========================================" << endl;
    cout << "Система управления строительной компанией" << endl;
    cout << "========================================\n" << endl;

    // ===================================================================
    // 1. СТАТИЧЕСКАЯ ИНИЦИАЛИЗАЦИЯ ОБЪЕКТОВ
    // ===================================================================
    cout << "\n### ДЕМОНСТРАЦИЯ 1: Статическая инициализация ###\n" << endl;

    // Статическая инициализация материалов
    BulkMaterial cement("Portland Cement M500", MeasureType::TONS, 50.5f);
    StructuralMaterial brick("Red Brick", 0.25f, 0.12f, 0.065f, 10000);

    cout << "Созданы статические объекты:" << endl;
    cement.displayInfo();
    cout << endl;
    brick.displayInfo();

    // Статическая инициализация оборудования
    Tool drill("Bosch GSB 13 RE", 5, ToolType::POWER_DRILL);
    cout << endl;
    drill.displayInfo();

    // Статическая инициализация строительного объекта
    ConstructionObject project1("123 Main Street", ObjectType::RESIDENTIAL, ProjectStatus::PLANNING);
    cout << endl;
    project1.displayInfo();

    // Статическая инициализация сотрудника
    Staff worker1("John Smith", StaffRank::WORKER, StaffSpecialization::MASON,
                  "+1-555-0101", "2023-01-15", 45000);
    cout << endl;
    worker1.displayInfo();

    // ===================================================================
    // 2. ДИНАМИЧЕСКАЯ ИНИЦИАЛИЗАЦИЯ (new/delete)
    // ===================================================================
    cout << "\n\n### ДЕМОНСТРАЦИЯ 2: Динамическая инициализация с new/delete ###\n" << endl;

    // Динамическая инициализация материалов
    BulkMaterial* sand = new BulkMaterial("River Sand", MeasureType::CUBIC_METERS, 100.0f);
    StructuralMaterial* rebar = new StructuralMaterial("Steel Rebar 12mm", 0.012f, 0.012f, 6.0f, 500);

    cout << "Динамически выделенные объекты:" << endl;
    sand->displayInfo();
    cout << endl;
    rebar->displayInfo();

    // Динамическая инициализация оборудования
    ConstructionMachinery* excavator = new ConstructionMachinery(
        "Caterpillar 320", 2, VehicleType::EXCAVATOR, FuelType::DIESEL
    );
    cout << endl;
    excavator->displayInfo();

    // Динамическая инициализация сотрудника
    Staff* engineer1 = new Staff(
        "Emily Johnson", StaffRank::ENGINEER, StaffSpecialization::GENERAL,
        "+1-555-0202", "2022-06-01", 75000
    );
    cout << endl;
    engineer1->displayInfo();

    // Динамическая инициализация строительной компании
    ConstructionCompany* company = new ConstructionCompany("BuildMaster Construction Co.");

    // ===================================================================
    // 3. РАБОТА СО ССЫЛКАМИ И УКАЗАТЕЛЯМИ
    // ===================================================================
    cout << "\n\n### ДЕМОНСТРАЦИЯ 3: Работа со ссылками и указателями ###\n" << endl;

    // Работа со ссылкой
    displayMaterialByReference(cement);

    // Работа с указателем
    displayStaffByPointer(engineer1);

    // Демонстрация разыменования указателя
    cout << "\n=== Разыменование указателя ===" << endl;
    cout << "Имя инженера через указатель: " << engineer1->getFullname() << endl;
    cout << "Зарплата инженера через указатель: $" << (*engineer1).getSalary() << endl;

    // Демонстрация работы со ссылкой
    cout << "\n=== Работа со ссылкой ===" << endl;
    Material& cementRef = cement;
    cout << "Название материала через ссылку: " << cementRef.getName() << endl;

    // ===================================================================
    // 4. ДИНАМИЧЕСКИЙ МАССИВ ОБЪЕКТОВ
    // ===================================================================
    cout << "\n\n### ДЕМОНСТРАЦИЯ 4: Динамический массив объектов ###\n" << endl;

    // Создание динамического массива указателей на ConstructionObject
    int arraySize = 3;
    ConstructionObject** projectArray = new ConstructionObject*[arraySize];

    projectArray[0] = new ConstructionObject("456 Oak Avenue", ObjectType::COMMERCIAL, ProjectStatus::IN_PROGRESS);
    projectArray[1] = new ConstructionObject("789 Pine Road", ObjectType::INDUSTRIAL, ProjectStatus::PLANNING);
    projectArray[2] = new ConstructionObject("321 Elm Street", ObjectType::RESIDENTIAL, ProjectStatus::IN_PROGRESS);

    cout << "Динамический массив указателей на ConstructionObject:" << endl;
    for (int i = 0; i < arraySize; ++i) {
        cout << "\nПроект [" << i << "]:" << endl;
        projectArray[i]->displayInfo();
    }

    // ===================================================================
    // 5. МАССИВ ДИНАМИЧЕСКИХ ОБЪЕКТОВ (МАССИВ УКАЗАТЕЛЕЙ)
    // ===================================================================
    cout << "\n\n### ДЕМОНСТРАЦИЯ 5: Массив динамических объектов (указатели) ###\n" << endl;

    // Создание массива указателей на объекты Staff
    const int staffCount = 4;
    Staff* staffArray[staffCount];

    staffArray[0] = new Staff("Michael Brown", StaffRank::WORKER, StaffSpecialization::WELDER,
                               "+1-555-0303", "2023-03-10", 48000);
    staffArray[1] = new Staff("Sarah Davis", StaffRank::FOREMAN, StaffSpecialization::ELECTRICIAN,
                               "+1-555-0404", "2021-08-20", 62000);
    staffArray[2] = new Staff("Robert Wilson", StaffRank::SITE_MANAGER, StaffSpecialization::GENERAL,
                               "+1-555-0505", "2020-02-15", 85000);
    staffArray[3] = new Staff("Lisa Martinez", StaffRank::WORKER, StaffSpecialization::CARPENTER,
                               "+1-555-0606", "2023-07-01", 46000);

    cout << "Массив указателей на объекты Staff:" << endl;
    for (int i = 0; i < staffCount; ++i) {
        cout << "\nСотрудник [" << i << "]:" << endl;
        staffArray[i]->displayInfo();
    }

    // ===================================================================
    // 6. КОМПЛЕКСНАЯ ДЕМОНСТРАЦИЯ СИСТЕМЫ
    // ===================================================================
    cout << "\n\n### ДЕМОНСТРАЦИЯ 6: Полная интеграция системы ###\n" << endl;

    // Создание склада
    Warehouse* mainWarehouse = new Warehouse("100 Industrial Drive");

    // Добавление материалов на склад
    mainWarehouse->addMaterial(sand);
    mainWarehouse->addMaterial(rebar);

    // Добавление оборудования на склад
    mainWarehouse->addEquipment(excavator);
    Tool* grinder = new Tool("Makita 9557NB", 10, ToolType::ANGLE_GRINDER);
    mainWarehouse->addEquipment(grinder);

    // Добавление склада в компанию
    company->addWarehouse(mainWarehouse);

    // Добавление сотрудников в компанию
    company->addStaff(engineer1);
    for (int i = 0; i < staffCount; ++i) {
        company->addStaff(staffArray[i]);
    }

    // Создание и добавление строительных объектов динамически
    ConstructionObject* project2 = new ConstructionObject(
        "555 Business Parkway", ObjectType::COMMERCIAL, ProjectStatus::IN_PROGRESS
    );
    company->buildNewObject(project2);

    // Назначение сотрудников на проекты
    engineer1->assignToObject(project2);
    staffArray[0]->assignToObject(project2);
    staffArray[1]->assignToObject(project2);

    // Отображение полной информации о компании
    company->displayInfo();
    company->displayAllStaff();
    company->displayAllWarehouses();
    company->displayAllObjects();

    // Отображение инвентаря склада
    mainWarehouse->displayInventory();

    // ===================================================================
    // 7. ДЕМОНСТРАЦИЯ ОПЕРАЦИЙ С ОБЪЕКТАМИ
    // ===================================================================
    cout << "\n\n### ДЕМОНСТРАЦИЯ 7: Операции с объектами ###\n" << endl;

    // Работа с материалами
    cout << "\n--- Операции с материалами ---" << endl;
    sand->addCount(50.0f);
    sand->removeCount(20.0f);
    cout << endl;
    sand->displayInfo();

    // Работа с оборудованием
    cout << "\n--- Операции с оборудованием ---" << endl;
    grinder->addCount(5);
    grinder->removeCount(3);
    cout << endl;
    grinder->displayInfo();

    // Изменение статуса проекта
    cout << "\n--- Изменение статуса проекта ---" << endl;
    project2->setStatus(ProjectStatus::COMPLETED);

    // Обновление информации о сотруднике
    cout << "\n--- Обновление информации о сотруднике ---" << endl;
    staffArray[0]->setSalary(52000);
    cout << "Обновлена зарплата сотрудника " << staffArray[0]->getFullname() << " на $"
         << staffArray[0]->getSalary() << endl;

    // ===================================================================
    // 8. ОЧИСТКА ПАМЯТИ - УДАЛЕНИЕ ДИНАМИЧЕСКИХ ОБЪЕКТОВ
    // ===================================================================
    cout << "\n\n### ДЕМОНСТРАЦИЯ 8: Очистка памяти (delete) ###\n" << endl;

    // Удаление массива динамических объектов (указателей)
    cout << "Удаление массива сотрудников:" << endl;
    for (int i = 0; i < staffCount; ++i) {
        delete staffArray[i];
        staffArray[i] = nullptr;
    }

    // Удаление динамического массива объектов
    cout << "\nУдаление массива проектов:" << endl;
    for (int i = 0; i < arraySize; ++i) {
        delete projectArray[i];
        projectArray[i] = nullptr;
    }
    delete[] projectArray;
    projectArray = nullptr;

    // Удаление отдельных динамических объектов
    cout << "\nУдаление отдельных объектов:" << endl;
    delete sand;
    sand = nullptr;

    delete rebar;
    rebar = nullptr;

    delete excavator;
    excavator = nullptr;

    delete grinder;
    grinder = nullptr;

    delete engineer1;
    engineer1 = nullptr;

    delete project2;
    project2 = nullptr;

    delete mainWarehouse;
    mainWarehouse = nullptr;

    delete company;
    company = nullptr;

    cout << "\n========================================" << endl;
    cout << "Программа успешно завершена!" << endl;
    cout << "========================================" << endl;

    return 0;
}
