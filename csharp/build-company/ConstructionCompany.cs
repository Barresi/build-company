namespace BuildCompany;

/// <summary>
/// Главный класс, представляющий строительную компанию
/// </summary>
public class ConstructionCompany
{
    private string companyName;
    private List<Staff> staff;
    private List<Warehouse> warehouses;
    private List<ConstructionObject> constructionObjects;

    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="companyName">Название компании</param>
    public ConstructionCompany(string companyName)
    {
        this.companyName = companyName;
        this.staff = new List<Staff>();
        this.warehouses = new List<Warehouse>();
        this.constructionObjects = new List<ConstructionObject>();
    }

    /// <summary>
    /// Получить название компании
    /// </summary>
    public string GetCompanyName()
    {
        return companyName;
    }

    /// <summary>
    /// Получить список персонала
    /// </summary>
    public List<Staff> GetStaff()
    {
        return staff;
    }

    /// <summary>
    /// Получить список складов
    /// </summary>
    public List<Warehouse> GetWarehouses()
    {
        return warehouses;
    }

    /// <summary>
    /// Получить список строительных объектов
    /// </summary>
    public List<ConstructionObject> GetConstructionObjects()
    {
        return constructionObjects;
    }

    /// <summary>
    /// Установить название компании
    /// </summary>
    public void SetCompanyName(string companyName)
    {
        this.companyName = companyName;
    }

    /// <summary>
    /// Добавить сотрудника
    /// </summary>
    public void AddStaff(Staff person)
    {
        staff.Add(person);
        Console.WriteLine($"Staff member '{person.GetFullname()}' added to {companyName}");
    }

    /// <summary>
    /// Удалить сотрудника
    /// </summary>
    public void DeleteStaff(int staffId)
    {
        if (staffId >= 0 && staffId < staff.Count)
        {
            var person = staff[staffId];
            staff.RemoveAt(staffId);
            Console.WriteLine($"Staff member '{person.GetFullname()}' removed from {companyName}");
        }
    }

    /// <summary>
    /// Добавить склад
    /// </summary>
    public void AddWarehouse(Warehouse warehouse)
    {
        warehouses.Add(warehouse);
        Console.WriteLine($"Warehouse at '{warehouse.GetAddress()}' added to {companyName}");
    }

    /// <summary>
    /// Удалить склад
    /// </summary>
    public void DeleteWarehouse(int warehouseId)
    {
        if (warehouseId >= 0 && warehouseId < warehouses.Count)
        {
            var warehouse = warehouses[warehouseId];
            warehouses.RemoveAt(warehouseId);
            Console.WriteLine($"Warehouse at '{warehouse.GetAddress()}' removed from {companyName}");
        }
    }

    /// <summary>
    /// Начать строительство нового объекта
    /// </summary>
    public void BuildNewObject(ConstructionObject obj)
    {
        constructionObjects.Add(obj);
        Console.WriteLine($"New construction project at '{obj.GetAddress()}' added to {companyName}");
    }

    /// <summary>
    /// Продать объект
    /// </summary>
    public void SellObject(int objectId)
    {
        if (objectId >= 0 && objectId < constructionObjects.Count)
        {
            var obj = constructionObjects[objectId];
            constructionObjects.RemoveAt(objectId);
            Console.WriteLine($"Construction project at '{obj.GetAddress()}' sold and removed from {companyName}");
        }
    }

    /// <summary>
    /// Отображение информации о компании
    /// </summary>
    public void DisplayInfo()
    {
        Console.WriteLine($"\n=== {companyName} ===");
        Console.WriteLine($"Total Staff: {staff.Count}");
        Console.WriteLine($"Total Warehouses: {warehouses.Count}");
        Console.WriteLine($"Total Projects: {constructionObjects.Count}");
    }

    /// <summary>
    /// Отображение всего персонала
    /// </summary>
    public void DisplayAllStaff()
    {
        Console.WriteLine($"\n=== All Staff Members of {companyName} ===");
        for (int i = 0; i < staff.Count; i++)
        {
            Console.WriteLine($"\nStaff [{i}]:");
            staff[i].DisplayInfo();
        }
    }

    /// <summary>
    /// Отображение всех складов
    /// </summary>
    public void DisplayAllWarehouses()
    {
        Console.WriteLine($"\n=== All Warehouses of {companyName} ===");
        for (int i = 0; i < warehouses.Count; i++)
        {
            Console.WriteLine($"\nWarehouse [{i}]:");
            warehouses[i].DisplayInfo();
        }
    }

    /// <summary>
    /// Отображение всех строительных объектов
    /// </summary>
    public void DisplayAllObjects()
    {
        Console.WriteLine($"\n=== All Construction Projects of {companyName} ===");
        for (int i = 0; i < constructionObjects.Count; i++)
        {
            Console.WriteLine($"\nProject [{i}]:");
            constructionObjects[i].DisplayInfo();
        }
    }
}
