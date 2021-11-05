#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define task "divisors"
using namespace std;
const int maxn = 1e4;
ll g[maxn + 5], n, k, d[maxn + 5];
///----------------------------------------------
void pt()
{
    for (int i = 2; i <= maxn; ++i)
        if (g[i] == 0)
            for (int j = i; j <= maxn; j += i)
                g[j] = i;
}
///----------------------------------------------
ll pw(ll x, ll y)
{
    ll t;
    if (y == 0)
        return 1;
    t = pw(x, y / 2);
    t = t * t;
    if (y % 2 == 1)
        t = t * x;
    return t;
}
///----------------------------------------------
void read()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
#endif // ONLINE_JUDGE
}
///----------------------------------------------
void solve()
{
    pt();
    while (cin >> n >> k)
    {
        ll res = 1;
        memset(d, 0, sizeof(d));
        fo(i, n - k + 1, n)
        {
            ll x = i;
            while (x > 1)
            {
                d[g[x]]++;
                x /= g[x];
            }
        }
        fo(i, 1, k)
        {
            ll x = i;
            while (x > 1)
            {
                d[g[x]]--;
                x /= g[x];
            }
        }
        fo(i, 1, n) res = res * (d[i] + 1);
        cout << res << '\n';
    }
}
///----------------------------------------------
int main()
{
    read();
    solve();
}
