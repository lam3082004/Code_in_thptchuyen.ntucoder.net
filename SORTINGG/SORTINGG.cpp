// Cho một mảng gồm N số đôi một phân biệt từ 1 đến N. Có Q phép thay đổi, mỗi phép yêu cầu
// sắp xếp một đoạn con liên tiếp của mảng theo thứ tự tăng dần hoặc giảm dần. Nhiệm vụ của bạn
// là in ra phần tử ở vị trí chính giữa của mảng sau Q phép thay đổi.
// Input
// Dòng đầu tiên gồm hai số N và Q (1 ≤ N ≤ 105

// , 0 ≤ Q ≤ 105

// , N lẻ). Dòng tiếp theo gồm N số
// là các phần tử của mảng. M dòng tiếp theo, mỗi dòng gồm hai số l, r (1 ≤ l, r ≤ N). Nếu l < r,
// bạn cần sắp xếp đoạn từ l đến r theo thứ tự tăng dần, ngược lại bạn cần sắp xếp đoạn từ r tới l
// theo thứ tự giảm dần.
// Output
// In ra một số là phần tử thứ N+1
// 2
// của mảng sau các phép thay đổi.
#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5 + 5;
int a[nmax], q, n, x[nmax], l[nmax], r[nmax], seg[4 * nmax], lazy[4 * nmax];
bool check[4 * nmax];
void build(int l, int r, int pos)
{
    if (l == r)
    {
        seg[pos] = (x[l] == 1);
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, 2 * pos);
    build(mid + 1, r, 2 * pos + 1);
    seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
}
void down(int l, int r, int pos)
{
    int mid = l + r >> 1;
    seg[2 * pos] = lazy[pos] * (mid - l + 1);
    seg[2 * pos + 1] = lazy[pos] * (r - mid);
    lazy[2 * pos] = lazy[pos];
    lazy[2 * pos + 1] = lazy[pos];
    check[2 * pos] = 1;
    check[2 * pos + 1] = 1;
    lazy[pos] = 0;
    check[pos] = 0;
}
void update(int l, int r, int u, int v, int k, int pos)
{
    if (r < u || l > v)
        return;
    if (l >= u && r <= v)
    {
        seg[pos] = k * (r - l + 1);
        lazy[pos] = k;
        check[pos] = 1;
        return;
    }
    int mid = l + r >> 1;
    if (check[pos])
        down(l, r, pos);
    update(l, mid, u, v, k, 2 * pos);
    update(mid + 1, r, u, v, k, 2 * pos + 1);
    seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
}
int get(int l, int r, int u, int v, int pos)
{
    if (r < u || l > v)
        return 0;
    if (l >= u && r <= v)
        return seg[pos];
    int mid = l + r >> 1;
    if (check[pos])
        down(l, r, pos);
    seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
    return get(l, mid, u, v, 2 * pos) + get(mid + 1, r, u, v, 2 * pos + 1);
}
int take(int l, int r, int p, int pos)
{
    if (r < p || l > p)
        return 0;
    if (l == p && r == p)
        return seg[pos];
    if (check[pos])
        down(l, r, pos);
    int mid = l + r >> 1;
    return take(l, mid, p, 2 * pos) + take(mid + 1, r, p, 2 * pos + 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("SORTING.inp","r",stdin);
    //freopen("SORTING.out","w",stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= q; i++)
        cin >> l[i] >> r[i];
    int u = 1, v = n, res = 1;
    while (u <= v)
    {
        int mid = u + v >> 1;
        memset(check, 0, sizeof check);
        memset(lazy, 0, sizeof lazy);
        for (int i = 1; i <= n; i++)
            if (mid > a[i])
                x[i] = 0;
            else
                x[i] = 1;
        build(1, n, 1);
        for (int i = 1; i <= q; i++)
            if (l[i] <= r[i])
            {
                int d1 = get(1, n, l[i], r[i], 1);
                int d0 = r[i] - l[i] + 1 - d1;
                update(1, n, l[i], l[i] + d0 - 1, 0, 1);
                update(1, n, r[i] - d1 + 1, r[i], 1, 1);
            }
            else
            {
                int d1 = get(1, n, r[i], l[i], 1);
                int d0 = l[i] - r[i] + 1 - d1;
                update(1, n, l[i] - d0 + 1, l[i], 0, 1);
                update(1, n, r[i], r[i] + d1 - 1, 1, 1);
            }
        if (take(1, n, (n + 1) / 2, 1) == 1)
        {
            res = mid;
            u = mid + 1;
        }
        else
            v = mid - 1;
    }
    cout << res << '\n';
}
