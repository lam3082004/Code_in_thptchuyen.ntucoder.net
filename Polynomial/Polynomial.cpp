// Polynomial
// Cho đa thức f(x) = anx
// n + an−1x
// n−1 + ... + a1x + a0 với hệ số nguyên (ai ∈ Z). Tìm và in ra tất

// cả các nghiệm nguyên của phương trình f(x) = 0.
// Dữ liệu
// • Dòng đầu gồm duy nhất một số nguyên dương n (n < 5);
// • Dòng thứ hai gồm n + 1 số nguyên a0, a1, ..., an (|ai
// | ≤ 109
// , an 6= 0).

// Kết quả
// • In ra tất cả các nghiệm nguyên của phương trình f(x) = 0. Nếu có nhiều hơn 1 nghiệm hãy
// in các nghiệm tăng dần, nếu phương trình vô nghiệm in ra "NO SOLUTION".
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 1000005
#define ll long long
using namespace std;
ll n, a[10], b[nmax], t = 1, dem = 0;
bool ok(ll x)
{
    ll tmp = 0;
    fo(i, 0, n)
    {
        ll s = 1;
        fo(j, 1, i) s *= x;
        tmp += s * a[i];
    }
    return (tmp == 0);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("POLYNOMIAL.inp", "r", stdin);
    freopen("POLYNOMIAL.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    fo(i, 0, n) cin >> a[i];
    int p = n;
    fo(i, 0, n) if (a[i] != 0) p = min(p, i);
    ll A = abs(a[p]);
    fo(i, 1, sqrt(A))
    {
        if (A % i == 0)
        {
            if (ok(i))
            {
                b[t] = i;
                t++;
            }
            if (ok(-i))
            {
                b[t] = -i;
                t++;
            }
            if (ok(A / i))
            {
                b[t] = A / i;
                t++;
            }
            if (ok(-A / i))
            {
                b[t] = -A / i;
                t++;
            }
        }
    }
    if (a[0] == 0)
    {
        b[t] = 0;
        t++;
    }
    if (t == 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    sort(b + 1, b + t);
    fo(i, 1, t - 1)
    {
        if (b[i] != b[i + 1] && b[i] != 0)
            cout << b[i] << ' ';
        if (b[i] == 0)
            cout << b[i] << ' ';
    }
}
