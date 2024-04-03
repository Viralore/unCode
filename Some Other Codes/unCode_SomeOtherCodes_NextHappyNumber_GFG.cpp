//Problem link : https://www.geeksforgeeks.org/problems/next-happy-number4538/0

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int returnSquare(int num)
    {
        int temp = 0;
        while(num!=0)
        {
            int x = num%10;
            temp = temp + x*x;
            num = num/10;
        }
        return temp;
    }
    
    bool isHappy(int num)
    {
        if(num==1 || num==7 || num==10) return true;
        if(num<10) return false;
        return isHappy(returnSquare(num));
    }

    int nextHappy(int N)
    {
        // code here
        int temp = N + 1;
        while(temp>0)
        {
            if(isHappy(temp)) return temp;
            temp++;
        }
        return -1;
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
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends