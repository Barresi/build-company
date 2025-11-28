#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
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

// Функция для демонстрации работы с умными указателями
void displayStaffByPointer(const shared_ptr<Staff>& staff) {
    cout << "\n=== Демонстрация работы с умными указателями ===" << endl;
    if (staff) {
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
    // 2. ДИНАМИЧЕСКАЯ ИНИЦИАЛИЗАЦИЯ (make_shared)
    // ===================================================================
    cout << "\n\n### ДЕМОНСТРАЦИЯ 2: Динамическая инициализация с make_shared ###\n" << endl;

    // Динамическая инициализация материалов
    auto sand = make_shared<BulkMaterial>("River Sand", MeasureType::CUBIC_METERS, 100.0f);
    auto rebar = make_shared<StructuralMaterial>("Steel Rebar 12mm", 0.012f, 0.012f, 6.0f, 500);

    cout << "Динамически выделенные объекты:" << endl;
    sand->displayInfo();
    cout << endl;
    rebar->displayInfo();

    // Динамическая инициализация оборудования
    auto excavator = make_shared<ConstructionMachinery>(
        "Caterpillar 320", 2, VehicleType::EXCAVATOR, FuelType::DIESEL
    );
    cout << endl;
    excavator->displayInfo();

    // Динамическая инициализация сотрудника
    auto engineer1 = make_shared<Staff>(
        "Emily Johnson", StaffRank::ENGINEER, StaffSpecialization::GENERAL,
        "+1-555-0202", "2022-06-01", 75000
    );
    cout << endl;
    engineer1->displayInfo();

    // Динамическая инициализация строительной компании
    auto company = make_shared<ConstructionCompany>("BuildMaster Construction Co.");

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
    // 4. ВЕКТОР УМНЫХ УКАЗАТЕЛЕЙ НА ОБЪЕКТЫ
    // ===================================================================
    cout << "\n\n### ДЕМОНСТРАЦИЯ 4: Вектор умных указателей на объекты ###\n" << endl;

    // Создание вектора умных указателей на ConstructionObject
    vector<shared_ptr<ConstructionObject>> projectArray;

    projectArray.push_back(make_shared<ConstructionObject>("456 Oak Avenue", ObjectType::COMMERCIAL, ProjectStatus::IN_PROGRESS));
    projectArray.push_back(make_shared<ConstructionObject>("789 Pine Road", ObjectType::INDUSTRIAL, ProjectStatus::PLANNING));
    projectArray.push_back(make_shared<ConstructionObject>("321 Elm Street", ObjectType::RESIDENTIAL, ProjectStatus::IN_PROGRESS));

    cout << "Вектор умных указателей на ConstructionObject:" << endl;
    for (size_t i = 0; i < projectArray.size(); ++i) {
        cout << "\nПроект [" << i << "]:" << endl;
        projectArray[i]->displayInfo();
    }

    // ===================================================================
    // 5. ВЕКТОР УМНЫХ УКАЗАТЕЛЕЙ НА ОБЪЕКТЫ STAFF
    // ===================================================================
    cout << "\n\n### ДЕМОНСТРАЦИЯ 5: Вектор умных указателей на объекты Staff ###\n" << endl;

    // Создание вектора умных указателей на объекты Staff
    vector<shared_ptr<Staff>> staffArray;

    staffArray.push_back(make_shared<Staff>("Michael Brown", StaffRank::WORKER, StaffSpecialization::WELDER,
                               "+1-555-0303", "2023-03-10", 48000));
    staffArray.push_back(make_shared<Staff>("Sarah Davis", StaffRank::FOREMAN, StaffSpecialization::ELECTRICIAN,
                               "+1-555-0404", "2021-08-20", 62000));
    staffArray.push_back(make_shared<Staff>("Robert Wilson", StaffRank::SITE_MANAGER, StaffSpecialization::GENERAL,
                               "+1-555-0505", "2020-02-15", 85000));
    staffArray.push_back(make_shared<Staff>("Lisa Martinez", StaffRank::WORKER, StaffSpecialization::CARPENTER,
                               "+1-555-0606", "2023-07-01", 46000));

    cout << "Вектор умных указателей на объекты Staff:" << endl;
    for (size_t i = 0; i < staffArray.size(); ++i) {
        cout << "\nСотрудник [" << i << "]:" << endl;
        staffArray[i]->displayInfo();
    }

    // ===================================================================
    // 6. КОМПЛЕКСНАЯ ДЕМОНСТРАЦИЯ СИСТЕМЫ
    // ===================================================================
    cout << "\n\n### ДЕМОНСТРАЦИЯ 6: Полная интеграция системы ###\n" << endl;

    // Создание склада
    auto mainWarehouse = make_shared<Warehouse>("100 Industrial Drive");

    // Добавление материалов на склад
    mainWarehouse->addMaterial(sand);
    mainWarehouse->addMaterial(rebar);

    // Добавление оборудования на склад
    mainWarehouse->addEquipment(excavator);
    auto grinder = make_shared<Tool>("Makita 9557NB", 10, ToolType::ANGLE_GRINDER);
    mainWarehouse->addEquipment(grinder);

    // Добавление склада в компанию
    company->addWarehouse(mainWarehouse);

    // Добавление сотрудников в компанию
    company->addStaff(engineer1);
    for (size_t i = 0; i < staffArray.size(); ++i) {
        company->addStaff(staffArray[i]);
    }

    // Создание и добавление строительных объектов динамически
    auto project2 = make_shared<ConstructionObject>(
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
    // 8. ДЕМОНСТРАЦИЯ ПЕРЕГРУЗКИ ОПЕРАТОРОВ И ДРУЖЕСТВЕННЫХ ФУНКЦИЙ
    // ===================================================================
    cout << "\n\n### ДЕМОНСТРАЦИЯ 8: Перегрузка операторов и дружественные функции ###\n" << endl;

    // 1. Дружественная функция operator<< для Material
    cout << "--- 1. Дружественная функция operator<< для Material ---" << endl;
    cout << "Вывод материала через operator<<: " << *sand << endl;

    // 2. Дружественная функция operator<< для Staff
    cout << "\n--- 2. Дружественная функция operator<< для Staff ---" << endl;
    cout << "Вывод сотрудника через operator<<: " << *engineer1 << endl;

    // 3. Перегрузка operator+ для сложения материалов
    cout << "\n--- 3. Перегрузка operator+ для BulkMaterial ---" << endl;
    auto sand1 = make_shared<BulkMaterial>("River Sand", MeasureType::CUBIC_METERS, 50.0f);
    auto sand2 = make_shared<BulkMaterial>("River Sand", MeasureType::CUBIC_METERS, 30.0f);
    BulkMaterial sand3 = *sand1 + *sand2;
    cout << "Складываем " << sand1->getCount() << " + " << sand2->getCount() << " = " << sand3.getCount() << " куб.м песка" << endl;

    // 4. Перегрузка operator+= для добавления материалов
    cout << "\n--- 4. Перегрузка operator+= для BulkMaterial ---" << endl;
    auto cement1 = make_shared<BulkMaterial>("Cement", MeasureType::TONS, 10.0f);
    auto cement2 = make_shared<BulkMaterial>("Cement", MeasureType::TONS, 5.0f);
    cout << "До добавления: " << cement1->getCount() << " тонн" << endl;
    *cement1 += *cement2;
    cout << "После добавления: " << cement1->getCount() << " тонн" << endl;

    // 5. Перегрузка operator== для сравнения материалов
    cout << "\n--- 5. Перегрузка operator== для сравнения ---" << endl;
    auto mat1 = make_shared<BulkMaterial>("Sand", MeasureType::TONS, 100.0f);
    auto mat2 = make_shared<BulkMaterial>("Sand", MeasureType::TONS, 100.0f);
    auto mat3 = make_shared<BulkMaterial>("Gravel", MeasureType::TONS, 100.0f);
    cout << "mat1 == mat2: " << ((*mat1 == *mat2) ? "true" : "false") << endl;
    cout << "mat1 == mat3: " << ((*mat1 == *mat3) ? "true" : "false") << endl;

    // 6. Перегрузка operator< для сортировки сотрудников по зарплате
    cout << "\n--- 6. Перегрузка operator< для сортировки Staff ---" << endl;
    vector<shared_ptr<Staff>> staffForSorting;
    staffForSorting.push_back(make_shared<Staff>("Alice", StaffRank::WORKER, StaffSpecialization::MASON, "+1-555-1111", "2023-01-01", 50000));
    staffForSorting.push_back(make_shared<Staff>("Bob", StaffRank::ENGINEER, StaffSpecialization::GENERAL, "+1-555-2222", "2022-01-01", 75000));
    staffForSorting.push_back(make_shared<Staff>("Charlie", StaffRank::FOREMAN, StaffSpecialization::ELECTRICIAN, "+1-555-3333", "2021-01-01", 60000));

    cout << "До сортировки:" << endl;
    for (const auto& s : staffForSorting) {
        cout << "  " << *s << endl;
    }

    sort(staffForSorting.begin(), staffForSorting.end(),
         [](const shared_ptr<Staff>& a, const shared_ptr<Staff>& b) { return *a < *b; });

    cout << "\nПосле сортировки по зарплате:" << endl;
    for (const auto& s : staffForSorting) {
        cout << "  " << *s << endl;
    }

    // 7. Перегрузка operator[] для доступа к материалам на складе
    cout << "\n--- 7. Перегрузка operator[] для Warehouse ---" << endl;
    cout << "Доступ к первому материалу на складе через operator[]: " << endl;
    if (auto material = (*mainWarehouse)[0]) {
        cout << "Материал: " << material->getName() << endl;
    }

    // 8. Конструктор копирования для BulkMaterial
    cout << "\n--- 8. Конструктор копирования BulkMaterial ---" << endl;
    BulkMaterial originalMaterial("Gravel", MeasureType::CUBIC_METERS, 75.0f);
    BulkMaterial copiedMaterial = originalMaterial;
    cout << "Оригинал: " << originalMaterial.getName() << ", " << originalMaterial.getCount() << " куб.м" << endl;
    cout << "Копия: " << copiedMaterial.getName() << ", " << copiedMaterial.getCount() << " куб.м" << endl;

    // 9. Конструктор копирования для Staff
    cout << "\n--- 9. Конструктор копирования Staff ---" << endl;
    Staff originalStaff("John Doe", StaffRank::WORKER, StaffSpecialization::WELDER, "+1-555-9999", "2023-06-01", 48000);
    Staff copiedStaff = originalStaff;
    cout << "Оригинал: " << originalStaff.getFullname() << ", Зарплата: $" << originalStaff.getSalary() << endl;
    cout << "Копия: " << copiedStaff.getFullname() << ", Зарплата: $" << copiedStaff.getSalary() << endl;

    // ===================================================================
    // 9. АВТОМАТИЧЕСКАЯ ОЧИСТКА ПАМЯТИ
    // ===================================================================
    cout << "\n\n### ДЕМОНСТРАЦИЯ 9: Автоматическая очистка памяти ###\n" << endl;
    cout << "С умными указателями память освобождается автоматически!" << endl;
    cout << "Не требуется явного вызова delete." << endl;
    cout << "Деструкторы объектов будут вызваны автоматически при выходе из области видимости." << endl;

    cout << "\n========================================" << endl;
    cout << "Программа успешно завершена!" << endl;
    cout << "========================================" << endl;

    return 0;
}
