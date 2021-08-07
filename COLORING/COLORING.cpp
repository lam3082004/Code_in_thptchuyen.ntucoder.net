// Tèo vẽ một hình chữ nhật trên mặt phẳng Oxy có các cạnh song song với hai trục Ox, Oy. Góc
// trái dưới của hình chữ nhật là gốc tọa độ (0, 0), góc phải trên là điểm (W, H). Tèo vẽ tiếp N điểm
// vào trong hình chữ nhật, điểm thứ i (1 ≤ i ≤ N) có tọa độ (xi
// , yi). Sau đó, Tèo tạo ra một dãy số
// a gồm N phần tử a1, a2, ..., aN . Với mỗi ai (1 ≤ i ≤ N), Tèo tô màu hình hình chữ nhật sao cho:
// • Nếu ai = 1, Tèo tô màu vùng phía bên trái điểm i (x < xi).
// • Nếu ai = 2, Tèo tô màu vùng phía bên phải điểm i (x > xi).
// • Nếu ai = 3, Tèo tô màu vùng phía bên dưới điểm i (y < yi).
// • Nếu ai = 4, Tèo tô màu vùng phía bên trên điểm i (y > yi).
// Sau khi Tèo tô màu xong, bạn hãy tính diện tích của vùng chưa được tô màu.
// Dữ liệu
// • Dòng đầu tiên, gồm 3 số nguyên dương W, H, N.
// • N dòng tiếp theo, mỗi dòng gồm ba số nguyên xi
// , yi
// ,
#include <bits/stdc++.h>
#define ll long long
#define nmax 100005
#define fo(i, a, b) for (ll i = a; i <= b; i++)
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int mod = 1e6 + 3;
ll n, m, t, d, x, y, u, v, l, r;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("TA.inp", "r", stdin);
    freopen("TA.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t;
    r = n, v = 0;
    u = m, l = 0;
    fo(i, 1, t)
    {
        cin >> x >> y >> d;
        if (d == 1)
            l = max(l, x);
        if (d == 2)
            r = min(r, x);
        if (d == 3)
            v = max(v, y);
        if (d == 4)
            u = min(u, y);
    }
    if (r <= l || u <= v)
        cout << 0;
    else
        cout << (r - l) * (u - v);
}
