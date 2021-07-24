// Bạn có một bảng số A gồm m hàng và n cột, mỗi ô trong bảng có chứa một số nguyên. Gọi
// D(x, y, u, v) (1 ≤ x < u ≤ m, 1 ≤ y < v ≤ n) là tổng bao quanh hình chữ nhật có đỉnh trái trên
// là (x, y) và đỉnh phải dưới là (u, v). Nói cách khác, D(x, y, u, v) là tổng của các ô (i, j) thỏa mãn
// x ≤ i ≤ u, y ≤ j ≤ v và ít nhất một trong các điều kiện sau:
// • i = x
// • i = u
// • j = y
// • j = v
// Nhiệm vụ của bạn là tìm giá trị D(x, y, u, v) lớn nhất có thể.
// Dữ liệu
// • Dòng đầu tiên chứa hai số nguyên dương m, n (2 ≤ m, n ≤ 300) - số hàng và số cột của
// bảng số A.
// • m dòng tiếp theo, mỗi dòng gồm n số nguyên có giá trị từ -10 đến 10 biểu diễn bảng số A.
// Kết quả
// • Một dòng duy nhất là giá trị lớn nhất của D(x, y, u, v).
#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const long long inf = 1e15;

int n, m;
int a[N][N];
long long col[N];
long long row[2][N];

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    long long res = -inf;
    for (int i = 1; i <= m; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            col[k] = 0;
            row[0][k] = row[0][k - 1] + a[i][k];
        }
        for (int j = i + 1; j <= m; j++)
        {
            for (int k = 1; k <= n; k++)
                row[1][k] = row[1][k - 1] + a[j][k];

            long long best = inf;
            for (int k = 1; k <= n; k++)
            {
                res = max(res, col[k] + row[0][k] + row[1][k] - best);
                best = min(best, row[0][k - 1] + row[1][k - 1] - col[k]);
            }

            for (int k = 1; k <= n; k++)
                col[k] = col[k] + a[j][k];
        }
    }

    cout << res;

    return 0;
}
