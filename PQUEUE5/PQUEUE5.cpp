#include <bits/stdc++.h>
#define l2 long long
using namespace std;
l2 n, k, x, b[1005];
struct ss
{
    bool operator()(l2 a, l2 b)
    {
        return a < b;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<l2, vector<l2>, ss> a;

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a.push(x);
        if (a.size() < k)
            cout << 0 << " ";
        else
        {
            for (int j = 1; j <= k; j++)
            {
                b[j] = a.top();
                a.pop();
            }
            cout << b[k] << " ";
            for (int j = 1; j <= k; j++)
            {
                a.push(b[j]);
            }
        }
    }
}
