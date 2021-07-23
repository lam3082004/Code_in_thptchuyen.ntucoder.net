// Cho một xâu S chỉ chứa các kí tự chữ cái latin in thường, hãy tìm xâu con đối xứng dài nhất của nó.
// Xâu con của một xâu là xâu thu được sau khi xóa một số kí tự của xâu đấy.
// Dữ liệu
// • Dòng đầu ghi một số nguyên dương N là độ dài xâu S.
// • Dòng hai ghi xâu S.
// Kết quả
// • In ra một số duy nhất độ dài xâu con đối xứng lớn nhất tìm được, nếu độ dài đấy lớn hơn 500 thì
// chỉ cần xuất ra 500.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define fi first
#define se second
#define LL long long
#define uint unsigned int
#define pb push_back
#define eb emplace_back
#define bit(s, i) ((s >> i) & 1)
#define off(s, i) (s & (~(1 << i)))
#define ii pair<int, int>
#define iii1 pair<ii, int>
#define iii2 pair<int, ii>
#define TASK "PALAGAIN"
using namespace std;
int n, f[10010][510], nxt[10010][140];
string s, x;
///--------------------------
void readf()
{
    cin >> n >> s;
    for (int i = 0; i < s.size(); ++i)
        x += s[s.size() - i - 1];
}
///--------------------------
void solve()
{
    s = " " + s;
    x = " " + x;
    for (int j = 'a'; j <= 'z'; ++j)
        nxt[n + 2][j] = nxt[n + 1][j] = n + 1;
    for (int i = n; i > 0; --i)
    {
        for (int j = 'a'; j <= 'z'; ++j)
            nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i]] = i;
    }
    for (int i = 0; i <= n; ++i)
        for (int j = 1; j <= min(n, 500); ++j)
            f[i][j] = n + 1;
    for (int j = 1; j <= min(500, n); ++j)
        for (int i = j; i <= n; ++i)
            f[i][j] = min(f[i - 1][j], nxt[f[i - 1][j - 1] + 1][x[i]]);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= min(500, n); ++j)
            if (f[i][j] < n + 1)
                ans = max(ans, j);
    cout << ans;
}
///--------------------------
int main()
{
#ifdef BDP0509
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    readf();
    solve();
}
