// COUNTK
// Người ta đặt một con Robot lên một tọa độ Descartes tại vị trí (0, 0). Con Robot được người điều
// khiển ra lệnh di chuyển đến vị trí (M, N) sau đúng K bước thỏa mãn điều kiện với mỗi bước di
// chuyển ở vị trí (i, j) chỉ có thể đến một trong 4 vị trí (i − 1, j),(i + 1, j),(i, j − 1),(i, j + 1).
// Yêu cầu: Bạn hãy tính xem con Robot có bao nhiêu cách di chuyển đến vị trí (M, N) thỏa mãn
// yêu cầu của người điều khiển.
// Dữ liệu
// • Dòng đầu gồm một số nguyên dương T là số testcase (T ≤ 10);
// • T dòng tiếp theo, mỗi dòng chứa các số nguyên K, M, N, mod.
// (0 ≤ K, |M|, |N| ≤ 105
// ; 1 ≤ mod ≤ 109
// ).
// Kết quả
// • In ra kết quả bài toán sau khi chia lấy dư cho mod ở mỗi dòng ứng với mỗi testcase.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; ++i)
#define fod(i, a, b) for (int i = a; i >= b; --i)
#define nmax 100005
#define nmax2 65000000
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e18
using namespace std;
//const int mod = 1e9 + 7;
ll t, k, m, n, mod, g[nmax], f[nmax];
void sang()
{
    fo(i, 2, nmax) if (g[i] == 0)
    {
        for (int j = i; j <= nmax; j += i)
            g[j] = i;
    }
}
ll mu(ll a, ll b)
{
    if (b == 0)
        return 1 % mod;
    ll t = mu(a, b / 2);
    t = (t * t) % mod;
    if (b & 1)
        t = (t * a) % mod;
    return t;
}
ll C(ll k, ll n)
{
    fo(i, 1, 100000)
        f[i] = 0;
    fo(i, n - k + 1, n)
    {
        ll x = i;
        while (x > 1)
        {
            f[g[x]]++;
            x /= g[x];
        }
    }
    fo(i, 1, k)
    {
        ll x = i;
        while (x > 1)
        {
            f[g[x]]--;
            x /= g[x];
        }
    }
    ll res = 1;
    fo(i, 1, 100000) if (f[i] > 0)
        res = (res * mu(i, f[i])) % mod;
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("new.inp", "r", stdin);
    freopen("new.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sang();
    cin >> t;
    while (t--)
    {
        cin >> k >> m >> n >> mod;
        m = abs(m);
        n = abs(n);
        if (k < m + n || (k - m - n) & 1)
        {
            cout << 0 << '\n';
            continue;
        }
        cout << (C((k - m - n) / 2, k) * C((k + m - n) / 2, k)) % mod << '\n';
    }
}
