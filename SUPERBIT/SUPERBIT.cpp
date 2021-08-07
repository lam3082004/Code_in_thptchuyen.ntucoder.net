// Cho mảng

// kích thước

// . Ban đầu tất cả đều bằng 0. Có

// truy vấn dạng:

// 1
// : Đặt
// [
// ] =
// . (1 ≤
// ≤
// . −1000000 ≤

// ≤ 1000000).

// 2
// : Cho biết tổng các phần tử từ
// [
// ]. .
// [
// ]. (1 ≤
// ,
// ≤
// ).

// Example:
// SUPERBIT.INP:
// 5 8
// 1 2 10
// 1 3 5
// 1 4 -2
// 2 1 3
// 2 2 5
// 1 2 0
// 2 1 3
// 2 2 5

// SUPERBIT.OUT:
// 15
// 13
// 5
// 3

// Giới hạn:
// 1 ≤
// ≤ 100000.
// 1 ≤
// ≤ 10^9.
// 50%
// ó
// ≤ 10^6.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define nmax 1000005
using namespace std;
int q, t[nmax], k = 0, ans = 0;
ll n, x, y, a[2 * nmax], h[2 * nmax], st[4 * nmax];
queue<ii> sol;
queue<ii> dou;
void update(ll id, ll l, ll r, ll p, ll k)
{
    if (p < l || r < p)
        return;
    if (l == r)
    {
        st[id] = k;
        return;
    }
    int mid = l + r >> 1;
    update(2 * id, l, mid, p, k);
    update(2 * id + 1, mid + 1, r, p, k);
    st[id] = st[2 * id] + st[2 * id + 1];
}
ll getsum(ll id, ll l, ll r, ll u, ll v)
{
    if (l > v || r < u)
        return 0;
    if (u <= l && r <= v)
        return st[id];
    int mid = l + r >> 1;
    return getsum(2 * id, l, mid, u, v) + getsum(2 * id + 1, mid + 1, r, u, v);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    fo(i, 1, q)
    {
        cin >> t[i] >> x >> y;
        if (t[i] == 1)
        {
            sol.push(ii(x, y));
            a[++k] = x;
        }
        else
        {
            dou.push(ii(x, y));
            a[++k] = x;
            a[++k] = y;
        }
    }
    fo(i, 1, k)
        h[i] = a[i];
    sort(h + 1, h + 1 + k);
    fo(i, 1, k)
        a[i] = lower_bound(h + 1, h + 1 + k, a[i]) - h;
    ans = k;
    k = 0;
    fo(i, 1, q)
    {
        if (t[i] == 1)
        {
            k++;
            x = sol.front().fi;
            y = sol.front().se;
            sol.pop();
            update(1, 1, ans, a[k], y);
        }
        else
        {
            k += 2;
            x = dou.front().fi;
            y = dou.front().se;
            dou.pop();
            cout << getsum(1, 1, ans, a[k - 1], a[k]) << '\n';
        }
    }
}
