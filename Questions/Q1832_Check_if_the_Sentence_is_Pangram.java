/*
1832. Check if the Sentence Is Pangram

A pangram is a sentence where every letter of the English alphabet appears at least once.
Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
Example 2:

Input: sentence = "leetcode"
Output: false
 

Constraints:

1 <= sentence.length <= 1000
sentence consists of lowercase English letters.
*/

import java.util.*;

class Solution
{
	public static boolean checkIfPangram(String sentence)
    	{
        	if(sentence.length()<26) return false;
        	boolean[] arr = new boolean[26];
        	for(int i=0;i<26;i++) arr[i] = false;
        
       		for(int i=0;i<sentence.length();i++)
        	{
            		int temp = (int)sentence.charAt(i) - 97;
            		if(temp>=0 && temp<=25) arr[temp] = true;
        	}

        	for(int i=0;i<arr.length;i++)
            		if(arr[i] != true) return false;

        	return true;
    	}
}

public class Q1832_Check_if_the_Sentence_is_Pangram
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		String sentence = in.nextLine();
		if(Solution.checkIfPangram(sentence)) System.out.println("true");
		else System.out.println("false");
	}
}