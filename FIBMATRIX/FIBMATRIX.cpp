#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
using namespace std;
struct matrix
{
    ll x[5][5];
};
ll n, base;
matrix A, B;
ll tich(ll a, ll b)
{
    a %= base;
    b %= base;
    ll q = (long double)a * b / base;
    return ((a * b - q * base) % base + base) % base;
}
matrix nhan(matrix a, matrix b)
{
    matrix c;
    fo(i, 0, 1)
        fo(j, 0, 1)
    {
        c.x[i][j] = 0;
        fo(t, 0, 1)
            c.x[i][j] = (c.x[i][j] + tich(a.x[i][t], b.x[t][j]) + base) % base;
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
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("FIBMATRIX.inp", "r", stdin);
    freopen("FIBMATRIX.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n >> base;
    B.x[0][0] = 0;
    B.x[0][1] = 1;
    B.x[1][0] = 1;
    B.x[1][1] = 1;
    A = mu(B, n);
    cout << A.x[0][1] % base;
}
