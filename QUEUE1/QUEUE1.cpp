#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (ll i = a; i <= b; i++)
#define nmax 1005
using namespace std;
const ll mod = 1e9;
deque<int> q;
void lam1()
{
    int x;
    cin >> x;
    q.push_back(x);
}
void lam2()
{
    if (q.empty())
        cout << -1 << endl;
    else
        cout << q.front() << endl;
}
void lam3()
{
    if (q.empty())
        cout << -1 << endl;
    else
    {
        cout << q.front() << endl;
        q.pop_front();
    }
}
void lam4()
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop_front();
    }
}
ll n;
char ch;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //    freopen("l.inp","r",stdin);
    //      freopen("l.out","w",stdout);
    cin >> n;
    while (n--)
    {
        cin >> ch;
        if (ch == 'E')
            lam1();
        if (ch == 'G')
            lam2();
        if (ch == 'D')
            lam3();
    }
    lam4();
}
