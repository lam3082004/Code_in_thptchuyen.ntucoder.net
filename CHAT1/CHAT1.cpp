#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (long long i = a; i <= b; i++)
#define nmax 1000005
#define fi first
#define se second
#define ii pair<int, int>
const ll mod = 1e9 + 7;
using namespace std;
ll n, t, x, a[nmax];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("CHAT1.inp", "r", stdin);
    freopen("CHAT1.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    fo(i, 1, n) a[i] = i * i + 1;
    cin >> t;
    while (t--)
    {
        cin >> x;
        ll l = 1, r = n, mid, pos;
        while (l <= r)
        {
            mid = l + r >> 1;
            if (a[mid] >= x)
            {
                pos = a[mid];
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        cout << pos << '\n';
    }
}
