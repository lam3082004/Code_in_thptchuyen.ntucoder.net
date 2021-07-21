// Cho một đồ thị gồm 𝑛 đỉnh và 𝑛.(𝑛−1)
// 2
// cạnh (mọi cặp 𝑖 và 𝑗 (𝑖 ≠ 𝑗) đều có cạnh nối), mỗi đỉnh được
// gán một nhãn mang giá trị không âm 𝑎𝑖
// . Trọng số của cạnh giữa hai đỉnh 𝑖 và 𝑗 (𝑖 ≠ 𝑗) là giá trị
// (𝑎𝑖 𝑥𝑜𝑟 𝑎𝑗).
// Yêu cầu: Tính giá trị cây khung nhỏ nhất của đồ thị.
// Input:
//  Dòng đầu chứa số nguyên dương 𝑛 (𝑛 ≤ 2.105).
//  Dòng thứ hai chứa 𝑛 số nguyên 𝑎1, 𝑎2, … , 𝑎𝑛
// (0 ≤ 𝑎𝑖 < 2
// 30).
// Output: In ra kết quả bài toán'
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
#define TASK "888G"
using namespace std;
const int mbit = 29;
struct trie
{
    trie *node[2];
    int cnt[2];
    trie()
    {
        memset(node, NULL, sizeof(node));
        memset(cnt, 0, sizeof(cnt));
    }
};
trie *root;
const int maxn = 2e5 + 5;
int n, a[maxn];
///--------------------------
void readf()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
}
///--------------------------
void push(int x)
{
    trie *p;
    p = root;
    for (int i = mbit; i >= 0; --i)
    {
        bool tmp = bit(x, i);
        if (p->node[tmp] == NULL)
            p->node[tmp] = new (trie);
        p = p->node[tmp];
        p->cnt[tmp]++;
    }
}
///--------------------------
int mini(int x, int dep, trie *p)
{
    int ans = 0;
    for (int i = dep; i >= 0; --i)
    {
        bool tmp = bit(x, i);
        if (p->node[tmp] != NULL)
        {
            p = p->node[tmp];
            ans <<= 1;
        }
        else
        {
            p = p->node[tmp ^ 1];
            ans = ans << 1 | 1;
        }
    }
    return ans;
}
///--------------------------
LL cal(int l, int r, int dep, trie *p)
{
    if (dep == 0)
    {
        if (p->node[0] == NULL || p->node[1] == NULL)
            return 0;
        return 1;
    }
    if (p->node[0] == NULL || p->node[1] == NULL)
    {
        if (p->node[0] != NULL)
            return cal(l, r, dep - 1, p->node[0]);
        return cal(l, r, dep - 1, p->node[1]);
    }
    int mid = 0;
    for (int i = l; i < r; ++i)
        if (bit(a[i + 1], dep) == 1)
        {
            mid = i;
            break;
        }
    int ans = a[l] ^ a[mid + 1];
    for (int i = l; i <= mid; ++i)
        ans = min(ans, mini(a[i] % (1 << dep),
                            dep - 1, p->node[1]) +
                           (1 << dep));
    return 0LL + ans + cal(l, mid, dep - 1, p->node[0]) +
           cal(mid + 1, r, dep - 1, p->node[1]);
}
///--------------------------
void solve()
{
    root = new (trie);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        push(a[i]);
    cout << cal(1, n, mbit, root) << '\n';
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
    readf();
    solve();
}
