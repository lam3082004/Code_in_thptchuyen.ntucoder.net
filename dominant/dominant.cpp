#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ii pair<int, int>
#define fi first
#define se second
#define nmax 300005
using namespace std;
int f[nmax], S[nmax], n, t;
string s;
ii b[nmax];
int main()
{
    cin >> t >> s;
    n = s.size();
    s = " " + s;
    S[0] = 0;
    fo(i, 1, n) S[i] = S[i - 1] + (s[i] == '1' ? 1 : -1);
    fo(i, 0, n) b[i] = ii(S[i], i);
    sort(b + 0, b + n + 1);
    f[0] = b[0].se;
    fo(i, 1, n) f[i] = min(f[i - 1], b[i].se);
    int j = 0, ans = 0;
    fo(i, 0, n)
    {
        while (b[j + 1].fi < b[i].fi)
            j++;
        if (b[j].fi < b[i].fi)
            ans = max(ans, b[i].se - f[j]);
    }
    if (t == 1)
        cout << ans;
    else
    {
        int k = 0;
        fo(i, ans, n) k += (S[i] - S[i - ans] > 0);
        cout << k;
    }
}
