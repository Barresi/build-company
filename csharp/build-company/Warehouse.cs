namespace BuildCompany;

/// <summary>
/// Класс, представляющий склад для материалов и оборудования
/// </summary>
public class Warehouse
{
    private string address;
    private List<Material> materials;
    private List<Equipment> equipment;

    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="address">Адрес склада</param>
    public Warehouse(string address)
    {
        this.address = address;
        this.materials = new List<Material>();
        this.equipment = new List<Equipment>();
    }

    /// <summary>
    /// Получить адрес
    /// </summary>
    public string GetAddress()
    {
        return address;
    }

    /// <summary>
    /// Получить список материалов
    /// </summary>
    public List<Material> GetMaterials()
    {
        return materials;
    }

    /// <summary>
    /// Получить список оборудования
    /// </summary>
    public List<Equipment> GetEquipment()
    {
        return equipment;
    }

    /// <summary>
    /// Установить адрес
    /// </summary>
    public void SetAddress(string address)
    {
        this.address = address;
    }

    /// <summary>
    /// Добавить материал
    /// </summary>
    public void AddMaterial(Material material)
    {
        materials.Add(material);
        Console.WriteLine($"Material '{material.GetName()}' added to warehouse at {address}");
    }

    /// <summary>
    /// Добавить оборудование
    /// </summary>
    public void AddEquipment(Equipment equip)
    {
        equipment.Add(equip);
        Console.WriteLine($"Equipment '{equip.GetName()}' added to warehouse at {address}");
    }

    /// <summary>
    /// Удалить материал
    /// </summary>
    public void RemoveMaterial(Material material)
    {
        materials.Remove(material);
        Console.WriteLine($"Material '{material.GetName()}' removed from warehouse");
    }

    /// <summary>
    /// Удалить оборудование
    /// </summary>
    public void RemoveEquipment(Equipment equip)
    {
        equipment.Remove(equip);
        Console.WriteLine($"Equipment '{equip.GetName()}' removed from warehouse");
    }

    /// <summary>
    /// Отображение информации о складе
    /// </summary>
    public void DisplayInfo()
    {
        Console.WriteLine($"[Warehouse]");
        Console.WriteLine($"  Address: {address}");
        Console.WriteLine($"  Materials stored: {materials.Count}");
        Console.WriteLine($"  Equipment stored: {equipment.Count}");
    }

    /// <summary>
    /// Отображение инвентаря склада
    /// </summary>
    public void DisplayInventory()
    {
        Console.WriteLine($"\n=== Warehouse Inventory at {address} ===");

        Console.WriteLine($"\nMaterials ({materials.Count}):");
        foreach (var material in materials)
        {
            material.DisplayInfo();
            Console.WriteLine();
        }

        Console.WriteLine($"\nEquipment ({equipment.Count}):");
        foreach (var equip in equipment)
        {
            equip.DisplayInfo();
            Console.WriteLine();
        }
    }
}
