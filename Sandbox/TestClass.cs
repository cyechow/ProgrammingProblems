using System;
using System.Text;
using System.Collection.Generic;

public class TestClass
{
	void TestClass();
	void ~TestClass();
	
	public bool IsAllUnique(string S)
	{
		// Determine if a string has all unique characters.
		// Assumptions:
		//	- Upper and lower case of each alphabetical character is considered different
		
		// Traverse through string, add to map, check if key exists, if it already does then return false.
		Dictionary<char, int> charCount = new Dictionary<char, int>();
		for (int i = 0; i < S.Length; i++)
		{
			if (charCount.ContainsKey(S[i])) return false;
			
			charCount.Add(S[i], 1);
		}
		
		return true;
	}
	
	public bool IsAllCharUnique(string S)
	{
		// Determine if a string has all unique characters. No additional data structures.
		// Assumptions:
		//	- Upper/lower case of each alphabetical character is considered different
		//	- Only ASCII characters
		
		bool[] isCharExist = new bool[128];
		
		for (int i = 0; i < S.Length; i++)
		{
			int currAsciiValue = (int)S[i];
			if (isCharExist[currAsciiValue - 1]) return false;
			
			isCharExist[currAsciiValue - 1] = true;
		}
		
		return true;
	}

	public bool CheckPermutation(String A, String B)
	{
		//  Check if one string is a permutation of the other.
		
		// Error check (empties, nulls)
		
		// A permutation is defined by all characters of one string is within the other.
		// Order does not matter.
		
		// At the very least, must traverse through A and B once.
		
		// Run through A, check against every character in B. If current character exists, mark this character exclude from B in the next character check.
		// If either A or B has all characters marked, then one is a permutation of the other.
		
		// We can sort both strings, find the first occurrence of A in B and start comparison at that index.
		
	}
}