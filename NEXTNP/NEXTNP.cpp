#include <bits/stdc++.h>
#define nmax 10000005
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
string s;
long long n, vi;
bool check = true;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("NEXTNP.inp", "r", stdin);
    freopen("NEXTNP.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> s;
    n = s.size();
    s = " " + s;
    for (int i = n; i >= 1 && check; --i)
    {
        if (s[i] == '0')
        {
            vi = i;
            s[i] = '1';
            check = false;
        }
    }
    for (int i = n; i > vi; --i)
    {
        s[i] = '0';
    }
    if (vi == 0)
    {
        cout << 1;
    }
    for (int i = 1; i <= n; ++i)
        cout << s[i];
}
