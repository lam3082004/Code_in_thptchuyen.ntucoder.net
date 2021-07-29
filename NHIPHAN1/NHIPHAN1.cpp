#include <bits/stdc++.h>
#define nmax 100005
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
ll x[30], n, d = 0;
void check()
{

    fo(i, 1, n) cout << x[i];
    cout << '\n';
}
void qlui(int k)
{
    fo(i, 0, 1)
    {
        x[k] = i;
        if (k == n)
        {
            ll dem = 0;
            fo(j, 2, n) if (x[j - 1] == 0 && x[j] == 1) dem++;
            if (dem < 1)
            {
                check();
            }
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
}