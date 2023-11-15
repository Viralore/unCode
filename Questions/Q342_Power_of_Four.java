/*
342. Power of Four
Given an integer n, return true if it is a power of four. Otherwise, return false.
An integer n is a power of four, if there exists an integer x such that n == 4x.

Example 1:
Input: n = 16
Output: true

Example 2:
Input: n = 5
Output: false

Example 3:
Input: n = 1
Output: true
 

Constraints:
-231 <= n <= 231 - 1
*/

import java.util.*;

class Solution
{
	public static double logWithBase(int n,int base)
    	{
        	double res = (Math.log(n)/Math.log(base));
        	return res;
    	}
    	public static boolean isPowerOfFour(int n)
    	{
        	int compare_1 = (int) Solution.logWithBase(n,4);
        	double compare_2 = Solution.logWithBase(n,4);
        	return compare_1-compare_2==0?true:false;
    	}
}

public class Q342_Power_of_Four
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		System.out.print("Enter the number to check for the power of four : ");
		int n = in.nextInt();
		if(Solution.isPowerOfFour(n)) System.out.println("true");
		else System.out.println("false");
		in.close();
	}
}