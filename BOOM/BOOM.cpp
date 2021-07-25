// Được biết ông tổng thống Chump của đất nước Ameniro đang định mở cuộc dội bom vào đất
// nước Sylic bị nghi vấn là vi phạm hiệp ước hòa bình của hai nước.
// Giả sử đất nước Sylic là một ma trận vuông N x N có các dòng và cột được đánh số từ 0 đến
// N − 1. Mỗi khu vực của đất nước Sylic được biểu diễn bởi một ô. Ô ở dòng i và cột j được gọi là
// ô (i, j).
// Ông Chump dự định tổ chức thả M quả bom vào đất nước Sylic. Mỗi quả bom được thả vào một
// ô cố định và có một sức công phá riêng, giả sử sức công phả của nó là w tại ô (x, y) thì ô (x, y)
// chịu sức công phá là w, các ô kề với ô (x, y) chịu sức công phá là w − 1, các ô liền kề tiếp đó chịu
// sức công phá là w − 2,... đến khi sức công phá của quả bom lên một ô nào đó bằng 0 thì các ô
// lân cận sẽ không chịu ảnh hưởng nữa.
// Để hiểu rõ hơn thì hãy xem hình ảnh dưới đây:
// Đất nước Sylic sau khi biết được kế hoạch của đất nước Ameniro rất lo lắng về những tổn thất
// mà mình sắp chịu phải. Vì vậy đất nước Sylic muốn biết tổn thất lớn nhất của mình phải chịu
// trong tất cả các khu vực của mình. Đất nước Sylic rất mong các bạn tính giúp kết quả này nhé.
// Dữ liệu
// • Dòng đầu ghi số nguyên dương N(5 ≤ N ≤ 300).
// • Dòng tiếp theo ghi số nguyên dương M(1 ≤ M ≤ 300).
// • Mỗi dòng trong M dòng tiếp theo ghi các số nguyên x, y, w(0 ≤ x, y ≤ N −1, 1 ≤ w ≤ 100).
// Khi đó sẽ có quả bom được thả ở ô (x, y) với sức công phá w
// Kết quả
// Free Contest 78
// • Ghi ra 1 số duy nhất là kết quả bài toán.
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define l2 long long
#define st first
#define nd second
#define ll2 pair<l2, l2>
#define lim 300
#define lar lim + 5
#define emerald ""
#define memset(a, b) memset(a, b, sizeof(a))
#define ladd(a, b) a = b + a
using namespace std;
l2 n, m, q, f[lar][lar], x, y, w, mx = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(f, 0);
    cin >> n >> m;
    while (cin >> x >> y >> w)
    {
        x++, y++;
        int u = x, v = y;
        while (w--)
        {
            f[x][y]++;
            f[x][v + 1]--;
            f[u + 1][y]--;
            f[u + 1][v + 1]++;
            if (x > 1)
                x--;
            if (y > 1)
                y--;
            if (u < n)
                u++;
            if (v < n)
                v++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] += f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1];
            mx = max(mx, f[i][j]);
        }
    }
    cout << mx;
}
