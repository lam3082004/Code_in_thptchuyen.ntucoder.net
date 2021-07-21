#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (long long i = a; i <= b; i++)
#define nmax 1000005
#define fi first
#define se second
#define ii pair<int, int>
const ll mod = 1e9 + 7;
using namespace std;
ll n, s = 0;
int a[nmax];
ll dp[nmax];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("REWARD.inp", "r", stdin);
    freopen("REWARD.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    dp[1] = a[1];
    dp[2] = max(max(0, a[1] + a[2]), max(a[1], a[2]));
    fo(i, 3, n)
    {
        dp[i] = dp[i - 1];
        dp[i] = max(dp[i], dp[i - 2] + a[i]);
        dp[i] = max(dp[i], dp[i - 3] + max(0, a[i - 1]) + a[i]);
    }
    cout << dp[n];
}