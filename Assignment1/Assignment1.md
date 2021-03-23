 

<img src="picture/1.png" alt="1" style="zoom:80%;" />



<center><font face="Time News Roman" size="18">Password Cracking</font>


<img src="picture/2.png" alt="2" style="zoom:90%;" />

<center>
    <font face="楷体" size="5">姓名：欧翌昕</font>
</center>

<center>
    <font face="楷体" size="5">专业：软件工程</font>
</center>

<center>
    <font face="楷体" size="5">学号：3190104783</font>
</center>

<center>
    <font face="楷体" size="5">课程名称：信息安全原理</font>
</center>

<center>
    <font face="楷体" size="5">指导老师：胡天磊</font>
</center>


<center>
    </font><font face="黑体" size="5">2020~2021春夏学期 2020 年 3 月 23 日</font>
</center>
---

## 1 Caesar

### Ciphertext

FBUQIUUDSHOFJOEKHDQCUMYJXJXUIQCUAUOQDTKFBEQTJEBUQHDYDWYDPZK

### Cryptanalysis Process

First use the coincidence index method to guess the length of the key as 3. Then traverse all strings of length 3 and use it as a key to decrypt the ciphertext. Filter the decrypted plaintext, for example, filter out the results where the string "the" appears four times or more, and print out the key and the corresponding plaintext to see if it has normal semantics.

```c++
#include <iostream>
using namespace std;

int main()
{
    string Ciphertext;
    cin >> Ciphertext;
    char Plaintext[100];

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
```

The output is:

```out
1: GCVRJVVETIPGKPFLIERDVNZKYKYVJRDVBVPREULGCFRUKFCVRIEZEXZEQAL
2: HDWSKWWFUJQHLQGMJFSEWOALZLZWKSEWCWQSFVMHDGSVLGDWSJFAFYAFRBM
3: IEXTLXXGVKRIMRHNKGTFXPBMAMAXLTFXDXRTGWNIEHTWMHEXTKGBGZBGSCN
4: JFYUMYYHWLSJNSIOLHUGYQCNBNBYMUGYEYSUHXOJFIUXNIFYULHCHACHTDO
5: KGZVNZZIXMTKOTJPMIVHZRDOCOCZNVHZFZTVIYPKGJVYOJGZVMIDIBDIUEP
6: LHAWOAAJYNULPUKQNJWIASEPDPDAOWIAGAUWJZQLHKWZPKHAWNJEJCEJVFQ
7: MIBXPBBKZOVMQVLROKXJBTFQEQEBPXJBHBVXKARMILXAQLIBXOKFKDFKWGR
8: NJCYQCCLAPWNRWMSPLYKCUGRFRFCQYKCICWYLBSNJMYBRMJCYPLGLEGLXHS
9: OKDZRDDMBQXOSXNTQMZLDVHSGSGDRZLDJDXZMCTOKNZCSNKDZQMHMFHMYIT
10: PLEASEENCRYPTYOURNAMEWITHTHESAMEKEYANDUPLOADTOLEARNINGINZJU
11: QMFBTFFODSZQUZPVSOBNFXJUIUIFTBNFLFZBOEVQMPBEUPMFBSOJOHJOAKV
12: RNGCUGGPETARVAQWTPCOGYKVJVJGUCOGMGACPFWRNQCFVQNGCTPKPIKPBLW
13: SOHDVHHQFUBSWBRXUQDPHZLWKWKHVDPHNHBDQGXSORDGWROHDUQLQJLQCMX
14: TPIEWIIRGVCTXCSYVREQIAMXLXLIWEQIOICERHYTPSEHXSPIEVRMRKMRDNY
15: UQJFXJJSHWDUYDTZWSFRJBNYMYMJXFRJPJDFSIZUQTFIYTQJFWSNSLNSEOZ
16: VRKGYKKTIXEVZEUAXTGSKCOZNZNKYGSKQKEGTJAVRUGJZURKGXTOTMOTFPA
17: WSLHZLLUJYFWAFVBYUHTLDPAOAOLZHTLRLFHUKBWSVHKAVSLHYUPUNPUGQB
18: XTMIAMMVKZGXBGWCZVIUMEQBPBPMAIUMSMGIVLCXTWILBWTMIZVQVOQVHRC
19: YUNJBNNWLAHYCHXDAWJVNFRCQCQNBJVNTNHJWMDYUXJMCXUNJAWRWPRWISD
20: ZVOKCOOXMBIZDIYEBXKWOGSDRDROCKWOUOIKXNEZVYKNDYVOKBXSXQSXJTE
21: AWPLDPPYNCJAEJZFCYLXPHTESESPDLXPVPJLYOFAWZLOEZWPLCYTYRTYKUF
22: BXQMEQQZODKBFKAGDZMYQIUFTFTQEMYQWQKMZPGBXAMPFAXQMDZUZSUZLVG
23: CYRNFRRAPELCGLBHEANZRJVGUGURFNZRXRLNAQHCYBNQGBYRNEAVATVAMWH
24: DZSOGSSBQFMDHMCIFBOASKWHVHVSGOASYSMOBRIDZCORHCZSOFBWBUWBNXI
25: EATPHTTCRGNEINDJGCPBTLXIWIWTHPBTZTNPCSJEADPSIDATPGCXCVXCOYJ
```

### Plaintext

PLEASEENCRYPTYOURNAMEWITHTHESAMEKEYANDUPLOADTOLEARNINGINZJU

“Please encryt your name with the same key and upload to Learing in ZJU”

The key is 10.

```c++
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
```

Plaintext: OUYIXIN

Ciphertext: EKOYNYD

---



## 2 Vigenère

### Ciphertext

ktbueluegvitnthuexmonveggmrcgxptlyhhjaogchoemqchpdnetxupbqntietiabpsmaoncnwvoutiugtagmmqsxtvxaoniiogtagmbpsmtuvvihpstpdvcrxhokvhxotawswquunewcgxptlcrxtevtubvewcnwwsxfsnptswtagakvoyyak

### Cryptanalysis Process

```c++
#include <iostream>
#include <cstring>
using namespace std;

double IC(int *Num, double total);
void Vigenere(char* Ciphertext, char* Plaintext, char* key, int keyLenth);
int find_string(char str[], char substr[]);

int main()
{
    char Ciphertext[200] = "ktbueluegvitnthuexmonveggmrcgxptlyhhjaogchoemqchpdnetxupbqntietiabpsmaoncnwvoutiugtagmmqsxtvxaoniiogtagmbpsmtuvvihpstpdvcrxhokvhxotawswquunewcgxptlcrxtevtubvewcnwwsxfsnptswtagakvoyyak";

    int keyLenth;
    int NumOfAlpha[26];

    for (keyLenth = 1; keyLenth < 10; keyLenth++)
    {
        cout << "The keyLenth is " << keyLenth << endl;
        for (int i = 0; i < keyLenth; i++)
        {
            memset(NumOfAlpha, 0, sizeof(int)*26);
            for (int j = i; j < strlen(Ciphertext); j += keyLenth)
            {
                NumOfAlpha[int(Ciphertext[j])-97] += 1;
            }
            cout << IC(NumOfAlpha, 1.0*strlen(Ciphertext)/keyLenth) << endl;
        }
    }

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
```

### Plaintext

itisessentialtoseekoutenemyagentswhohavecometoconductespionageagainstyouandtobribethemtoserveyougivetheminstructionsandcareforthemthusdoubledagentsarerecruitedandusedsuntzutheartofwar

“It is essential to seek out enemy agents who have come to conduct espionage against you and to bribe them to serve you give the minstructions and care for them thus doubled agents are recruited and used sun tzu the art of war”

---



## 3 Unknown

### Ciphertext

MAL TIRRUEZF CR MAL RKZYIOL EX MAL OIY UAE RICF “MAL ACWALRM DYEUPLFWL CR ME DYEU MAIM UL IZL RKZZEKYFLF GH OHRMLZH”

### Cryptanalysis Process

It is observed that the frequency of "MAL" in the ciphertext is higher. It is guessed that the "MAL" in the ciphertext corresponds to the "the" in the plaintext. On this basis, it is guessed while replacing, and the ciphertext is decrypted synchronously according to the mapping relationship that has been guessed. Finally, a complete mapping relationship is obtained.

```c++
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
```

### Plaintext

the password is the surname of the man who said "the highest knowledge is to know that we are surrounded by mystery"

