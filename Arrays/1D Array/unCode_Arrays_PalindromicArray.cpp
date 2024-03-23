//Program to check whether the given array is palindromic or not

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(vector<int>& arr)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        if (arr[left] != arr[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main()
{
    vector<int> arr = {1, 2, 3, 2, 1};
    if (isPalindrome(arr))
    {
        cout << "The array is a palindrome." << endl;
    }
    else
    {
        cout << "The array is not a palindrome." << endl;
    }
    return 0;
}
