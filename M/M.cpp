// Giáng Sinh sắp đến, thầy Minh quyết định trang trí khu du lịch của mình.
// Trước cửa khu du lịch, có một hàng gồm N cây, đánh số từ 1 đến N theo chiều
// từ trái sang phải, cây thứ i có độ cao h[i]. Thầy Minh quyết định chọn một số
// cây để treo mỗi cây một đèn lồng đỏ trên ngọn, sao cho khi nhìn từ vịnh Hạ Long
// vào, các đèn lồng sẽ tạo thành một chữ M.
// Chữ M được định nghĩa như sau: Đó là một dãy các cây, khi xét từ trái sang
// phải, có thể chia thành 4 phân đoạn, trong đó độ cao các dãy trong đoạn đầutiên
// tăng nghiêm ngặt, trong đoạn thứ hai giảm nghiêm ngặt, trong đoạn thứ ba tăng
// nghiêm ngặt và trong đoạn thứ tư giảm nghiêm ngặt.
// Tức là, có một dãy các chỉ số a[1] < a[2] < ... < a[i] < b[1] < b[2] <
// ... < b[j] < c[1] < c[2] < . . . < c[k] < d[1] < d[2] < . . . < d[l] sao cho:
// Dãy h[a[1]],h[a[2]], . . . , h[a[i]]là dãy tăng nghiêm ngặt, và i ≥ 2.
// Dãy h[a[i]],h[b[1]], . . . , h[b[j]]là dãy giảm nghiêm ngặt, j ≥ 1.
// Dãy h[b[j]],h[c[1]], . . . ,h[c[k]]là dãy tăng nghiêm ngặt, k ≥ 1.
// Dãy h[c[k]],h[d[1]],. . . , h[d[l]]là dãy giảm nghiêm ngặt, l ≥ 1.
// Độ hoành tráng của chữ M là số lượng đèn lồng tạo thành chữ M.
// Yêu cầu: Hãy tìm độ hoành tráng lớn nhất của một chữ M mà thầy Minh có
// thể tạo được.
// Input
// Dòng 1 chứa số nguyên dương N ≤ 50,000
// Dòng 2 chứa N số nguyên dương không vượt quá 109
// .

// Dữ liệu đảm bảo tồn tại ít nhất một cách treo đèn. Các số trên một dòng của
// file input được ghi cách nhau bởi dấu cách.
// Output
// Ghi ra độ hoành tráng lớn nhất của một chữ M có thể có.
#include <bits/stdc++.h>

#define el cout << "\n"
#define file ""
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define maxn 50004

using namespace std;
int n, a[maxn], b[maxn], f[5][maxn], t[maxn], ans;
void up(int x, int v, int d)
{
    if (d)
        for (; x < maxn; x += x & -x)
            t[x] = max(t[x], v);
    else
        for (; x; x -= x & -x)
            t[x] = max(t[x], v);
}
int get(int x, int d)
{
    int s = 0;
    if (d)
        for (; x; x -= x & -x)
            s = max(s, t[x]);
    else
        for (; x < maxn; x += x & -x)
            s = max(s, t[x]);
    return s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ///freopen(file".inp","r",stdin);
    ///freopen(file".out","w",stdout);
    cin >> n;
    f1(i, n)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    f1(i, n) a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
    for (int x = 1; x <= 4; x++)
    {
        f1(i, maxn) t[i] = 0;
        for (int i = x; i <= n; i++)
        {
            int d;
            if (x % 2)
                d = -1;
            else
                d = 1;
            f[x][i] = get(a[i] + d, x % 2) + 1;
            if (max(f[x][i], f[x - 1][i]) >= x)
                up(a[i], max(f[x][i], f[x - 1][i]), x % 2);
        }
    }
    f1(i, n) ans = max(ans, f[4][i]);
    cout << ans;
    return 0;
}
