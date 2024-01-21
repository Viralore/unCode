/*
    Kth number using Digits array

    Example :
    Arr : 1 5 7     K : 8
    Process : 1,5,7,11,15,17,51,55,57,71,75,77,111,115,117,151..................................
    Output : 55
*/

#include<bits/stdc++.h>
using namespace std;

void inputVec(vector<int> &v,int n)
{
    int temp;
    cout<<"Elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }
}

int kthNumberUsingDigits(vector<int> v,int k)
{
    queue<int> q;
    int n = v.size();
    int top;
    for(int i=0;i<n;i++)
        q.push(v[i]);
    while(k--)
    {
        top = q.front();
        q.pop();
        for(int i=0;i<n;i++)
            q.push(top*10+v[i]);
    }
    return top;
}

/*
    Using queue
    put all digits first
    then pop 1 by 1 and multiply with the given digits
    remember the total pop function calls
*/

int main()
{
    int n,k;
    cout<<"No. Elements : ";cin>>n;
    vector<int> v;
    inputVec(v,n);
    cout<<"k : ";cin>>k;
    cout<<kthNumberUsingDigits(v,k);
    return 0;
}
