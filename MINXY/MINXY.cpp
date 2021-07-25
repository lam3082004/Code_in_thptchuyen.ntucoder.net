// Cho 3 số nguyên dương : a,b,c (a , b , c <= 1e16; c>0 )

// Tìm nghiệm không âm của phương trình:

// a.x + b.y = c

// sao cho x+y  MIN(x,y >=0)

// không tìm được in ra "no solution"

// Ví dụ
// input:

// 2 3 5

// output:

// 2
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
using namespace std;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll d = gcd(a, b);
    if (a > b)
        swap(a, b);
    if (c % d == 0)
    {
        a = a / d, b = b / d, c = c / d;
        ll m = a, n = b;
        ll xm = 1, ym = 0;
        ll xn = 0, yn = 1;
        ll xr, yr;
        ll q, r;
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

        ll p = b;
        q = a;
        xm = (((xm % p) * (c % p)) % p + p) % p;
        ym = (c - a * xm) / b;
        cout << xm + ym;
    }
    else
        cout << "no solution";
}
