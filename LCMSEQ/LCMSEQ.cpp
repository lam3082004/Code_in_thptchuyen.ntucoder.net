// Son là một học sinh rất giỏi toán. Anh ta rất yêu thích các bài toán liên quan đến bội chung nhỏ
// nhất. Son định nghĩa bội chung nhỏ nhất của một dãy là bội chung nhỏ nhất của tất cả các số
// trong dãy đó. Son tự mình đặt ra bài toán sau:
// Trong các dãy số dương có tổng bằng n, tìm dãy số có bội chung nhỏ nhất lớn nhất.
// Tuy là tác giả nhưng Son vẫn chưa giải quyết được bài toán này. Bạn hãy giúp Son nhé.
// Dữ liệu
// • Gồm một dòng duy nhất chứa số nguyên dương n không vượt quá 350.
// Kết quả
// • Gồm một số nguyên duy nhất là bội chung nhỏ nhất của dãy số thỏa mãn yêu cầu bài toán.
// Dữ liệu đảm bảo kết quả bài toán không vượt quá kiểu dữ số nguyên 64bit.
// Giới hạn
// • 30% số test ứng với 30% số điểm có 1 ≤ n ≤ 100 .
// • 70% số test còn lại ứng với 70% số điểm không có giới hạn gì thêm.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define fi first
#define se second
#define LL unsigned long long
#define pb push_back
#define eb emplace_back
#define bit(s, i) ((s >> i) & 1)
#define off(s, i) (s & (~(1 << i)))
#define ii pair<int, int>
#define TASK "LCMSEQ"
using namespace std;
int n, k, nt[360], pc[360];
LL f[360][360];
LL __lcm(LL a, LL b)
{
    return a / __gcd(a, b) * b;
}
///--------------------------
void readf()
{
    cin >> n;
}
///--------------------------
void solve()
{
    memset(nt, true, sizeof(nt));
    nt[1] = false;
    fo(i, 2, n) if (nt[i])
        fo(j, 2, n / i) nt[i * j] = false;
    k = 0;
    fo(i, 1, n) if (nt[i]) pc[++k] = i;
    fo(i, 0, n)
        fo(j, 0, k) f[i][j] = 1;
    fo(j, 1, k)
        fo(i, 1, n)
    {
        f[i][j] = f[i][j - 1];
        LL x = 1;
        while (x <= i)
        {
            f[i][j] = max(f[i][j], __lcm(f[i - x][j - 1], x));
            x *= pc[j];
        }
    }
    cout << f[n][k];
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
