#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (long long i = a; i <= b; i++)
#define nmax 1000005
#define fi first
#define se second
#define ii pair<int, int>
const ll mod = 1e9 + 7;
using namespace std;
ll n, a[nmax], s = 0;
map<ll, ll> f;
ll b[nmax], z = 0;
ll C(ll k, ll n)
{
    if (k == 0 || k == n)
        return 1;
    if (k == 1)
        return n;
    return C(k - 1, n - 1) + C(k, n - 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("TGD.inp", "r", stdin);
    freopen("TGD.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    fo(i, 1, n)
    {
        if (a[i] > 0)
            f[a[i]]++;
    }
    fo(i, 1, n)
    {
        if (f[a[i]] != f[a[i + 1]])
            b[++z] = f[a[i]];
    }
    fo(i, 1, z)
    {
        if (b[i] >= 3)
            s += C(3, b[i]);
    }
    cout << s;
}
