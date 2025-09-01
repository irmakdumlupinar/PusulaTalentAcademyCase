using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.Json;
using System.Xml.Linq;

public class FilterPeopleFromXmlClass
{
    public static string FilterPeopleFromXml(string xmlData)
    {
        var doc = XDocument.Parse(xmlData);

        var people = doc.Descendants("Person")
            .Select(p => new
            {
                Name = (string)p.Element("Name"),
                Age = (int)p.Element("Age"),
                Department = (string)p.Element("Department"),
                Salary = (int)p.Element("Salary"),
                HireDate = DateTime.Parse((string)p.Element("HireDate"))
            })
            .Where(p => p.Age > 30
                        && p.Department == "IT"
                        && p.Salary > 5000
                        && p.HireDate < new DateTime(2019, 1, 1))
            .ToList();

        var result = new
        {
            Names = people.Select(p => p.Name).OrderBy(n => n).ToList(),
            TotalSalary = people.Any() ? people.Sum(p => p.Salary) : 0,
            AverageSalary = people.Any() ? people.Average(p => p.Salary) : 0,
            MaxSalary = people.Any() ? people.Max(p => p.Salary) : 0,
            Count = people.Count
        };

        return JsonSerializer.Serialize(result);
    }
}