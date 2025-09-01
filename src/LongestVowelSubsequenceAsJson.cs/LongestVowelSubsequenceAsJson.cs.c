
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.Json;

public class LongestVowelSubsequence
{
    public static string LongestVowelSubsequenceAsJson(List<string> words)
    {
        if (words == null || words.Count == 0)
            return JsonSerializer.Serialize(new List<object>());

        var vowels = new HashSet<char> { 'a', 'e', 'i', 'o', 'u' };

        var results = words.Select(word =>
        {
            string longestSeq = "";
            string currentSeq = "";

            foreach (char c in word.ToLower())
            {
                if (vowels.Contains(c))
                {
                    currentSeq += c;
                    if (currentSeq.Length > longestSeq.Length)
                        longestSeq = currentSeq;
                }
                else
                {
                    currentSeq = "";
                }
            }

            return new
            {
                word = word,
                sequence = longestSeq,
                length = longestSeq.Length
            };
        }).ToList();

        return JsonSerializer.Serialize(results);
    }
}
