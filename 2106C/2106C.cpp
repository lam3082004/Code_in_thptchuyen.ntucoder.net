#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
using namespace std;
ll n, s = 0, s1 = 0, s2 = 0, k1 = 0, k2 = 0, k = 0;
ll a[nmax], b[nmax], c[nmax], dp[nmax][5];
ll maxx(ll x, ll y, ll z)
{
    ll max1 = max(max(x, y), z);
    if (z == max1)
        return 3;
    else if (x == max1)
        return 1;
    else
        return 2;
}
ll maxx1(ll m, ll n)
{
    if (m == max(m, n))
        return 1;
    else
        return 2;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("2106C.inp", "r", stdin);
    freopen("2106C.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    fo(i, 1, n)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[1][1] = a[1];
    dp[1][2] = b[1];
    dp[1][3] = c[1];
    for (int i = 2; i <= n; ++i)
    {
        dp[i][1] = max(dp[i - 1][2], dp[i - 1][3]) + a[i];
        dp[i][2] = max(dp[i - 1][3], dp[i - 1][1]) + b[i];
        dp[i][3] = max(dp[i - 1][1], dp[i - 1][2]) + c[i];
    }
    cout << max({dp[n][1], dp[n][2], dp[n][3]});
}
