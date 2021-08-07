// Một nhà máy sản xuất gốm sứ có hai phân xưởng. Phân xưởng nặn và phân xưởng vẽ. Đầu tiên
// tất cả các sản phẩm được hình thành từ phân xưởng nặn sau đó nó được chuyển sang phân xưởng
// vẽ để vẽ các hoa văn lên sản phẩm trước khi nung. Do hai phân xưởng này ở cách xa nhau nên
// trong một ngày tất cả đồ gốm sản xuất trong ngày chỉ được vận chuyển một lần duy nhất từ phân
// xưởng nặn sang phân xưởng vẽ bằng một ô tô chuyên dụng. May mắn là nó chạy rất nhanh nên
// thời gian vận chuyển xem như bằng 0. Sau khi hoàn thành vẽ xong, toàn bộ sản phẩm sẽ ngay
// lập tức đem đi nung (khi đó phân xưởng nặn sẽ ngồi chơi, phân xưởng nung làm việc).
// Phân xưởng nặn có N thợ thủ công, thợ thủ công thứ i nặn một sản phẩm mất ai đơn vị thời
// gian. Phân xưởng vẽ có M thợ thủ công, thợ thủ công thứ j hoàn thành vẽ hoa văn lên một sản
// phẩm mất bi đơn vị thời gian.
// Ngày làm việc kéo dài T đơn vị thời gian và khi bắt đầu cả trong phân xưởng nặn và vẽ không có
// sản phẩm nào. Ngoài ra, sau khi kết thúc ngày làm việc trong cả hai phân xưởng này cũng không
// còn sản phẩm nào (tức là tất cả các sản phẩm đã hoàn thành cả hai phần việc nặn và vẽ).
// Hỏi rằng số lượng sản phẩm tối đa mà hai phân xưởng sản xuất trong ngày là bao nhiêu?
// Dữ liệu
// • Dòng đầu tiên ghi số nguyên dương T (1 ≤ T ≤ 109
// )
// • Dòng thứ hai ghi số nguyên dương N (1 ≤ N ≤ 100000)
// • Dòng thứ ba ghi N số nguyên dương a1, a2, ..., aN (ai ≤ 109
// )
// • Dòng thứ tư ghi số nguyên dương M (1 ≤ M ≤ 100000)
// • Dòng thứ năm ghi M số nguyên dương b1, b2, ..., bm (bj ≤ 109
// )

// Kết quả
// • Một số nguyên duy nhất là số lượng sản phẩm tối đa có thể hoàn thành trong ngày của hai
#include <bits/stdc++.h>
#define ll long long
#define nmax 100005
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;
int t, n, m, a[nmax], b[nmax];
ll tmp, kq = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    cin >> n;
    fo(i, 1, n)
            cin >>
        a[i];
    cin >> m;
    fo(i, 1, m)
            cin >>
        b[i];
    ll l = 1, r = 1e14;
    while (l <= r)
    {
        ll mid = l + r >> 1;
        int u = 1, v = 1e9, ans = 1e9;
        while (u <= v)
        {
            int md = u + v >> 1;
            tmp = 0;
            fo(i, 1, n)
                tmp += md / a[i];
            if (tmp >= mid)
            {
                ans = md;
                v = md - 1;
            }
            else
                u = md + 1;
        }
        ans = t - ans;
        tmp = 0;
        fo(i, 1, m)
            tmp += ans / b[i];
        if (tmp >= mid)
        {
            kq = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << kq;
}
