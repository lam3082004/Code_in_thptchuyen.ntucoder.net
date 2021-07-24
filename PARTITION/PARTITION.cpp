// Cho mảng A kích thước n và hai số l, r
// Một cách phân đoạn mảng A là cách chia mảng A thành một hoặc một số đoạn, mỗi đoạn là
// một chuỗi các phần tử liên tục trong mảng A
// Yêu cầu: Đếm số cách phân đoạn mảng A sao cho tổng của mỗi đoạn con nằm trong đoạn
// [l, r]. Do kết quả có thể rất lớn, nên chỉ cần in ra phần dư của kết quả sau khi đem chia cho 109 + 7
// Input
// • Dòng đầu tiên gồm 3 số n, l, r
// • Dòng thứ hai gồm n số, là các phần tử của mảng A
// Output
// • Một dòng duy nhất là kết quả bài toán
#include <bits/stdc++.h>
using namespace std;
#define nmax 100007
int n;
long long a[nmax];
long long sum[nmax], dp[nmax], tong[nmax];
long long L, R;
long long const mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> L >> R;
    tong[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tong[i] = tong[i - 1] + a[i];
    }
    dp[0] = 1;
    sum[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int l, r, m;
        l = 1;
        r = i;
        int f = -1;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (tong[i] - tong[m - 1] >= L)
            {
                f = max(f, m);
                l = m + 1;
            }
            else
                r = m - 1;
        }
        int e = 1e9;
        l = 1;
        r = i;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (tong[i] - tong[m - 1] <= R)
            {
                e = min(e, m);
                r = m - 1;
            }
            else
                l = m + 1;
        }
        //cout << i << " " << e << " " << f << '\n';
        if (e > f)
        {
            dp[i] = 0;
            sum[i] = sum[i - 1];
        }
        else
        {
            dp[i] = (sum[f - 1] - sum[e - 2] + mod) % mod;
            sum[i] = (sum[i - 1] + dp[i]) % mod;
        }
    }
    cout << dp[n];
    return 0;
}
