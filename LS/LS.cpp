// Mr Bin và Mr Bon là hai cậu bé rất hiếu động, bố của hai cậu có một chiếc đèn
// chiếu tia laser để giảng bài, hai cậu mượn của bố để chơi và chiếu đèn vào nhau. Mr
// Bin đứng ở tọa độ (0; 0) còn Mr Bon đứng ở tọa độ (xm; ym). Có một bức tường nối
// hai điểm (x1

// ; y1) và (x2; y2). Bức tường này có lúc che khuất hai cậu bé khiến các

// cậu không thể chơi được trò chơi của mình.
// Yêu cầu: Bạn hãy kiểm tra xem liệu Mr Bin có thể chiếu đèn laser vào vị trí của Mr
// Bon hay là bị bức tường che khuất?
// Dữ liệu: Vào từ file văn bản LS.INP
//  Dòng đầu gồm duy nhất một số nguyên dương T − là số tests case
//  T dòng tiếp theo, mỗi dòng ghi 6 số nguyên dương là tọa độ của
// (x1
// ; y1
// ), (x2
// ; y2) và (xm; ym)

// Kết quả: Ghi ra file văn bản LS.OUT gồm T dòng ghi YES hoặc NO nếu Mr Bin có
// thể chiếu đèn tới Mr Bon hoặc không.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
using namespace std;
struct point
{
    ll x, y;
};
ll re(point a, point b, point c)
{
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}
double p, q;
ll n;
point a, b, c, o;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("LS.inp", "r", stdin);
    freopen("LS.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    fo(i, 1, n)
    {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        o.x = 0;
        o.y = 0;
        if (re(a, b, o) == 0 && re(a, b, c) == 0)
        {
            if (a.x * (c.x - a.x) > 0 || a.y * (c.y - a.y) > 0)
                cout << "NO" << '\n';
            else
                cout << "YES" << '\n';
        }
        else
        {
            p = max(re(a, b, c), re(a, b, o));
            q = min(re(a, b, c), re(a, b, o));
            if (p / q >= 0 && q != 0 || q / p >= 0 && p != 0)
                cout << "YES" << '\n';
            else
            {
                p = max(re(o, c, a), re(o, c, b));
                q = min(re(o, c, a), re(o, c, b));
                if (p / q > 0 && q != 0 || q / p > 0 && p != 0)
                    cout << "YES" << '\n';
                else
                    cout << "NO" << '\n';
            }
        }
    }
}
