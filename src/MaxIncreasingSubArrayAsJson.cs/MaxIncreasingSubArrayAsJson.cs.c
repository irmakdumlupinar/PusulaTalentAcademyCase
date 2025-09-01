/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cpplite/CTemplate.c to edit this template
 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.Json;

public class MaxIncreasingSubArray
{
    public static string MaxIncreasingSubArrayAsJson(List<int> numbers)
    {
        if (numbers == null || numbers.Count == 0)
            return JsonSerializer.Serialize(new List<int>());

        List<int> current = new List<int> { numbers[0] };
        List<int> best = new List<int>(current);
        int currentSum = numbers[0];
        int bestSum = numbers[0];

        for (int i = 1; i < numbers.Count; i++)
        {
            if (numbers[i] > numbers[i - 1])
            {
                current.Add(numbers[i]);
                currentSum += numbers[i];
            }
            else
            {
                if (currentSum > bestSum)
                {
                    best = new List<int>(current);
                    bestSum = currentSum;
                }
                current = new List<int> { numbers[i] };
                currentSum = numbers[i];
            }
        }

        // son alt diziyi kontrol et
        if (currentSum > bestSum)
            best = current;

        return JsonSerializer.Serialize(best);
    }
}

