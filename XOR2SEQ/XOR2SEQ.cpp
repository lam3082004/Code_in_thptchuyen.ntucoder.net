// Cho hai dãy số a và b, mỗi dãy gồm n phần tử.
// Với mỗi cặp (i, j) sao cho 1 ≤ i, j ≤ n, người ta viết giá trị ai + bj ra một mảnh giấy. Sau đó,
// người ta tính tổng XOR1
// của n
// 2
// số trên mảnh giấy đó.
// Hãy cho kết quả của phép tính tổng XOR trên.
// Dữ liệu
// • Dòng đầu tiên gồm số nguyên n (1 ≤ n ≤ 100000) - độ dài của hai dãy a và b.
// • Dòng thứ hai gồm n số nguyên a1, a2, . . . , an (0 ≤ ai < 2
// 20) - các phần tử của dãy a.
// • Dòng thứ ba gồm n số nguyên b1, b2, . . . , bn (0 ≤ bi < 2
// 20) - các phần tử của dãy b.
// Kết quả
// • In ra tổng XOR cần tìm
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
using namespace std;
ll n, a[nmax], b[nmax], dp[50 * nmax], T, kq = 0, dem, f[25];
void mu()
{
    f[0] = 1;
    fo(i, 1, 21)
        f[i] = f[i - 1] * 2;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mu();
    cin >> n;
    fo(i, 1, n)
            cin >>
        a[i];
    fo(i, 1, n)
            cin >>
        b[i];
    fo(k, 0, 20)
    {
        T = f[k];
        dem = 0;
        fo(i, 0, f[k + 2])
            dp[i] = 0;
        fo(i, 1, n)
        {
            ll B = b[i] % f[k + 1];
            dp[B]++;
        }
        fo(i, 0, f[k + 2])
            dp[i] = dp[i - 1] + dp[i];
        fo(i, 1, n)
        {
            ll A = a[i] % f[k + 1];
            if (T - A - 1 >= 0)
                dem += dp[2 * T - A - 1] - dp[T - A - 1];
            else
                dem += dp[2 * T - A - 1];
            dem += dp[4 * T - A - 1] - dp[3 * T - A - 1];
        }
        if (dem % 2 == 1)
            kq += f[k];
    }
    cout << kq;
}
