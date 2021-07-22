// ADISTINCT
// Bờm là một chàng trai rất đam mê những bài toán với dãy số. Bờm không thích những dãy số có
// hai phần tử giống nhau nằm cạnh nhau, và gọi những dãy số có tính chất này là dãy xấu. Chính
// vì thế, hôm nay Bờm đặt ra bài toán như sau:
// Cho một dãy gồm n số nguyên. Đếm số dãy số khác nhau là hoán vị của dãy số trên, đồng thời
// không phải là dãy xấu. Hai hoán vị a và b được xem là khác nhau nếu tồn tại ít nhất một vị trí i
// sao cho ai 6= bi
// .
// Vì kết quả bài toán có thể rất lớn, Bờm chỉ muốn tìm số lượng dãy theo modulo 109 + 7. Tuy
// nhiên, Bờm chưa thể giải quyết được bài toán này. Là một lập trình viên tài năng, nhưng lại đang
// cô đơn và rảnh rỗi vì không có ai đi chơi giáng sinh cùng, bạn có thể giúp Bờm không?
// Dữ liệu
//  Dòng đầu tiên chứa số nguyên dương n là số số trong dãy (1  n  750).
//  Dòng thứ hai chứa n số nguyên dương a1; a2; :::; an miêu tả các số trong dãy (1  ai  n).
// Kết quả
//  Đưa ra một số nguyên duy nhất là kết quả bài toán theo modulo 109 + 7 trên một dòng
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
#define TASK "adistinct"
using namespace std;
const int maxn = 752;
const int mod = 1e9 + 7;
int n, a[maxn], C[maxn][maxn];
int dp[2][maxn * maxn];
///--------------------------
void readf()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a[x]++;
    }
}
///--------------------------
void combi()
{
    for (int i = 0; i < maxn; ++i)
        for (int j = i; j < maxn; ++j)
            if (i == 0 || i == j)
                C[i][j] = 1;
            else
                C[i][j] = (C[i - 1][j - 1] + C[i][j - 1]) % mod;
}
///--------------------------
void solve()
{
    combi();
    int s = 0;
    int last = 0, cur = 0, pos;
    for (int i = 1; i <= n; ++i)
        if (a[i] > 0)
        {
            pos = i;
            dp[last][a[i] - 1] = 1;
            s += a[i];
            break;
        }
    for (int i = pos + 1; i <= n; ++i)
        if (a[i] > 0)
        {
            cur ^= 1;
            for (int c = 0; c <= s + a[i]; ++c)
                dp[cur][c] = 0;
            for (int t = 1; t <= min(a[i], s + 1); ++t)
                for (int x = 0; x < s; ++x)
                    for (int y = max(0, t + x - s - 1); y <= min(x, t); ++y)
                    {
                        int tmp = dp[last][x];
                        tmp = 1LL * tmp * C[y][x] % mod;
                        tmp = 1LL * tmp * C[t - y][s + 1 - x] % mod;
                        tmp = 1LL * tmp * C[t - 1][a[i] - 1] % mod;
                        int &rs = dp[cur][x - y + a[i] - t];
                        rs = (rs + tmp) % mod;
                    }
            s += a[i];
            last ^= 1;
        }
    cout << dp[cur][0] << '\n';
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
    readf();
    solve();
}
