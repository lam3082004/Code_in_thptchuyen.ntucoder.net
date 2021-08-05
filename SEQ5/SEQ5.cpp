// Cho dãy số a gồm n phần tử. Nhiệm vụ của bạn là xác định nhóm chỉ số 1 ≤ i1 < i2 < ⋯ < i5k ≤ n
// sao cho biểu thức dưới đây đạt giá trị lớn nhất
// S = (ai1 − 2ai2 + 3ai3 − 4ai4 + 5ai5

// ) + (ai6 − 2ai7 + 3ai8 − 4ai9 + 5ai10)

// + ⋯ + (ai5k−4 − 2ai5k−3 + 3ai5k−2 − 4ai5k−1 + 5ai5k
// )

// Input:
//  Dòng đầu tiên là hai số nguyên n, k (5 ≤ 5k ≤ n ≤ 1000)
//  Dòng tiếp theo là dãy số a1, a2, ... , an
// (|ai
// | ≤ 109
// )

// Output:
//  Một dòng duy nhất là kết quả bài toán
#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e18;
const int nmax = 1005;
int n, k;
long long f[nmax][nmax][6], a[nmax];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            for (int t = 1; t <= 5; t++)
                f[i][j][t] = -oo;
    f[1][1][1] = a[1];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= k; j++)
        {
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][5] + a[i]);
            f[i][j][2] = max(f[i - 1][j][2], f[i - 1][j][1] - 2 * a[i]);
            f[i][j][3] = max(f[i - 1][j][3], f[i - 1][j][2] + 3 * a[i]);
            f[i][j][4] = max(f[i - 1][j][4], f[i - 1][j][3] - 4 * a[i]);
            f[i][j][5] = max(f[i - 1][j][5], f[i - 1][j][4] + 5 * a[i]);
        }
    long long ans = -oo;
    for (int i = 5; i <= n; i++)
        ans = max(ans, f[i][k][5]);
    cout << ans;
}
