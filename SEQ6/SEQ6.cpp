// Cho số nguyên dương n. Dãy số a1, a2, ... , ak

// (1 ≤ ai ≤ n) được gọi là

// dãy chia hết nếu ai+1 chia hết cho ai với mọi i từ 1 đến k − 1
// Yêu cầu: Cho 2 số nguyên dương n và m, đếm số dãy chia hết có độ dài m.
// Vì kết quả có thể rất lớn nên chỉ in ra số dư khi chia cho 109 + 7
// Input:
// Một dòng duy nhất chứa 2 số nguyên dương n và m
// Output:
// Một số duy nhất là kết quả của bài toán.
// Giới hạn:
// • 1 ≤ n, m ≤ 105
// • Có 40% số test có 1 ≤ n, m ≤ 1000
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e18
#define ar array
using namespace std;
const int mod = 1e9 + 7;
ll n, m, gt[nmax], inv[nmax], f[20][nmax];
ll mu(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = mu(a, b / 2);
    t = (t * t) % mod;
    if (b & 1)
        t = (t * a) % mod;
    return t;
}
ll C(ll k, ll n)
{
    if (k > n)
        return 0;
    return ((gt[n] * inv[k]) % mod * inv[n - k]) % mod;
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
    gt[0] = 1;
    fo(i, 1, 100000)
        gt[i] = (gt[i - 1] * i) % mod;
    inv[100000] = mu(gt[100000], mod - 2);
    for (int i = 99999; i >= 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    cin >> n >> m;
    fo(i, 1, n)
        f[1][i] = 1;
    fo(i, 1, 16)
        fo(j, 1, n)
            fo(t, 2, n / j)
    {
        f[i + 1][j * t] = (f[i + 1][j * t] + f[i][j]) % mod;
    }
    ll ans = 0;
    fo(i, 1, 17)
        fo(j, 1, n)
            ans = (ans + f[i][j] * C(i - 1, m - 1)) % mod;
    cout << ans;
}
