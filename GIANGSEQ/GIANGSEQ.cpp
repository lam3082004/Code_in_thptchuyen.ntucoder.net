// GIANGSEQ
// Giang có một dãy số nguyên a gồm n phần tử a1, a2, ..., an. Giang muốn thay đổi nhiều nhất k
// phần tử trong dãy a sao cho dãy a mịn nhất có thể.
// Giang định nghĩa độ mịn của dãy a là giá trị tuyệt đối lớn nhất của hiệu giữa hai phần
// tử liên tiếp của dãy a.
// Ví dụ như dãy 4, 5, 8, 6, 7 có độ mịn là 3 do hiệu giữa hai phần tử liên tiếp 5 và 8 là hiệu
// giữa hai phần tử liên tiếp có giá trị tuyệt đối lớn nhất trong dãy.
// Độ mịn của dãy càng nhỏ thì dãy càng mịn.
// Yêu cầu
// Tính độ mịn nhỏ nhất của dãy mà Giang có thể đạt được.
// Dữ liệu
// • Dòng đầu tiên gồm hai số nguyên dương n và k (1 ≤ k ≤ n ≤ 2000).
// • Dòng thứ hai gồm n số nguyên a1, a2, ..., an (−109 ≤ ai ≤ 109

// ) mô tả dãy a mà Giang muốn

// làm mịn.
// Kết quả
// • Gồm một dòng duy nhất chứa một số nguyên là độ mịn nhỏ nhất có thể của dãy a sau khi
// Giang đã thay đổi nhiều nhất k phần tử của dãy.
#include <bits/stdc++.h>
using namespace std;
const int nmax = 2005;
const int oo = 2e9;
typedef pair<int, int> ii;
int n, a[nmax], k, f[2][nmax], ans;
bool check(long long x)
{
    for (int i = 1; i <= n; i++)
    {
        f[1][i] = min(f[1][i - 1], f[0][i - 1]) + 1;
        f[0][i] = i - 1;
        for (int j = 1; j < i; j++)
            if (abs(a[i] - a[j]) <= x * (i - j))
                f[0][i] = min(f[0][i], f[0][j] + i - j - 1);
    }
    int tmp = min(f[1][n], f[0][n]);
    if (tmp > k)
        return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("GIANGSEQ.inp","r",stdin);
    //("GIANGSEQ.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long l = 0, r = oo;
    while (l <= r)
    {
        long long mid = l + r >> 1;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
}
