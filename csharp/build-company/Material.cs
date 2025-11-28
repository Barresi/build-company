namespace BuildCompany;

/// <summary>
/// Абстрактный базовый класс для всех материалов
/// </summary>
public abstract class Material
{
    protected string name;

    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="name">Название материала</param>
    public Material(string name)
    {
        this.name = name;
    }

    /// <summary>
    /// Получить название материала
    /// </summary>
    public string GetName()
    {
        return name;
    }

    /// <summary>
    /// Установить название материала
    /// </summary>
    public void SetName(string name)
    {
        this.name = name;
    }

    /// <summary>
    /// Абстрактный метод для отображения информации о материале
    /// </summary>
    public abstract void DisplayInfo();
}
