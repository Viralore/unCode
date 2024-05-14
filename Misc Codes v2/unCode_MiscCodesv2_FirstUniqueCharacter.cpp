//Program to find the index of first unique character in the string

#include <bits/stdc++.h>
using namespace std;

int firstUniqueChar(string s)
{
    unordered_map<char, int> countMap;
    queue<char> uniqueQueue;

    for (char ch : s) 
    {
        countMap[ch]++;
    }

    for (char ch : s) 
    {
        if (countMap[ch] == 1) 
        {
            uniqueQueue.push(ch);
        }
    }

    while (!uniqueQueue.empty()) 
    {
        char ch = uniqueQueue.front();
        uniqueQueue.pop();
        for (int i = 0; i < s.length(); i++) 
        {
            if (s[i] == ch) 
            {
                return i;
            }
        }
    }
    return -1;
}

int main() 
{
    string s = "ffffiiiiirssstt";
    int index = firstUniqueChar(s);
    if (index != -1) 
    {
        cout << "The index of the first unique character in \"" << s << "\" is: " << index << endl;
    } 
    else 
    {
        cout << "No unique character found in \"" << s << "\"" << endl;
    }
    return 0;
}
