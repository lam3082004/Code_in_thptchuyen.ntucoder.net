#include <bits/stdc++.h>
#define nmax 100005
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
string s;
ll n, l[nmax], r[nmax], z = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("COW.inp", "r", stdin);
    freopen("COW.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    cin >> s;
    l[-1] = 0;
    r[n] = 0;
    fo(i, 0, s.size() - 1)
    {
        if (s[i] == 'C')
            l[i] = l[i - 1] + 1;
        else
            l[i] = l[i - 1];
    }
    for (int i = s.size() - 1; i >= 1; i--)
    {
        if (s[i] == 'W')
            r[i] = r[i + 1] + 1;
        else
            r[i] = r[i + 1];
    }
    fo(i, 1, n)
    {
        if (s[i] == 'O')
        {
            z += l[i - 1] * r[i + 1];
        }
    }
    cout << z;
}
