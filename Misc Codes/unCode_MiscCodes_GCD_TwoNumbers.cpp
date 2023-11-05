//Program to find GCD of Two Numbers
//we will use recursion

#include<bits/stdc++.h>
using namespace std;

int GCD(int a,int b)
{
    if(a==0) return b;      //if any number is divisible then remainder becomes zero then return the other number
    else return GCD(b%a,a); //recursion till remainder becomes zero
}

int main()
{
    int A,B;                                            //declaring two variables
    cout<<"Enter first number  : ";                     //taking inputs
    cin>>A;
    cout<<"Enter Second number : ";
    cin>>B;
    cout<<"GCD of "<<A<<" and "<<B<<" is "<<GCD(A,B);   //printing the GCD
    return 0;
}
