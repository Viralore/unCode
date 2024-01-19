//Program to find squareroot upto user defined decimal places

#include<bits/stdc++.h>
using namespace std;

float squareRoot(int N,int P)
{
    int start = 0,last = N;
    int mid = (start+last)/2;
    int temp;
    while(start<=last)
    {
        if(mid*mid<=N) temp=mid;
        if(mid*mid>N)
        {
            last = mid-1;
            mid = (start+last)/2;
        }
        else
        {
            start = mid+1;
            mid = (start+last)/2;
        }
    }
    float fans = temp;
    float inc = 0.1;
    for(int t=1;t<=P;t++)
    {
        while(fans*fans<=N)
        {
            fans += inc;
        }
        fans -= inc;
        inc = inc/10;
    }
    return fans;
}

int main()
{
    int n,p;
    cout<<"Number         : ";cin>>n;
    cout<<"Decimal Places : ";cin>>p;
    cout<<"Square root of "<<n<<" upto "<<p<<" decimal places : "<<squareRoot(n,p);
    return 0;
}
