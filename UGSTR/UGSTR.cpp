// Một xâu 𝐴 được gọi là chứa xâu 𝐵 nếu tồn tại (𝑖,𝑗) mà 1 ≤ 𝑖 ≤ 𝑗 ≤ |𝐴| mà 𝐵 = 𝐴𝑖𝐴𝑖+1 … 𝐴𝑗
// .
// Cho 𝑛 xâu 𝑠1, 𝑠2, …, 𝑠𝑛 chỉ gồm các chữ cái latinh thường.
// Một xâu được gọi là xấu xí nếu như nó không chứa bất kì xâu nào trong các xâu 𝑠1, 𝑠2, … , 𝑠𝑛.
// Yêu cầu: Cho số nguyên dương 𝑘. Bạn hãy đếm số lượng xâu độ dài 𝑘 chỉ gồm các chữ cái latinh
// thường và không phải là xâu xấu xí.
// Input:
//  Dòng đầu chứa hai số nguyên dương 𝑛 và 𝑘 (𝑛, 𝑘 ≤ 1000).
//  Dòng thứ 𝑖 trong 𝑛 dòng tiếp theo chứa duy nhất một xâu kí tự 𝑠𝑖
// (|𝑠𝑖
// | ≤ 1000) − Dữ liệu
// đảm bảo ∑ |𝑠𝑖 1≤
// | ≤ 1000.
// 𝑖≤𝑛
// Output: In ra kết quả bài toán sau khi chia lấy dư cho 109
// .
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
#define TASK "UGSTR"
using namespace std;
const int mod = 1000000000;
const int maxn = 1005;
const int maxc = 30;
int trie[maxn][maxc], link[maxn], go[maxn][maxc];
int cur, n, m, dp[maxn][maxn][2];
bool terminal[maxn];
///--------------------------
void push(string s, int p)
{
    for (auto c : s)
    {
        int tmp = c - 'a';
        if (trie[p][tmp] == 0)
            trie[p][tmp] = ++cur;
        p = trie[p][tmp];
    }
    terminal[p] = 1;
}
///--------------------------
void build_aho()
{
    queue<int> bfs;
    bfs.push(0);
    link[0] = 0;
    while (bfs.size())
    {
        int u = bfs.front();
        bfs.pop();
        if (terminal[link[u]])
            terminal[u] = 1;
        for (int c = 0; c < 26; ++c)
        {
            go[u][c] = go[link[u]][c];
            if (trie[u][c])
            {
                link[trie[u][c]] = go[u][c];
                go[u][c] = trie[u][c];
                bfs.push(trie[u][c]);
            }
        }
    }
}
///--------------------------
inline void cong(int &A, int B)
{
    A = (A + B) % mod;
}
///--------------------------
void solve()
{
    cin >> n >> m;
    cur = 0;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        push(s, 0);
    }
    build_aho();
    dp[0][0][0] = 1;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j <= cur; ++j)
            for (int ok = 0; ok < 2; ++ok)
                for (int c = 0; c < 26; ++c)
                {
                    int k = go[j][c];
                    cong(dp[i + 1][k][ok || terminal[k]], dp[i][j][ok]);
                }
    int ans = 0;
    for (int i = 0; i <= cur; ++i)
        cong(ans, dp[m][i][1]);
    cout << ans << '\n';
}
///--------------------------
int main()
{
    srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef TLH2203
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif // TLH2203
    solve();
}
