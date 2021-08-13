// ho hai số nguyên dương X và K. Hãy đếm số số nguyên thuộc đoạn
// [1, K] và nguyên tố cùng nhau với X.
// Dữ liệu vào file KGCD.INP gồm một dòng duy nhất chứa hai số
// nguyên dương X và K.
// Kết quả in ra file KGCD.OUT gồm một số nguyên duy nhất là kết quả
// của bài toán.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
ll X, K, m[10000], p[10000], d, s = 0, a[20], b[20], t = 0;
ll tohop(ll x, ll k)
{
    fo(i, a[x - 1] + 1, t - k + x) if (b[i] == 0)
    {
        a[x] = i;
        b[i] = 1;
        if (x == k)
        {
            ll n = 1;
            fo(j, 1, k)
                n *= m[a[j]];
            p[++d] = n;
        }
        else
            tohop(x + 1, k);
        b[i] = 0;
    }
}
int main()
{
    cin >> X >> K;
    fo(i, 2, sqrt(X)) if (X % i == 0)
    {
        m[++t] = i;
        while (X % i == 0)
            X /= i;
    }
    if (X > 1)
        m[++t] = X;
    fo(i, 1, t)
    {
        d = 0;
        tohop(1, i);
        if (i % 2 == 1)
            fo(j, 1, d) s += K / p[j];
        else
            fo(j, 1, d) s -= K / p[j];
    }
    cout << K - s;
}
