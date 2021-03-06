#include <iostream>
using namespace std;

int main()
{
    string Ciphertext;
    cin >> Ciphertext;
    char Plaintext[100];

    cout << Ciphertext.size() << endl;

    for (int key = 1; key < 26; key++)
    {
        int i;
        for (i = 0; i < Ciphertext.size(); i++)
        {
            Plaintext[i] = char((Ciphertext[i] - 65 + key) % 26 + 65);
        }
        Plaintext[i] = '\0';

        cout << key << ": " << Plaintext << endl;
    }
    
    return 0;
}