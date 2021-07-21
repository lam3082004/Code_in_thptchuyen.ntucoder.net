#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 1000005
#define ii pair<ll, ll>
#define fi first
#define se second
const ll mod = 1e9 + 7;
using namespace std;
ll a, b, n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("SO19.inp", "r", stdin);
    freopen("SO19.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n)
    {
        cin >> a >> b;
        cout << (b * (b + 1) / 2) * (b * (b + 1) / 2) - (a * (a + 1) / 2) * (a * (a + 1) / 2) + a * a * a << endl;
    }
}
