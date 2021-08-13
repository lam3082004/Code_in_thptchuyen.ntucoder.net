// Cho n điểm trên mặt phẳng tọa độ, hãy tìm bán kính đường tròn nhỏ nhất phủ tất
// cả các điểm.
// Dữ liệu:
//  Dòng đầu tiên ghi số nguyên dương n là số điểm trên mặt phẳng.
//  n dòng kế tiếp mỗi dòng ghi hai số nguyên x, y là tọa độ của điểm thứ i.
// Kết quả Một số thực với 3 chữ số phần thập phân là kết quả cần tìm.
// Ví dụ:

// CIRCLE.INP CIRCLE.OUT
// 4
// 0 0
// 1 1
// 1 0
// 0 1

// 0.707

// Giới hạn:
//  N ≤ 100.
//  x, y kiểu int
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long double
#define nmax 10000007
#define ii pair<ll, ll>
#define fi first
#define se second
const ll mod = 1e9 + 7;
using namespace std;
struct point
{
    long double x;
    long double y;
};
ll canh(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
ll s(point a1, point b1, point c1)
{
    ll a = canh(a1, b1);
    ll b = canh(b1, c1);
    ll c = canh(c1, a1);
    ll p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
ll r(point a1, point b1, point c1)
{
    ll a = canh(a1, b1);
    ll b = canh(b1, c1);
    ll c = canh(c1, a1);
    if (c * c + a * a < b * b)
        return b / 2;
    if (a * a + b * b < c * c)
        return c / 2;
    if (c * c + b * b < a * a)
        return a / 2;
    return (a * b * c) / (4 * s(a1, b1, c1));
}
point a[nmax];
ll maxx = 0;
long long t;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    fo(i, 1, t)
            cin >>
        a[i].x >> a[i].y;
    fo(i, 1, t - 2)
    {
        fo(j, i + 1, t - 1)
        {
            fo(z, j + 1, t)
            {
                maxx = max(maxx, r(a[i], a[j], a[z]));
            }
        }
    }
    cout << setprecision(3) << fixed << maxx;
}
