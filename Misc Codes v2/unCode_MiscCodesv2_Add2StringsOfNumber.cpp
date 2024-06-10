//Program to add 2 strings of numbers

#include <bits/stdc++.h>
using namespace std;

string addStrings(string num1, string num2) 
{
    if (num1.length() < num2.length()) 
        swap(num1, num2);

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    string result = "";
    int carry = 0;

    for (size_t i = 0; i < num1.length(); ++i) 
    {
        int digit1 = num1[i] - '0';
        int digit2 = (i < num2.length()) ? num2[i] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    if (carry) 
    {
        result += carry + '0';
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() 
{
    string num1, num2;
    cout << "Enter the first number string: ";
    cin >> num1;
    cout << "Enter the second number string: ";
    cin >> num2;

    string result = addStrings(num1, num2);

    cout << "The sum of the two number strings is: " << result << endl;

    return 0;
}
