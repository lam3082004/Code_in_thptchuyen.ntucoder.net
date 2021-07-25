// Người ta định nghĩa bảng số A và bảng số B là tương đồng bậc k nếu:
// 1) Hai bảng có cùng kích thước (cùng số dòng, cùng số cột);
// 2) Hai phần tử tương ứng chênh lệch không quá k (|A[i, j] - B[i,j]| ≤ k).
// Yêu cầu
// Cho số nguyên k và 2 bảng số P, Q có cùng kích thước m × n, hãy tìm bảng số C
// và D tương ứng là bảng con của bảng số P và Q mà C và D tương đồng có cùng
// kích thước r × c và r × c đạt giá trị lớn nhất.
// Dữ liệu
//  Dòng đầu chứa ba số nguyên m, n, k;
//  m dòng sau, mỗi dòng n số nguyên không âm mô tả bảng số P;
//  m dòng sau, mỗi dòng n số nguyên không âm mô tả bảng số Q;
//  Các số không vượt quá 109.
// Kết quả
//  Giá trị r × c đạt giá trị lớn nhất tìm được.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; ++i)
#define fod(i, a, b) for (int i = a; i >= b; --i)
#define nmax 100005
#define nmax2 65000000
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e18
using namespace std;
const int mod = 1e9 + 7;
int m, n, k, a[70][70], b[70][70], d[70][70], L[70], R[70];
int ans = 0;
void xuli(int t)
{
    fo(r, 1, m)
        fo(c, 1, n)
    {
        fo(i, 1, r)
            fo(j, 1, c)
        {
            int x, y, u, v, res;
            if (t & 1)
            {
                x = i, y = j;
                u = m - r + i, v = n - c + j;
            }
            else
            {
                x = i, y = n - c + j;
                u = m - r + i, v = j;
            }
            if (t <= 2)
                res = abs(b[x][y] - a[u][v]);
            else
                res = abs(a[x][y] - b[u][v]);
            if (res <= k)
                d[i][j] = 1;
            else
                d[i][j] = 0;
        }
        fo(i, 1, r)
        {
            fo(j, 1, c) if (d[i - 1][j] > 0 && d[i][j] > 0)
                d[i][j] += d[i - 1][j];
            fo(j, 1, c)
            {
                L[j] = j - 1;
                while (L[j] > 0 && d[i][L[j]] >= d[i][j])
                    L[j] = L[L[j]];
            }
            fod(j, c, 1)
            {
                R[j] = j + 1;
                while (R[j] <= c && d[i][R[j]] >= d[i][j])
                    R[j] = R[R[j]];
            }
            fo(j, 1, c)
                ans = max(ans, d[i][j] * (R[j] - L[j] - 1));
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("new.inp", "r", stdin);
    freopen("new.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> k;
    fo(i, 1, m)
            fo(j, 1, n)
                cin >>
        a[i][j];
    fo(i, 1, m)
            fo(j, 1, n)
                cin >>
        b[i][j];
    xuli(1);
    xuli(2);
    xuli(3);
    xuli(4);
    cout << ans;
}
