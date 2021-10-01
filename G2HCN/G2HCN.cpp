#include <bits/stdc++.h>
#define nmax 10000005
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
ll x[10], y[10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("G2HCN.inp", "r", stdin);
    freopen("G2HCN.out", "w", stdout);
#endif // ONLINE_JUDGE
    fo(i, 1, 4) cin >> x[i] >> y[i];
    if (x[1] >= x[4] || x[2] <= x[3] || y[1] <= y[4] || y[2] >= y[3])
        cout << 0;
    else
    {
        sort(x + 1, x + 5);
        sort(y + 1, y + 5);
        cout << (x[3] - x[2]) * (y[3] - y[2]);
    }
}
