using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.Json;

public class FilterEmployeesClass
{
    public static string FilterEmployees(IEnumerable<(string Name, int Age, string Department, decimal Salary, DateTime HireDate)> employees)
    {
        var filtered = employees
            .Where(e => e.Age >= 25 && e.Age <= 40)
            .Where(e => e.Department == "IT" || e.Department == "Finance")
            .Where(e => e.Salary >= 5000 && e.Salary <= 9000)
            .Where(e => e.HireDate > new DateTime(2017, 1, 1))
            .ToList();

        var result = new
        {
            Names = filtered
                .Select(e => e.Name)
                .OrderByDescending(n => n.Length)
                .ThenBy(n => n)
                .ToList(),
            TotalSalary = filtered.Any() ? filtered.Sum(e => e.Salary) : 0,
            AverageSalary = filtered.Any() ? Math.Round(filtered.Average(e => e.Salary), 2) : 0,
            MinSalary = filtered.Any() ? filtered.Min(e => e.Salary) : 0,
            MaxSalary = filtered.Any() ? filtered.Max(e => e.Salary) : 0,
            Count = filtered.Count
        };

        return JsonSerializer.Serialize(result);
    }
}

