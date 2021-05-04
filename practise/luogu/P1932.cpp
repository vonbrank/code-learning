#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10050;
class bigint
{
private:
    bool minus;
    int num[maxn];

public:
    bigint();
    void read();
    void print();

    bool operator<(const bigint &b) const;
    bool operator<=(const bigint &b) const;
    bool operator!=(const bigint &b) const;
    bool operator==(const bigint &b) const;
    bool operator>(const bigint &b) const;
    bool operator>=(const bigint &b) const;

    bigint operator+(const bigint &b) const;
    bigint operator-() const;
    bigint operator-(const bigint &b) const;

    bigint operator=(const int &b);
    bigint abs() const;
};

bigint::bigint()
{
    minus = false;
    memset(num, 0, sizeof(num));
    num[0] = 1;
}

void bigint::read()
{
    memset(num, 0, sizeof(num));
    char s[maxn];
    scanf("%1s", s + 1);
    if (s[1] == '-')
    {
        minus = true;
        scanf("%s", s + 1);
    }
    else
    {
        scanf("%s", s + 2);
    }
    num[0] = strlen(s + 1);
    for (int i = 1; i <= num[0]; i++)
    {
        num[i] = s[num[0] - i + 1] - '0';
    }
}

void bigint::print()
{
    if (minus)
        printf("-");
    for (int i = num[0]; i >= 1; i--)
    {
        printf("%d", num[i]);
    }
}

bool bigint::operator<(const bigint &b) const
{
    if (minus != b.minus)
        return minus > b.minus;
    if (num[0] != b.num[0])
        return num[0] < b.num[0];
    for (int i = num[0]; i >= 1; i--)
    {
        if (num[i] != b.num[i])
            return num[i] <= b.num[i];
    }
    return false;
}

bool bigint::operator<=(const bigint &b) const
{
    if (*this < b || *this == b)
        return true;
    else
        return false;
}

bool bigint::operator!=(const bigint &b) const
{
    if (*this < b || b < *this)
        return true;
    else
        return false;
}

bool bigint::operator==(const bigint &b) const
{
    if (minus != b.minus)
        return false;
    if (num[0] != b.num[0])
        return false;
    for (int i = num[0]; i >= 1; i--)
    {
        if (num[i] != b.num[i])
            return false;
    }
    return true;
}

bool bigint::operator>=(const bigint &b) const
{
    if (b < *this || b == *this)
        return true;
    else
        return false;
}

bool bigint::operator>(const bigint &b) const
{
    if (b < *this)
        return true;
    else
        return false;
}

bigint bigint::operator+(const bigint &b) const
{
    bigint c;
    c.num[0] = max(num[0], b.num[0]);
    for (int i = 1; i <= c.num[0]; i++)
    {
        c.num[i] += num[i] + b.num[i];
        c.num[i + 1] += c.num[i] / 10;
        c.num[i] %= 10;
    }
    if (c.num[c.num[0] + 1])
        c.num[0]++;
    return c;
}

bigint bigint::operator-() const
{
    bigint c = *this;
    c.minus ^= 1;
    return c;
}

bigint bigint::operator-(const bigint &b) const
{
    if (minus && !b.minus)
    {
        return -(abs() + b);
    }
    if (!minus && minus)
    {
        return *this + b.abs();
    }
}

bigint bigint::operator=(const int &b)
{
    int k = b, i = 0;
    while (k)
    {
        num[++num[0]] = k % 10;
        k /= 10;
    }
    return *this;
}

bigint bigint::abs() const
{
    bigint b, c = *this;
    if (c < b)
        c = (-c);
    return c;
}

int main()
{
    bigint a, b, c;
    char op[5];

    a.read();
    scanf("%s", op + 1);
    b.read();
    a.print();
    printf(" %s ", op + 1);
    b.print();
    printf(" = ");

    if (op[1] == '<')
    {
        if (op[1] == '<' && op[2] == '=')
        {
            if (a <= b)
                printf("true");
            else
                printf("false");
        }
        else
        {

            if (a < b)
                printf("true");
            else
                printf("false");
        }
    }

    if (op[1] == '!' && op[2] == '=')
    {
        if (a != b)
            printf("true");
        else
            printf("false");
    }
    if (op[1] == '=' && op[2] == '=')
    {
        if (a == b)
            printf("true");
        else
            printf("false");
    }
    if (op[1] == '>')
    {
        if (op[1] == '>' && op[2] == '=')
        {
            if (a >= b)
                printf("true");
            else
                printf("false");
        }
        else
        {

            if (a > b)
                printf("true");
            else
                printf("false");
        }
    }

    if (op[1] == '+')
        (a + b).print();

    // a.abs().print();
    return 0;
}