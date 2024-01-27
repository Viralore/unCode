/*
    Generate strings of length 2N
    of valid Parenthesis
    Count and Print
*/

/*
input :
3

output :
((()))
()()()
(())()
()(())
(()())
*/

#include<bits/stdc++.h>
using namespace std;

void printStrings(int n,string out,int close,int open)
{
    if(out.size()==2*n)
    {
        cout<<out<<endl;
        return;
    }
    if(close<open)
    {
        printStrings(n,out+")",close+1,open);
    }
    if(open<n)
    {
        printStrings(n,out+"(",close,open+1);
    }
}

void generateString(int n)
{
    string temp = "";
    printStrings(n,temp,0,0);
}

int main()
{
    int n;
    cin>>n;
    generateString(n);
    return 0;
}
