namespace BuildCompany;

/// <summary>
/// Пользовательское исключение для ошибок строительной компании
/// </summary>
public class ConstructionException : Exception
{
    public ConstructionException() : base() { }

    public ConstructionException(string message) : base(message) { }

    public ConstructionException(string message, Exception innerException)
        : base(message, innerException) { }
}

/// <summary>
/// Исключение для недостаточного количества материала
/// </summary>
public class InsufficientMaterialException : ConstructionException
{
    public float RequestedAmount { get; }
    public float AvailableAmount { get; }

    public InsufficientMaterialException(float requested, float available)
        : base($"Недостаточно материала. Запрошено: {requested}, доступно: {available}")
    {
        RequestedAmount = requested;
        AvailableAmount = available;
    }
}
