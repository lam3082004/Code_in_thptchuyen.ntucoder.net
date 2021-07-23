// Cho dãy số A gồm N số nguyên. Tìm 5 chỉ số 1 ≤ i1 < i2 < ⋯ < i5 ≤ N sao cho:
// S = (ai1 − ai2 + ai3 − ai4 + ai5

// ) đạt giá trị lớn nhất, đếm số lượng cách chọn thỏa mãn.

// Input
// - Dòng đầu là số nguyên N (5 ≤ N ≤ 106
// )
// - Dòng thứ hai gồm N số nguyên a1, a2, ... , aN (|ai
// | < 109
// )

// Output
// - Gồm hai số S lớn nhất tìm được và C là số lượng bộ 5 chỉ số đều cho S lớn nhất.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 1000003
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e18
#define ar array
using namespace std;
const int mod = 1e9 + 7;
int n;
ll a[nmax], f[nmax][6];
string g[nmax][6];
string add(string a, string b)
{
    string res = "";
    while (a.size() < b.size())
        a = '0' + a;
    while (b.size() < a.size())
        b = '0' + b;
    int du = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        int tmp = a[i] - 48 + b[i] - 48 + du;
        du = tmp / 10;
        tmp = tmp % 10;
        res = (char)(tmp + 48) + res;
    }
    if (du > 0)
        res = '1' + res;
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n)
            cin >>
        a[i];
    memset(f, -0x3f, sizeof(f));
    fo(i, 0, n)
    {
        f[i][0] = 0;
        g[i][0] = "1";
    }
    fo(i, 0, n)
        fo(j, 1, 5)
            g[i][j] = "0";
    fo(i, 1, n)
        fo(j, 1, min(i, 5))
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] + (j & 1 ? 1 : -1) * a[i]);
    fo(i, 1, n)
        fo(j, 1, min(i, 5))
    {
        if (f[i][j] == f[i - 1][j])
            g[i][j] = g[i - 1][j];
        if (f[i][j] == f[i - 1][j - 1] + (j & 1 ? 1 : -1) * a[i])
            g[i][j] = add(g[i][j], g[i - 1][j - 1]);
    }
    cout << f[n][5] << ' ' << g[n][5];
}
