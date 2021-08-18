#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, a, b) for (ll i = a; i <= b; i++)
#define ff(i, a, b) for (ll i = a; i >= b; i--)
ll b[1005];
int main()
{

    priority_queue<ll> qu;
    ll a;
    cin >> a;
    fo(i, 1, a)
    {
        ll b;
        cin >> b;
        if (b == 1)
        {
            cout << qu.size() << endl;
        }
        if (b == 2)
        {
            cout << (qu.empty() ? "YES" : "NO") << endl;
        }
        if (b == 3)
        {
            ll x;
            cin >> x;
            qu.push(x);
        }
        if (b == 4)
        {
            if (!qu.empty())
                qu.pop();
        }
        if (b == 5)
        {
            if (!qu.empty())
            {
                cout << qu.top() << endl;
            }
            else
                cout << -1 << endl;
        }
    }
}
