// BONUS2 - PHẦN THƯỞNG 2
// Tuấn là người chiến thắng trong một cuộc thi "Tìm hiểu kiến thức vũ trụ" và được nhận các
// phần thưởng do công ty XYZ tài trợ. Các phần thưởng được bố trí trên một bảng hình vuông m×n
// có dạng một lưới ô vuông kích thước đơn vị. Các dòng của bảng được đánh số từ 1 đến m, từ trên
// xuống dưới và các cột của bảng được đánh số từ 1 đến n, từ trái qua phải. Ô nằm trên giao của
// dòng i và cột j được gọi là ô (i, j) và trên ô đó chứa một món quà có giá trị là aij
// Để nhận phần thưởng, Tuấn được phép chọn hai hình vuông kích thước k × k không giao nhau
// chiếm trọn trong một số ô của bảng và nhận tất cả các phần quà có trong các ô nằm trong hình
// vuông đó.
// Yêu cầu: Hãy xác định tổng giá trị lớn nhất của món quà mà Tuấn có thể nhận được.
// Input
// • Dòng thứ nhất chứa ba số nguyên dương m, n, k
// • Dòng thứ i trong số m dòng tiếp theo chứa n số nguyên, số thứ j là aij
// Output
// • Ghi ra một số nguyên duy nhất là tổng giá trị lớn nhất của các món quà mà Tuấn có thể nhận
// được.
// Giới hạn
// • 1 ≤ m, n ≤ 1500
// • k đảm bảo có thể chọn được 2 hình vuông
// • 0 ≤ aij ≤ 500
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define fod(i, a, b) for (int i = a; i >= b; i--)
#define nmax 1000005
#define ii pair<int, int>
#define fi first
#define se second
#define oo 1e18
using namespace std;
const int mod = 1e9 + 7;
ll t, m, n, k, a[1505][1505], f[1505][1505], dp[1505][1505];
ll s(ll x, ll y, ll u, ll v)
{
    return f[u][v] - f[x - 1][v] - f[u][y - 1] + f[x - 1][y - 1];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("new.inp", "r", stdin);
    freopen("new.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> k;
    fo(i, 1, m)
        fo(j, 1, n)
    {
        cin >> a[i][j];
        f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
    }
    memset(dp, -0x3f, sizeof(dp));
    fo(i, k, m)
        fo(j, k, n)
            dp[i][j] = max({dp[i][j - 1], dp[i - 1][j], s(i - k + 1, j - k + 1, i, j)});
    //    fo(i,k,m)
    //    {
    //        fo(j,k,n)
    //            cout<<dp[i][j]<<' ';
    //        cout<<'\n';
    //    }
    ll ans = -oo;
    fo(i, k, m)
        fo(j, k, n)
            ans = max(ans, s(i - k + 1, j - k + 1, i, j) + max(dp[m][j - k], dp[i - k][n]));
    cout << ans;
}
