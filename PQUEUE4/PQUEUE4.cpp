#include <bits/stdc++.h>
#define l2 long long
using namespace std;
l2 n, d, p, k, t = 0;
struct ss
{
    bool operator()(l2 a, l2 b)
    {
        return a > b;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<l2, vector<l2>, ss> a;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        a.push(k);
    }

    while (a.size() != 1)
    {
        d = a.top();
        a.pop();
        p = a.top();
        a.pop();
        t += d + p;
        a.push(d + p);
    }
    cout << t;
}
