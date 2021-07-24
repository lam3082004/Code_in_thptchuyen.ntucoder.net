// FOFGCD
// Cho hàm số f(a, b) :
// f(a, b) = (
// 0 khi b = 0;
// 1 + f(a, b − gcd(a, b)) khi b 6= 0.
// Với gcd(a, b) là ước chung lớn nhất của a và b.
// Cho hai số tự nhiên x và y. Yêu cầu tính f(x, y).
// Dữ liệu
// • Gồm một dòng duy nhất chứa hai số tự nhiên x và y (1 ≤ x, y ≤ 1012).
// Kết quả
// • In ra f(x, y).
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 10000005
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int mod = 1e9 + 7;
ll t, n, k, a, b, kq = 0;
vector<ll> p, q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    ll d = __gcd(a, b);
    a /= d;
    b /= d;
    fo(i, 2, sqrt(a)) if (a % i == 0)
    {
        while (a % i == 0)
        {
            a /= i;
            p.push_back(i);
        }
    }
    if (a > 1)
        p.push_back(a);
    while (!p.empty())
    {
        ll tmp = 1e12;
        fo(i, 0, p.size() - 1)
            tmp = min(tmp, b % p[i]);
        kq += tmp;
        ll pos;
        fo(i, 0, p.size() - 1) if (tmp == b % p[i])
            pos = i;
        b -= tmp;
        fo(i, 0, p.size() - 1) if (pos == i)
            b /= p[i];
        else q.push_back(p[i]);
        p = q;
        q.clear();
    }
    cout << kq + b;
}
