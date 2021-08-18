#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 10000005
#define ii pair<ll, ll>
#define fi first
#define se second
const ll mod = 1e9 + 7;
using namespace std;
deque<int> s;
int n, a[10000000], x, k = 0;
bool NT[nmax + 1];
void sang()
{
    memset(NT, true, sizeof(NT));
    NT[0] = false;
    NT[1] = false;
    for (int i = 2; i * i <= 10000000; i++)
    {
        if (NT[i])
        {
            for (int j = i * i; j <= 10000000; j += i)
                NT[j] = false;
        }
    }
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
    ;
    cin >> n;
    sang();
    fo(i, 1, n)
    {
        cin >> x;
        if (NT[x])
            a[++k] = x;
    }
    n = k;
    sort(a + 1, a + n + 1, greater<int>());
    fo(i, 1, n) if (i % 2 == 0) s.push_front(a[i]);
    else s.push_back(a[i]);
    if (s.empty())
        cout << -1;
    while (!s.empty())
    {
        cout << s.front() << " ";
        s.pop_front();
    }
}
