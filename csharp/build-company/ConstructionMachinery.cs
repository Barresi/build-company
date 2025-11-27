namespace BuildCompany;

/// <summary>
/// Класс для строительной техники и транспортных средств
/// </summary>
public class ConstructionMachinery : Equipment
{
    private VehicleType vehicleType;
    private FuelType fuelType;

    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="name">Название техники</param>
    /// <param name="count">Количество</param>
    /// <param name="vehicleType">Тип техники</param>
    /// <param name="fuelType">Тип топлива</param>
    public ConstructionMachinery(string name, int count, VehicleType vehicleType, FuelType fuelType)
        : base(name, count)
    {
        this.vehicleType = vehicleType;
        this.fuelType = fuelType;
    }

    /// <summary>
    /// Получить тип техники
    /// </summary>
    public VehicleType GetVehicleType()
    {
        return vehicleType;
    }

    /// <summary>
    /// Получить тип топлива
    /// </summary>
    public FuelType GetFuelType()
    {
        return fuelType;
    }

    /// <summary>
    /// Установить тип техники
    /// </summary>
    public void SetVehicleType(VehicleType vehicleType)
    {
        this.vehicleType = vehicleType;
    }

    /// <summary>
    /// Установить тип топлива
    /// </summary>
    public void SetFuelType(FuelType fuelType)
    {
        this.fuelType = fuelType;
    }

    /// <summary>
    /// Отображение информации о технике
    /// </summary>
    public override void DisplayInfo()
    {
        Console.WriteLine($"[Construction Machinery]");
        Console.WriteLine($"  Name: {name}");
        Console.WriteLine($"  Type: {vehicleType.ToDisplayString()}");
        Console.WriteLine($"  Fuel Type: {fuelType.ToDisplayString()}");
        Console.WriteLine($"  Count: {count}");
    }
}
