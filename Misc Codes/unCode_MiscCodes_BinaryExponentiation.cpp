//Program to find any power of any number using bit manipulation

#include<bits/stdc++.h>
using namespace std;

int power(int a,int n)
{
    int ans = 1;
    while(n>0)
    {
        int last_bit = (n&1);
        if(last_bit == 1) ans = ans*a;
        a = a*a;
        n = n>>1;
    }
    return ans;
}

int main()
{
    int base,exponent;
    cout<<"Enter the base  : ";cin>>base;
    cout<<"Enter the power : ";cin>>exponent;
    cout<<base<<" to the power "<<exponent<<" is "<<power(base,exponent)<<endl;;
    return 0;
}
