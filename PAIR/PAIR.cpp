// Kì nghỉ đông của trường sắp đến, thầy Toàn không muốn các học sinh của mình ở nhà rảnh rỗi trong kì nghỉ này. Vì vậy, thầy quyết định chia lớp thành các nhóm học tập trong lớp, đồng thời ra các bài tập chung trong mỗi nhóm. Mỗi nhóm học tập sẽ có 2 học sinh, rất may lớp của thầy số học sinh là chẵn. Có tất cả
// n
//  nhóm học tập, thầy Toàn trên tay có danh sách các địa chỉ nhà của mỗi học sinh. Mỗi địa chỉ nhà của các học sinh được kí hiệu bằng một cặp tọa độ nguyên
// (
// x
// ,
// y
// )
// . Khoảng cách giữa 2 nhà  được tính bằng công thức khoảng cách Manhattan. Thầy Toàn muốn tăng hiệu suất học tập của cả lớp, vì vậy thầy muốn tổng khoảng cách của các cặp nhà trong mỗi nhóm học tập là nhỏ nhất để tất cả học sinh có thể dễ dàng qua nhà bạn trao đổi. Hãy giúp thầy tính tổng này.

// INPUT

// - Dòng đầu chứa số nguyên dương
// n
// .
// (
// 1
// ≤
// n
// ≤
// 10
// )

// -
// 2
// n
//  dòng tiếp theo, mỗi dòng chứa một cặp tọa độ
// (
// x
// ,
// y
// )

// (
// 0
// ≤
// x
// ,
// y
// ≤
// 1000
// )

// OUTPUT

// - In ra tổng khoảng cách nhỏ nhất.
#include <bits/stdc++.h>
#define lo long long
#define KKH "PAIR"
#define fi first
#define se second
#define BIT(x, k) (((x) >> (k - 1)) & 1)
#define rs(x, a) memset(x, (a), sizeof x)
#define off(x, k) ((x) ^ (1 << (k - 1)))
using namespace std;
void START()
{
#ifdef toilagun2004
    freopen(KKH ".inp", "r", stdin);
    freopen(KKH ".out", "w", stdout);
#endif // toilagun2004
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const int gh = (1 << 20) + 1;
int n, a[21], dp[gh], kq, x[21], y[21], c[21][21];
inline void mini(int &a, int b)
{
    if (a > b)
        a = b;
}
int cal(int mask, int b)
{
    if (b <= 1)
        return 0;
    int &tmp = dp[mask];
    if (tmp != 0)
        return tmp;
    tmp = 1e9;
    for (int i = 1; i <= n; ++i)
        if (BIT(mask, i))
            for (int j = i + 1; j <= n; ++j)
                if (BIT(mask, j))
                    mini(tmp, cal(mask ^ (1 << (i - 1)) ^ (1 << (j - 1)), b - 2) + c[i][j]);
    return tmp;
}
int main()
{
    START();
    cin >> n;
    n <<= 1;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            c[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
    cout << cal((1 << n) - 1, n);
}
