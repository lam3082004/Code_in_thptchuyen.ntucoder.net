// Cho hàm fx = c

// 2x−6 × fx−1 × fx−2 × fx−3 với x ≥ 4
// Yêu cầu: Cho n, f1, f2, f3 và c. Tính fn mod (109 + 7)
// Input:
//  Một dòng duy nhất gồm 5 số: n, f1, f2, f3 và c
//  4 ≤ n ≤ 1018

// , 1 ≤ f1, f2, f3, c ≤ 109

// Output:
//  Một dòng duy nhất là giá trị fn mod (109 + 7)
// Giới hạn:
//  Có 30% số test có n ≤ 100000
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; ++i)
#define fod(i, a, b) for (int i = a; i >= b; --i)
#define nmax 200005
#define nmax2 65000000
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e18
using namespace std;
const int mod = 1e9 + 6;
const int base = 1e9 + 7;
ll t, n, f1, f2, f3, c;
struct matrix
{
    ll x[15][15];
};
ll tich(ll a, ll b)
{
    a %= mod;
    b %= mod;
    ll q = (long double)a * b / mod;
    return ((a * b - q * mod) % mod + mod) % mod;
}
matrix nhan(matrix a, matrix b)
{
    matrix c;
    fo(i, 1, 5)
        fo(j, 1, 5)
    {
        c.x[i][j] = 0;
        fo(t, 1, 5)
            c.x[i][j] = (c.x[i][j] + tich(a.x[i][t], b.x[t][j])) % mod;
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
ll poww(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = poww(a, b / 2);
    t = (t * t) % base;
    if (b & 1)
        t = (t * a) % base;
    return t;
}
matrix A, B;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("new.inp", "r", stdin);
    freopen("new.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> f1 >> f2 >> f3 >> c;
    A.x[1][1] = 1;
    A.x[2][2] = 1;
    A.x[3][3] = 1;
    B.x[1][2] = 1;
    B.x[2][3] = 1;
    B.x[3][1] = 1;
    B.x[3][2] = 1;
    B.x[3][3] = 1;
    B = mu(B, n - 3);
    A = nhan(A, B);
    ll ans = 1;
    ans = (ans * poww(f1, A.x[3][1])) % base;
    ans = (ans * poww(f2, A.x[3][2])) % base;
    ans = (ans * poww(f3, A.x[3][3])) % base;
    fo(i, 1, 5)
        fo(j, 1, 5)
            A.x[i][j] = B.x[i][j] = 0;
    A.x[1][5] = 2;
    B.x[1][3] = 1;
    B.x[2][1] = 1;
    B.x[2][3] = 1;
    B.x[3][2] = 1;
    B.x[3][3] = 1;
    B.x[4][3] = 1;
    B.x[4][4] = 1;
    B.x[5][3] = 1;
    B.x[5][4] = 1;
    B.x[5][5] = 1;
    B = mu(B, n - 3);
    A = nhan(A, B);
    ans = (ans * poww(c, A.x[1][3])) % base;
    cout << ans;
}
