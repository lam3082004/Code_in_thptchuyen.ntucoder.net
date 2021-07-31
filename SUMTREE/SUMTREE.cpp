// Cây trong lý thuyết đồ thị là một đồ thị vô hướng, có trọng số, liên thông không chu
// trình. Một cây gồm N đỉnh sẽ có N − 1 cạnh nối giữa chúng.
// Yêu cầu: Cho một cây N đỉnh, bạn hãy tính tổng khoảng cách từ các đỉnh của đồ thị
// đến các đỉnh còn lại, Tức là với mỗi đỉnh u (1 ≤ u ≤ N), bạn phải tính tổng khoảng cách từ
// đỉnh u đến các đỉnh v của đồ thị (1 ≤ v ≤ N).
// Input:
// - Dòng đầu tiên chứa một số nguyên dương N (1 ≤ N ≤ 105
// )

// - N − 1 dòng tiếp theo, mỗi dòng chứa 3 số nguyên u, v, w biểu diễn cạnh nối giữa 2
// đỉnh u, v có trọng số là w. (1 ≤ u, v ≤ N, u ≠ v, 1 ≤ w ≤ 106
// ).

// Output: Xuất ra trên N dòng, dòng thứ i là tổng khoảng cách từ đỉnh i đến các đỉnh
// trên đồ thị.
// Subtask:
//  Subtask 1 (40%): n ≤ 1000
//  Subtask 2 (60%): Ràng buộc gốc
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, u, v, temp;
vector<int> adj[112345], weigh[112345];

int child[112345], res[112345], pen[112345], ans[112345];
void dfs(int at, int par)
{
    child[at] = 0;
    res[at] = 0;
    for (int i = 0; i < adj[at].size(); i++)
    {
        int to = adj[at][i];
        if (to == par)
            continue;
        dfs(to, at);
        child[at] += child[to] + 1;
        res[at] += res[to] + weigh[at][i] * (child[to] + 1);
    }
}

void dfs_ngu(int at, int par)
{
    ans[at] = pen[at] + res[at];
    for (int i = 0; i < adj[at].size(); i++)
    {
        int to = adj[at][i];
        if (to == par)
            continue;
        pen[to] = weigh[at][i] * (child[1] - child[to]) + pen[at] + res[at] - res[to] - weigh[at][i] * (child[to] + 1);
        dfs_ngu(to, at);
    }
}

int32_t main()
{
    memset(ans, 0, sizeof(ans));
    memset(pen, 0, sizeof(pen));
    memset(res, 0, sizeof(res));
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> temp;
        adj[u].push_back(v);
        adj[v].push_back(u);
        weigh[u].push_back(temp);
        weigh[v].push_back(temp);
    }
    dfs(1, 0);
    dfs_ngu(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
}
