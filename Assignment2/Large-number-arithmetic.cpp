#include <iostream>
#include <cstring>
using namespace std;

#define MAX 10000

typedef struct bigint* BigInt;
struct bigint{
    int len;
    int digit[MAX];
    bigint(){
        len = 0;
		memset(digit, 0, MAX*sizeof(int));
	}
};

BigInt String2BigInt(char* s)
{
    BigInt d = new(struct bigint);
    d->len = strlen(s);
    for (int i = 0; i < d->len; i++)
    {
        d->digit[i] = s[d->len-i-1]-'0';
    }

    return d;
}

void BigInt2String(BigInt d, char *s)
{
    for (int i = 0; i < d->len; i++)
    {
        s[d->len-i-1] = d->digit[i]+'0';
    }
    s[d->len] = '\0';
}

BigInt add(BigInt a, BigInt b)
{
    BigInt c = new(struct bigint);
    int CF = 0;
    for (int i = 0; i < a->len || i < b->len; i++)
    {
        int tmp = a->digit[i]+b->digit[i]+CF;
        c->digit[c->len++] = tmp%10;
        CF = tmp/10;
    }
    if (CF)
    {
        c->digit[c->len++] = CF;
    }
    
    return c;
}

BigInt sub(BigInt a, BigInt b)
{
    BigInt c = new(struct bigint);
    for (int i = 0; i < a->len || i < b->len; i++)
    {
        while (a->digit[i] < b->digit[i])
        {
            a->digit[i+1]--;
            a->digit[i] += 10;
        }
        c->digit[c->len++] = a->digit[i]-b->digit[i];
    }

    while (c->len >= 2 && c->digit[c->len-1] == 0)
    {
        c->len--;
    }
    
    return c;
}

BigInt mul(BigInt a, BigInt b)
{
    BigInt c;


    return c;
}

BigInt div(BigInt a, BigInt b)
{
    BigInt c;


    return c;
}

BigInt mod(BigInt a, BigInt b)
{
    BigInt c;


    return c;
}

int main()
{
    char a[MAX], b[MAX];
    cin >> a;
    cin >> b;

    BigInt A = String2BigInt(a);
    BigInt B = String2BigInt(b);
    BigInt C;
    char c[MAX];

    C = add(A, B);
    BigInt2String(C, c);
    cout << c << endl;

    C = sub(A, B);
    BigInt2String(C, c);
    cout << c << endl;

    // C = mul(A, B);
    // BigInt2String(C, c);
    // cout << c << endl;

    // C = div(A, B);
    // BigInt2String(C, c);
    // cout << c << endl;

    // C = mod(A, B);
    // BigInt2String(C, c);
    // cout << c << endl;

    return 0;
}