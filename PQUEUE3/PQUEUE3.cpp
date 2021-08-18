#include <bits/stdc++.h>
#define l2 long long
using namespace std;
l2 n, d, p, k, t = 0;
struct hang
{
    l2 d, p;
};
struct ss
{
    bool operator()(hang a, hang b)
    {
        if (a.p < b.p)
            return true;
        else if (a.p == b.p)
        {
            if (a.d > b.d)
                return true;
        }
        return false;
    }
};
hang temp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<hang, vector<hang>, ss> a;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        if (k == 1)
        {
            cin >> d >> p;
            temp.d = d;
            temp.p = p;
            a.push(temp);
        }
        else
        {
            if (!a.empty())
            {
                t += a.top().p;
                a.pop();
            }
        }
    }

    cout << t;
}
