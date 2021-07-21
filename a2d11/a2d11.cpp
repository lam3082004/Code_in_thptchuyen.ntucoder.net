#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 500005
using namespace std;
ll n, m, z = 0;
ll a[105][105], b[105][105], c[105][105];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a2d11.inp", "r", stdin);
    freopen("a2d11.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    fo(i, 1, n)
            fo(j, 1, m) cin >>
        a[i][j];
    fo(i, 1, n)
            fo(j, 1, m) cin >>
        b[i][j];
    fo(i, 1, n)
    {
        fo(j, 1, m)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    fo(i, 1, n)
    {
        fo(j, 1, m)
        {
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
}
