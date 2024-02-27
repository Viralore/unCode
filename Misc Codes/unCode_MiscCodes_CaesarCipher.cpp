//Program for Caesar Cipher

#include <bits/stdc++.h>
using namespace std;

string caesarCipher(string text, int shift)
{
    string result = "";

    for (char& c : text)
    {
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            c = base + (c - base + shift) % 26;
        }
        result += c;
    }

    return result;
}


int main()
{
    string message;
    int shift;

    cout << "Enter message to encrypt: ";
    getline(cin, message);

    cout << "Enter shift value: ";
    cin >> shift;

    string encrypted = caesarCipher(message, shift);
    cout << "Encrypted message: " << encrypted << endl;
    return 0;
}
