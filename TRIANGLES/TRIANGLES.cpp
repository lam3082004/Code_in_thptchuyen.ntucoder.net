// Cho một dãy số nguyên
// a
// 1
// ,
// a
// 2
// ,
// .
// .
// .
// ,
// a
// n

// Yêu cầu 1: Tìm một dãy con liên tiếp dài nhất (ít nhất có 3 số hạng) sao cho 3 số hạng bất kì của dãy con là độ dài của ba cạnh của một tam giác.

// Yêu cầu 2: Tìm một dãy con dài nhất ( không nhất thiết là các số hạng liên tiếp, có ít nhất 3 số hạng) sao cho 3 số hạng bất kỳ của dãy con là độ dài của ba cạnh trong một tam giác

// Dữ liệu:

// - Dòng đầu ghi số nguyên dương n.

// - Dòng thứ hai ghi n số nguyên
// a
// 1
// ,
// a
// 2
// ,
// .
// .
// .
// ,
// a
// n
// (
// 1
// ≤
// a
// i
// ≤
// 10
// 9
// )

// Kết quả:

// - Dòng 1 ghi độ dài của dãy tìm được ứng với yêu cầu 1; nếu không tồn tại dãy thì in ra 0

// - Dòng 2 ghi độ dài của dãy tìm được ứng với yêu cầu 2; nếu không tồn tại dãy thì in ra 0
#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define oo 10000000000
using namespace std;
void LSH()
{
#ifndef ONLINE_JUDGE
    freopen("TRIANGLES.INP", "r", stdin);
    freopen("TRIANGLES.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ii seg[4000005];
int b[10], a[1000005], seg1[4000005];
void update(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = ii(a[l], oo);
        seg1[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    update(id * 2, l, mid);
    update(id * 2 + 1, mid + 1, r);
    b[1] = seg[id * 2].fi;
    b[2] = seg[id * 2].se;
    b[3] = seg[id * 2 + 1].fi;
    b[4] = seg[id * 2 + 1].se;
    sort(b + 1, b + 5);
    seg1[id] = max(seg1[id * 2], seg1[id * 2 + 1]);
    seg[id].fi = b[1];
    seg[id].se = b[2];
}
int get1(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return -oo;
    if (u <= l && r <= v)
        return seg1[id];
    int mid = l + r >> 1;
    return max(get1(id * 2, l, mid, u, v), get1(id * 2 + 1, mid + 1, r, u, v));
}
ii get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return ii(oo, oo);
    if (u <= l && r <= v)
        return seg[id];
    int mid = l + r >> 1;
    ii x = get(id * 2, l, mid, u, v);
    ii y = get(id * 2 + 1, mid + 1, r, u, v);
    b[1] = x.fi;
    b[2] = x.se;
    b[3] = y.fi;
    b[4] = y.se;
    sort(b + 1, b + 5);
    return {b[1], b[2]};
}
int n, vi, ans = 0, p1, s = 0;
ii p;
bool check(int l, int r)
{
    p = get(1, 1, n, l, r);
    p1 = get1(1, 1, n, l, r);
    if (l >= 1 && r <= n && p.fi + p.se > p1)
        return true;
    return false;
}
void cal()
{
    ans = 0;
    vi = 0;
    update(1, 1, n);
    for (int i = 1; i <= n - 2; ++i)
    {
        if (vi < i + 2)
        {
            vi = i + 2;
        }
        while (check(i, vi))
        {
            s = vi - i + 1;
            vi++;
        }
        ans = max(ans, s);
    }
    cout << ans << '\n';
}
void cal1()
{
    ans = 0;
    vi = 1;
    for (int i = 3; i <= n; ++i)
    {
        while (i - 2 > vi && a[vi] + a[vi + 1] <= a[i])
            vi++;
        if (a[vi] + a[vi + 1] > a[i])
            ans = max(ans, i - vi + 1);
    }
    cout << ans;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cal();
    sort(a + 1, a + n + 1);
    cal1();
}
int main()
{
    LSH();
    solve();
}
