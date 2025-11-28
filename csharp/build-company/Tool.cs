namespace BuildCompany;

/// <summary>
/// Класс для инструментов и ручного оборудования
/// </summary>
public class Tool : Equipment
{
    private ToolType type;

    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="name">Название инструмента</param>
    /// <param name="count">Количество</param>
    /// <param name="type">Тип инструмента</param>
    public Tool(string name, int count, ToolType type)
        : base(name, count)
    {
        this.type = type;
    }

    /// <summary>
    /// Получить тип инструмента
    /// </summary>
    public ToolType GetToolType()
    {
        return type;
    }

    /// <summary>
    /// Установить тип инструмента
    /// </summary>
    public void SetToolType(ToolType type)
    {
        this.type = type;
    }

    /// <summary>
    /// Отображение информации об инструменте
    /// </summary>
    public override void DisplayInfo()
    {
        Console.WriteLine($"[Tool]");
        Console.WriteLine($"  Name: {name}");
        Console.WriteLine($"  Type: {type.ToDisplayString()}");
        Console.WriteLine($"  Count: {count}");
    }
}
