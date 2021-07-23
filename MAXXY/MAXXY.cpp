// Cho 3 số nguyên dương : a,b,c (a , b , c <= 1e16)

// Tìm nghiệm không âm của phương trình:

// a.x + b.y = c

// sao cho x+y  MAX

// không tìm được in ra "no solution"

// Ví dụ
// input:

// 2 3 5

// output:

// 2
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 1000005
#define ld long double
using namespace std;
ll a, b, c, d, k;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    cin >> a >> b >> c;
    d = gcd(a, b);
    if (a > b)
        swap(a, b);
    if (c % d != 0)
    {
        cout << "no solution";
        return 0;
    }
    a /= d, b /= d, c /= d;
    ll m = a, n = b, r, q, p;
    ll xm = 1, ym = 0;
    ll xn = 0, yn = 1;
    ll xr, yr;
    while (n != 0)
    {
        q = m / n;
        r = m % n;
        xr = xm - q * xn;
        yr = ym - q * yn;
        m = n;
        xm = xn;
        ym = yn;
        n = r;
        xn = xr;
        yn = yr;
    }
    p = b;
    q = a;
    ym = (((ym % q) * (c % q)) % q + q) % q;
    xm = (c - b * ym) / a;
    cout << xm + ym << '\n';
}
