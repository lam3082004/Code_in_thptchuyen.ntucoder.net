#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
struct point
{
    ll x, y;
};
ll ok(point A, point B)
{
    point BA, AO;
    BA.x = A.x - B.x;
    BA.y = A.y - B.y;
    AO.x = -A.x;
    AO.y = -A.y;
    ll s = BA.x * AO.y - BA.y * AO.x;
    return s;
}
point p[1000005];
ll t, h, n, k, a[1000005];
long double kq;
string s;
int main()
{
    while (cin >> s)
    {
        t = 0, h = 0, k = 1, kq = 0;
        n = s.size();
        s = ' ' + s;
        p[1].x = 0, p[1].y = 0;
        fo(i, 1, n - 1)
        {
            if (s[i] == 'R')
                h++;
            else
                t++;
            if (s[i] != s[i + 1])
            {
                p[++k].x = h;
                p[k].y = t;
            }
        }
        a[1] = k;
        t = k;
        k = 1;
        while (t > 0)
        {
            h = t;
            while (ok(p[t], p[h]) <= 0 && t > 0)
                t--;
            a[++k] = t;
            h = t;
        }
        a[k] = 1;
        fo(i, 1, k - 1)
        {
            t = 0;
            fo(j, a[i + 1], a[i] - 1)
                t += p[j].x * p[j + 1].y - p[j].y * p[j + 1].x;
            t += p[a[i]].x * p[a[i + 1]].y - p[a[i]].y * p[a[i + 1]].x;
            kq += abs(t);
        }
        cout << fixed << setprecision(3) << kq / 2 << '\n';
    }
}
