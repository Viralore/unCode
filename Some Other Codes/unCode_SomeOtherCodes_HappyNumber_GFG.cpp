//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int returnSquare(int num)
    {
        int temp=0;
        while(num!=0)
        {
            int x = num%10;
            temp = temp + x*x;
            num/=10;
        }
        return temp;
    }
    
    bool isHappyNumber(int num)
    {
        if(num==1 || num==7 || num==10) return true;
        if(num<10) return false;
        return isHappyNumber(returnSquare(num));
    }
    
    int isHappy(int N)
    {
        // code here
        if(isHappyNumber(N)) return 1;
        return 0;
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
        cout << ob.isHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends