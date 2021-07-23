// Tại trang trại Free Contest có N con cừu xếp thành một đường thẳng, con cừu thứ i có bộ lông
// trị giá Ai
// . Bạn là một công nhân tài năng, công việc của bạn là chọn ra một đoạn con liên tiếp
// các con cừu sao cho tổng giá trị bộ lông của tất cả các con cừu trong đoạn không ít hơn K và giá
// trị trung bình của tất cả các con cừu trong đoạn con được chọn là lớn nhất.
// Dữ liệu
// • Dòng đầu tiên chứa số nguyên dương N, K (1 ≤ N ≤ 100000, 0 ≤ K ≤ 109
// ).
// • Dòng thứ hai chứa N số nguyên Ai (1 ≤ Ai ≤ 109
// ).
// Kết quả
// • Gồm một số nguyên duy nhất là kết quả của bài toán (Kết quả làm tròn xuống thành số
// nguyên)
#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5 + 5;
const int mod = 1e9 + 7;
int k, n, a[nmax];
long long f[nmax], s[nmax], minn[nmax];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    long long l = 1, r = 1e9, res = 0;
    while (l <= r)
    {
        long long mid = l + r >> 1;
        for (int i = 1; i <= n; i++)
            s[i] = f[i] - mid * i;
        minn[1] = s[1];
        for (int i = 2; i <= n; i++)
            minn[i] = min(minn[i - 1], s[i]);
        bool check = false;
        for (int i = 1; i <= n; i++)
        {
            int u = 1, v = i, tmp = n + 1;
            while (u <= v)
            {
                int m = u + v >> 1;
                if (f[i] - f[m - 1] >= k)
                {
                    tmp = m;
                    u = m + 1;
                }
                else
                    v = m - 1;
            }
            if (tmp != n + 1 && s[i] >= minn[tmp - 1])
            {
                check = true;
                break;
            }
        }
        if (check)
        {
            l = mid + 1;
            res = mid;
        }
        else
            r = mid - 1;
    }
    cout << res;
}
