/*
344. Reverse String
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    void reverseString(vector<char>& s) 
    {
        int l = 0;
        int r = s.size() - 1;

        while (l < r)
        {
            swap(s[l++], s[r--]);
        }
    }
};

void print1DVec(vector<char> v)
{
    for(char i : v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<char> vec{'h','e','l','l','o'};
    print1DVec(vec);
    Solution obj;
    obj.reverseString(vec);
    print1DVec(vec);
    return 0;
}