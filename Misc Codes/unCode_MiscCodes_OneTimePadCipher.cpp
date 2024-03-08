//Program for one time pad cipher

#include <bits/stdc++.h>
using namespace std;

string generateKey(int length)
{
    string key;
    for (int i = 0; i < length; ++i)
    {
        key += static_cast<char>(rand() % 26 + 'A');
    }
    return key;
}

string encrypt(const string& message, const string& key)
{
    string ciphertext;
    for (size_t i = 0; i < message.length(); ++i)
    {
        ciphertext += static_cast<char>((message[i] ^ key[i]) + 'A');
    }
    return ciphertext;
}

string decrypt(const string& ciphertext, const string& key)
{
    string decryptedMessage;
    for (size_t i = 0; i < ciphertext.length(); ++i)
    {
        decryptedMessage += static_cast<char>((ciphertext[i] ^ key[i]) + 'A');  // XOR and convert to uppercase
    }
    return decryptedMessage;
}

int main()
{
    srand(static_cast<unsigned>(time(0)));
    string message, key;
    cout << "Enter the message to encrypt: ";
    getline(cin, message);
    key = generateKey(message.length());
    cout<<"Key used : "<<key<<endl;
    string ciphertext = encrypt(message, key);
    cout << "Encrypted Message: " << ciphertext << endl;
    string decryptedMessage = decrypt(ciphertext, key);
    cout << "Decrypted Message: " << decryptedMessage << endl;
    return 0;
}
