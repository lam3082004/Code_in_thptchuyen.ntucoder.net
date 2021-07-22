// Bờm có bộ bài gồm n lá bài được đánh số từ 1 đến n. Lá bài thứ i có ba thông số (ui
// , vi
// , ki). Phú
// Ông đưa cho Bờm một số nguyên dương s và đố Bờm chọn ra một số lá bài thỏa mãn:
//  Không chọn hai lá bài mà tổng thông số vi là một số nguyên tố.
//  Tổng thông số ui của tất cả các lá bài được chọn không nhỏ hơn s.
// Khi đó thông số ki lớn nhất trong các lá bài được chọn là số việc cần làm của Bờm trong ngày.
// Yêu cầu: Hãy giúp Bờm chọn các lá bài thỏa mãn yêu cầu của Phú Ông và số công việc của
// Bờm làm trong ngày là ít nhất.
// Dữ liệu cho trong file CARDTP.INP gồm:
//  Dòng đầu ghi hai số nguyên dương n và s.
//  n dòng tiếp theo, mỗi dòng ghi ba số nguyên dương ui
// , vi
// , ki mô tả ba thông số của một lá bài

// (ui
// , vi ≤ 106
// , ki ≤ n).

// Kết quả ghi ra file CARDTP.OUT là số việc ít nhất của Bờm cần làm trong ngày, nếu không có
// cách chọn bài thì ghi ra 0 (Bờm không phải làm việc gì trong ngày).
// Ví dụ:

// CARDTP.INP CARDTP.OUT
// 5 8
// 5 5 1
// 1 5 4
// 4 6 3
// 1 12 4
// 3 12 1

// 4

// Giải thích:
// Bờm có thể chọn ba lá bài ứng với ba bộ: (4, 6, 3); (1, 12, 4); (3, 12, 1), khi đó tổng thông số ui
// là: 4 + 1 + 3 = 8; tổng thông số vi của hai trong ba lá bài đều không là số nguyên tố; thông số ki
// lớn nhất bằng 4. Vậy kết quả là 4.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define __unique(V) (V).resize(unique((V).begin(), (V).end()) - (V).begin())
#define cntbit(X) __builtin_popcount((X))
#define bit(S, i) (((S) >> (i)) & 1)
#define PI acos(-1)
#define fi first
#define se second
#define LL long long
#define ii pair<int, int>
#define iii pair<int, ii>
#define eb emplace_back
#define TASK "cardtp"
using namespace std;
struct data
{
    int fr, to, capa, flow;
    data()
    {
        fr = to = capa = flow = 0;
    }
    data(int u, int v, int ca)
    {
        fr = u;
        to = v;
        flow = 0;
        capa = ca;
    }
    int isdelta(void)
    {
        return capa - flow;
    }
};
const int maxn = 2e6;
const int N = 1e6 + 5;
const int nn = 1e3 + 5;
vector<int> adj[N];
vector<data> Edge;
int cost[N], dist[N], vis[N];
int pr[N << 1], sour, sink, n, s;
int U[nn], V[nn], K[nn];
///--------------------------
void readf()
{
    cin >> n >> s;
    fo(i, 1, n) cin >> U[i] >> V[i] >> K[i];
}
///--------------------------
void sieve()
{
    memset(pr, 1, sizeof(pr));
    pr[0] = pr[1] = 0;
    for (int i = 2; i * i <= maxn; ++i)
        if (pr[i])
            for (int j = i * i; j <= maxn; j += i)
                pr[j] = 0;
}
///--------------------------
void addEdge(int u, int v, int ca)
{
    adj[u].eb(Edge.size());
    Edge.eb(u, v, ca);
    adj[v].eb(Edge.size());
    Edge.eb(v, u, ca);
}
///--------------------------
bool BFS()
{
    fo(i, 1, n) dist[V[i]] = -1;
    dist[sink] = -1;
    queue<int> qu;
    qu.push(sour);
    dist[sour] = 0;
    while (qu.size())
    {
        int u = qu.front();
        qu.pop();
        for (auto it : adj[u])
        {
            int v = Edge[it].to;
            if (dist[v] < 0 && Edge[it].isdelta() > 0)
            {
                dist[v] = dist[u] + 1;
                qu.push(v);
            }
        }
    }
    return dist[sink] >= 0;
}
///--------------------------
int DFS(int u, int delta)
{
    if (u == sink)
        return delta;
    for (; vis[u] < adj[u].size(); ++vis[u])
    {
        int it = adj[u][vis[u]];
        if (Edge[it].isdelta() <= 0)
            continue;
        int v = Edge[it].to;
        if (dist[v] == dist[u] + 1)
            if (int x = DFS(v, min(delta, Edge[it].isdelta())))
            {
                Edge[it].flow += x;
                Edge[it ^ 1].flow -= x;
                return x;
            }
    }
    return 0;
}
///--------------------------
bool check(int val)
{
    vector<int> arr;
    fo(i, 1, n) cost[V[i]] = 0, adj[V[i]].clear();
    fo(i, 1, n) if (K[i] <= val)
    {
        if (V[i] == 1)
            cost[V[i]] = max(cost[V[i]], U[i]);
        else
            cost[V[i]] += U[i];
        arr.eb(V[i]);
    }
    sort(arr.begin(), arr.end());
    __unique(arr);
    for (int i = 0; i < arr.size(); ++i)
        for (int j = 0; j < i; ++j)
            if (pr[arr[i] + arr[j]])
                addEdge(arr[i], arr[j], maxn);
    cost[sour] = cost[sink] = 0;
    adj[sour].clear();
    adj[sink].clear();
    int sum = 0;
    for (auto u : arr)
    {
        if (u & 1)
            addEdge(sour, u, cost[u]);
        else
            addEdge(u, sink, cost[u]);
        sum += cost[u];
    }
    int MinCut = 0;
    while (BFS())
    {
        while (1)
        {
            vis[sour] = vis[sink] = 0;
            for (auto u : arr)
                vis[u] = 0;
            int delta = DFS(sour, INT_MAX);
            if (delta == 0)
                break;
            MinCut += delta;
        }
    }
    return (sum - MinCut >= s);
}
///--------------------------
void solve()
{
    sour = 1e6 + 1;
    sink = 1e6 + 2;
    int dau = 1, cuoi = n, ans = 0;
    while (dau <= cuoi)
    {
        int mid = dau + cuoi >> 1;
        if (check(mid))
        {
            ans = mid;
            cuoi = mid - 1;
        }
        else
            dau = mid + 1;
    }
    cout << ans << '\n';
}
///--------------------------
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef TLH2203
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif // TLH2203
    sieve();
    readf();
    solve();
}
