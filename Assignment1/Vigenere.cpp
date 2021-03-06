#include <iostream>
#include <cstring>
using namespace std;

double IC(int *Num, double total);
void Vigenere(char* Ciphertext, char* Plaintext, char* key, int keyLenth);
int find_string(char str[], char substr[]);

// int main()
// {
//     string Ciphertext = "ktbueluegvitnthuexmonveggmrcgxptlyhhjaogchoemqchpdnetxupbqntietiabpsmaoncnwvoutiugtagmmqsxtvxaoniiogtagmbpsmtuvvihpstpdvcrxhokvhxotawswquunewcgxptlcrxtevtubvewcnwwsxfsnptswtagakvoyyak";
    
//     int keyLenth;
//     int NumOfAlpha[26];

//     for (keyLenth = 1; keyLenth < 10; keyLenth++)
//     {
//         cout << "The keyLenth is " << keyLenth << endl;
//         for (int i = 0; i < keyLenth; i++)
//         {
//             memset(NumOfAlpha, 0, sizeof(int)*26);
//             for (int j = i; j < Ciphertext.size(); j += keyLenth)
//             {
//                 NumOfAlpha[int(Ciphertext[j])-97] += 1;
//             }
//             cout << IC(NumOfAlpha, 1.0*Ciphertext.size()/keyLenth) << endl;
//         }
//     }

//     return 0;
// }

int main()
{
    char Ciphertext[200] = "ktbueluegvitnthuexmonveggmrcgxptlyhhjaogchoemqchpdnetxupbqntietiabpsmaoncnwvoutiugtagmmqsxtvxaoniiogtagmbpsmtuvvihpstpdvcrxhokvhxotawswquunewcgxptlcrxtevtubvewcnwwsxfsnptswtagakvoyyak";
    char Plaintext[200];
    char key[4];
    key[4] = '\0';
    for (key[0] = 'a'; key[0] <= 'z'; key[0]++)
    {
        for (key[1] = 'a'; key[1] <= 'z'; key[1]++)
        {
            for (key[2] = 'a'; key[2] <= 'z'; key[2]++)
            {
                Vigenere(Ciphertext, Plaintext, key, 3);
                char s[5] = "the";
                int num = find_string(Plaintext, s);
                if (num > 3)
                {
                    cout << "The key is " << key << endl;
                    cout << "The Plaintext is " << Plaintext << endl;
                    cout << "The num is " << num << endl;
                }
            }
        }
    }

    return 0;
}

double IC(int *Num, double total)
{
    double result = 0;
    for (int i = 0; i < 26; i++)
    {
        result += 1.0*Num[i]*Num[i]/total/total;
    }

    return result;
}

void Vigenere(char* Ciphertext, char* Plaintext, char* key, int keyLenth)
{
    int i;
    for (i = 0; i < strlen(Ciphertext); i++)
    {
        Plaintext[i] = char((int(Ciphertext[i]-97) - int(key[i%keyLenth]-97) + 26) % 26 + 97);
    }
    Plaintext[i] = '\0';
}

int find_string(char str[], char substr[])
{
    int count = 0,i,j,check;
    int len = strlen(str);
    int sublen = strlen(substr);
    for(i = 0; i < len; i++)
    {
        check = 1;
        for(j = 0; j + i < len && j < sublen; j++)
        {
            if(str[i+j] != substr[j])
            {
                check = 0;
                break;
            }
        }
        if(check == 1)
        {
            count++;
            i = i + sublen;
        }
    }

    return count;
}