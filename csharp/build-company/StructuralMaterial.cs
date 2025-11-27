namespace BuildCompany;

/// <summary>
/// Класс для конструкционных материалов (кирпичи, балки, панели и т.д.)
/// </summary>
public class StructuralMaterial : Material
{
    private float width;
    private float height;
    private float length;
    private int count;

    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="name">Название материала</param>
    /// <param name="width">Ширина в метрах</param>
    /// <param name="height">Высота в метрах</param>
    /// <param name="length">Длина в метрах</param>
    /// <param name="count">Количество</param>
    public StructuralMaterial(string name, float width, float height, float length, int count)
        : base(name)
    {
        this.width = width;
        this.height = height;
        this.length = length;
        this.count = count;
    }

    /// <summary>
    /// Получить ширину
    /// </summary>
    public float GetWidth()
    {
        return width;
    }

    /// <summary>
    /// Получить высоту
    /// </summary>
    public float GetHeight()
    {
        return height;
    }

    /// <summary>
    /// Получить длину
    /// </summary>
    public float GetLength()
    {
        return length;
    }

    /// <summary>
    /// Получить количество
    /// </summary>
    public int GetCount()
    {
        return count;
    }

    /// <summary>
    /// Установить ширину
    /// </summary>
    public void SetWidth(float width)
    {
        this.width = width;
    }

    /// <summary>
    /// Установить высоту
    /// </summary>
    public void SetHeight(float height)
    {
        this.height = height;
    }

    /// <summary>
    /// Установить длину
    /// </summary>
    public void SetLength(float length)
    {
        this.length = length;
    }

    /// <summary>
    /// Установить количество
    /// </summary>
    public void SetCount(int count)
    {
        this.count = count;
    }

    /// <summary>
    /// Добавить количество
    /// </summary>
    public void AddCount(int amount)
    {
        count += amount;
        Console.WriteLine($"Added {amount} units. New count: {count}");
    }

    /// <summary>
    /// Удалить количество
    /// </summary>
    public void RemoveCount(int amount)
    {
        if (count >= amount)
        {
            count -= amount;
            Console.WriteLine($"Removed {amount} units. New count: {count}");
        }
        else
        {
            Console.WriteLine($"Cannot remove {amount} units. Only {count} available.");
        }
    }

    /// <summary>
    /// Вычислить объем одной единицы
    /// </summary>
    public float CalculateVolume()
    {
        return width * height * length;
    }

    /// <summary>
    /// Отображение информации о материале
    /// </summary>
    public override void DisplayInfo()
    {
        Console.WriteLine($"[Structural Material]");
        Console.WriteLine($"  Name: {name}");
        Console.WriteLine($"  Dimensions: {width}m x {height}m x {length}m");
        Console.WriteLine($"  Volume per unit: {CalculateVolume():F6} m3");
        Console.WriteLine($"  Count: {count} pieces");
    }
}
