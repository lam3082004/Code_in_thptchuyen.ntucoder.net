// Cho một ma trận A kích thước M x N. Các hàng được đánh số từ 1 đến M, các cột được đánh
// số từ 1 đến N. Ô nằm ở hàng thứ i, cột thứ j mang giá trị Aij .
// F(i, j, k) với 1 ≤ i ≤ M, 1 ≤ j ≤ N, 0 ≤ k ≤ min(i − 1, j − 1, M − i, N − j) được định nghĩa là
// tổng của các Axy thõa mãn |i − x| + |j − y| ≤ k.
// Tìm F(i, j, k) lớn nhất tổng tại trong ma trận.
// Dữ liệu
// • Dòng đầu gồm hai số nguyên dương M và N
// • M dòng tiếp theo, mỗi dòng gồm N số, diễn tả ma trận A
// Kết quả
// • Một dòng duy nhất ghi F(i, j, k) lớn nhất tồn trại trong ma trận
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (ll i = a; i <= b; i++)
using namespace std;
ll n, m, maxx = -1e9, a[505][505], f[1505][1505], s[1505][1505];
int main()
{
    cin >> m >> n;
    fo(i, 1, m)
            fo(j, 1, n) cin >>
        a[i][j];
    memset(f, 0, sizeof(f));
    fo(i, 1, m)
        fo(j, 1, n)
            f[i - j + n][i + j] = a[i][j];
    fo(i, 1, m + n - 1)
        fo(j, 2, m + n)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + f[i][j];
    fo(i, 1, m)
        fo(j, 1, n)
    {
        ll k = min(i - 1, min(m - i, min(j - 1, n - j)));
        fo(t, 0, k)
            maxx = max(maxx, s[i + t - j + n][j + i + t] - s[i + t - j + n][j + i - t - 1] - s[i - t - j + n - 1][j + i + t] + s[i - t - j + n - 1][j + i - t - 1]);
    }
    cout << maxx;
}
