// Một cửa hàng có
// n
//  loại mặt hàng, mỗi mặt hàng có giá trị là
// v
// i
// , trọng lượng
// w
// i
//  và có số lượng
// a
// i
// . Với 1 chiếc túi có thể đựng trọng lượng tối đa là
// W
// . Hãy tính tổng giá trị các mặt hàng lớn nhất bạn có thể mang.

// Dữ liệu vào:

// - Dòng đầu tiên là 2 số nguyên dương
// n
//  và
// W
// (
// n
// ≤
// 100
// ,
// W
// ≤
// 10
// 4
// )
// .

// -
// n
//  dòng tiếp theo gồm 3 số
// w
// i
// ,
// v
// i
//  và
// a
// i

// (
// 1
// ≤
// w
// i
// ,
// v
// i
// ,
// a
// i
// ≤
// 1000
// )
// .

// Dữ liệu ra:

// - Gồm 1 dòng là tổng giá trị các mặt hàng lớn nhất bạn có thể mang.
#include <bits/stdc++.h>
using namespace std;
int n, m;
int w[123456], v[123456];
int dp[10001][10001];
int nn = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int nw, nv, na;
        cin >> nw >> nv >> na;
        int pre = 1;
        while (pre <= na)
        {
            nn++;
            w[nn] = pre * nw;
            v[nn] = pre * nv;
            na -= pre;
            pre *= 2;
        }
        if (na > 0)
        {
            nn++;
            w[nn] = na * nw;
            v[nn] = na * nv;
        }
    }
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= nn; i++)
    {
        for (int j = 0; j <= m; j++)
            if (w[i] <= j)
            {
                dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
    }
    cout << dp[nn][m];
}
