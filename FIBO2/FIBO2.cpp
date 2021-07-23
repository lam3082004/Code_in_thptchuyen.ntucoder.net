//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define matrix vector<vector<ll>>
const ll BASE = 1e9 + 7;
const ll mod = 2000000016;
int n;
ll ans = 0;
matrix m;
string s;
matrix operator*(const matrix &a, const matrix &b)
{
    matrix c = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % BASE) % BASE;
            }
        }
    }
    return c;
}
matrix power(matrix &a, ll n)
{
    if (n == 1)
        return a;
    matrix t = power(a, n / 2);
    t = t * t;
    if (n % 2)
        t = t * a;
    return t;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.size();
    for (int i = 1; i <= n; ++i)
    {
        ans = (10 * ans + (s[i - 1] - '0')) % mod;
    }
    if (ans == 0)
        cout << 0;
    else
    {
        m = {{0, 1}, {1, 1}};
        m = power(m, ans);
        cout << m[0][1];
    }
}
