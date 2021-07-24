#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 10000005
#define fi first
#define se second
#define ii pair<int, int>
const ll mod = 1e8 + 7;
using namespace std;
ll mu(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tam = mu(a, b / 2);
    tam = (tam * tam) % mod;
    if (b % 2 == 1)
        tam = (tam * a) % mod;
    return tam;
}
int n, t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n <= 2)
            cout << 1 << '\n';
        else if (n == 3)
            cout << 3 << '\n';
        else if (n % 2 == 0)
            cout << n * 2 << '\n';
        else
            cout << n * 4 << '\n';
    }
}
