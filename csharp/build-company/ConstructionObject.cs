namespace BuildCompany;

/// <summary>
/// Класс, представляющий строительный проект/объект
/// </summary>
public class ConstructionObject
{
    private string address;
    private ObjectType objectType;
    private ProjectStatus status;

    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="address">Адрес объекта</param>
    /// <param name="objectType">Тип объекта</param>
    /// <param name="status">Статус проекта</param>
    public ConstructionObject(string address, ObjectType objectType, ProjectStatus status)
    {
        this.address = address;
        this.objectType = objectType;
        this.status = status;
    }

    /// <summary>
    /// Получить адрес
    /// </summary>
    public string GetAddress()
    {
        return address;
    }

    /// <summary>
    /// Получить тип объекта
    /// </summary>
    public ObjectType GetObjectType()
    {
        return objectType;
    }

    /// <summary>
    /// Получить статус
    /// </summary>
    public ProjectStatus GetStatus()
    {
        return status;
    }

    /// <summary>
    /// Установить адрес
    /// </summary>
    public void SetAddress(string address)
    {
        this.address = address;
    }

    /// <summary>
    /// Установить тип объекта
    /// </summary>
    public void SetObjectType(ObjectType objectType)
    {
        this.objectType = objectType;
    }

    /// <summary>
    /// Установить статус
    /// </summary>
    public void SetStatus(ProjectStatus status)
    {
        this.status = status;
        Console.WriteLine($"Project status updated to: {status.ToDisplayString()}");
    }

    /// <summary>
    /// Отображение информации об объекте
    /// </summary>
    public void DisplayInfo()
    {
        Console.WriteLine($"[Construction Object]");
        Console.WriteLine($"  Address: {address}");
        Console.WriteLine($"  Type: {objectType.ToDisplayString()}");
        Console.WriteLine($"  Status: {status.ToDisplayString()}");
    }
}
