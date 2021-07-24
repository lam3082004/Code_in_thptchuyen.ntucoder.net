// TRAIN - HUẤN LUYỆN
// Tại một học viện thể thao nọ, người ta nghĩ ra một phương pháp mới để huấn luyện vận
// động viên. Theo phương pháp này các vận động viên cần rèn luyện hàng ngày nhưng sự tăng
// giảm khối lượng bài tập cần thay đổi đan xen.
// Khối lượng bài tập được thể hiện bởi dãy số nguyên a1, a2, . . . , am; trong đó ai
// là một số

// nguyên dương thể hiện cho khối lượng bài tập của vận động viên ở ngày thứ i.
// Khối lượng bài tập ở hai ngày liên tục là khác nhau ai ≠ ai+1 và phải đảm bảo sự tăng
// giảm khối lượng đan xen giữa các ngày tập, nghĩa là nếu ai < ai+1, thì ai+1 > ai+2, hoặc nếu
// ai > ai+1, thì ai+1 < ai+2, với 1 ≤ i ≤ m − 2.
// Tổng khối lượng các bài tập là n, a1 + a2+. . . +am = n. Không có giới hạn về số ngày
// tập, tuy nhiên khối lượng tập luyện ở ngày đầu tiên phải bằng k, a1 = k.
// Trước khi áp dụng phương pháp tập luyện này, Ban huấn luyện muốn biết có tất cả bao
// nhiêu phương án khác nhau thỏa mãn các ràng buộc ở trên.
// Bạn cần viết chương trình xác định từ khối lượng tập luyện n và khối lượng ngày đầu
// tiên k có bao nhiêu phương án, kết quả trả về là phần dư của số phương án cho 109 + 7.
// Input: Hai số nguyên n, k trên cùng một dòng (1 ≤ n ≤ 5000, 1 ≤ k ≤ n) .
// Output: Một con số thể hiện phần dư của số phương án cho 109 + 7. Ví dụ:
#include <bits/stdc++.h>
using namespace std;
const int nmax = 5005;
const int mod = 1e9 + 7;
int n, k;
long long f[nmax][nmax][2];
long long sub1()
{
    f[k][k][1] = 1;
    f[k][k][0] = 1;
    for (int i = k + 1; i <= n; i++)
        for (int j = i; j >= 1; j--)
        {
            for (int t = 1; t < j; t++)
                f[i][j][1] = (f[i][j][1] + f[i - j][t][0]) % mod;
            for (int t = j + 1; t <= n; t++)
                f[i][j][0] = (f[i][j][0] + f[i - j][t][1]) % mod;
        }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + f[n][i][1]) % mod;
    return ans;
}
long long sub2()
{
    for (int i = 0; i <= k; i++)
        f[k][i][1] = 1;
    for (int i = k; i <= n; i++)
        f[k][i][0] = 1;
    for (int i = k + 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
            f[i][j][1] = (f[i][j + 1][1] + f[i - j][j - 1][0]) % mod;
        for (int j = 1; j <= i; j++)
            f[i][j][0] = (f[i][j - 1][0] + f[i - j][j + 1][1]) % mod;
        for (int j = i + 1; j <= n; j++)
            f[i][j][0] = f[i][j - 1][0];
    }
    return (f[n][1][1] + f[n][n][0]) % mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    cin >> n >> k;
    if (n == k)
    {
        cout << 1;
        return 0;
    }
    cout << sub2();
}
