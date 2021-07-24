#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 10000005
#define ii pair<ll, ll>
#define fi fisnt
#define se second
#define oo 1e18
using namespace std;
const int mod = 1e9 + 7;
ll n, a, b;
bool nt[nmax];
void sang()
{
    memset(nt, 1, sizeof(nt));
    nt[1] = nt[0] = 0;
    fo(i, 2, sqrt(nmax)) if (nt[i])
    {
        for (int j = i * i; j <= nmax; j += i)
            nt[j] = 0;
    }
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
    cin >> a >> b;
    sang();
    ll ans = 0;
    fo(i, a, b) if (nt[i])
        ans++;
    cout << ans;
}
