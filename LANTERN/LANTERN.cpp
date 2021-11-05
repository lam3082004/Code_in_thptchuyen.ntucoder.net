#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; ++i)
#define ii pair<ll, int>
#define fi first
#define se second
using namespace std;
const int nmax = 1e5 + 5;
int n, a[nmax], t = 0, k, s = 0, b[nmax];
bool check(int x)
{
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (a[i] + x - 1) / x;
    return ans <= k;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> n;
    fo(i, 1, n) cin >> a[i];
    ll l = 1, r = 1e9;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << r + 1;
}
