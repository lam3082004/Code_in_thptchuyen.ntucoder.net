// Cho đồ thị gồm 𝑛 đỉnh, ban đầu chưa có cạnh giữa các đỉnh.
// Có 𝑞 truy vấn, mỗi truy vấn thuộc một trong 3 loại sau:
//  1 𝑢 𝑣: thêm cạnh vô hướng 𝑢 − 𝑣, dữ liệu đảm bảo cạnh này không xuất hiện cho đến khi
// được thêm vào.
//  2 𝑢 𝑣: xóa cạnh vô hướng 𝑢 − 𝑣, dữ liệu đảm bảo cạnh này được xuất hiện cho đến khi bị
// xóa.
//  3 𝑢 𝑣: trả lời cho câu hỏi: 𝑢 và 𝑣 có thuộc cùng một thành phần liên thông không?
// Yêu cầu: Với mỗi truy vấn loại 3, bạn hãy đưa ra 𝑌𝐸𝑆 nếu như 𝑢 và 𝑣 thuộc cùng thành phần liên
// thông ở thời điểm đó, ngược lại in ra 𝑁𝑂.
// Input:
//  Dòng đầu tiên chứa hai số nguyên dương 𝑛 và 𝑞 (𝑛, 𝑞 ≤ 105).
//  Mỗi dòng trong 𝑞 dòng tiếp theo chứa ba số nguyên dương 𝑡, 𝑢, 𝑣 (1 ≤ 𝑡 ≤ 3; 1 ≤ 𝑢, 𝑣 ≤
// 𝑛) thể hiện các truy vấn.
// Output: Với mỗi truy vấn 3, in ra kết quả tương ứng trên một dòng
#include <bits/stdc++.h>
#define lo long long
#define KKH "DSUROLL"
#define fi first
#define se second
#define BIT(x, k) (((x) >> (k)) & 1)
#define rs(x, a) memset(x, (a), sizeof x)
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
const int gh = 1e5 + 6;
struct four
{
    int u, v, l, r;
} q[gh];
map<pair<int, int>, int> mp;
int l[gh], r[gh], n, t[gh], fa[gh], sz[gh];
vector<pair<int, int>> node[4 * gh];
inline int anc(int i)
{
    while (i != fa[i])
        i = fa[i];
    return i;
}
void join(stack<pair<int, int>> &stk, int u, int v)
{
    u = anc(u);
    v = anc(v);
    if (u == v)
        return;
    if (sz[u] > sz[v])
        swap(u, v);
    stk.push({u, fa[u]});
    stk.push({v, sz[v]});
    fa[u] = v;
    sz[v] += sz[u];
}
void build(int id, int i, int j, int u, int v, int l, int r)
{
    if (i > r || j < l)
        return;
    if (i >= l && j <= r)
    {
        node[id].push_back({u, v});
        return;
    }
    int giua = (i + j) >> 1;
    build(id << 1, i, giua, u, v, l, r);
    build(id << 1 | 1, giua + 1, j, u, v, l, r);
}
void chia(int id, int i, int j)
{
    stack<pair<int, int>> stk;
    for (auto x : node[id])
        join(stk, x.fi, x.se);
    if (i == j && t[i] == 3)
    {
        if (anc(l[i]) == anc(r[i]))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    if (i != j)
    {
        int giua = (i + j) >> 1;
        chia(id << 1, i, giua);
        chia(id << 1 | 1, giua + 1, j);
    }
    while (stk.size())
    {
        pair<int, int> tmp;
        tmp = stk.top();
        stk.pop();
        sz[tmp.fi] = tmp.se;
        tmp = stk.top();
        stk.pop();
        fa[tmp.fi] = tmp.se;
    }
}
int main()
{
    START();
    int T;
    cin >> n >> T;
    for (int i = 1; i <= n; ++i)
        fa[i] = i, sz[i] = 1;
    int id = 0;
    for (int i = 1; i <= T; ++i)
    {
        int &type = t[i], &u = l[i], &v = r[i];
        cin >> type >> u >> v;
        if (u > v)
            swap(u, v);
        if (type == 1)
            mp[{u, v}] = i;
        else if (type == 2)
            q[++id] = {u, v, mp[{u, v}], i}, mp[{u, v}] = -1;
    }
    for (auto x : mp)
        if (x.se != -1)
            q[++id] = {x.fi.fi, x.fi.se, x.se, T};
    //    for (int i=1;i<=id;i++)
    //        cout<<q[i].u<<' '<<q[i].v<<' '<<q[i].l<<' '<<q[i].r<<'\n';
    for (int i = 1; i <= id; ++i)
        build(1, 1, T, q[i].u, q[i].v, q[i].l, q[i].r);
    chia(1, 1, T);
}
