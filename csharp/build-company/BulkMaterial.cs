namespace BuildCompany;

/// <summary>
/// Класс для сыпучих материалов (цемент, песок, щебень и т.д.)
/// </summary>
public class BulkMaterial : Material
{
    private MeasureType measureUnit;
    private float count;

    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="name">Название материала</param>
    /// <param name="measureUnit">Единица измерения</param>
    /// <param name="count">Количество</param>
    public BulkMaterial(string name, MeasureType measureUnit, float count)
        : base(name)
    {
        this.measureUnit = measureUnit;
        this.count = count;
    }

    /// <summary>
    /// Свойство для единицы измерения
    /// </summary>
    public MeasureType MeasureUnit
    {
        get { return measureUnit; }
        set { measureUnit = value; }
    }

    /// <summary>
    /// Свойство для количества с валидацией
    /// </summary>
    public float Count
    {
        get { return count; }
        set
        {
            if (value < 0)
                throw new ArgumentException("Количество материала не может быть отрицательным");
            count = value;
        }
    }

    // Устаревшие методы для обратной совместимости
    public MeasureType GetMeasureUnit() => MeasureUnit;
    public float GetCount() => Count;
    public void SetMeasureUnit(MeasureType measureUnit) => MeasureUnit = measureUnit;
    public void SetCount(float count) => Count = count;

    /// <summary>
    /// Добавить количество
    /// </summary>
    public void AddCount(float amount)
    {
        count += amount;
        Console.WriteLine($"Added {amount} {measureUnit.ToDisplayString()}. New count: {count}");
    }

    /// <summary>
    /// Удалить количество (с выбросом исключения при недостатке)
    /// </summary>
    public void RemoveCount(float amount)
    {
        if (amount < 0)
        {
            throw new ArgumentException("Количество для удаления не может быть отрицательным");
        }

        if (count < amount)
        {
            throw new InsufficientMaterialException(amount, count);
        }

        count -= amount;
        Console.WriteLine($"Removed {amount} {measureUnit.ToDisplayString()}. New count: {count}");
    }

    /// <summary>
    /// Попытаться удалить количество (безопасная версия с try-catch)
    /// </summary>
    public bool TryRemoveCount(float amount)
    {
        try
        {
            RemoveCount(amount);
            return true;
        }
        catch (InsufficientMaterialException ex)
        {
            Console.WriteLine($"Ошибка: {ex.Message}");
            return false;
        }
        catch (ArgumentException ex)
        {
            Console.WriteLine($"Ошибка валидации: {ex.Message}");
            return false;
        }
    }

    /// <summary>
    /// Отображение информации о материале
    /// </summary>
    public override void DisplayInfo()
    {
        Console.WriteLine($"[Bulk Material]");
        Console.WriteLine($"  Name: {name}");
        Console.WriteLine($"  Count: {count} {measureUnit.ToDisplayString()}");
    }
}
