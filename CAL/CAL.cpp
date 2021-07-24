// Bạn được thách đố tính giá trị
// T = (∑ ∑ ∑ ∑ ∑ |i − j| ∗ |j − k| ∗ |k − x| ∗ |x − y| ∗ |y − i|

// n
// y=1
// n
// x=1
// n
// k=1
// n
// j=1
// n
// i=1

// ) % 10007

// Input
// Gồm nhiều dòng, mỗi dòng chứa một số nguyên dương n. Kết thúc file bằng một số 0.
// Output
// Gồm nhiều dòng, mỗi dòng chứa kết quả tương ứng với dữ liệu vào.
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 10007;
long long F[101];

long long MU(long long a, long long b)
{
    long long res = 1;
    for (; b; a = (a * a) % MOD, b >>= 1)
        if (b & 1)
            res = res * a % MOD;
    return res;
}

void Init()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void Solve()
{
    long long n, a, b, c, d, e;
    for (n = 1; n <= 12; ++n)
        for (a = 1; a <= n; ++a)
            for (b = 1; b <= n; ++b)
                if (a != b)
                    for (c = 1; c <= n; ++c)
                        if (b != c)
                            for (d = 1; d <= n; ++d)
                                if (c != d)
                                    for (e = 1; e <= n; ++e)
                                        if (d != e && a != e)
                                            F[n] = (F[n] + abs(a - b) * abs(b - c) * abs(c - d) * abs(d - e) * abs(e - a)) % MOD;
    while (cin >> n)
    {
        if (!n)
            return;
        if (n <= 12)
        {
            cout << F[n] << '\n';
            continue;
        }
        long long S = 0, A = 1, B = 1;
        for (long long i = 1; i <= 12; ++i)
        {
            A = (A * (n - i) + MOD * MOD) % MOD;
            if (i < 12)
                B = (B * (i - 12) + MOD * MOD) % MOD;
        }
        for (long long i = 1; i <= 12; ++i)
        {
            S = (S + ((A * MU(n - i, MOD - 2) % MOD) * MU(B, MOD - 2) % MOD) * F[i] % MOD) % MOD;
            B = B * MU(i - 12 + MOD, MOD - 2) % MOD * i % MOD;
        }
        cout << S << '\n';
    }
}

int main()
{
    //Maketest();
    Init();
    Solve();
}
