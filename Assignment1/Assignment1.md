 

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


​    

<center>
    </font><font face="黑体" size="5">2020~2021春夏学期 2020 年 3 月 6 日</font>
</center>


---

## 1 Caesar

Ciphertext: FBUQIUUDSHOFJOEKHDQCUMYJXJXUIQCUAUOQDTKFBEQTJEBUQHDYDWYDPZK

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

Plaintext: PLEASEENCRYPTYOURNAMEWITHTHESAMEKEYANDUPLOADTOLEARNINGINZJU

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

Ciphertext: ktbueluegvitnthuexmonveggmrcgxptlyhhjaogchoemqchpdnetxupbqntietiabpsmaoncnwvoutiugtagmmqsxtvxaoniiogtagmbpsmtuvvihpstpdvcrxhokvhxotawswquunewcgxptlcrxtevtubvewcnwwsxfsnptswtagakvoyyak

```

```

Plaintext: itisessentialtoseekoutenemyagentswhohavecometoconductespionageagainstyouandtobribethemtoserveyougivetheminstructionsandcareforthemthusdoubledagentsarerecruitedandusedsuntzutheartofwar

“It is essential to seek out enemy agents who have come to conduct espionage against you and to bribe them to serve you give the minstructions and care for them thus doubled agents are recruited and used sun tzu the art of war”

---



## 3 Unknown

