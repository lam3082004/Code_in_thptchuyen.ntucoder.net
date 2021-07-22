// Dãy số
// Cho bốn số nguyên dương , từ hai số ta xây dựng được dãy số với công thức
// như sau:
//  .
// 
// Sau khi tạo ra được dãy số đó, Mr Toàn muốn bạn tính giá trị
//  . Kết quả của bài toán sẽ rất
// lớn nên Mr Toàn chỉ yêu cầu bạn chia lấy dư cho 1000000007.
// Dữ liệu: Từ file SEQ.INP gồm một dòng duy nhất chứa 4 số nguyên dương .
// Kết quả: Trong file SEQ.OUT in ra
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
using namespace std;
const int base = 1e9 + 7;
ll a, b, c, d, ans;
struct MaTran
{
    ll f[2][2];
    MaTran()
    {
        f[0][0] = b;
        f[0][1] = 0;
        f[1][0] = c;
        f[1][1] = 1;
    }
};
ll nhan(ll a, ll b, ll mod)
{
    if (b == 0)
        return 0;
    ll t = nhan(a, b / 2, mod);
    t = (t + t) % mod;
    if (b % 2 == 1)
        t = (t + a) % mod;
    return t;
}
MaTran operator*(MaTran a, MaTran b)
{
    MaTran res;
    fo(i, 0, 1)
        fo(j, 0, 1)
    {
        res.f[i][j] = 0;
        fo(k, 0, 1)
            res.f[i][j] = (res.f[i][j] + nhan(a.f[i][k], b.f[k][j], base - 1)) % (base - 1);
    }
    return res;
}
ll mu(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = mu(a, b / 2);
    t = nhan(t, t, base);
    if (b % 2 == 1)
        t = nhan(t, a, base);
    return t;
}
MaTran powermod(MaTran a, ll n)
{
    if (n == 1)
        return a;
    if (n % 2 != 0)
        return powermod(a, n - 1) * a;
    MaTran tmp = powermod(a, n / 2);
    return tmp * tmp;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("SEQ_2019.inp", "r", stdin);
    freopen("SEQ_2019.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> a >> b >> c >> d;
    MaTran A;
    A = powermod(A, d - 1);
    MaTran B;
    B.f[0][0] = b;
    B.f[0][1] = 1;
    B.f[1][0] = 0;
    B.f[1][1] = 0;
    MaTran C = B * A;
    cout << mu(a, C.f[0][0]) << endl;
}