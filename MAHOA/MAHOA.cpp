// Nam rất thích thú với việc mã hoá dữ liệu. Trong buổi thảo luận ở lớp, Nam đã trình bày 1 ý tưởng rất
// thú vị rằng bạn ấy vừa phát minh ra một cách mã hoá mới, có thể mã hoá các thông tin mà không ai
// có thể giải mã. Cách mã hoá đó là: Với một số nguyên N, xoá các chữ số từ con số này bằng mọi cách
// có thể, ta sẽ nhận được các số mới. Hãy tìm tổng của tất cả các con số mới thu được. Tổng này chính
// là mã hoá của N.
// Một bạn trong lớp đã ý kiến “Mình nghĩ cách mã hoá của cậu trên máy tính sẽ thực hiện mất nhiều
// thời gian với số có nhiều chữ số, chẳng hạn số có 100 chữ số. Không thể chờ để có một mã số cho số
// có 100 chữ số. Cách mã hoá này của cậu không thể áp dụng trên thực tế”. Nam đã trả lời: “ Không!
// Ngày mai mình sẽ đưa ra chương trình thực hiện cách mã hoá này, và sẽ mã hoá cho số có 100 chữ số
// trong thời gian không quá 1 giây”
// Yêu cầu: Cho số nguyên N (1 ≤ N ≤ 10100), xác định số nguyên S là mã hoá của N theo phương pháp
// mã hoá của Nam
// Input:
//  Một dòng duy nhất là số nguyên N (chữ số bên trái nhất của N khác 0)
// Output:
//  Một số duy nhất là phần dư của S khi chia cho 109 + 7
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int mod = 1e9 + 7;
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
ll n, t = 0;
string s;
int main()
{
    cin >> s;
    n = s.size();
    s = " " + s;
    fo(i, 1, n)
        t = (t + (s[i] - '0') * (mu(11, n - i) * mu(2, i - 1) % mod)) % mod;
    cout << t;
}
