#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (ll i = a; i <= b; i++)
#define nmax 100005
using namespace std;
const int gh = 1e6 + 6;
int n, a[gh], m;
bool check(int x)
{
    ll s = 0;
    fo(i, 1, n) if (a[i] > x)
        s += (a[i] - x);
    return s >= m;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("SAW.inp", "r", stdin);
    freopen("SAW.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    fo(i, 1, n)
            cin >>
        a[i];
    int dau = 1, cuoi = 1e9, ans = -1;
    while (dau <= cuoi)
    {
        int giua = (dau + cuoi) >> 1;
        if (check(giua))
        {
            ans = giua;
            dau = giua + 1;
        }
        else
            cuoi = giua - 1;
    }
    cout << ans;
}
