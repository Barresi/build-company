namespace BuildCompany;

/// <summary>
/// Класс, представляющий сотрудника
/// </summary>
public class Staff
{
    private string fullname;
    private StaffRank rank;
    private StaffSpecialization specialization;
    private string telephone;
    private string hiringDate;
    private List<ConstructionObject> constructionObjects;
    private int salary;

    /// <summary>
    /// Конструктор
    /// </summary>
    public Staff(string fullname, StaffRank rank, StaffSpecialization specialization,
                 string telephone, string hiringDate, int salary)
    {
        this.fullname = fullname;
        this.rank = rank;
        this.specialization = specialization;
        this.telephone = telephone;
        this.hiringDate = hiringDate;
        this.salary = salary;
        this.constructionObjects = new List<ConstructionObject>();
    }

    /// <summary>
    /// Свойство для полного имени
    /// </summary>
    public string Fullname
    {
        get { return fullname; }
        set
        {
            if (string.IsNullOrWhiteSpace(value))
                throw new ArgumentException("Имя сотрудника не может быть пустым");
            fullname = value;
        }
    }

    /// <summary>
    /// Свойство для должности
    /// </summary>
    public StaffRank Rank
    {
        get { return rank; }
        set { rank = value; }
    }

    /// <summary>
    /// Свойство для специализации
    /// </summary>
    public StaffSpecialization Specialization
    {
        get { return specialization; }
        set { specialization = value; }
    }

    /// <summary>
    /// Свойство для телефона с валидацией
    /// </summary>
    public string Telephone
    {
        get { return telephone; }
        set
        {
            if (string.IsNullOrWhiteSpace(value))
                throw new ArgumentException("Номер телефона не может быть пустым");
            telephone = value;
        }
    }

    /// <summary>
    /// Свойство для даты найма (только для чтения после создания)
    /// </summary>
    public string HiringDate
    {
        get { return hiringDate; }
        private set { hiringDate = value; }
    }

    /// <summary>
    /// Свойство для зарплаты с валидацией
    /// </summary>
    public int Salary
    {
        get { return salary; }
        set
        {
            if (value < 0)
                throw new ArgumentException("Зарплата не может быть отрицательной");
            if (value < 30000)
                throw new ArgumentException("Зарплата не может быть меньше минимальной ($30,000)");
            salary = value;
        }
    }

    /// <summary>
    /// Свойство для списка проектов (только для чтения)
    /// </summary>
    public List<ConstructionObject> ConstructionObjects
    {
        get { return constructionObjects; }
    }

    // Устаревшие методы для обратной совместимости
    public string GetFullname() => Fullname;
    public StaffRank GetRank() => Rank;
    public StaffSpecialization GetSpecialization() => Specialization;
    public string GetTelephone() => Telephone;
    public string GetHiringDate() => HiringDate;
    public int GetSalary() => Salary;
    public List<ConstructionObject> GetConstructionObjects() => ConstructionObjects;

    public void SetFullname(string fullname) => Fullname = fullname;
    public void SetRank(StaffRank rank) => Rank = rank;
    public void SetSpecialization(StaffSpecialization specialization) => Specialization = specialization;
    public void SetTelephone(string telephone) => Telephone = telephone;
    public void SetHiringDate(string hiringDate) => HiringDate = hiringDate;
    public void SetSalary(int salary) => Salary = salary;

    /// <summary>
    /// Назначить на объект
    /// </summary>
    public void AssignToObject(ConstructionObject obj)
    {
        constructionObjects.Add(obj);
        Console.WriteLine($"{fullname} assigned to project at {obj.GetAddress()}");
    }

    /// <summary>
    /// Удалить с объекта
    /// </summary>
    public void RemoveFromObject(ConstructionObject obj)
    {
        constructionObjects.Remove(obj);
        Console.WriteLine($"{fullname} removed from project at {obj.GetAddress()}");
    }

    /// <summary>
    /// Отображение информации о сотруднике
    /// </summary>
    public void DisplayInfo()
    {
        Console.WriteLine($"[Staff Member]");
        Console.WriteLine($"  Name: {fullname}");
        Console.WriteLine($"  Rank: {rank.ToDisplayString()}");
        Console.WriteLine($"  Specialization: {specialization.ToDisplayString()}");
        Console.WriteLine($"  Telephone: {telephone}");
        Console.WriteLine($"  Hiring Date: {hiringDate}");
        Console.WriteLine($"  Salary: ${salary}");
        Console.WriteLine($"  Assigned Projects: {constructionObjects.Count}");
    }
}
