// Xét hàm sau 𝑓(𝑘, 𝑟, 𝑝, 𝑞) = {
// 𝑝
// 𝑞
// 𝑛ế𝑢 𝑘 = 1
// 1
// 𝑟+𝑓(𝑘−1,𝑟,𝑝,𝑞)
// 𝑛ế𝑢 𝑘 > 1
// Ví dụ: 𝑓(4,1,1,1) =
// 1
// 1+
// 1
// 1+
// 1
// 1+
// 1
// 1
// =
// 3
// 5
// Yêu cầu: Cho 5 số nguyên dương 𝑘, 𝑟, 𝑝, 𝑞, 𝑀. Gọi phân số tối giản
// 𝑎
// 𝑏
// = 𝑓(𝑘, 𝑟, 𝑝, 𝑞), hãy
// tính 𝑎%𝑀, 𝑏%𝑀 (trong đó 𝑥%𝑀 là phần dư của phép chia 𝑥 cho 𝑀).
// Input
// - Gồm nhiều dòng, mỗi dòng chứa 5 số nguyên dương 𝑘, 𝑟, 𝑝, 𝑞, 𝑀 (𝑟, 𝑝, 𝑞 ≤ 100).
// Output
// - Gồm nhiều dòng, mỗi dòng chứa hai số 𝑎%𝑀, 𝑏%𝑀 là kết quả tương ứng với bộ
// dữ liệu vào.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
struct matrix
{
    ll x[5][5];
};
ll k, r, p, q, d, M, mod;
ll tich(ll a, ll b)
{
    a %= mod;
    b %= mod;
    ll q = (long double)a * b / mod;
    return ((a * b - q * mod) % mod + mod) % mod;
}
matrix nhan(matrix a, matrix b)
{
    matrix c;
    fo(i, 1, 2)
        fo(j, 1, 2)
    {
        c.x[i][j] = 0;
        fo(t, 1, 2)
            c.x[i][j] = (c.x[i][j] + tich(a.x[i][t], b.x[t][j])) % mod;
    }
    return c;
}
matrix mu(matrix a, ll n)
{
    if (n == 1)
        return a;
    matrix t = mu(a, n / 2);
    t = nhan(t, t);
    if (n % 2 == 1)
        t = nhan(t, a);
    return t;
}
matrix A, T;
int main()
{
    while (cin >> k >> r >> p >> q >> M)
    {
        d = __gcd(p, q);
        mod = M * d;
        if (k == 1)
            cout << (p / d) % M << ' ' << (q / d) % M << '\n';
        else
        {
            A.x[1][1] = 0;
            A.x[1][2] = 1;
            A.x[2][1] = 1;
            A.x[2][2] = r;
            T.x[1][1] = 0;
            T.x[1][2] = p;
            T.x[2][1] = 0;
            T.x[2][2] = q;
            A = mu(A, k - 1);
            T = nhan(A, T);
            cout << T.x[1][2] / d << ' ' << T.x[2][2] / d << '\n';
        }
    }
}
