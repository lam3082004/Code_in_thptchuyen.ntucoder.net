// Fibonacci

// {
// Yêu cầu: Cho , hãy tính

// và ( ) .

// Input
// - Dòng đầu là số nguyên T là số lượng bộ dữ liệu;
// - T dòng sau, mỗi dòng 3 số

// ;

// Output
// - Gồm T dòng, mỗi dòng 2 số là giá trị và tương ứng với dữ liệu vào.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 1000005
using namespace std;
ll t, a, b, m, p, q, k, f[nmax];
ll lt(ll a, ll b, ll c)
{
    if (b == 0)
        return 1;
    ll t = lt(a, b / 2, c);
    t = (t * t) % c;
    if (b % 2 == 1)
        t = (t * a) % c;
    return t;
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> m;
        f[1] = 1;
        f[2] = 1;
        fo(i, 3, m * m + 1)
            f[i] = (f[i - 1] + f[i - 2]) % m;
        fo(i, 3, m * m) if (f[i] == 1 && f[i + 1] == 1)
        {
            k = i - 1;
            break;
        }
        p = lt(a, b, k);
        q = __gcd(a, b) % k;
        cout << f[p] << ' ' << f[q] << '\n';
    }
}
