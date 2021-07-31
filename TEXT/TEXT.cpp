#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
string a;
ll n, x = 0, m = 0, maxx = 0, t = 0;
bool ok(char a)
{
    return (a <= 'z' && a >= 'A');
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("TEXT.inp", "r", stdin);
    freopen("TEXT.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    fo(i, 1, 2) getline(cin, a);
    a = ' ' + a;
    fo(i, 1, n - 1)
    {
        if (a[i] == '(')
            x++;
        if (a[i] == ')')
            x--;
        if (x != 0)
        {
            if (ok(a[i]) && (a[i + 1] == ' ' || a[i + 1] == ')'))
                t++;
        }
        else
        {
            if (ok(a[i]))
                m++;
            else
            {
                maxx = max(maxx, m);
                m = 0;
            }
        }
    }
    cout << maxx << ' ' << t;
}
