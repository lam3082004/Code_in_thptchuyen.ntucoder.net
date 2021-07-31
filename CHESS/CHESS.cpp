// au một thời gian dài nghỉ dịch CHUNOC-20, hôm nay là ngày đầu tiên đất nước Free Contest
// cho phép toàn bộ công dân ra ngoài để vui chơi và làm việc. Trong suốt thời gian nghỉ dịch, Thợ
// Săn đã tôi luyện được khả năng chơi cờ vua thượng thừa của mình và hôm nay anh ấy đã quyết
// định sang chơi nhà Cá Nóc và nhờ Cá Nóc kiểm tra năng lực của bản thân.
// Thấy Thợ Săn rất háo hức, Cá Nóc liền nghĩ ra một trò chơi thú vị liên quan đến cờ vua để thách
// đố Thợ Săn. Cá Nóc đặt lên bàn cờ vua siêu to khổng lồ mà Thợ Săn mang đến N con vua, con
// vua thứ i nằm ở ô (xi
// , yi). Mỗi con vua mỗi bước có thể đi sang 8 ô kề nó.
// Bàn cờ vua có kích thước 109 × 109
// , ô nằm ở hàng thứ i, cột thứ j được kí hiệu là ô (i, j).
// Cá Nóc muốn hỏi Thợ Săn Q câu hỏi, với câu hỏi thứ i, Cá Nóc sẽ chọn ra một ô (ai
// , bi) và Thợ
// Săn sẽ phải tìm ra tổng khoảng cách ngắn nhất để cả N con vua di chuyển và thể gặp nhau tại ô
// (ai
// , bi) đó.
// Dữ liệu
// • Dòng đầu tiên chứ hai số nguyên dương N, Q.
// • N dòng tiếp theo, mỗi dòng chứa hai số nguyên dương xi
// , yi
// • Q dòng tiếp theo, mỗi dòng chứa hai số nguyên dương ai
// , bi
// Kết quả
// • Ghi kết quả ra Q dòng, dòng thứ i ghi ra tổng khoảng cách ngắn nhất từ N con vua đến vị
// trí gặp mặt của câu hỏi thứ i.
// Giới hạn
// Beginner Free Contest 20
// • 1 ≤ xi
// , yi
// , ai
// , bi ≤ 109
// • 60% số điểm có N ∗ Q ≤ 1e8
// • 40% số điểm còn lại có N, Q ≤ 105
#include <bits/stdc++.h>
#define ll long long
#define nmax 100005
#define fo(i, a, b) for (ll i = a; i <= b; i++)
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int mod = 1e6 + 3;
struct point
{
    ll x, y;
};
ll n, t, u[nmax], v[nmax], p[nmax], q[nmax], a, b, kq;
point d[nmax];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("TA.inp", "r", stdin);
    freopen("TA.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    fo(i, 1, n)
    {
        cin >> d[i].x >> d[i].y;
        u[i] = d[i].x + d[i].y;
        v[i] = d[i].x - d[i].y;
    }
    sort(u + 1, u + 1 + n);
    sort(v + 1, v + 1 + n);
    fo(i, 1, n)
    {
        p[i] = p[i - 1] + u[i];
        q[i] = q[i - 1] + v[i];
    }
    while (t--)
    {
        cin >> a >> b;
        ll l = 1, r = n, ans = n + 1;
        kq = 0;
        while (l <= r)
        {
            ll mid = l + r >> 1;
            if (u[mid] >= a + b)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        kq += p[n] - p[ans - 1] - (n - ans + 1) * (a + b) + (ans - 1) * (a + b) - p[ans - 1];
        l = 1, r = n, ans = n + 1;
        while (l <= r)
        {
            ll mid = l + r >> 1;
            if (v[mid] >= a - b)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        kq += q[n] - q[ans - 1] - (n - ans + 1) * (a - b) + (ans - 1) * (a - b) - q[ans - 1];
        cout << kq / 2 << '\n';
    }
}
