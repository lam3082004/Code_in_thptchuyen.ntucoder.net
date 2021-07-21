#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (long long i = a; i <= b; i++)
#define nmax 1000005
#define fi first
#define se second
#define ii pair<int, int>
const ll mod = 1e9 + 7;
using namespace std;
ll x, dem = 0, n, a[nmax], z = 0, b[nmax];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("SN.inp", "r", stdin);
    freopen("SN.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    fo(i, 1, n)
    {
        if (a[i] != a[i + 1])
        {
            b[++z] = a[i];
        }
    }
    //fo(i, 1, z) cout << b[i] << ' ';
    ll s = 1, t = 1;
    while (t <= (z + 1))
    {
        if (b[t] == s)
        {
            t++;
            s++;
        }
        else
        {
            cout << s;
            return 0;
        }
    }
}
