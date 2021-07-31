// MWIS - TẬP ĐỘC LẬP CÓ TRỌNG SỐ CỰC ĐẠI
// Cho một cây n đỉnh, đỉnh i được gán trọng số là ai
// Một tập độc lập trên cây là tập hợp các đỉnh sao cho với hai đỉnh bất kì trong tập thì không có
// cạnh nối giữa hai đỉnh đó. Giá trị của một tập là tổng trọng số các đỉnh trên tập đó
// Yêu cầu: Tìm tập độc lập có giá trị lớn nhất
// Input
// • Dòng đầu tiên số nguyên n - số đỉnh của cây
// • Dòng thứ hai là n số, số thứ i là ai - trọng số của đỉnh i
// • n − 1 dòng tiếp theo, mỗi dòng gồm hai số (u, v) mô tả một cạnh của cây
// Output
// • Một số nguyên duy nhất là giá trị của tập độc lập tìm được
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define fod(i, a, b) for (int i = a; i >= b; i--)
#define nmax 1000005
#define nmax2 1000005
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e18
using namespace std;
const int mod = 1e9 + 7;
ll n, a[nmax], dp[nmax][2];
vector<int> p[nmax];
bool vs[nmax];
void dfs(int u)
{
    vs[u] = 1;
    for (auto v : p[u])
        if (!vs[v])
        {
            dfs(v);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    dp[u][1] += a[u];
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
    ll s = 0;
    fo(i, 1, n)
    {
        cin >> a[i];
        s += a[i];
    }
    fo(i, 1, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
}
