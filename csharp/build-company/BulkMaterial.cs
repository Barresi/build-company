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
    /// Получить единицу измерения
    /// </summary>
    public MeasureType GetMeasureUnit()
    {
        return measureUnit;
    }

    /// <summary>
    /// Получить количество
    /// </summary>
    public float GetCount()
    {
        return count;
    }

    /// <summary>
    /// Установить единицу измерения
    /// </summary>
    public void SetMeasureUnit(MeasureType measureUnit)
    {
        this.measureUnit = measureUnit;
    }

    /// <summary>
    /// Установить количество
    /// </summary>
    public void SetCount(float count)
    {
        this.count = count;
    }

    /// <summary>
    /// Добавить количество
    /// </summary>
    public void AddCount(float amount)
    {
        count += amount;
        Console.WriteLine($"Added {amount} {measureUnit.ToDisplayString()}. New count: {count}");
    }

    /// <summary>
    /// Удалить количество
    /// </summary>
    public void RemoveCount(float amount)
    {
        if (count >= amount)
        {
            count -= amount;
            Console.WriteLine($"Removed {amount} {measureUnit.ToDisplayString()}. New count: {count}");
        }
        else
        {
            Console.WriteLine($"Cannot remove {amount} {measureUnit.ToDisplayString()}. Only {count} available.");
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
