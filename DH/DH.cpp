// Công ty giải pháp tin học Bê - ta nhận được n đơn đặt hàng. Đơn đặt hàng thứ
// i cần hoàn thành không muộn hơn thời điểm ti

// , lúc đó công ty được nhận một khoản

// tiền công fi

// (hoàn thành đúng thời hạn). Nếu công ty hoàn thành đơn đặt hàng i sau

// thời điểm ti

// thì công ty không được một khoản tiền công nào từ đơn đặt hàng i (hoàn
// thành không đúng thời hạn). Sau khi phân tích các đơn đặt hàng, công ty nhận thấy tất
// cả các đơn đặt hàng đều phải hoàn thành trong một khoảng thời gian là 1 đơn vị thời
// gian. Do công ty hiện chỉ có một tổ thi công cho nên các công việc phải được thực
// hiện tuần tự, tức là tại mỗi thời điểm, công ty chỉ có thể thực hiện một đơn đặt hàng
// nào đó và khi đã thực hiện một đơn đặt hàng thì thực hiện cho đến khi hoàn thành mới
// chuyển sang thực hiện các đơn đặt hàng khác. Điều này dẫn đến có thể không hoàn
// thành được tất cả các đơn đặt hàng đúng thời hạn.
// Yêu cầu: Bạn hãy giúp công ty chọn một số đơn đặt hàng để hoàn thành đúng thời hạn
// và tổng tiền công nhận được là lớn nhất, in ra giá trị lớn nhất đó.
// Dữ liệu: Vào từ file văn bản DH.INP
//  Dòng đầu gồm duy nhất một số nguyên dương n − là số lượng đơn đặt hàng.
//  N dòng tiếp theo, mỗi dòng ghi hai số nguyên dương ti và fi

// tương ứng là thời
// điểm phải hoàn thành công việc và tiền công nhận được khi hoàn thành đúng
// thời hạn công việc. Mọi công việc đều bắt đầu thực hiện từ thời điểm 0.
// Kết quả: Ghi ra file văn bản DH.OUT kết quả bài toán.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 100005
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
ll n, kq = 0, t = 0;
ii p[nmax];
priority_queue<ll> q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n)
    {
        cin >> p[i].fi >> p[i].se;
        t = max(t, p[i].fi * 1LL);
    }
    sort(p + 1, p + 1 + n, greater<ii>());
    int i = 1;
    while (t > 0)
    {
        while (p[i].fi == t && i <= n)
        {
            q.push(p[i].se);
            i++;
        }
        if (!q.empty())
        {
            kq += q.top();
            q.pop();
        }
        t--;
    }
    cout << kq;
}
