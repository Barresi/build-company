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

// ===================================================================
// 6. ДЕМОНСТРАЦИЯ СТАТИЧЕСКИХ ПОЛЕЙ И МЕТОДОВ
// ===================================================================
Console.WriteLine("\n\n### ДЕМОНСТРАЦИЯ 6: Статические поля и методы ###\n");

// Создаем несколько компаний для демонстрации статического счетчика
ConstructionCompany company2 = new ConstructionCompany("ABC Construction Ltd.");
ConstructionCompany company3 = new ConstructionCompany("XYZ Builders Inc.");

// Вызываем статический метод для получения статистики
Console.WriteLine($"Количество созданных компаний (через статический метод): {ConstructionCompany.GetTotalCompaniesCreated()}");

// Вызываем статический метод для отображения статистики
ConstructionCompany.DisplayStatistics();

// ===================================================================
// 7. ДЕМОНСТРАЦИЯ СВОЙСТВ С GET/SET
// ===================================================================
Console.WriteLine("\n\n### ДЕМОНСТРАЦИЯ 7: Свойства с get/set аксессорами ###\n");

// Использование свойств вместо методов Get/Set
Console.WriteLine("--- Работа со свойствами материала ---");
BulkMaterial gravel = new BulkMaterial("Crushed Gravel", MeasureType.CubicMeters, 75.0f);

// Чтение через свойство
Console.WriteLine($"Название материала (через свойство): {gravel.Name}");
Console.WriteLine($"Количество (через свойство): {gravel.Count} {gravel.MeasureUnit.ToDisplayString()}");

// Изменение через свойство с валидацией
try
{
    gravel.Count = 100.0f;
    Console.WriteLine($"Новое количество: {gravel.Count}");

    // Попытка установить отрицательное значение (вызовет исключение)
    Console.WriteLine("\nПопытка установить отрицательное количество...");
    gravel.Count = -10.0f;
}
catch (ArgumentException ex)
{
    Console.WriteLine($"Ошибка валидации: {ex.Message}");
}

Console.WriteLine("\n--- Работа со свойствами сотрудника ---");
Staff testWorker = new Staff("Test Worker", StaffRank.Worker, StaffSpecialization.Mason,
                             "+1-555-9999", "2024-01-01", 45000);

// Использование свойств
Console.WriteLine($"Сотрудник: {testWorker.Fullname}");
Console.WriteLine($"Зарплата: ${testWorker.Salary}");

try
{
    // Попытка установить слишком низкую зарплату
    Console.WriteLine("\nПопытка установить зарплату ниже минимальной...");
    testWorker.Salary = 25000;
}
catch (ArgumentException ex)
{
    Console.WriteLine($"Ошибка валидации: {ex.Message}");
}

// ===================================================================
// 8. ДЕМОНСТРАЦИЯ TRY-CATCH И THROW
// ===================================================================
Console.WriteLine("\n\n### ДЕМОНСТРАЦИЯ 8: Обработка исключений (try-catch, throw) ###\n");

Console.WriteLine("--- Пример 1: Недостаточное количество материала ---");
BulkMaterial concrete = new BulkMaterial("Concrete Mix", MeasureType.Tons, 20.0f);

try
{
    Console.WriteLine($"Текущее количество бетона: {concrete.Count} тонн");
    Console.WriteLine("Попытка удалить 30 тонн (больше, чем есть)...");
    concrete.RemoveCount(30.0f);
}
catch (InsufficientMaterialException ex)
{
    Console.WriteLine($"Поймано исключение InsufficientMaterialException:");
    Console.WriteLine($"  Сообщение: {ex.Message}");
    Console.WriteLine($"  Запрошено: {ex.RequestedAmount} тонн");
    Console.WriteLine($"  Доступно: {ex.AvailableAmount} тонн");
}

Console.WriteLine("\n--- Пример 2: Безопасное удаление с TryRemoveCount ---");
bool success = concrete.TryRemoveCount(15.0f);
Console.WriteLine($"Удаление 15 тонн: {(success ? "Успешно" : "Ошибка")}");

success = concrete.TryRemoveCount(10.0f);
Console.WriteLine($"Удаление 10 тонн: {(success ? "Успешно" : "Ошибка")}");

Console.WriteLine("\n--- Пример 3: Удаление сотрудника с несуществующим ID ---");
company.DeleteStaff(999); // Вызовет обработку исключения внутри метода

Console.WriteLine("\n--- Пример 4: Множественная обработка исключений ---");
try
{
    Staff invalidStaff = new Staff("", StaffRank.Worker, StaffSpecialization.Mason,
                                   "+1-555-0000", "2024-01-01", 50000);
}
catch (ArgumentException ex)
{
    Console.WriteLine($"Ошибка создания сотрудника: {ex.Message}");
}

// ===================================================================
// 9. ДЕМОНСТРАЦИЯ USING STATEMENT
// ===================================================================
Console.WriteLine("\n\n### ДЕМОНСТРАЦИЯ 9: Using statement для управления ресурсами ###\n");

string logFilePath = "construction_company.log";

Console.WriteLine("--- Пример 1: Using statement с CompanyLogger ---");
// using statement автоматически вызовет Dispose() в конце блока
using (CompanyLogger logger = new CompanyLogger(logFilePath))
{
    logger.Log("Программа запущена");
    logger.Log("Создана компания: " + company.GetCompanyName());
    logger.Log($"Всего компаний создано: {ConstructionCompany.GetTotalCompaniesCreated()}");
    logger.Log("Выполнены основные операции");
} // Здесь автоматически вызывается logger.Dispose()

Console.WriteLine($"Логи записаны в файл: {logFilePath}");

Console.WriteLine("\n--- Пример 2: Статический метод с using для записи в лог ---");
CompanyLogger.LogToFile(logFilePath, "Статический метод записи в лог");
CompanyLogger.LogToFile(logFilePath, $"Материал обработан: {concrete.Name}");

Console.WriteLine("\n--- Пример 3: Чтение логов с использованием using ---");
string logs = CompanyLogger.ReadLogs(logFilePath, 5);
Console.WriteLine("Последние записи из лога:");
Console.WriteLine(logs);

Console.WriteLine("\n--- Пример 4: Try-catch с using для безопасной работы с файлами ---");
try
{
    using (StreamWriter reportWriter = new StreamWriter("company_report.txt"))
    {
        reportWriter.WriteLine("=== Отчет строительной компании ===");
        reportWriter.WriteLine($"Компания: {company.GetCompanyName()}");
        reportWriter.WriteLine($"Всего сотрудников: {company.GetStaff().Count}");
        reportWriter.WriteLine($"Всего складов: {company.GetWarehouses().Count}");
        reportWriter.WriteLine($"Всего проектов: {company.GetConstructionObjects().Count}");
        reportWriter.WriteLine($"Дата отчета: {DateTime.Now}");
    } // StreamWriter автоматически закрывается здесь

    Console.WriteLine("Отчет сохранен в файл: company_report.txt");

    // Чтение отчета
    using (StreamReader reportReader = new StreamReader("company_report.txt"))
    {
        Console.WriteLine("\nСодержимое отчета:");
        Console.WriteLine(reportReader.ReadToEnd());
    } // StreamReader автоматически закрывается здесь
}
catch (IOException ex)
{
    Console.WriteLine($"Ошибка работы с файлом: {ex.Message}");
}

// ===================================================================
// ИТОГОВАЯ СТАТИСТИКА
// ===================================================================
Console.WriteLine("\n\n### ИТОГОВАЯ СТАТИСТИКА ###\n");

Console.WriteLine("Продемонстрированные концепции C#:");
Console.WriteLine("✓ Статическое поле (totalCompaniesCreated) и статический метод (GetTotalCompaniesCreated)");
Console.WriteLine("✓ Свойства с get/set аксессорами и валидацией (Name, Count, Salary)");
Console.WriteLine("✓ Try-catch блоки для перехвата исключений");
Console.WriteLine("✓ Throw для инициализации исключений (ArgumentException, InsufficientMaterialException)");
Console.WriteLine("✓ Using statement для автоматического управления ресурсами (StreamWriter, StreamReader, CompanyLogger)");
Console.WriteLine("✓ Пользовательские исключения (ConstructionException, InsufficientMaterialException)");
Console.WriteLine("✓ IDisposable интерфейс и правильное освобождение ресурсов");

Console.WriteLine("\n========================================");
Console.WriteLine("Программа успешно завершена!");
Console.WriteLine("========================================");
