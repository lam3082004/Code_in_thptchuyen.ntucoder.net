#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 2000005
#define fi first
#define se second
using namespace std;
ll n, a[nmax], s = 0, t = 0;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    fo(i, 1, n)
    {
        if (a[i] > 0)
        {
            if (a[i - 1] > 0)
                t = (a[i], a[i - 1]) / 2,
                s += t,
                a[i] -= 2 * t;
            if (a[i + 1] > 0)
                t = (a[i] + a[i + 1]) / 2,
                s += t,
                a[i] -= 2 * t,
                a[i + 1] -= 2 * t;
            else
                s += a[i] / 2;
        }
    }
    cout << s;
}
