#include <bits/stdc++.h>
#define nmax 100005
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
string a, b;
ll dem = 0;
ll x[nmax], y[nmax];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("CSC.inp", "r", stdin);
    freopen("CSC.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> a >> b;
    fo(i, 0, a.size() - 1)
    {
        x[a[i] - '0']++;
    }
    fo(i, 0, b.size() - 1)
    {
        y[b[i] - '0']++;
    }
    fo(i, 0, 9)
    {
        if (x[i] > 0 && y[i] > 0)
        {
            cout << i << ' ';
            dem++;
        }
    }
    if (dem == 0)
        cout << "-1";
}
