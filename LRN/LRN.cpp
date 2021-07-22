// LRN

//     Cho ba số nguyên dương L,
//     R, N.Tính giá trị X R i = L(C i N ∗ i 2) mod 1000003.

//        Dữ liệu
// • Gồm một dòng duy nhất chứa ba số nguyên dương L,
//                           R, N(1 ≤ L ≤ R ≤ N ≤ 1018).Kết quả
// • In ra giá trị cần tính.
#include <bits/stdc++.h>
#define TASK "MA_E7"
#define LL long long
using namespace std;
const int mod = 1e6 + 3;
LL l, r, n;
int L[5], R[5], N[5], dp[5][2][2];
int fact[mod + 5], invf[mod + 5];
///------------------------
int pw(int A, int B)
{
    int tmp = 1;
    for (; B; A = 1LL * A * A % mod, B >>= 1)
        if (B & 1)
            tmp = 1LL * tmp * A % mod;
    return tmp;
}
///------------------------
int C(int K, int M)
{
    if (K > M)
        return 0;
    if (K == M)
        return 1;
    return (1LL * (1LL * fact[M] * invf[M - K] % mod) * invf[K] % mod);
}
///------------------------
int F(int i, bool okL, bool okR)
{
    int &rs = dp[i][okL][okR];
    if (rs != -1)
        return rs;
    rs = 0;
    if (i == 0)
    {
        for (int j = max(0, (1 - okL) * L[i]); j <= min(mod - 1, (1 - okR) * R[i]); ++j)
            rs = (rs + 1LL * C(j, N[i]) * j * j) % mod;
        return rs;
    }
    for (int j = max(0, (1 - okL) * L[i]); j <= min(mod - 1, (1 - okR) * R[i]); ++j)
        rs = (rs + 1LL * C(j, N[i]) * F(i - 1, okL || (j > L[i]), okR || (j < R[i]))) % mod;
    return rs;
}
///------------------------
void solve()
{
    cin >> l >> r >> n;
    fact[0] = 1;
    for (int i = 1; i <= mod; ++i)
        fact[i] = 1LL * fact[i - 1] * i % mod;
    invf[mod - 1] = pw(fact[mod - 1], mod - 2);
    for (int i = mod - 2; i >= 0; --i)
        invf[i] = 1LL * (i + 1) * invf[i + 1] % mod;
    LL tmp = n;
    for (int i = 0; i < 3; ++i)
    {
        L[i] = l % mod;
        l /= mod;
        R[i] = r % mod;
        r /= mod;
        N[i] = tmp % mod;
        tmp /= mod;
    }
    memset(dp, -1, sizeof(dp));
    cout << F(2, 0, 0) << '\n';
}
///------------------------
int main()
{

    solve();
}
