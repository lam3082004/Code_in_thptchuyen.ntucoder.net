#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 500005
using namespace std;
ll mu(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tam = mu(a, b / 2);
    tam = tam * tam;
    if (b % 2 == 1)
        tam = (tam * a);
    return tam;
}
ll n, k, a[105], b[105], t[105], dem = 0;
long double s = 1;
ll qlui(ll x)
{
    fo(i, a[x - 1] + 1, n - x + k) if (b[i] == 0)
    {
        a[x] = i;
        b[i] = 1;
        if (x == k)
        {
            fo(j, 1, k)
                    cout
                << a[j] << ' ';
            cout << '\n';
        }
        else
            qlui(x + 1);
        b[i] = 0;
    }
}
void read()
{
    cin >> n >> k;
}
int main()
{
    // freopen("l.inp","r",stdin);
    // freopen("l.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    fo(i, n - k + 1, n)
        s = s * i / (i - n + k);
    cout << s << '\n';
    qlui(1);
}
