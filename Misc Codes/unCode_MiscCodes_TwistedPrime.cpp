//Program to check for Twisted Prime
//Twisted Prime is a number which is prime and its reverse is also prime like 73 is prime and 37 is also prime
//we will use string for taking input as it is easy to reverse the given number

//Time Complexity to check for Prime
//Worst Case    Average Case    Best Case
//O(sqrt(N))     O(sqrt(N))     O(sqrt(N))

//Time Complexity to check for Twisted Prime
//Worst Case    Average Case    Best Case
//O(sqrt(N))     O(sqrt(N))     O(sqrt(N))

#include<bits/stdc++.h>
using namespace std;

//To check for prime
bool isPrime(string input)
{
    int n = stoi(input);            //converting the given number(string) to integer data type stoi stands for string to integer
    if(n<2) return false;
    for(int i=2;i<sqrt(n);i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

//Function to reverse the number
string reverseNumber(string str)
{
    string temp = "";               //temp var to hold reverse of given number
    int len = str.length();

    for(int i=len-1;i>=0;i--)       //to traverse the whole string in reverse
        temp = temp + str[i];       //reversing the string

    return temp;                    //returning the reverse
}

//Function to find whether given number is prime or not
bool isTwistedPrime(string input)
{
    string rev = reverseNumber(input);      //firstly we reverse the given number then check for prime
    if(isPrime(rev)) return true;           //if revere of given number is prime then return true
    return false;                           //if not then return false
}

int main()
{
    string input;                                                   //declaring the string as input
    cout<<"Enter the number to check for twisted prime : ";
    cin>>input;                                                     //taking input

    if(isPrime(input))                                              //check whether the given number is prime or not
    {
        if(isTwistedPrime(input))                                   //if given number is prime then check for twisted prime
        {
            cout<<input<<" is Twisted Prime"<<endl;                 //printing the result
        }
        else cout<<input<<" is prime but not Twisted Prime"<<endl;
    }
    else cout<<input<<" is not a Prime number"<<endl;               //if not prime

    return 0;
}
