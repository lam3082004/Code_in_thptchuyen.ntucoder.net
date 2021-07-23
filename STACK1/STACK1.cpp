#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 10000005
#define ii pair<ll, ll>
#define fi first
#define se second
const ll mod = 1e9 + 7;
using namespace std;
ll t, a, x;
stack<ll> s;
void a1()
{
    cin >> x;
    s.push(x);
}
void a2()
{
    if (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    else
        cout << -1 << endl;
}
void a3()
{
    if (!s.empty())
    {
        cout << s.top() << endl;
    }
    else
        cout << -1 << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> a;
        if (a == 1)
            a1();
        if (a == 2)
            a2();
        if (a == 3)
            a3();
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
