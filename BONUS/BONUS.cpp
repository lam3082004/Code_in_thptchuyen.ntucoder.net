// Theo truyền thuyết, vua Sêram rất khâm phục và đã tặng thưởng cho nhà thông thái Sêta vì đã
// sáng tạo ra cờ vua. Phần thưởng mà Sêta mong muốn là tất cả các hạt lúa mì đặt trên bàn cờ theo
// quy tắc sau: Ô thứ nhất đặt một hạt, ô thứ hai đặt 2 hạt, ô thứ ba đặt 4 hạt, ... , tiếp tục theo quy
// luật ô sau có số hạt gấp đôi số hạt của ô trước, cho tới khi đặt đến ô thứ 64 trên bàn cờ vua. Rất
// thích thú với truyền thuyết này, Long và Vân cùng nhau giải quyết bài toán sau:
// Xét một bảng số kích thước m × n, các hàng được đánh số từ 1 đến m từ trên xuống dưới, các
// cột được đánh số từ 1 đến n từ trái sang phải. Ô nằm giao giữa hàng i và cột j được gọi là ô (i,j).
// Với một số nguyên dương k (k ≤ 10), lần lượt điền các số vào các ô của bảng theo nguyên tắc
// sau:
// - Bắt đầu điền từ ô (1,1) ghi số 1;
// - Điền lần lượt từng ô từ trên xuống dưới, từ trái qua phải. Ô tiếp theo điền giá trị gấp k lần
// giá trị điền ô trước.
// Với bộ 4 số nguyên dương (x, y, u, v) thỏa mãn 1 ≤ x ≤ u ≤ m và 1 ≤ y ≤ v ≤ n, hai bạn Long
// và Vân muốn tính tổng các số nằm trong các ô (i,j) mà x ≤ i ≤ u và y ≤ j ≤ v.
// Yêu cầu: Cho 7 số nguyên dương m, n, k, x, y, u, v, hãy tính tổng các số nằm trong các ô (i,j)
// mà x ≤ i ≤ u và y ≤ j ≤ v của bảng số được điền theo quy tắc trên.
// Dữ liệu: Vào từ file văn bản BONUS.INP gồm một dòng chứa 7 số nguyên dương
// m, n, k, x, y, u, v.
// Kết quả: Ghi ra file văn bản BONUS.OUT gồm một dòng chứa một số là phần dư của phép chia
// tổng các số được tính chia cho 111539768.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
using namespace std;
const int mod = 111539768;
ll mu(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = mu(a, b / 2);
    t = (t * t) % mod;
    if (b % 2 == 1)
        t = (t * a) % mod;
    return t;
}
ll kq(ll a, ll b)
{
    if (b == 1)
        return a;
    ll t = kq(a, b / 2);
    t = (t + t * mu(a, b / 2)) % mod;
    if (b % 2 == 1)
        t = (t + mu(a, b)) % mod;
    return t;
}
ll m, n, k, x, y, u, v, t, s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> k >> x >> y >> u >> v;
    t = kq(k, v - y) + 1;
    s = (t * mu(k, (x - 1) * m + y - 1)) % mod;
    if (u == x)
        cout << s;
    else
    {
        s = (s * (kq(mu(k, m), u - x) + 1)) % mod;
        cout << s;
    }
}
