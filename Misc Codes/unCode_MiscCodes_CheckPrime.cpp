//Program to check whether a number is prime or not
//we will use NOOB approach

//Time Complexity to check
//Worst Case    Average Case    Best Case
//O(N)            O(N)            O(N)

#include<bits/stdc++.h>
using namespace std;

//function to check whether a number is prime or not
bool isPrime(int n)
{
    if(n<2) return false;           //if number is negative or less than 2 then return false
    for(int i=2;i<n;i++)            //loop till the given number
    {
        if(n%i==0) return false;    //if any number in between 2 to that number then not a prime so return false
    }
    return true;                    //if program control reach this point meaning number is prime so return true
}

int main()
{
    int n;                                                  //declaring input var
    cout<<"Enter a number to check : ";
    cin>>n;                                                 //taking input

    if(isPrime(n)) cout<<"Number : "<<n<<" is Prime"<<endl; //checking and printing the result
    else cout<<"Number : "<<n<<" is not Prime"<<endl;

	return 0;
}
