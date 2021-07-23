#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (ll i = a; i <= b; i++)
#define nmax 1005
using namespace std;
const ll mod = 1e9;
string s;
stack<char> y;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //    freopen("l.inp","r",stdin);
    //      freopen("l.out","w",stdout);
    cin >> s;
    fo(i, 0, s.size() - 1)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            y.push(s[i]);
        if (s[i] == ')')
            if (y.empty())
            {
                cout << "NO";
                return 0;
            }
            else if (y.top() == '(')
                y.pop();
            else
            {
                cout << "NO";
                return 0;
            }
        if (s[i] == '}')
            if (y.empty())
            {
                cout << "NO";
                return 0;
            }
            else if (y.top() == '{')
                y.pop();
            else
            {
                cout << "NO";
                return 0;
            }
        if (s[i] == ']')
            if (y.empty())
            {
                cout << "NO";
                return 0;
            }
            else if (y.top() == '[')
                y.pop();
            else
            {
                cout << "NO";
                return 0;
            }
    }
    if (y.empty())
        cout << "YES";
    else
        cout << "NO";
}
