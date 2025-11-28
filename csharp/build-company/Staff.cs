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
    /// Получить полное имя
    /// </summary>
    public string GetFullname()
    {
        return fullname;
    }

    /// <summary>
    /// Получить должность
    /// </summary>
    public StaffRank GetRank()
    {
        return rank;
    }

    /// <summary>
    /// Получить специализацию
    /// </summary>
    public StaffSpecialization GetSpecialization()
    {
        return specialization;
    }

    /// <summary>
    /// Получить телефон
    /// </summary>
    public string GetTelephone()
    {
        return telephone;
    }

    /// <summary>
    /// Получить дату найма
    /// </summary>
    public string GetHiringDate()
    {
        return hiringDate;
    }

    /// <summary>
    /// Получить зарплату
    /// </summary>
    public int GetSalary()
    {
        return salary;
    }

    /// <summary>
    /// Получить список проектов
    /// </summary>
    public List<ConstructionObject> GetConstructionObjects()
    {
        return constructionObjects;
    }

    /// <summary>
    /// Установить полное имя
    /// </summary>
    public void SetFullname(string fullname)
    {
        this.fullname = fullname;
    }

    /// <summary>
    /// Установить должность
    /// </summary>
    public void SetRank(StaffRank rank)
    {
        this.rank = rank;
    }

    /// <summary>
    /// Установить специализацию
    /// </summary>
    public void SetSpecialization(StaffSpecialization specialization)
    {
        this.specialization = specialization;
    }

    /// <summary>
    /// Установить телефон
    /// </summary>
    public void SetTelephone(string telephone)
    {
        this.telephone = telephone;
    }

    /// <summary>
    /// Установить дату найма
    /// </summary>
    public void SetHiringDate(string hiringDate)
    {
        this.hiringDate = hiringDate;
    }

    /// <summary>
    /// Установить зарплату
    /// </summary>
    public void SetSalary(int salary)
    {
        this.salary = salary;
    }

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
