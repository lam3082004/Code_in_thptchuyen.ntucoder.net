// Yêu cầu: Trong lớp học có n học sinh và m cặp học sinh là bạn bè của nhau. Nhiệm vụ của bạn là chia lớp học thành 2 nhóm, sao cho các học sinh trong cùng 1 nhóm không phải là bạn trực tiếp của nhau. Nếu có cách chia thỏa mãn thì in ra "Yes", không thì in ra "No".

// Lưu ý: Bạn của bạn chưa chắc đã là bạn.

// Input:

// Dòng đầu tiên chứa 2 số nguyên dương n,m là số lượng học sinh và số lượng cặp là bạn bè của nhau. (n<=105, m<=2*105)
// m dòng tiếp theo, mỗi dòng gồm 2 số nguyên dương u,v biểu thị 2 học sinh u,v là bạn bè của nhau.
// Output: 1 dòng duy nhất là Yes hoặc No.
#include <bits/stdc++.h>
using namespace std;
#define nmax 100100
int vs[nmax];
vector<int> adj[nmax];
int n, m;
vector<int> d[2];
void BFS(int root)
{
    if (vs[root] != -1)
        return;
    vs[root] = 0;
    d[0].push_back(root);
    queue<int> q;
    q.push(root);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if (v == u)
                continue;
            //if(check[v]) continue;
            if (vs[v] == vs[u])
            {
                cout << "No";
                exit(0);
            }
            if (vs[v] == 1 - vs[u])
                continue;
            vs[v] = 1 - vs[u];
            d[vs[v]].push_back(v);
            q.push(v);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    //n la so dinh
    d[0].clear();
    d[1].clear();
    memset(vs, -1, sizeof(vs));
    for (int i = 1; i <= n; i++)
        adj[i].clear();
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        BFS(i);
    cout << "Yes";
    return 0;
}
