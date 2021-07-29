#include <bits/stdc++.h>
#define nmax 100005
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
ll x[30], n, dem = 0;
bool nt(ll x)
{
    if (x <= 1)
        return false;
    fo(i, 2, sqrt(x)) if (x % i == 0) return false;
    return true;
}
void check()
{
    ll dem1 = 0, dem2 = 0;
    fo(i, 1, n)
    {
        if (x[i] == 0)
            dem1++;
        else
            dem2++;
    }
    if (nt(dem2))
    {
        if (nt(abs(dem2 - dem1)))
        {
            dem++;
        }
    }
}
void qlui(int k)
{
    fo(i, 0, 1)
    {
        x[k] = i;
        if (k == n)
        {
            check();
        }
        else
            qlui(k + 1);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    qlui(1);
    cout << dem;
}
