#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 200005
using namespace std;
ll n, m, z = 1e9;
ll a[nmax];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("absmin.inp", "r", stdin);
    freopen("absmin.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    fo(i, 1, n - 1)
    {
        z = min(z, abs(a[i] - a[i + 1]));
    }
    cout << z;
}
