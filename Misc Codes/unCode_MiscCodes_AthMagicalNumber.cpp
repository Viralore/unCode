/*
    Find Ath Magical Number in set of Natural Number

    A number is magical if it is divisible by B or C

    input  : A : 8  B : 2  C : 3
    output : 12
*/

#include<bits/stdc++.h>
using namespace std;

int lcm(int a,int b)
{
    return a*b/(__gcd(a,b));
}

int AthMagicalNumber(int A,int B,int C)
{
    int s = 1,e = A*min(B,C),cnt=0;
    int lc = lcm(B,C), mid;
    while(s<=e)
    {
        mid = (s+e)/2;
        cnt = (mid/B) + (mid/C) - (mid/lc);
        if(cnt==A) return mid;
        else if(cnt>A) e = mid-1;
        else s = mid+1;
    }
    return mid;
}

int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    cout<<AthMagicalNumber(A,B,C);
    return 0;
}
