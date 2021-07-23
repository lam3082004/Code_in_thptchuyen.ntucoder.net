// Có một danh sách gồm n số và hai người chơi di chuyển luân phiên. Trên mỗi nước đi, người chơi xóa số đầu tiên hoặc số cuối cùng khỏi danh sách và điểm của họ sẽ tăng theo số đó. Cả hai người chơi đều cố gắng tối đa hóa điểm số của mình.

// Số điểm tối đa có thể cho người chơi đầu tiên khi cả hai người chơi đều chơi tối ưu là bao nhiêu?

// Đầu vào:

// Dòng đầu tiên chứa số nguyên n: kích thước của danh sách (n
// ≤
// 5000).

// Dòng tiếp theo có n số nguyên x1, x2,…, xn: nội dung của danh sách.

// Đầu ra:

// In số điểm tối đa có thể cho người chơi đầu tiên.
#include <bits/stdc++.h>

using namespace std;

long long n, a[5005], f[5007][5007], s[5005];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            long long cuoi = j + i - 1;
            if (i == 1)
                f[j][cuoi] = a[j];
            else
            {
                f[j][cuoi] = s[cuoi] - s[j - 1] - min(f[j + 1][cuoi], f[j][cuoi - 1]);
            }
        }
    }
    cout << f[1][n];
}
