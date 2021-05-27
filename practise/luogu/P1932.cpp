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
    bigint(const int &n);
    operator int() const;
    void read();
    void print() const;

    bool operator<(const bigint &x) const;
    bool operator<=(const bigint &x) const;
    bool operator!=(const bigint &x) const;
    bool operator==(const bigint &x) const;
    bool operator>(const bigint &x) const;
    bool operator>=(const bigint &x) const;

    bigint operator+(const bigint &x) const;
    bigint operator-() const;
    bigint operator-(const bigint &x) const;
    bigint operator*(const bigint &x) const;
    bigint operator/(const bigint &x) const;
    bigint operator%(const bigint &x) const;
    bigint operator=(const int &x);
    // bigint(const int &x);
    bigint abs() const;
};

bigint::bigint()
{
    minus = false;
    memset(num, 0, sizeof(num));
    num[0] = 1;
}

bigint::bigint(const int &n)
{
    int tmp = n;
    minus = tmp < 0;
    memset(num, 0, sizeof(num));
    while (tmp > 0)
    {
        num[++num[0]] = tmp % 10;
        tmp /= 10;
    }
    if (num[0] == 0)
        num[0] = 1;
}

bigint::operator int() const
{
    int n = 0;
    for (int i = num[0]; i >= 1; i--)
    {
        n *= 10;
        n += num[i];
    }
    return n;
}

void bigint::read()
{
    memset(num, 0, sizeof(num));
    char s[maxn];
    scanf("%s", s + 1);
    if (s[1] == '-')
    {
        minus = true;
        num[0] = strlen(s + 2);
        for (int i = 1; i <= num[0]; i++)
        {
            num[i] = s[num[0] - i + 2] - '0';
        }
    }
    else
    {
        num[0] = strlen(s + 1);
        for (int i = 1; i <= num[0]; i++)
        {
            num[i] = s[num[0] - i + 1] - '0';
        }
    }
}

void bigint::print() const
{
    if (minus)
        printf("-");
    for (int i = num[0]; i >= 1; i--)
    {
        // printf("$");
        printf("%d", num[i]);
    }
}

bool bigint::operator<(const bigint &x) const
{
    if (minus != x.minus)
        return minus > x.minus;
    if (num[0] != x.num[0])
        return num[0] < x.num[0];
    for (int i = num[0]; i >= 1; i--)
    {
        if (num[i] != x.num[i])
            return num[i] <= x.num[i];
    }
    return false;
}

bool bigint::operator<=(const bigint &x) const
{
    if (*this < x || *this == x)
        return true;
    else
        return false;
}

bool bigint::operator!=(const bigint &x) const
{
    if (*this < x || x < *this)
        return true;
    else
        return false;
}

bool bigint::operator==(const bigint &x) const
{
    if (minus != x.minus)
        return false;
    if (num[0] != x.num[0])
        return false;
    for (int i = num[0]; i >= 1; i--)
    {
        if (num[i] != x.num[i])
            return false;
    }
    return true;
}

bool bigint::operator>=(const bigint &x) const
{
    if (x < *this || x == *this)
        return true;
    else
        return false;
}

bool bigint::operator>(const bigint &x) const
{
    if (x < *this)
        return true;
    else
        return false;
}

bigint bigint::operator+(const bigint &x) const
{

    if ((*this) == bigint(0))
        return x;
    if (x == bigint(0))
        return *this;

    if (*this < bigint(0) && x > bigint(0))
        return x - (*this).abs();
    if (*this < bigint(0) && x < bigint(0))
        return -((*this).abs() + x.abs());
    if (*this > bigint(0) && x < bigint(0))
        return (*this) - x.abs();

    bigint a = *this, b = x, c;
    c.num[0] = max(a.num[0], b.num[0]);
    for (int i = 1; i <= c.num[0]; i++)
    {
        c.num[i] += a.num[i] + b.num[i];
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

bigint bigint::operator-(const bigint &x) const
{

    // this->print();
    // printf(" - ");
    // x.print();
    // printf(" = ");
    // puts("");
    bigint a = *this, b = x, c;
    if (a == bigint(0))
        return -b;
    if (b == bigint(0))
        return a;

    if (a < bigint(0) && b > bigint(0))
        return -(-a + b);
    if (a < bigint(0) && b < bigint(0))
        return (-b) - (-a);
    if (a > bigint(0) && b < bigint(0))
        return a + (-b);

    if (a < b)
    {
        c.minus ^= 1;
        swap(a, b);
    }

    c.num[0] = a.num[0];
    for (int i = 1; i <= c.num[0]; i++)
    {
        c.num[i] = a.num[i] - b.num[i];
    }
    for (int i = 1; i <= c.num[0]; i++)
    {
        if (c.num[i] < 0)
        {
            c.num[i + 1] -= 1;
            c.num[i] += 10;
        }
    }
    while (!c.num[c.num[0]])
    {
        if (c.num[0] == 1)
            break;
        c.num[0]--;
    }

    // c.print();
    // puts("");
    return c;
}

bigint bigint::operator*(const bigint &x) const
{
    bigint a = *this, b = x, c;
    if (a.abs() < b.abs())
        swap(a, b);
    c.minus = a.minus ^ b.minus;
    c.num[0] = a.num[0] + b.num[0];
    for (int j = 1; j <= b.num[0]; j++)
    {
        for (int i = 1; i <= a.num[0]; i++)
        {
            c.num[i + j - 1] += a.num[i] * b.num[j];
            c.num[i + j] += c.num[i + j - 1] / 10;
            c.num[i + j - 1] %= 10;
        }
    }
    while (!c.num[c.num[0]])
    {
        if (c.num[0] == 1)
        {
            c = bigint(0);
            break;
        }
        c.num[0]--;
    }
    return c;
}

bigint bigint::operator/(const bigint &x) const
{
    bigint a = *this, b = x, c, tmp, cnt;
    bool flag = a.minus ^ b.minus;
    // c.minus = ;
    a = a.abs();
    b = b.abs();
    tmp.num[0] = a.num[0];
    tmp.num[tmp.num[0]] = 1;
    while (a > b)
    {
        cnt = bigint(0);
        while (b * tmp * (cnt + bigint(1)) <= a)
            cnt = cnt + bigint(1);
        c = c + tmp * cnt;
        a = a - b * tmp * cnt;
        tmp.num[tmp.num[0]] = 0;
        tmp.num[0]--;
        tmp.num[tmp.num[0]] = 1;
    }
    if (!(c.num[0] == 1 && c.num[1] == 0))
        c.minus = flag;
    return c;
}

bigint bigint::operator%(const bigint &x) const
{
    // (*this / b).print();
    // puts("");
    bigint a = *this, b = x;
    return a - a / b * b;
}

bigint bigint::operator=(const int &x)
{
    int k = x, i = 0;
    while (k)
    {
        num[++num[0]] = k % 10;
        k /= 10;
    }
    return *this;
}

// bigint::operator bigint()
// {
// }

bigint bigint::abs() const
{
    bigint c = *this;
    if (c < bigint(0))
        c = (-c);
    return c;
}

int main()
{
    bigint a, b;
    a.read();
    b.read();

    (a + b).print();
    puts("");
    (a - b).print();
    puts("");
    (a * b).print();
    puts("");
    (a / b).print();
    puts("");
    // (a / b * b).print();
    // puts("");
    (a % b).print();
    puts("");

    // ((a - bigint(80) * b)).print();
}