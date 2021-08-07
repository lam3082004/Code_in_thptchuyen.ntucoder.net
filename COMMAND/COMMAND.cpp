// Cho mảng a chứa n số nguyên.
// Ban đầu tất cả các phần tử trong mảng đều bằng 0.
// Ta viết m câu lệnh vào 1 mảnh giấy. Các câu lệnh được đánh số từ 1 đến m.
// Những lệnh này có thể là một trong hai loại sau:
//  l r (1 ≤ l ≤ r ≤ n) - tăng tất cả các phần tử của mảng có chỉ số thuộc đoạn [l, r]
// lên 1 đơn vị
//  l r (1 ≤ l ≤ r ≤ m) - thực hiện tất cả các câu lệnh có chỉ số thuộc đoạn [l, r].
// Dữ liệu đảm bảo rằng r nhỏ hơn chỉ số của câu lệnh hiện tại
// Yêu cầu: tìm giá trị của mảng a sau khi thực hiện tất cả các câu lệnh
// Input:
//  Dòng đầu tiên của mỗi test chứa số nguyên n và m.
//  m dòng tiếp theo chứa các câu lệnh theo mẫu, miêu tả bằng t, l, r, với t là
// loại câu lệnh (1 hoặc 2)
// Output:
//  Với mỗi test in ra các phần tử của mảng a sau khi thực hiện tất cả các câu
// lệnh trên một dòng. Các số cách nhau bởi dấu cách.
//  Do giá trị có thể rất lớn nên chỉ cần in ra phần dư của nó cho 109 + 7
// Ràng buộc: 1 ≤ n, m ≤ 105
// Subtask:
//  Subtask 1 (20%): 1 ≤ n, m ≤ 10
//  Subtask 2 (30%): 1 ≤ n, m ≤ 1000
//  Subtask 3 (50%): Ràng buộc gốc
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; ++i)
#define ii pair<ll, ll>
#define fi first
#define se second
#define nmax 100005
#define oo 1e18
using namespace std;
const int mod = 1e9 + 7;
struct com
{
    ll t, l, r;
};
ll n, m, ans[nmax], st[4 * nmax], laz[4 * nmax];
com a[nmax];
void down(int id, int l, int r)
{
    int mid = l + r >> 1;
    st[2 * id] = (st[2 * id] + laz[id] * (mid - l + 1)) % mod;
    st[2 * id + 1] = (st[2 * id + 1] + laz[id] * (r - mid)) % mod;
    laz[2 * id] = (laz[2 * id] + laz[id]) % mod;
    laz[2 * id + 1] = (laz[2 * id + 1] + laz[id]) % mod;
    laz[id] = 0;
}
void update(int id, int l, int r, int u, int v, ll val)
{
    if (r < u || v < l)
        return;
    if (u <= l && r <= v)
    {
        st[id] = (st[id] + (r - l + 1) * val) % mod;
        laz[id] = (laz[id] + val) % mod;
        return;
    }
    int mid = l + r >> 1;
    down(id, l, r);
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);
    st[id] = (st[2 * id] + st[2 * id + 1]) % mod;
}
ll get(int id, int l, int r, int u, int v)
{
    if (r < u || v < l)
        return 0;
    if (u <= l && r <= v)
        return st[id];
    int mid = l + r >> 1;
    down(id, l, r);
    return (get(2 * id, l, mid, u, v) + get(2 * id + 1, mid + 1, r, u, v)) % mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    fo(i, 1, m)
            cin >>
        a[i].t >> a[i].l >> a[i].r;
    update(1, 1, m, 1, m, 1);
    for (int i = m; i >= 1; i--)
        if (a[i].t == 2)
        {
            ll res = get(1, 1, m, i, i);
            update(1, 1, m, a[i].l, a[i].r, res);
            update(1, 1, m, i, i, -res);
        }
    fo(i, 1, m) if (a[i].t == 1)
    {
        ll res = get(1, 1, m, i, i);
        ans[a[i].l] = ((ans[a[i].l] + res) % mod + mod) % mod;
        ans[a[i].r + 1] = ((ans[a[i].r + 1] - res) % mod + mod) % mod;
    }
    fo(i, 1, n)
        ans[i] = ((ans[i] + ans[i - 1]) % mod + mod) % mod;
    fo(i, 1, n)
            cout
        << ans[i] << ' ';
}
