// Cho dãy số nguyên dương gồm  phần tử , , … ,  và  truy vấn. Mỗi truy vấn gồm 3 số
// nguyên dương (, , ).
// Yêu cầu:Với mỗi truy vấn, đếm số cách chọn  phần tử trong đoạn [, ] sao cho tổng của
// phần tử đó là nhỏ nhất có thể.
// Dữ liệu
//  Dòng đầu gồm hai số nguyên dương  và  (, ≤ 2.10);
//  Dòng thứ hai chứa  số nguyên dương , , … ,  ( ≤ 10);
//  Dòng thứ  trong  dòng tiếp theo gồm bộ ba số nguyên (, , ) (1 ≤  ≤  ≤ ,  ≤  −
//  + 1).
// Kết quả Gồm  dòng, mỗi dòng là kết quả của bài toàn khi chia lấy dư cho (10 + 7)
#pragma optimize GCC "O2"
#include <bits/stdc++.h>
#define lo long long
#define fi first
#define se second
#define KKH "TV_0302"
#define BIT(x, k) (((x) >> (k - 1)) & 1)
#define rs(x, a) memset(x, (a), sizeof x)
#define off(x, k) ((x) ^ (1 << (k - 1)))
using namespace std;
void START()
{
#ifdef toilagun2004
    freopen(KKH ".inp", "r", stdin);
    freopen(KKH ".out", "w", stdout);
#endif // toilagun2004
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const int mod = 1e9 + 7;
const int gh = 2e5 + 6;
struct Node
{
    int val, l, r;
    Node() { val = l = r = 0; }
} it[18 * gh];
struct query
{
    int l, x, pos;
};
int n, a[gh], id, ver[gh], gt[gh], inv[gh];
int mu(int a, int b)
{
    if (b == 1)
        return a;
    if (b == 0)
        return 1;
    int t = mu(a, b / 2);
    t = (1LL * t * t) % mod;
    return (b & 1) ? (1LL * t * a) % mod : t;
}
int C(int n, int k)
{
    return (1LL * (1LL * gt[n] * inv[k]) % mod * inv[n - k]) % mod;
}
void update(int fi, int se, int i, int j, int h)
{
    if (i > j)
        return;
    if (i == j)
    {
        it[se].val = it[fi].val + 1;
        return;
    }
    int giua = (i + j) >> 1;
    if (h <= giua)
    {
        it[se].l = ++id;
        it[se].r = it[fi].r;
        update(it[fi].l, it[se].l, i, giua, h);
    }
    else
    {
        it[se].l = it[fi].l;
        it[se].r = ++id;
        update(it[fi].r, it[se].r, giua + 1, j, h);
    }
    it[se].val = it[it[se].l].val + it[it[se].r].val;
}
int get(int fi, int se, int i, int j, int k)
{
    if (i == j)
        return C(it[se].val - it[fi].val, k);
    int giua = (i + j) >> 1, tmp = it[it[se].l].val - it[it[fi].l].val;
    if (k <= tmp)
        return get(it[fi].l, it[se].l, i, giua, k);
    return get(it[fi].r, it[se].r, giua + 1, j, k - tmp);
}
int rrhoa(int n, int x[])
{
    pair<int, int> tmp[n + 6];
    for (int i = 1; i <= n; ++i)
        tmp[i] = {x[i], i};
    sort(tmp + 1, tmp + 1 + n);
    int D = 0, cuoi = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        if (cuoi != tmp[i].fi)
            D++, cuoi = tmp[i].fi;
        x[tmp[i].se] = D;
    }
    return D;
}
int main()
{
    START();
    gt[0] = 1;
    for (int i = 1; i < gh; ++i)
        gt[i] = (1LL * gt[i - 1] * i) % mod;
    inv[gh - 1] = mu(gt[gh - 1], mod - 2);
    for (int i = gh - 2; i >= 0; --i)
        inv[i] = (1LL * inv[i + 1] * (i + 1)) % mod;
    int T;
    cin >> n >> T;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    rrhoa(n, a);
    for (int i = 1; i <= n; ++i)
    {
        ver[i] = ++id;
        update(ver[i - 1], ver[i], 1, n, a[i]);
    }
    for (int test = 1; test <= T; test++)
    {
        int i, j, t;
        cin >> i >> j >> t;
        cout << get(ver[i - 1], ver[j], 1, n, t) << '\n';
    }
}
