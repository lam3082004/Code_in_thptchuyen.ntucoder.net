#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; ++i)
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;
ll n, f[70];
string s[N];
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
#ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    s[1] = "1";
    s[2] = "1";
    fo(i, 3, 1000)
        s[i] = add(s[i - 1], s[i - 2]);
    while (cin >> n)
    {
        cout << s[n] << '\n';
    }
}