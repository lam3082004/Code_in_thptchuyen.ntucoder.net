#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (long long i = a; i <= b; i++)
const int mod = 1e9 + 7;
using namespace std;
struct matrix
{
    ll x[105][105];
};
ll n, m;
matrix tl(matrix a, matrix b)
{
    matrix c;
    fo(i, 1, m)
        fo(j, 1, m)
    {
        c.x[i][j] = 0;
        fo(t, 1, m)
            c.x[i][j] = (((c.x[i][j] + a.x[i][t] * b.x[t][j]) % mod) + mod) % mod;
    }
    return c;
}
matrix pw(matrix a, ll b)
{
    if (b == 1)
        return a;
    matrix t = pw(a, b / 2);
    t = tl(t, t);
    if (b % 2 == 1)
        t = tl(t, a);
    return t;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("MATRIXPW.inp", "r", stdin);
    freopen("MATRIXPW.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n >> m;
    matrix A;
    fo(i, 1, m)
            fo(j, 1, m) cin >>
        A.x[i][j];
    A = pw(A, n);
    fo(i, 1, m)
    {
        fo(j, 1, m)
                cout
            << A.x[i][j] << ' ';
        cout << endl;
    }
}
