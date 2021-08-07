// Ban đầu con châu chấu ở một điểm và sẽ phải bay theo một đường thẳng, không ngừng nghỉ
// đến đồng cỏ gần nhất. Đồng cỏ có dạng một hình chữ nhật có cạnh song song với trục toạ độ. Xác
// định số nguyên d nhỏ nhất, để sau khi bay khoảng cách d, con châu chấu sẽ nằm bên trong hoặc
// biên của đồng cỏ.
// Input
// • Gồm 3 dòng, mỗi dòng ghi hai số nguyên, lần lượt là toạ độ ban đầu của con châu chấu, toạ
// độ hai đỉnh đối diện của hình chữ nhật
// Output
// • In ra số nguyên d nhỏ nhất
// Giới hạn
// • Tất cả toạ độ nằm trong khoảng [−108
// , 108
// ]
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define fod(i, a, b) for (int i = a; i >= b; i--)
#define nmax 300005
#define ii pair<int, int>
#define fi first
#define se second
#define oo 1e18
using namespace std;
const int mod = 1e8 + 7;
ll t, n, a, b, x, y, u, v, ans;
ll kc(ll x, ll y, ll u, ll v)
{
    long double p = (u - x) * (u - x) + (v - y) * (v - y);
    ll q = sqrt(p);
    return q + (q * q != (ll)p);
}
ll hopper(ll a, ll b, ll x, ll y, ll u, ll v)
{
    if (a < x)
    {
        if (b < y)
            ans = kc(a, b, x, y);
        if (b > v)
            ans = kc(a, b, x, v);
        if (b >= y && b <= v)
            ans = x - a;
        return ans;
    }
    if (a > u)
    {
        if (b < y)
            ans = kc(a, b, u, y);
        if (b > v)
            ans = kc(a, b, u, v);
        if (b >= y && b <= v)
            ans = a - u;
        return ans;
    }
    if (a >= x && a <= u)
    {
        if (b < y)
            return y - b;
        if (b > v)
            return b - v;
        if (b >= y && b <= v)
            return 0;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("new.inp", "r", stdin);
    freopen("new.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> x >> y >> u >> v;
    if (x > u)
        swap(x, u);
    if (y > v)
        swap(y, v);
    cout << hopper(a, b, x, y, u, v);
}
