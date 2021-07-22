// JUSTIN BIEBER
// Một em bé đang cố gắng giải bài toán 8 quân hậu kinh điển: đặt 8 quân hậu trên
// bàn cờ vua kích thước 8 x 8 ô vuông sao cho không có bất kì hai quân hậu nào
// nằm trên cùng một cột, hàng, hoặc đường chéo (nói cách khác, hai quân hậu ấy
// không thể “ăn” nhau). Em bé hiểu khái niệm hàng và cột rất rõ song đường chéo
// thì còn nhiều khúc mắc. Em đã thành công với việc đặt 8 quân hậu sao cho không
// có hai quân hậu nào nằm trên cùng hàng hoặc cột nhưng vẫn có khả năng một
// vài quân hậu đang nằm trên một đường chéo.
// Sau khi em sắp xếp xong, em đã đưa kết quả này cho các bạn trẻ tham gia Free
// Contest 10, ngoài ra, BTC của cuộc thi còn cung cấp cho các thí sinh đáp án của
// bài toán quân hậu trên. Em bé nhờ các bạn rằng, từ bàn cờ mà em vừa sắp xếp,
// hãy thực hiện một số ít nhất các di chuyển các quân hậu để đưa về đáp án mà
// các bạn đã được cung cấp.
// Biết rằng từ kết quả của em bé, có thể di chuyển các quân hậu để trở thành kết
// quả đúng. Giả sử trong một bước, một quân hậu có thể đi đúng 1 ô dọc theo hàng
// hoặc cột để đến một ô trống khác trong bàn cờ.
// Hãy giúp em bé, với trường hợp tổng quát cho bàn cờ kích thước N x N.

// Dữ liệu:
//  Có nhiều test trong cùng một input
//  Mỗi test bắt đầu bằng số N (3 < N < 17). Tiếp đó là hai dòng, mỗi dòng có
// N số. Dòng thứ nhất của test gồm các số a1, a2, ... , an cho biết cách xếp quân
// hậu thứ i của em bé được đặt ở cột ai, hàng thứ i. Tương tự như thế, dòng thứ
// hai của test gồm các số b1, b2, ... , bn cho biết cách xếp quân hậu đúng mà bạn
// cần biến đổi bàn cờ ban đầu đến trạng thái đó.
//  Kết thúc của input là một số 0.

// Kết quả : Với mỗi test, in ra một dòng duy nhất đưa ra số bước di chuyển quân
// hậu. Các kết quả của các test nên được phân cách bởi dấu xuống dòng.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define __unique(V) (V).resize(unique((V).begin(), (V).end()) - (V).begin())
#define cntbit(X) __builtin_popcount((X))
#define bit(S, i) (((S) >> (i - 1)) & 1)
#define PI acos(-1)
#define fi first
#define se second
#define LL long long
#define ii pair<int, int>
#define iii pair<int, ii>
#define eb emplace_back
#define TASK "justin"
using namespace std;
const int maxn = 20, maxbit = (1 << 18);
int n, a[maxn], b[maxn], dp[maxbit][maxn];
vector<int> S[maxn];
///--------------------------
void readf()
{
    fo(i, 1, n) cin >> a[i];
    fo(i, 1, n)
    {
        int x;
        cin >> x;
        b[x] = i;
    }
}
///--------------------------
void solve()
{
    int frq = (1 << n) - 1;
    for (int i = 0; i < n; ++i)
        S[i].clear();
    for (int mask = 0; mask <= (frq); ++mask)
        S[cntbit(mask)].eb(mask);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
        for (auto mask : S[i])
            for (int j = 1; j <= n; ++j)
                if (bit(mask, j))
                    dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << (j - 1))][i - 1] + abs(a[i] - j) + abs(b[j] - i));
    cout << dp[frq][n] << '\n';
}
///--------------------------
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif // ONLINE_JUDGE
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        readf();
        solve();
    }
}
