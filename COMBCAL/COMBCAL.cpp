// Cho ba số nguyên dương N, M, R.Tính giá trị A = R P−1 i = 1
//  N i
// 
// ×
//  M R−i
// 
// × i × (R − i).Dữ liệu
// • Dòng đầu tiên chứa số nguyên dương T là số lượng bộ dữ liệu.T dòng tiếp theo, mỗi dòng chứa ba số nguyên dương N, M, K(1 ≤ N, M ≤ 1018, R ≤ N + M).Kết quả
// • In ra T dòng, mỗi dòng tương ứng với giá trị của A sau khi lấy phần dư với 107 + 19.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 10000025
using namespace std;
const ll mod = 1e7 + 19;
ll t, n, m, k, a, b, s, gt[nmax], inv[nmax], N, K;
ll tich(ll a, ll b)
{
    a %= mod;
    b % mod;
    ll q = (long double)a * b / mod;
    return (((a * b - q * mod) % mod) + mod) % mod;
}
ll mu(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = mu(a, b / 2);
    t = tich(t, t);
    if (b % 2 == 1)
        t = tich(t, a);
    return t;
}
int main()
{
    gt[0] = 1;
    fo(i, 1, mod - 1)
        gt[i] = (gt[i - 1] * i) % mod;
    inv[mod - 1] = mu(gt[mod - 1], mod - 2);
    for (int i = mod - 2; i >= 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        a = 0;
        b = 0;
        s = 1;
        ll p = n + m - 2, q = k - 2;
        while (p > 0 || q > 0)
        {
            N = p % mod;
            K = q % mod;
            if (N >= K)
                s = tich(s, tich(gt[N], tich(inv[N - K], inv[K])));
            else
                s *= 0;
            p /= mod;
            q /= mod;
        }
        s = tich(s, tich(n, m));
        cout << s << '\n';
    }
}
