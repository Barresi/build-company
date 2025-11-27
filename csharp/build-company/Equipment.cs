namespace BuildCompany;

/// <summary>
/// Абстрактный базовый класс для всего оборудования
/// </summary>
public abstract class Equipment
{
    protected string name;
    protected int count;

    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="name">Название оборудования</param>
    /// <param name="count">Количество</param>
    public Equipment(string name, int count)
    {
        this.name = name;
        this.count = count;
    }

    /// <summary>
    /// Получить название оборудования
    /// </summary>
    public string GetName()
    {
        return name;
    }

    /// <summary>
    /// Получить количество
    /// </summary>
    public int GetCount()
    {
        return count;
    }

    /// <summary>
    /// Установить название оборудования
    /// </summary>
    public void SetName(string name)
    {
        this.name = name;
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
    /// Абстрактный метод для отображения информации об оборудовании
    /// </summary>
    public abstract void DisplayInfo();
}
