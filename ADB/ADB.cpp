#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 10000007
const ll mod = 1e9 + 7;
using namespace std;
ll n, k, a[nmax], l;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("ADB.inp", "r", stdin);
    freopen("ADB.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n >> k;
    fo(i, 1, n) cin >> a[i];
    fo(i, 1, n)
        l = __gcd(l, a[i]);
    fo(i, 2, sqrt(l))
    {
        if (l % i == 0)
        {
            cout << k / i * i;
            return 0;
        }
    }
    cout << k / l * l;
}
