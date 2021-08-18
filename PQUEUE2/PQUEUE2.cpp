#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
#define fi first
#define se second
const ll mod = 1e9 + 7;
using namespace std;
priority_queue<ll> c;
priority_queue<ll, vector<int>, greater<int>> d;
ll n, a[nmax];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("PQUEUE2.inp", "r", stdin);
    freopen("PQUEUE2.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    fo(i, 1, n)
    {
        cin >> a[i];
        c.push(a[i]);
        d.push(a[i]);
    }
    while (!d.empty())
    {
        cout << d.top() << ' ';
        d.pop();
    }
    cout << '\n';
    while (!c.empty())
    {
        cout << c.top() << ' ';
        c.pop();
    }
}
