namespace BuildCompany;

/// <summary>
/// Статус строительного проекта
/// </summary>
public enum ProjectStatus
{
    Planning,
    InProgress,
    Suspended,
    Completed,
    Cancelled
}

/// <summary>
/// Тип строительного объекта
/// </summary>
public enum ObjectType
{
    Residential,
    Industrial,
    Commercial,
    Infrastructure
}

/// <summary>
/// Должность сотрудника
/// </summary>
public enum StaffRank
{
    Worker,
    Foreman,
    SiteManager,
    Engineer,
    ProjectDirector
}

/// <summary>
/// Специализация сотрудника
/// </summary>
public enum StaffSpecialization
{
    Mason,
    Welder,
    Electrician,
    CraneOperator,
    ConcreteWorker,
    Carpenter,
    Plumber,
    General
}

/// <summary>
/// Единица измерения для материалов
/// </summary>
public enum MeasureType
{
    Pieces,
    Kilograms,
    CubicMeters,
    SquareMeters,
    Tons
}

/// <summary>
/// Тип инструмента
/// </summary>
public enum ToolType
{
    PowerDrill,
    HammerDrill,
    Screwdriver,
    AngleGrinder,
    CircularSaw,
    WeldingMachine,
    HandTool
}

/// <summary>
/// Тип строительной техники
/// </summary>
public enum VehicleType
{
    Excavator,
    Bulldozer,
    Crane,
    DumpTruck,
    ConcreteMixer,
    Loader,
    Grader,
    AsphaltPaver
}

/// <summary>
/// Тип топлива
/// </summary>
public enum FuelType
{
    Diesel,
    Gasoline,
    Electric,
    Hybrid
}

/// <summary>
/// Вспомогательные методы для работы с перечислениями
/// </summary>
public static class EnumExtensions
{
    public static string ToDisplayString(this ProjectStatus status)
    {
        return status switch
        {
            ProjectStatus.Planning => "Planning",
            ProjectStatus.InProgress => "In Progress",
            ProjectStatus.Suspended => "Suspended",
            ProjectStatus.Completed => "Completed",
            ProjectStatus.Cancelled => "Cancelled",
            _ => "Unknown"
        };
    }

    public static string ToDisplayString(this ObjectType type)
    {
        return type switch
        {
            ObjectType.Residential => "Residential",
            ObjectType.Industrial => "Industrial",
            ObjectType.Commercial => "Commercial",
            ObjectType.Infrastructure => "Infrastructure",
            _ => "Unknown"
        };
    }

    public static string ToDisplayString(this StaffRank rank)
    {
        return rank switch
        {
            StaffRank.Worker => "Worker",
            StaffRank.Foreman => "Foreman",
            StaffRank.SiteManager => "Site Manager",
            StaffRank.Engineer => "Engineer",
            StaffRank.ProjectDirector => "Project Director",
            _ => "Unknown"
        };
    }

    public static string ToDisplayString(this StaffSpecialization spec)
    {
        return spec switch
        {
            StaffSpecialization.Mason => "Mason",
            StaffSpecialization.Welder => "Welder",
            StaffSpecialization.Electrician => "Electrician",
            StaffSpecialization.CraneOperator => "Crane Operator",
            StaffSpecialization.ConcreteWorker => "Concrete Worker",
            StaffSpecialization.Carpenter => "Carpenter",
            StaffSpecialization.Plumber => "Plumber",
            StaffSpecialization.General => "General",
            _ => "Unknown"
        };
    }

    public static string ToDisplayString(this MeasureType type)
    {
        return type switch
        {
            MeasureType.Pieces => "pcs",
            MeasureType.Kilograms => "kg",
            MeasureType.CubicMeters => "m3",
            MeasureType.SquareMeters => "m2",
            MeasureType.Tons => "t",
            _ => "Unknown"
        };
    }

    public static string ToDisplayString(this ToolType type)
    {
        return type switch
        {
            ToolType.PowerDrill => "Power Drill",
            ToolType.HammerDrill => "Hammer Drill",
            ToolType.Screwdriver => "Screwdriver",
            ToolType.AngleGrinder => "Angle Grinder",
            ToolType.CircularSaw => "Circular Saw",
            ToolType.WeldingMachine => "Welding Machine",
            ToolType.HandTool => "Hand Tool",
            _ => "Unknown"
        };
    }

    public static string ToDisplayString(this VehicleType type)
    {
        return type switch
        {
            VehicleType.Excavator => "Excavator",
            VehicleType.Bulldozer => "Bulldozer",
            VehicleType.Crane => "Crane",
            VehicleType.DumpTruck => "Dump Truck",
            VehicleType.ConcreteMixer => "Concrete Mixer",
            VehicleType.Loader => "Loader",
            VehicleType.Grader => "Grader",
            VehicleType.AsphaltPaver => "Asphalt Paver",
            _ => "Unknown"
        };
    }

    public static string ToDisplayString(this FuelType type)
    {
        return type switch
        {
            FuelType.Diesel => "Diesel",
            FuelType.Gasoline => "Gasoline",
            FuelType.Electric => "Electric",
            FuelType.Hybrid => "Hybrid",
            _ => "Unknown"
        };
    }
}
