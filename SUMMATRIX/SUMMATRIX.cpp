#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 100005
using namespace std;
const int mod = 10;
struct matrix
{
    ll x[30][30];
};
ll m, n;
matrix nhan(matrix a, matrix b)
{
    matrix c;
    fo(i, 1, m)
        fo(j, 1, m)
    {
        c.x[i][j] = 0;
        fo(k, 1, m)
            c.x[i][j] = (((c.x[i][j] + a.x[i][k] * b.x[k][j]) % mod) + mod) % mod;
    }
    return c;
}
matrix tong(matrix a, matrix b)
{
    matrix c;
    fo(i, 1, m)
        fo(j, 1, m)
    {
        c.x[i][j] = 0;
        c.x[i][j] = (((c.x[i][j] + a.x[i][j] + b.x[i][j]) % mod) + mod) % mod;
    }
    return c;
}
matrix mu(matrix a, ll n)
{
    if (n == 1)
        return a;
    matrix t = mu(a, n / 2);
    t = nhan(t, t);
    if (n % 2 == 1)
        t = nhan(t, a);
    return t;
}
matrix kq(matrix a, ll n)
{
    if (n == 1)
        return a;
    matrix t = kq(a, n / 2);
    t = tong(t, nhan(mu(a, n / 2), t));
    if (n % 2 == 1)
        t = tong(t, mu(a, n));
    return t;
}
matrix A;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("SUMMATRIX.inp", "r", stdin);
    freopen("SUMMATRIX.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> m >> n;
    fo(i, 1, m)
            fo(j, 1, m) cin >>
        A.x[i][j];
    A = kq(A, n);
    fo(i, 1, m)
    {
        fo(j, 1, m) cout << A.x[i][j] % mod << ' ';
        cout << '\n';
    }
}
