#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 10000005
#define ii pair<ll, ll>
#define fi first
#define se second
const ll mod = 1e9 + 7;
using namespace std;
ll n, s = 0, a[305][305], d[nmax], t = 0;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a2d10.inp", "r", stdin);
    freopen("a2d10.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n)
            fo(j, 1, n) cin >>
        a[i][j];
    fo(i, 1, n)
        fo(j, 1, n)
    {
        ll minn1 = min(i, j);
        ll minn2 = min(n - i + 1, n - j + 1);
        ll minn = min(minn1, minn2);
        d[minn] += a[i][j];
    }
    for (int i = n / 2; i >= 1; i--)
        cout << d[i] << ' ';
}