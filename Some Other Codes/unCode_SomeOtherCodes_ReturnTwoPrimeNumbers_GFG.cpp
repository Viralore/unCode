//Problem link : https://www.geeksforgeeks.org/problems/return-two-prime-numbers2509/0

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isPrime(int n)
    {
        if(n<2) return false;
        for(int i=2;i<n;i++)
            if(n%i==0) return false;
        return true;
    }
    vector<int> primeDivision(int N){
        // code here
        vector<int> v;
        if(N%2!=0)
        {
            if(isPrime(N-2)) 
            {
                v.push_back(2);
                v.push_back(N-2);
                return v;
            }
        }
        for(int i=2;i<=N-2;i++)
        {
            if(isPrime(i) && isPrime(N-i))
            {
                v.push_back(i);
                v.push_back(N-i);
                return v;
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;    
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends