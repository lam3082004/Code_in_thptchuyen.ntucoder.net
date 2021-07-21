// Cụm Dân Cư
// Vương quốc Ba Sao tươi đẹp, người dân hiền lành chăm chỉ làm ăn. Tại đây có 𝑛
// ngôi làng nằm dọc theo đường quốc lộ, mỗi ngôi làng đều dự trữ một lượng lương thực
// nhất định cho làng của mình. Làng thứ i có số lương thực dự trữ là ai. Các làng liên tiếp có
// thể kết nghĩa với nhau thành một cụm dân cư nếu có lượng lương thực trung bình cộng lớn
// hơn hoặc bằng P.
// Yêu cầu: Hãy xác định số cụm dân cư khác nhau có thể hình thành trong vương quốc
// Dữ liệu vào: GROUP.INP
// - Dòng đầu chứa số nguyên 𝑛(1 ≤ 𝑛 ≤ 10)
// - Dòng hai chứa 𝑛 số nguyên 𝑎1, 𝑎2, … , 𝑎𝑛(0 ≤ 𝑎𝑖 ≤ 109)
// - Dòng cuối chứa một số nguyên dương 𝑃(0 ≤ 𝑃 ≤ 109).
// Dữ liệu ra: GROUP.OUT
// - Ghi một số nguyên không âm duy nhất là kết quả tìm được.
#include <bits/stdc++.h>
#define lo long long
#define KKH "GROUP"
#define fi first
#define se second
#define BIT(x, k) (((x) >> (k)) & 1)
#define rs(x, a) memset(x, (a), sizeof x)
using namespace std;
void START()
{
#ifdef toilagun2004
    freopen(KKH ".inp", "r", stdin);
    freopen(KKH ".out", "w", stdout);
#endif // toilagun2004
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const int gh = 1e6 + 6;
int n, p, b[gh];
lo s[gh], kq;
pair<lo, int> tmp[gh];
void update(int i)
{
    for (; i <= n; i += i & -i)
        b[i]++;
}
lo get(int i)
{
    lo tmp = 0;
    for (; i > 0; i -= i & -i)
        tmp += b[i];
    return tmp;
}
template <class H>
void xiout(int n, H a[])
{
    for (int i = 0; i <= n; ++i)
        cout << a[i] << ' ';
    cout << endl;
}
int32_t main()
{
    START();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        s[i] = s[i - 1] + a;
    }
    cin >> p;
    for (int i = 1; i <= n; ++i)
        s[i] -= 1LL * p * i;
    for (int i = 0; i <= n; ++i)
        tmp[i] = {s[i], i};
    sort(tmp, tmp + 1 + n);
    lo d = 0, cuoi = 1e9;
    for (int i = 0; i <= n; ++i)
    {
        if (cuoi != tmp[i].fi)
        {
            d++;
            cuoi = tmp[i].fi;
        }
        s[tmp[i].se] = d;
    }
    update(s[0]);
    for (int i = 1; i <= n; ++i)
    {
        kq += get(s[i]);
        update(s[i]);
    }
    cout << kq;
}
