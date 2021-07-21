#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 1000005
#define ii pair<ll, ll>
#define fi first
#define se second
const ll mod = 1e9 + 7;
using namespace std;
ll n, s = 0, dem = 0;
ll a[nmax], b[nmax];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("RANKING.inp", "r", stdin);
    freopen("RANKING.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1, greater<ll>());
    // fo(i, 1, n) cout << a[i] << '\n';
    // cout << endl;
    b[1] = 1;
    fo(i, 2, n)
    {
        if (a[i] == a[i - 1])
            b[i] = b[i - 1];
        else
            b[i] = b[i - 1] + 1;
    }
    // fo(i, 1, n) cout << b[i] << '\n';
    // cout << endl;
    fo(i, 1, n)
    {
        s += b[i];
    }
    cout << s;
}