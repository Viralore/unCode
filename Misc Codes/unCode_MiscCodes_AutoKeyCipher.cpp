//Program for Auto Key Cipher

#include<bits/stdc++.h>
using namespace std;

string generateAutoKey(string message, string key)
{
    string generatedKey = key;
    for (int i = key.length(); i < message.length(); ++i)
    {
        generatedKey += message[i - key.length()];
    }
    return generatedKey;
}

string autoKeyCipher(string message, string key, bool encrypt)
{
    string encryptedMessage = "";
    string generatedKey = generateAutoKey(message, key);

    for (int i = 0; i < message.length(); ++i)
    {
        char m = message[i];
        char k = generatedKey[i];
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
            if (encrypt)
            {
                generatedKey += m;
            }
            else
            {
                generatedKey += encryptedMessage.back();
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

    string encryptedMessage = autoKeyCipher(message, key, true);
    cout << "Encrypted message: " << encryptedMessage << endl;

    string decryptedMessage = autoKeyCipher(encryptedMessage, key, false);
    cout << "Decrypted message: " << decryptedMessage << endl;

    return 0;
}
