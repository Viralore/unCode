//Program to validate parenthesis

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> st;
        unordered_map<char, char> mappings = 
        {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) 
        {
            if (mappings.find(c) != mappings.end()) 
            {
                if (st.empty() || st.top() != mappings[c]) 
                {
                    return false;
                }
                st.pop();
            } 
            else 
            {
                st.push(c);
            }
        }
        return st.empty();
    }
};

int main() 
{
    Solution solution;
    string test_case_1 = "{[()]}{{[[(())]]}}";  //valid
    string test_case_2 = "{[()]}{{[[(())]]}";   //invalid

    cout << boolalpha;
    cout << "test_case_1 : " << solution.isValid(test_case_1) << endl;
    cout << "test_case_2 : " << solution.isValid(test_case_2) << endl;

    return 0;
}
