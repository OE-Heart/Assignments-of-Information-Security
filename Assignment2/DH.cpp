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

BigInt Int2BigInt(int x)
{
    BigInt d = new(struct bigint);
    int len = 0;
    while(x > 0)
    {
        d->digit[len++] = x%10;
        x /= 10;
    }
    d->len = len;

    return d;
}

int BigInt2Int(BigInt d)
{
    int x = 0;
    for (int i = d->len-1; i >= 0; i--)
    {
        x = x*10 + d->digit[i];
    }
    return x;
}

BigInt Copy(BigInt d)
{
    BigInt r = new(struct bigint);
    r->len = d->len;
    for (int i = 0; i < r->len; i++)
    {
        r->digit[i] = d->digit[i];
    }

    return r;
}

int Compare(BigInt a, BigInt b)
{
    if (a->len > b->len)
    {
        return 1;
    }
    else if (a->len < b->len)
    {
        return -1;
    }
    else
    {
        for (int i = a->len-1; i >= 0; i--)
        {
            if (a->digit[i] > b->digit[i])
            {
                return 1;
            }
            else if(a->digit[i] < b->digit[i])
            {
                return -1;
            }
        }
        return 0;
    }
}

BigInt ShiftRight(BigInt d, int n)
{
    BigInt r = new(struct bigint);
    r->len = d->len+n;
    for (int i = n; i < r->len; i++)
    {
        r->digit[i] = d->digit[i-n];
    }

    return r;
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
    BigInt c = new(struct bigint);
    int i, j;
    for (i = 0; i < b->len; i++)
    {
        int CF = 0;
        for (j = 0; j < a->len; j++)
        {
            int tmp = a->digit[j]*b->digit[i]+c->digit[i+j]+CF;
            c->digit[i+j] = tmp%10;
            if (i+j >= c->len) c->len++;
            CF = tmp/10;
        }
        if (CF)
        {
            c->digit[i+j] = CF;
            if (i+j >= c->len) c->len++;
        }
    }

    return c;
}

BigInt div(BigInt a, BigInt b)
{
    BigInt c = new(struct bigint);
    BigInt divisor;
    BigInt divident = Copy(a);
    c->len = a->len-b->len+1;
    for (int i = a->len-b->len; i >= 0; i--)
    {
        divisor = ShiftRight(b, i);
        while (Compare(divident, divisor) != -1)
        {
            c->digit[i]++;
            divident = sub(divident, divisor);
        }
    }

    return c;
}

BigInt mod(BigInt a, BigInt b)
{
    BigInt c = new(struct bigint);
    BigInt divisor;
    BigInt divident = Copy(a);
    c->len = a->len-b->len+1;
    for (int i = a->len-b->len; i >= 0; i--)
    {
        divisor = ShiftRight(b, i);
        while (Compare(divident, divisor) != -1)
        {
            c->digit[i]++;
            divident = sub(divident, divisor);
        }
    }

    BigInt round = mul(b, c);
    BigInt remainder = sub(a, round);

    return remainder;
}

int main()
{
    int p, g, a, b;
    cin >> p;
    cin >> g;
    cin >> a;
    cin >> b; 
    BigInt P = Int2BigInt(p);
    BigInt G = Int2BigInt(g);
    BigInt A = Int2BigInt(a);
    BigInt B = Int2BigInt(b);

    BigInt XA = mul(G, G);
    for (int i = 2; i < a; i++)
    {
        XA = mul(XA, G);
    }
    BigInt YA = mod(XA, P);
    
    BigInt XB = mul(G, G);
    for (int i = 2; i < b; i++)
    {
        XB = mul(XB, G);
    }
    BigInt YB = mod(XB, P);

    int ya = BigInt2Int(YA);
    cout << ya << endl;
    int yb = BigInt2Int(YB);
    cout << yb << endl;

    int xa = BigInt2Int(XA);
    int xb = BigInt2Int(XB);

    BigInt AK = mul(YA, YA);
    for (int i = 2; i < b; i++)
    {
        AK = mul(AK, YA);
    }
    BigInt K = mod(AK, P);
    int k = BigInt2Int(K);
    cout << k << endl;

    // BigInt BK = mul(YB, YB);
    // for (int i = 2; i < a; i++)
    // {
    //     BK = mul(BK, YB);
    // }
    // BigInt T = mod(BK, P);
    // int t = BigInt2Int(T);
    // cout << t << endl;

    return 0;
}