#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define fn(i, a, b) for (int i = a; i >= b; i ==)
#define maxn 1000005
using namespace std;
int k, mod;
long long a[maxn], n;
bool pr[maxn];
void readf()
{
    cin >> k >> n >> mod;
}
void sieve()
{
    memset(pr, 0, sizeof(pr));
    for (int i = 2; i * i <= k; ++i)
        if (pr[i] == 0)
            for (int j = i * i; j <= k; j += i)
                pr[j] = 1;
}
int V(int p, int D)
{
    int cnt = 0;
    while (D > 0)
        cnt += (D /= p);
    return cnt;
}
void del(int p)
{
    long long L = n - k;
    long long pos = (L / p + 1) * p - L;
    int cnt = V(p, k);
    for (int i = pos; i <= k; i += p)
    {
        if (cnt == 0)
            return;
        while (cnt > 0 && a[i] % p == 0)
        {
            a[i] /= p;
            cnt--;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> n >> mod;
    sieve();
    for (int i = 1; i <= k; ++i)
        a[i] = n - k + i;
    for (int i = 2; i <= k; ++i)
        if (pr[i] == 0)
            del(i);
    for (int i = 1; i <= k; ++i)
        a[i] %= mod;
    int ans = 1;
    for (int i = 1; i <= k; ++i)
        ans = 1ll * ans * a[i] % mod;
    cout << ans << '\n';
}