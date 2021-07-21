#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 200005
using namespace std;
ll n, m, z = 0;
ll a[nmax], min = 1e12;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("absmax.inp", "r", stdin);
    freopen("absmax.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    cout << max(abs(a[1] + a[2]), abs(a[n] + a[n - 1]));
}
