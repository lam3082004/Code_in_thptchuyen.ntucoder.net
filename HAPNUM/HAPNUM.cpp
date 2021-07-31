// HAPNUM
// Một số nguyên có 2N hoặc 2N+1 chữ số được gọi là số may mắn nếu như tổng N
// chữa số đầu tiên là bằng tổng của N chữ số cuối cùng. Ví dụ: 121, 21312, 3223 là
// các số may mắn, còn 123, 2334 không phải số may mắn. Ta có thể mở rộng khái
// niệm này cho dãy chữ số: Dãy gồm 2 N hoặc 2N+1 chữ số được gọi là dãy số may
// mắn nếu như tổng N chữ số đầu tiên là bằng tổng của N chữ số cuối cùng. Chẳng
// hạn, dãy 010, 0120120, 012012 là các dãy số may mắn, còn 001200, 31212 không
// phải là dãy số may mắn. Cho M tấm bìa được đánh số từ 1 đến M. Trên mỗi tấm bìa
// có ghi một dãy gồm K chữ số.

// Yêu cầu:
// Hãy tính xem có bao nhiêu cách sắp xếp M tấm bìa thành một dãy để số thu được
// bằng cách đọc từ trái qua phải các dãy chữ số trên chúng là dãy số may mắn.

// Dữ liệu:
//  Dòng đầu tiên chứa hai số nguyên M và K,
//  Dòng thứ i trong số M dòng tiếp theo chứa dãy gồm K chữ số viết trên tấm
// bìa i.

// Kết quả: Ghi một số nguyên duy nhất là kết quả mà bạn tìm được.
#include <bits/stdc++.h>
using namespace std;
const int nmax = 105;
const int mod = 1e9 + 7;
int n, k;
string a[nmax];
long long f[nmax][4055];
int res, tong[nmax], tong2[nmax];
void sub1()
{
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = n / 2; j >= 1; j--)
            for (int k = res / 2; k >= tong[i]; k--)
                f[j][k] = (f[j][k] + f[j - 1][k - tong[i]]) % mod;
    long long ans = f[n / 2][res / 2];
    for (int i = 1; i <= n / 2; i++)
        ans = (ans * i * i) % mod;
    cout << ans << '\n';
}
void sub2()
{
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        int tmp = res / 2 - tong2[i];
        if (tmp < 0)
            continue;
        for (int j = 1; j <= n; j++)
            if (j != i)
                for (int t = tmp; t >= tong[j]; t--)
                    for (int k = n / 2; k >= 1; k--)
                        f[k][t] = (f[k][t] + f[k - 1][t - tong[j]]) % mod;
        ans = (ans + f[n / 2][tmp]) % mod;
    }
    for (int i = 1; i <= n / 2; i++)
        ans = (ans * i * i) % mod;
    cout << ans;
}
void sub3()
{
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((res - a[i][k / 2 + 1] + '0') % 2 == 1)
            continue;
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        int tmp = (res - a[i][k / 2 + 1] + '0') / 2 - tong2[i];
        if (tmp < 0)
            continue;
        for (int j = 1; j <= n; j++)
            if (j != i)
                for (int t = tmp; t >= tong[j]; t--)
                    for (int p = n / 2; p >= 1; p--)
                        f[p][t] = (f[p][t] + f[p - 1][t - tong[j]]) % mod;
        ans = (ans + f[n / 2][tmp]) % mod;
    }
    for (int i = 1; i <= n / 2; i++)
        ans = (ans * i * i) % mod;
    cout << ans;
}
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
        a[i] = " " + a[i];
        for (int j = 1; j <= k; j++)
            tong[i] += a[i][j] - '0';
        for (int j = 1; j <= k / 2; j++)
            tong2[i] += a[i][j] - '0';
        res += tong[i];
    }
    if (n % 2 == 0)
    {
        if (res % 2 == 1)
        {
            cout << 0;
            return 0;
        }
        sub1();
        return 0;
    }
    if (k % 2 == 0)
    {
        if (res % 2 == 1)e
        {
            cout << 0;
            return 0;
        }
        sub2();
        return 0;
    }
    sub3();
}
