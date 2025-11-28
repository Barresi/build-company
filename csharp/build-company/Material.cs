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
    /// Свойство для получения и установки названия материала
    /// </summary>
    public string Name
    {
        get { return name; }
        set
        {
            if (string.IsNullOrWhiteSpace(value))
                throw new ArgumentException("Название материала не может быть пустым");
            name = value;
        }
    }

    // Устаревшие методы для обратной совместимости
    public string GetName() => Name;
    public void SetName(string name) => Name = name;

    /// <summary>
    /// Абстрактный метод для отображения информации о материале
    /// </summary>
    public abstract void DisplayInfo();
}
