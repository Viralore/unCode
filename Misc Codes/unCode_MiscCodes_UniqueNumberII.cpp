//Unique Number II
//Given 2N+2 Numbers where 2N numbers are repeated

/*
    Example : Arr : 5 7 3 2 11 3 5 2  n : 8
    Output  : 7 11
*/

#include<bits/stdc++.h>
using namespace std;

int bitIndex(int x)
{
    int pos=0;
    if(x&1==1) return 0;
    while(x>0)
    {
        int last_bit = x&1;
        if(last_bit==1) break;
        else pos++;
        x = x>>1;
    }
    return pos;
}

vector<int> uniqueNumberII(vector<int> v)
{
    int n = v.size();
    vector<int> ans;
    int temp=0;
    for(int i=0;i<n;i++)
        temp = temp^v[i];
    int temp_b=temp;
    int pos = bitIndex(temp);
    for(int i=0;i<n;i++)
    {
        if((v[i]>>pos)==1) temp = temp^v[i];
        else temp_b = temp_b ^ v[i];
    }
    ans.push_back(temp);
    ans.push_back(temp_b);
    return ans;
}

int main()
{
    int n,temp;
    cout<<"No. elements : ";cin>>n;
    vector<int> v,output;
    cout<<"Elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }
    output = uniqueNumberII(v);
    for(int i=0;i<2;i++)
        cout<<output[i]<<" ";
    return 0;
}
