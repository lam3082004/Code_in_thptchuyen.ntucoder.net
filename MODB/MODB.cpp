// Cho ba số nguyên dương M, B, P với P là một số nguyên tố. In ra "YES" nếu tồn tại số nguyên
// dương A thỏa mãn: M ≡ AB (mod P), ngược lại in ra "NO".
// Dữ liệu
// • Gồm một dòng duy nhất chứa ba số nguyên dương M, B, P (M, B, P ≤ 109 + 10).
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; ++i)
#define fod(i, a, b) for (int i = a; i >= b; --i)
#define nmax 1000005
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e18
using namespace std;
const int mod = 1e9 + 7;
int m, b, p;
map<int, int> f;
ll mu(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = mu(a, b / 2);
    t = (t * t) % p;
    if (b & 1)
        t = (t * a) % p;
    return t;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("new.inp", "r", stdin);
    freopen("new.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> b >> p;
    int x = 0;
    fo(i, 2, 100) if (__gcd(i, p) == 1)
    {
        bool ok = 1;
        fo(j, 1, sqrt(p - 1)) if ((p - 1) % j == 0)
        {
            if (mu(i, j) == 1)
                ok = 0;
            if (j > 1 && mu(i, (p - 1) / j) == 1)
                ok = 0;
        }
        if (ok)
        {
            x = i;
            break;
        }
    }
    x = mu(x, b);
    int k = sqrt(p);
    fo(q, 0, k)
    {
        int res = mu(x, k * q);
        if (!f[res])
            f[res] = 1;
    }
    fo(r, 0, k - 1)
    {
        int res = mu(mu(x, r), p - 2);
        res = (1LL * res * m) % p;
        if (f[res])
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
