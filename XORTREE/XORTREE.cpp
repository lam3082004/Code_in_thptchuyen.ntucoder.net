// Cho một cây gồm n đỉnh và n − 1 cạnh. Cạnh thứ i có trọng số là c[i]
// Cạnh thứ i được coi là tốt nếu c[i] ≤ k
// Với một đường đi từ u đến v thì độ tốt của đường đi này là xor của tất cả các cạnh tốt trong đó
// Yêu cầu: Cho cây và các bộ u, v, k. Với mỗi bộ u, v, k tìm độ tốt của đường đi từ u đến v
// Input:
// • Dòng đầu tiên chứa n – số đỉnh của cây
// • n − 1 dòng tiếp theo chứa thông tin về cây. Mỗi dòng chứa 3 số nguyên u, v, c là cạnh nối
// hai đỉnh u, v có trọng số là c
// • Dòng tiếp theo chứa m – số yêu cầu
// • m dòng tiếp theo chứa thông tin của các yêu cầu. Mỗi dòng gồm 3 số nguyên u, v, k
// Output:
// • Ở mỗi yêu cầu, in ra một số nguyên trên một dòng là độ tốt của đường đi đó
// Ràng buộc:
// • 1 ≤ n, m ≤ 105
// • 1 ≤ u, v ≤ n
// • 1 ≤ c, k ≤ 109
// Subtask:
// • Subtask1 (20%): 1 ≤ n, m ≤ 10
// • Subtask2 (30%): 1 ≤ n, m ≤ 103
// • Subtask3 (50%): 1 ≤ n, m ≤ 105
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e18
#define ar array
using namespace std;
const int mod = 1e9 + 7;
struct xtr
{
    ll u, v, k, pos;
};
ll n, m, ind[nmax], out[nmax], t[2 * nmax], d[nmax], dem = 0;
xtr a[nmax], b[nmax];
vector<ii> p[nmax];
bool vs[nmax];
ii ans[nmax];
ll cmp1(xtr a, xtr b)
{
    return a.k > b.k;
}
void dfs(int u)
{
    ind[u] = ++dem;
    vs[u] = 1;
    for (auto v : p[u])
        if (!vs[v.fi])
        {
            d[v.fi] = d[u] ^ v.se;
            dfs(v.fi);
        }
    out[u] = ++dem;
}
void update(int m, ll val)
{
    while (m < 2 * nmax)
    {
        t[m] ^= val;
        m += m & -m;
    }
}
ll get(int m)
{
    ll tmp = 0;
    while (m > 0)
    {
        tmp ^= t[m];
        m -= m & -m;
    }
    return tmp;
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
    cin >> n;
    fo(i, 1, n - 1)
    {
        cin >> a[i].u >> a[i].v >> a[i].k;
        p[a[i].u].push_back(ii(a[i].v, a[i].k));
        p[a[i].v].push_back(ii(a[i].u, a[i].k));
    }
    cin >> m;
    fo(i, 1, m)
    {
        cin >> b[i].u >> b[i].v >> b[i].k;
        b[i].pos = i;
    }
    sort(a + 1, a + n, cmp1);
    sort(b + 1, b + 1 + m, cmp1);
    dfs(1);
    int j = 1;
    fo(i, 1, m)
    {
        while (a[j].k > b[i].k && j <= n)
        {
            if (ind[a[j].u] > ind[a[j].v])
            {
                update(ind[a[j].u], a[j].k);
                update(out[a[j].u], a[j].k);
            }
            else
            {
                update(ind[a[j].v], a[j].k);
                update(out[a[j].v], a[j].k);
            }
            ++j;
        }
        ll res = d[b[i].u] ^ d[b[i].v] ^ get(ind[b[i].u]) ^ get(ind[b[i].v]);
        ans[i] = ii(b[i].pos, res);
        //        cout<<b[i].pos<<' '<<b[i].u<<' '<<b[i].v<<' '<<d[b[i].u]<<' '<<d[b[i].v]<<' '
        //        <<get(ind[b[i].u])<<' '<<get(ind[b[i].v])<<' '<<res<<'\n';
    }
    sort(ans + 1, ans + 1 + m);
    fo(i, 1, m)
            cout
        << ans[i].se << '\n';
}
