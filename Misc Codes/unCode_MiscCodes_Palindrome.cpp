//Program to check whether given string is Palindrome or not

//Time Complexity
//Worst Case    Average Case    Best Case
//O(N)              O(N)          O(N)
//Space Complexity O(1)

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string input)
{
    string temp="";                             //temporary variable to check
    int len = input.length();                   //storing the length
    for(int i=len-1;i>=0;i--)                   //to reverse the string
    {
        temp = temp + input[i];
    }
    for(int i=0,j=len-1;i<len;i++,j--)          //to check if reverse and input string are same or not
    {
        if(input[i]!=temp[j]) return false;     //if not then return false as not palindrome
    }
    return true;                                //if program counter reaches here then string is palindrome
}

int main()
{
    string input;                                                       //declaring the variables
    cout<<"Enter the string to check for palindrome : ";
    cin>>input;                                                         //taking input
    bool check = isPalindrome(input);                                   //storing the result of the isPalindrome function to check palindrome
    if(check) cout<<"Given string : "<<input<<" is Palindrome"<<endl;   //printing the result
    else cout<<"Given string : "<<input<<" is not a Palindrome"<<endl;
    return 0;
}
