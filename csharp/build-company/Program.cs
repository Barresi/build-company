using BuildCompany;
using System.Text;

// Установка кодировки для корректного отображения символов UTF-8
Console.OutputEncoding = Encoding.UTF8;

Console.WriteLine("========================================");
Console.WriteLine("Система управления строительной компанией");
Console.WriteLine("C# реализация для Лабораторной работы №4");
Console.WriteLine("========================================\n");

// ===================================================================
// 1. СОЗДАНИЕ ОБЪЕКТОВ
// ===================================================================
// В C# все объекты классов создаются в куче (heap) с помощью оператора new
// и автоматически удаляются сборщиком мусора (Garbage Collector)
Console.WriteLine("\n### ДЕМОНСТРАЦИЯ 1: Создание объектов ###\n");

// Создание материалов
BulkMaterial cement = new BulkMaterial("Portland Cement M500", MeasureType.Tons, 50.5f);
StructuralMaterial brick = new StructuralMaterial("Red Brick", 0.25f, 0.12f, 0.065f, 10000);
BulkMaterial sand = new BulkMaterial("River Sand", MeasureType.CubicMeters, 100.0f);
StructuralMaterial rebar = new StructuralMaterial("Steel Rebar 12mm", 0.012f, 0.012f, 6.0f, 500);

Console.WriteLine("Созданные материалы:");
cement.DisplayInfo();
Console.WriteLine();
brick.DisplayInfo();
Console.WriteLine();
sand.DisplayInfo();
Console.WriteLine();
rebar.DisplayInfo();

// Создание оборудования (можно форматировать в несколько строк для читаемости)
Tool drill = new Tool("Bosch GSB 13 RE", 5, ToolType.PowerDrill);
ConstructionMachinery excavator = new ConstructionMachinery(
    "Caterpillar 320", 2, VehicleType.Excavator, FuelType.Diesel
);

Console.WriteLine();
drill.DisplayInfo();
Console.WriteLine();
excavator.DisplayInfo();

// Создание строительного объекта
ConstructionObject project1 = new ConstructionObject("123 Main Street", ObjectType.Residential, ProjectStatus.Planning);
Console.WriteLine();
project1.DisplayInfo();

// Создание сотрудников
Staff worker1 = new Staff("John Smith", StaffRank.Worker, StaffSpecialization.Mason,
                          "+1-555-0101", "2023-01-15", 45000);
Staff engineer1 = new Staff(
    "Emily Johnson", StaffRank.Engineer, StaffSpecialization.General,
    "+1-555-0202", "2022-06-01", 75000
);

Console.WriteLine();
worker1.DisplayInfo();
Console.WriteLine();
engineer1.DisplayInfo();

// Создание строительной компании
ConstructionCompany company = new ConstructionCompany("BuildMaster Construction Co.");
Console.WriteLine();
company.DisplayInfo();

// ===================================================================
// 2. МАССИВЫ ОБЪЕКТОВ
// ===================================================================
Console.WriteLine("\n\n### ДЕМОНСТРАЦИЯ 2: Массивы объектов ###\n");

// Создание массива объектов ConstructionObject
int arraySize = 3;
ConstructionObject[] projectArray = new ConstructionObject[arraySize];

projectArray[0] = new ConstructionObject("456 Oak Avenue", ObjectType.Commercial, ProjectStatus.InProgress);
projectArray[1] = new ConstructionObject("789 Pine Road", ObjectType.Industrial, ProjectStatus.Planning);
projectArray[2] = new ConstructionObject("321 Elm Street", ObjectType.Residential, ProjectStatus.InProgress);

Console.WriteLine("Массив строительных объектов:");
for (int i = 0; i < arraySize; i++)
{
    Console.WriteLine($"\nПроект [{i}]:");
    projectArray[i].DisplayInfo();
}

// Создание массива объектов Staff
const int staffCount = 4;
Staff[] staffArray = new Staff[staffCount];

staffArray[0] = new Staff("Michael Brown", StaffRank.Worker, StaffSpecialization.Welder,
                          "+1-555-0303", "2023-03-10", 48000);
staffArray[1] = new Staff("Sarah Davis", StaffRank.Foreman, StaffSpecialization.Electrician,
                          "+1-555-0404", "2021-08-20", 62000);
staffArray[2] = new Staff("Robert Wilson", StaffRank.SiteManager, StaffSpecialization.General,
                          "+1-555-0505", "2020-02-15", 85000);
staffArray[3] = new Staff("Lisa Martinez", StaffRank.Worker, StaffSpecialization.Carpenter,
                          "+1-555-0606", "2023-07-01", 46000);

Console.WriteLine("\n\nМассив сотрудников:");
for (int i = 0; i < staffCount; i++)
{
    Console.WriteLine($"\nСотрудник [{i}]:");
    staffArray[i].DisplayInfo();
}

// ===================================================================
// 3. КОМПЛЕКСНАЯ ДЕМОНСТРАЦИЯ СИСТЕМЫ
// ===================================================================
Console.WriteLine("\n\n### ДЕМОНСТРАЦИЯ 3: Полная интеграция системы ###\n");

// Создание склада
Warehouse mainWarehouse = new Warehouse("100 Industrial Drive");

// Добавление материалов на склад
mainWarehouse.AddMaterial(sand);
mainWarehouse.AddMaterial(rebar);

// Добавление оборудования на склад
mainWarehouse.AddEquipment(excavator);
Tool grinder = new Tool("Makita 9557NB", 10, ToolType.AngleGrinder);
mainWarehouse.AddEquipment(grinder);

// Добавление склада в компанию
company.AddWarehouse(mainWarehouse);

// Добавление сотрудников в компанию
company.AddStaff(engineer1);
for (int i = 0; i < staffCount; i++)
{
    company.AddStaff(staffArray[i]);
}

// Создание и добавление строительных объектов
ConstructionObject project2 = new ConstructionObject(
    "555 Business Parkway", ObjectType.Commercial, ProjectStatus.InProgress
);
company.BuildNewObject(project2);

// Назначение сотрудников на проекты
engineer1.AssignToObject(project2);
staffArray[0].AssignToObject(project2);
staffArray[1].AssignToObject(project2);

// Отображение полной информации о компании
company.DisplayInfo();
company.DisplayAllStaff();
company.DisplayAllWarehouses();
company.DisplayAllObjects();

// Отображение инвентаря склада
mainWarehouse.DisplayInventory();

// ===================================================================
// 4. ОПЕРАЦИИ С ОБЪЕКТАМИ
// ===================================================================
Console.WriteLine("\n\n### ДЕМОНСТРАЦИЯ 4: Операции с объектами ###\n");

// Работа с материалами
Console.WriteLine("\n--- Операции с материалами ---");
sand.AddCount(50.0f);
sand.RemoveCount(20.0f);
Console.WriteLine();
sand.DisplayInfo();

// Работа с оборудованием
Console.WriteLine("\n--- Операции с оборудованием ---");
grinder.AddCount(5);
grinder.RemoveCount(3);
Console.WriteLine();
grinder.DisplayInfo();

// Изменение статуса проекта
Console.WriteLine("\n--- Изменение статуса проекта ---");
project2.SetStatus(ProjectStatus.Completed);

// Обновление информации о сотруднике
Console.WriteLine("\n--- Обновление информации о сотруднике ---");
staffArray[0].SetSalary(52000);
Console.WriteLine($"Обновлена зарплата сотрудника {staffArray[0].GetFullname()} на $" +
                  $"{staffArray[0].GetSalary()}");

// ===================================================================
// 5. УПРАВЛЕНИЕ ПАМЯТЬЮ В C#
// ===================================================================
Console.WriteLine("\n\n### ДЕМОНСТРАЦИЯ 5: Управление памятью в C# ###\n");

Console.WriteLine("В C# управление памятью происходит автоматически через Garbage Collector.");
Console.WriteLine("Объекты удаляются автоматически, когда на них нет ссылок.");
Console.WriteLine("Явное освобождение памяти (delete) не требуется.");

// Создание временных объектов для демонстрации
{
    BulkMaterial tempMaterial = new BulkMaterial("Temporary Material", MeasureType.Tons, 100);
    Console.WriteLine($"\nСоздан временный объект: {tempMaterial.GetName()}");
    // Объект tempMaterial будет автоматически удален сборщиком мусора
    // когда выйдет из области видимости
}

Console.WriteLine("Временный объект вышел из области видимости и будет удален GC.");

// Принудительный вызов сборщика мусора (обычно не рекомендуется в продакшене)
GC.Collect();
GC.WaitForPendingFinalizers();
Console.WriteLine("Сборка мусора выполнена.");

Console.WriteLine("\n========================================");
Console.WriteLine("Программа успешно завершена!");
Console.WriteLine("========================================");
