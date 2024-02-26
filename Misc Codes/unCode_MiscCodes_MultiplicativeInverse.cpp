//Program to find Multiplicative Inverse of A mod B

#include<bits/stdc++.h>
using namespace std;

int extendedEuclidean(int n1,int n2)
{
    int q,r=0,r1,r2,t,t1=0,t2=1;
    if(n1>n2)
    {
        r1 = n1;
        r2 = n2;
    }
    else
    {
        r1 = n2;
        r2 = n1;
    }
    while(r!=1)
    {
        q = r1/r2;
        r = r1%r2;
        t = t1 - (q*t2);
        r1 = r2;
        r2 = r;
        t1 = t2;
        t2 = t;
    }
    return t;
}

int main()
{
    int n1,n2;
    cout<<"Enter n1 : ";cin>>n1;
    cout<<"Enter n2 : ";cin>>n2;
    cout<<"Multiplicative Inverse : "<<extendedEuclidean(n1,n2);
    return 0;
}
