/*
242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 
Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/

import java.util.*;

class Solution
{
    public static boolean isAnagram(String s, String t)
    {
        if(s.length()!=t.length()) return false;
        int[] arr = new int[26];

        for(int i=0;i<s.length();i++)
        {
            int temp = (int)s.charAt(i) - 97;
            if(temp>=0 && temp<=25) arr[temp]++;
        }
        for(int i=0;i<t.length();i++)
        {
            int temp = (int)t.charAt(i) - 97;
            if(temp>=0 && temp<=25) arr[temp]--;
        }

        for(int i=0;i<arr.length;i++)
            if(arr[i]!=0) return false;
        
        return true;
    }
}

public class Q242_Valid_Anagram
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		System.out.print("Please enter first string  : ");
		String s = in.nextLine();
		System.out.print("Please enter second string : ");
		String t = in.nextLine();
		if(Solution.isAnagram(s,t)) System.out.println("true");
		else System.out.println("false");
	}
}