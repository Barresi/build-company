namespace BuildCompany;

/// <summary>
/// Класс для логирования действий компании в файл
/// Демонстрация использования using statement для работы с файлами
/// </summary>
public class CompanyLogger : IDisposable
{
    private StreamWriter? writer;
    private string logFilePath;
    private bool disposed = false;

    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="logFilePath">Путь к файлу логов</param>
    public CompanyLogger(string logFilePath)
    {
        this.logFilePath = logFilePath;

        try
        {
            // Открываем файл для записи (или создаем новый)
            writer = new StreamWriter(logFilePath, append: true);
            writer.WriteLine($"\n=== Сессия логирования начата: {DateTime.Now} ===");
            writer.Flush();
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ошибка при открытии файла логов: {ex.Message}");
            throw;
        }
    }

    /// <summary>
    /// Записать сообщение в лог
    /// </summary>
    public void Log(string message)
    {
        if (disposed)
        {
            throw new ObjectDisposedException(nameof(CompanyLogger));
        }

        try
        {
            string timestamp = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss");
            writer?.WriteLine($"[{timestamp}] {message}");
            writer?.Flush();
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ошибка при записи в лог: {ex.Message}");
        }
    }

    /// <summary>
    /// Статический метод для записи в лог с автоматическим освобождением ресурсов
    /// Демонстрация using statement
    /// </summary>
    public static void LogToFile(string logFilePath, string message)
    {
        // using statement автоматически вызовет Dispose() в конце блока
        using (StreamWriter writer = new StreamWriter(logFilePath, append: true))
        {
            string timestamp = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss");
            writer.WriteLine($"[{timestamp}] {message}");
        } // Здесь автоматически вызывается writer.Dispose()
    }

    /// <summary>
    /// Альтернативный синтаксис using declaration (C# 8.0+)
    /// </summary>
    public static void LogToFileModern(string logFilePath, string message)
    {
        // using declaration - объект будет освобожден в конце области видимости
        using StreamWriter writer = new StreamWriter(logFilePath, append: true);
        string timestamp = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss");
        writer.WriteLine($"[{timestamp}] {message}");
    } // Здесь автоматически вызывается writer.Dispose()

    /// <summary>
    /// Чтение логов из файла с использованием using
    /// </summary>
    public static string ReadLogs(string logFilePath, int maxLines = 10)
    {
        try
        {
            using (StreamReader reader = new StreamReader(logFilePath))
            {
                List<string> lines = new List<string>();
                string? line;

                while ((line = reader.ReadLine()) != null && lines.Count < maxLines)
                {
                    lines.Add(line);
                }

                return string.Join("\n", lines);
            } // StreamReader автоматически закрывается здесь
        }
        catch (FileNotFoundException)
        {
            return "Файл логов не найден";
        }
        catch (Exception ex)
        {
            return $"Ошибка чтения логов: {ex.Message}";
        }
    }

    /// <summary>
    /// Демонстрация множественного using для работы с несколькими ресурсами
    /// </summary>
    public static void CopyLogs(string sourceFile, string destinationFile)
    {
        try
        {
            // Множественный using - оба потока будут автоматически закрыты
            using (StreamReader reader = new StreamReader(sourceFile))
            using (StreamWriter writer = new StreamWriter(destinationFile))
            {
                string? line;
                while ((line = reader.ReadLine()) != null)
                {
                    writer.WriteLine(line);
                }
            } // Оба ресурса освобождаются здесь в обратном порядке

            Console.WriteLine($"Логи скопированы из {sourceFile} в {destinationFile}");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ошибка копирования логов: {ex.Message}");
            throw;
        }
    }

    /// <summary>
    /// Реализация IDisposable для правильного освобождения ресурсов
    /// </summary>
    public void Dispose()
    {
        Dispose(true);
        GC.SuppressFinalize(this);
    }

    /// <summary>
    /// Protected реализация Dispose
    /// </summary>
    protected virtual void Dispose(bool disposing)
    {
        if (!disposed)
        {
            if (disposing)
            {
                // Освобождаем управляемые ресурсы
                if (writer != null)
                {
                    writer.WriteLine($"=== Сессия логирования завершена: {DateTime.Now} ===\n");
                    writer.Flush();
                    writer.Close();
                    writer.Dispose();
                    writer = null;
                }
            }

            disposed = true;
        }
    }

    /// <summary>
    /// Деструктор (финализатор)
    /// </summary>
    ~CompanyLogger()
    {
        Dispose(false);
    }
}
