#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 1000005
#define fi first
#define se second
#define ii pair<int, int>
const ll mod = 1e9 + 7;
using namespace std;
int m, n, q, k = 0;
ll a[nmax], s[nmax], p[nmax], b[nmax];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("strongseq.inp", "r", stdin);
    freopen("strongseq.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n >> q;
    fo(i, 1, n)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        p[i] = p[i - 1] + a[i] * a[i];
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << ((s[y] - s[x - 1]) * (s[y] - s[x - 1]) - (p[y] - p[x - 1])) / 2 << '\n';
    }
}
