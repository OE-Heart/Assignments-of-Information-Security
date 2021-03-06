#include <iostream>
using namespace std;

int main()
{
    int key;
    cout << "Please input the key: ";
    cin >> key;

    string Plaintext;
    cout << "Please input the plaintext: ";
    cin >> Plaintext;
    char Ciphertext[100];

    int i;
    for (i = 0; i < Plaintext.size(); i++)
    {
        Ciphertext[i] = char((Plaintext[i] - 65 - key + 26) % 26 + 65);
    }
    Ciphertext[i] = '\0';

    cout << "The ciphertext is: " << Ciphertext << endl;
    
    return 0;
}