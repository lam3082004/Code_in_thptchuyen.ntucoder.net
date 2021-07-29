#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 1000005
#define fi first
#define se second
#define ii pair<int, int>
const ll mod = 1e9 + 7;
using namespace std;
ll n, a[nmax], x[55], dem = 0, s = 0, p = 0;
void read()
{
    cin >> n;
    fo(i, 1, n)
    {
        cin >> a[i];
        p += a[i];
    }
}
bool nt(ll x)
{
    if (x <= 1)
        return false;
    fo(i, 2, sqrt(x)) if (x % i == 0) return false;
    return true;
}
void check()
{
    ll sum = 0;
    fo(i, 1, n)
    {
        if (x[i] == 0)
            sum += a[i];
    }
    if (nt(p - 2 * sum))
        dem++;
}
void np(int i)
{
    fo(j, 0, 1)
    {
        x[i] = j;
        if (i == n)
            check();
        else
            np(i + 1);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("SL2.inp", "r", stdin);
    freopen("SL2.out", "w", stdout);
#endif // ONLINE_JUDGE
    read();
    np(1);
    cout << dem;
}
