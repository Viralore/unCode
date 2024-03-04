//Program for Vigenere Cipher

#include <bits/stdc++.h>
using namespace std;

string vigenereCipher(string message, string key, bool encrypt)
{
    string encryptedMessage = "";

    // Repeat the key to match the length of the message
    while (key.length() < message.length())
    {
        key += key;
    }

    // Encrypt or decrypt each character in the message
    for (int i = 0; i < message.length(); ++i)
    {
        char m = message[i];
        char k = key[i];
        if (isalpha(m))
        {
            char shift = isupper(m) ? 'A' : 'a';
            if (encrypt)
            {
                encryptedMessage += ((m - shift + k - 'A') % 26) + shift;
            }
            else
            {
                encryptedMessage += ((m - shift - (k - 'A') + 26) % 26) + shift;
            }
        }
        else
        {
            encryptedMessage += m;
        }
    }

    return encryptedMessage;
}

int main()
{
    string message = "Hello World";
    string key = "key";

    string encryptedMessage = vigenereCipher(message, key, true);
    cout << "Encrypted message: " << encryptedMessage << endl;

    string decryptedMessage = vigenereCipher(encryptedMessage, key, false);
    cout << "Decrypted message: " << decryptedMessage << endl;
    return 0;
}
