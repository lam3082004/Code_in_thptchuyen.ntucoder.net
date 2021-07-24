// Trong khi chị gái mình say sưa với các phép toán thì cậu em trai Mr Bin lại thích thú với nghề xây dựng. Trước cửa nhà Mr Bin có một cái hồ rất rộng gọi là hồ sinh thái Vinh Tân. Giữa hồ có một hòn đảo nhỏ. Một lần Mr Bin nảy ra ý định bắc một cái cầu từ cửa nhà mình đến đảo giữa hồ để kinh doanh du lịch. Một vấn đề khá hóc búa đối với Mr Bin là làm thế nào xác định được khoảng cách từ nhà mình đển đảo giữa hồ?.

// Có thể mô tả đảo giữa hồ như là một đa giác lồi còn nhà của Mr Bin như là một điểm nằm ngoài đa giác đó trên mặt phẳng toạ độ. Bạn hãy lập trình giúp Mr Bin tính khoảng cách nhỏ nhất từ nhà mình đến đảo.

// Dữ liệu:

// Dòng đầu tiên ghi N là số đỉnh của đa giác (N≤1500)
// Dòng thứ hai ghi toạ độ của điểm được xem như là nhà của Mr Bin
// Tiếp theo là N dòng, mỗi dòng liệt kê toạ độ của một đỉnh của đa giác. Các đỉnh của đa giác được liệt kê ngược theo chiều kim đồng hồ.
// Tất cả các toạ độ đều có trị tuyệt đối không vượt quá 50000
// Kết quả:  một số thực duy nhất là khoảng cách từ nhà của Mr Bin đến đảo giữa hồ (giữ lại 4 chữ số phần thập phân)
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ld long double
using namespace std;
struct point
{
    ll x, y;
};
ll kc(point A, point B)
{
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}
ld dg(ll b, ll c, ll a)
{
    if (a + b > c && a + c > b)
    {
        ld x = (ld)(c + a - b) * (c + a - b) / (4 * a);
        return (ld)sqrt(c - x);
    }
    else
        return (ld)min(b, c);
}
ll n, t, s[1505];
point A, M[1505];
ld minn = 1e9;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("CAU.inp", "r", stdin);
    freopen("CAU.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> A.x >> A.y;
    fo(i, 1, n)
    {
        cin >> M[i].x >> M[i].y;
        s[i] = kc(M[i], A);
    }
    fo(i, 1, n)
        fo(j, 1, n) if (i == j) minn = min(minn, (ld)sqrt(s[i]));
    else minn = min(minn, dg(s[i], s[j], kc(M[i], M[j])));
    cout << setprecision(4) << fixed << minn;
}
