#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 10000005
#define ii pair<ll, ll>
#define fi first
#define se second
const ll mod = 1e9 + 7;
using namespace std;
vector<vector<ll>> a(100005);
ll n, m, q, x, y, u, v, dem = 0;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    fo(i, 1, m)
    {
        a[i].push_back(0);
        fo(j, 1, n)
        {
            long long x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    cin >> q;
    fo(i, 1, q)
    {
        cin >> x >> y >> u >> v;
        dem = 0;
        for (int i = x; i <= u; i++)
            for (int j = y; j <= v; j++)
                dem = dem + a[i][j];
        cout << dem << endl;
    }
}
