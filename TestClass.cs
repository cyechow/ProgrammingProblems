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

	public bool CheckPermutation(string A, string B)
	{
		//  Check if one string is a permutation of the other.
		
		// Error check (empties, nulls)
		
		// A permutation is defined by all characters of one string is within the other.
		// Order does not matter.
		
		
	}
}