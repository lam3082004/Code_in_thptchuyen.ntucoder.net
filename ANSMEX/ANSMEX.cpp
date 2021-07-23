// Cho dãy nguyên dương gồm 𝑛 phần tử 𝑎1, 𝑎2, … , 𝑎𝑛. Bạn có hai loại truy vấn:
// 1. Cho cặp số nguyên 𝑙 và 𝑟 (1 ≤ 𝑙 ≤ 𝑟 ≤ 𝑛): gọi 𝑐𝑥 là số lần xuất hiện của giá trị 𝑥 trong tập
// giá trị {𝑎𝑙
// , 𝑎𝑙+1, …, 𝑎𝑟
// }. Tính 𝑀𝑒𝑥{𝑐0, 𝑐1, …, 𝑐109 }.
// 2. Cho cặp số nguyên 𝑝 và 𝑥. Gán 𝑎𝑝 = 𝑥.
// Giá trị 𝑀𝑒𝑥 của một tập hợp là giá trị nguyên không âm nhỏ nhất không xuất hiện trong tập hợp
// đó.
// Như vậy có thể biết được giá trị 𝑀𝑒𝑥 trong truy vấn thứ nhất luôn là một giá trị nguyên dương vì
// 𝑐0 = 0.
// Yêu cầu: In ra giá trị 𝑀𝑒𝑥 với các truy vấn thứ nhất.
// Input:
//  Dòng đầu tiên chứa hai số nguyên dương 𝑛 và 𝑞 (1 < 𝑛, 𝑞 ≤ 105).
//  Dòng thứ hai chứa 𝑛 số nguyên dương 𝑎1, 𝑎2, … , 𝑎𝑛
// (𝑎𝑖 ≤ 109).
//  Dòng thứ 𝑖 trong 𝑞 dòng tiếp theo gồm:
// o Nếu là truy vấn loại một, gồm ba số nguyên dương 𝑡𝑖 = 1,𝑙𝑖 và 𝑟𝑖
// (1 ≤ 𝑙𝑖 ≤ 𝑟𝑖 ≤
// 𝑛).
// o Nếu là truy vấn loại hai, gồm ba số nguyên dương 𝑡𝑖 = 2, 𝑝𝑖 và 𝑥𝑖
// (1 ≤ 𝑝𝑖 ≤ 𝑛; 1 ≤
// 𝑥 ≤ 109).
// Output: In ra kết quả với mỗi truy vấn loại một, mỗi kết quả in trên một dòng.
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
#define TASK "940F"
using namespace std;
const int sq = 2154;
const int sz = 632;
const int maxn = 1e5 + 5;
struct query
{
    int time, L, R, id;
    query()
    {
        time = L = R = id = 0;
    }
    query(int x, int y, int z, int t)
    {
        time = x;
        L = y;
        R = z;
        id = t;
    }
    bool operator<(const query &A) const
    {
        if (time / sq != A.time / sq)
            return time < A.time;
        if (L / sq != A.L / sq)
            return L < A.L;
        return R < A.R;
    }
};
vector<query> qu;
vector<int> V;
int n, q, a[maxn], tp[maxn], l[maxn], r[maxn];
ii nxt[maxn], pre[maxn];
int cnt[maxn << 1], slcnt[maxn], ans[maxn];
///--------------------------
void readf()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        V.eb(a[i]);
    }
    for (int i = 1; i <= q; ++i)
    {
        cin >> tp[i] >> l[i] >> r[i];
        if (tp[i] == 2)
            V.eb(r[i]);
    }
    sort(V.begin(), V.end());
    __unique(V);
}
///--------------------------
inline int change(int x)
{
    return upper_bound(V.begin(), V.end(), x) - V.begin();
}
///--------------------------
inline void update(int val, int type)
{
    slcnt[cnt[val]]--;
    cnt[val] += type;
    slcnt[cnt[val]]++;
}
///--------------------------
inline bool inside(int a, int b, int c)
{
    return b <= a && a <= c;
}
///--------------------------
void mov(int L1, int R1, int T1, int L2, int R2, int T2)
{
    if (T1 < T2)
    {
        for (int i = T1; i < T2; ++i)
        {
            if (inside(nxt[i].fi, L1, R1))
                update(a[nxt[i].fi], -1);
            a[nxt[i].fi] = nxt[i].se;
            if (inside(nxt[i].fi, L1, R1))
                update(a[nxt[i].fi], 1);
        }
    }
    if (T1 > T2)
    {
        for (int i = T1; i > T2; --i)
        {
            if (inside(pre[i].fi, L1, R1))
                update(a[pre[i].fi], -1);
            a[pre[i].fi] = pre[i].se;
            if (inside(pre[i].fi, L1, R1))
                update(a[pre[i].fi], 1);
        }
    }
    if (R1 < R2)
        for (int i = R1 + 1; i <= R2; ++i)
            update(a[i], 1);
    else
        for (int i = R2 + 1; i <= R1; ++i)
            update(a[i], -1);
    if (L1 < L2)
        for (int i = L1; i <= L2 - 1; ++i)
            update(a[i], -1);
    else
        for (int i = L2; i <= L1 - 1; ++i)
            update(a[i], 1);
}
///--------------------------
int what_mex()
{
    for (int i = 1; i < sz; ++i)
        if (slcnt[i] == 0)
            return i;
}
///--------------------------
void solve()
{
    for (int i = 1; i <= n; ++i)
        a[i] = change(a[i]);
    int tm = 0;
    for (int i = 1; i <= q; ++i)
    {
        if (tp[i] == 1)
            qu.eb(tm, l[i], r[i], i);
        if (tp[i] == 2)
        {
            r[i] = change(r[i]);
            nxt[tm++] = ii(l[i], r[i]);
            pre[tm] = ii(l[i], a[l[i]]);
            a[l[i]] = r[i];
        }
    }
    for (int i = 1; i <= q; ++i)
        if (tp[i] == 2)
        {
            a[pre[tm].fi] = pre[tm].se;
            tm--;
        }
    sort(qu.begin(), qu.end());
    int x = 1, y = 1, tg = 0;
    update(a[x], 1);
    for (auto it : qu)
    {
        mov(x, y, tg, it.L, it.R, it.time);
        x = it.L;
        y = it.R;
        tg = it.time;
        ans[it.id] = what_mex();
    }
    for (int i = 1; i <= q; ++i)
        if (ans[i] > 0)
            cout << ans[i] << '\n';
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
