#include <bits/stdc++.h>
using namespace std;

#define el cout << "\n"
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define maxn 100005
int n, a[maxn], b[maxn], f[2][maxn], ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    f1(i, n) cin >> a[i];
    a[0] = -1e9;
    f1(i, n)
    {
        if (a[i] > a[i - 1])
            f[0][i] = f[0][i - 1] + 1, f[1][i] = f[1][i - 1] + 1;
        else
            f[0][i] = 1, f[1][i] = 1;
        if (i > 1)
        {
            if (a[i] > a[i - 2] + 1)
                f[1][i] = max(f[1][i], f[0][i - 2] + 2);
        }
        ans = max(ans, f[1][i]);
        ans = max(ans, min(f[0][i] + 1, n));
        //cout << f[0][i] << ' ' << f[1][i], el;
    }
    cout << ans;
    return 0;
}
