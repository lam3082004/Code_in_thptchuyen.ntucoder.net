// Ngũ cốc là món ăn chính của những chú ngựa đua. Hôm nay, Lê là người được cử đi mua ngũ
// cốc tại đại lý NC cho các chú ngựa ăn. Lê muốn mua X kg ngũ cốc. Ở đại lý NC có N loại ngũ cốc
// đánh số từ 1 đến N. Loại ngũ cốc thứ i đang có các tải chứa Pi kg với giá Ci mỗi tải. Giả thiết mỗi loại
// ngũ cốc đều có số lượng không hạn chế và không bán lẻ. Xác định chi phí nhỏ nhất để Lê có thể mua
// được ít nhất X kg ngũ cốc.
// Dữ liệu
// • Dòng đầu tiên chứa hai số nguyên N và X (1 ≤ N ≤ 100; 1 ≤ X ≤ 5 × 104
// ).

// • N dòng tiếp theo, dòng thứ i chứa hai số nguyên Pi

// , Ci (1 ≤ Pi

// , Ci ≤ 5000).

// Kết quả
// • Một số nguyên duy nhất là kết quả bài toán.
#include <bits/stdc++.h>
using namespace std;
const int nmax = 105;
int p[nmax], c[nmax], x, n, ans = 1e9, f[nmax][55010];
int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> p[i] >> c[i];
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= x + 5000; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= p[i])
                f[i][j] = min(min(f[i][j], f[i - 1][j - p[i]] + c[i]), f[i][j - p[i]] + c[i]);
        }
    for (int i = x; i <= x + 5000; i++)
        ans = min(ans, f[n][i]);
    cout << ans << endl;
}
