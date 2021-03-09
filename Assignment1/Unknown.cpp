#include <iostream>
#include <cstring>
using namespace std;

void Replace(char* s, char a, char b);
void Decrypt(char* s);

int main()
{
    char Ciphertext[200] = "MAL TIRRUEZF CR MAL RKZYIOL EX MAL OIY UAE RICF \"MAL ACWALRM DYEUPLFWL CR ME DYEU MAIM UL IZL RKZZEKYFLF GH OHRMLZH\"\0";

    Decrypt(Ciphertext);

    cout << Ciphertext;

    return 0;
    
}

void Replace(char* s, char a, char b)
{
    for(int i = 0; i < strlen(s); i++)
    {
        if (s[i] == a) s[i] = b;
    }
}

void Decrypt(char* s)
{
    Replace(s, 'M', 't');
    Replace(s, 'A', 'h');
    Replace(s, 'L', 'e');
    Replace(s, 'E', 'o');
    Replace(s, 'X', 'f');
    Replace(s, 'I', 'a');
    Replace(s, 'C', 'i');
    Replace(s, 'R', 's');
    Replace(s, 'W', 'g');
    Replace(s, 'F', 'd');
    Replace(s, 'U', 'w');
    Replace(s, 'D', 'k');
    Replace(s, 'Y', 'n');
    Replace(s, 'P', 'l');
    Replace(s, 'Z', 'r');
    Replace(s, 'T', 'p');
    Replace(s, 'K', 'u');
    Replace(s, 'G', 'b');
    Replace(s, 'H', 'y');
    Replace(s, 'O', 'm');
}