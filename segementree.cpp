#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 500005
using namespace std;
ll a[nmax], st[4 * nmax];
ll n, k, l, r, t, z;
void build(ll id, ll i, ll j)
{
    if (i == j)
    {
        st[id] = a[i];
        return;
    }
    ll mid = i + j >> 1;
    build(2 * id, i, mid);
    build(2 * id + 1, mid + 1, j);
    st[id] = st[2 * id] + st[2 * id + 1];
}
void update(ll id, ll l, ll r, ll u, ll v)
{
    if (r < u || u < l)
    {
        return;
    }
    if (l == r)
    {
        st[id] = v;
        return;
    }
    ll mid = l + r >> 1;
    update(2 * id, l, mid, u, v);
    update(2 * id + 1, mid + 1, r, u, v);
    st[id] = min(st[2 * id], st[2 * id + 1]);
}
ll get(ll id, ll l, ll r, ll u, ll v)
{
    if (r < u || v < l)
    {
        return 1e18;
    }
    if (r <= v && u <= l)
    {
        return st[id];
    }
    ll mid = l + r >> 1;

    return min(get(2 * id, l, mid, u, v), get(2 * id + 1, mid + 1, r, u, v));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n)
    {
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }
    cout << get(1, 1, n, 1, n) << '\n';
}