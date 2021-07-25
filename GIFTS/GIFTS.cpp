// SloW MoTioN là một lập trình viên đam mê lập trình thi đấu và rất hay tham gia Free Contest.
// Tuy rất giỏi, có nhiều ý tưởng táo bạo trong lập trình nhưng anh lại là một người rất nhát gái.
// Trùng hợp thay, hôm nay là sinh nhật của Free Contest và cũng là sinh nhật của cô gái mà anh
// thương thầm bao năm nay. Vì thế, anh ta muốn tặng cho anh Kiên, cha đẻ của Free Contest cũng
// như Crush của mình mỗi người một khoảng bánh.
// SloW MoTioN có một dải bánh gồm n chiếc bánh, mỗi chiếc bánh có một và chỉ một màu sắc. Là
// một người không thích sự tẻ nhạt, SLoW MoTioN muốn tặng cho anh Kiên và Crush của mình
// 2 khoảng bánh rời nhau (mỗi khoảng bánh là một đoạn con liên tiếp của dải bánh) sao cho mỗi
// chiếc bánh trong các khoảng bánh đó có màu riêng biệt (và cũng khác với những chiếc bánh trong
// khoảng bánh của người còn lại).
// SLoW MoTioN cũng là một người rất thích sự hoành tráng, vì vậy anh ta muốn cực đại hóa tổng
// độ dài hai khoảng bánh sẽ làm quà tặng. Nhưng độ dài dải bánh ban đầu rất lớn, có thể lên đến
// 103 nên anh ta cần sự trở giúp của bạn để có thể tính tổng độ dài hai khoảng bánh sẽ tặng anh
// Kiên và Crush của mình.
// Dữ liệu
// • Dòng đầu tiên là số bộ dữ liệu T (T ≤ 10)
// • Mỗi bộ dữ liệu gồm 2 dòng
// – Dòng đầu chứa độ dài dải bánh n (n ≤ 1000)
// – Dòng thứ hai chứa n số nguyên dương C1, C2, ..., Cn là màu sắc của n chiếc bánh.
// (Ci ≤ 105
// )
// Kết quả
// • In ra T số nguyên trên T dòng là kết quả của các bộ dữ liệu
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
#define TASK "gifts"
using namespace std;
multiset<int, greater<int>> cost;
multiset<int, greater<int>>::iterator ic;
set<int> pos;
set<int>::iterator ip;
const int maxn = 1e3 + 5;
vector<int> V[maxn], R;
bool ok[maxn];
int dp[maxn][maxn], a[maxn], n;
///--------------------------
void readf()
{
    cin >> n;
    R.clear();
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        R.eb(a[i]);
    }
    sort(R.begin(), R.end());
    __unique(R);
    for (int i = 1; i <= n; ++i)
        a[i] = upper_bound(R.begin(), R.end(), a[i]) - R.begin();
    memset(dp, 0, sizeof(dp));
    memset(ok, 0, sizeof(ok));
    for (int i = 0; i < maxn; ++i)
        V[i].clear();
    for (int i = 1; i <= n; ++i)
    {
        V[a[i]].eb(i);
    }
}
///--------------------------
void DEL(int p)
{
    ip = pos.lower_bound(p);
    int R = (*ip);
    ip--;
    int L = (*ip);
    pos.insert(p);
    ic = cost.find(dp[L + 1][R - 1]);
    cost.erase(ic);
    cost.insert(dp[L + 1][p - 1]);
    cost.insert(dp[p + 1][R - 1]);
}
///--------------------------
void solve()
{
    ///----------- predp
    for (int i = 1; i <= n; ++i)
    {
        memset(ok, 0, sizeof(ok));
        for (int j = i; j <= n; ++j)
            if (ok[a[j]])
                break;
            else
            {
                dp[i][j] = j - i + 1;
                ok[a[j]] = 1;
            }
    }
    for (int i = n; i > 0; --i)
        for (int j = i; j <= n; ++j)
            dp[i][j] = max(dp[i][j], max(dp[i + 1][j], dp[i][j - 1]));
    ///------------------
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        memset(ok, 0, sizeof(ok));
        cost.clear();
        pos.clear();
        pos.insert(0);
        pos.insert(n + 1);
        cost.insert(dp[1][n]);
        for (int j = i; j <= n; ++j)
            if (ok[a[j]])
                break;
            else
            {
                ok[a[j]] = 1;
                for (auto x : V[a[j]])
                    DEL(x);
                ans = max(ans, j - i + 1 + (*cost.begin()));
            }
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
    int T;
    cin >> T;
    while (T--)
    {
        readf();
        solve();
    }
}
