/*
    Print the binary strings of length N with no consecutive 1's
*/

/*
input :
3
output :
0 0 0
0 0 1
1 0 0
1 0 1
0 1 0
*/

#include<bits/stdc++.h>
using namespace std;

void printVec(vector<string> ans)
{
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}

vector<string> printBinaryString(int n)
{
    if(n==1) return {"0","1"};
    vector<string> output;
    vector<string> subprob = printBinaryString(n-1);
    for(int i=0;i<subprob.size();i++)
    {
        string temp=subprob[i];
        int size = temp.size();
        if(temp[size-1]=='1') output.push_back(temp+"0");
        else
        {
            output.push_back(temp+"0");
            output.push_back(temp+"1");
        }
    }
    return output;
}

int main()
{
    int n;cout<<"Enter N : ";cin>>n;
    vector<string> ans = printBinaryString(n);
    cout<<endl<<"Binary Strings with no consecutive 1's of length "<<n<<endl;
    printVec(ans);
    return 0;
}
