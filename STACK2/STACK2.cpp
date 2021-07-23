#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 10000005
#define ii pair<ll, ll>
#define fi first
#define se second
const ll mod = 1e9 + 7;
using namespace std;
string s;
deque<int> s1;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    fo(i, 0, s.size() - 1)
    {
        if (s[i] == '(')
            s1.push_front(s[i]);
        if (s[i] == ')')
            if (s1.empty())
            {
                cout << "NO";
                return 0;
            }
            else
                s1.pop_front();
    }
    if (s1.empty())
        cout << "YES";
    else
        cout << "NO";
}
