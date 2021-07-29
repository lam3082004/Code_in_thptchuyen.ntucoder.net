#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 1000005
const ll mod = 1e9 + 7;
using namespace std;
ll n, x[35];
void in()
{
    fo(i, 1, n)
            cout
        << x[i];
    cout << '\n';
}
void qlui(ll k)
{
    fo(j, 0, 1)
    {
        x[k] = j;
        if (k == n)
            in();
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
}