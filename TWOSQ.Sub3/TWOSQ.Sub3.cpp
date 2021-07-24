// Tiếp tục với series chuyện có thật ... do ARSENAL1886 bịa ra!!!
// ARSENAL1886 vừa chiến thắng cuộc thi “Tìm hiểu kiến thức vũ trụ” và nhận được phần thưởng
// do ban tổ chức tài trợ. Phần thưởng được bố trí trên một bảng kích thước m × n (tượng trưng cho
// vũ trụ), các dòng của bảng được đánh số từ 1 đến m từ trên xuống dưới, các cột của bảng được
// đánh số từ 1 đến n từ trái qua phải. Ô nằm trên giao của dòng i và cột j được gọi là ô (i,j) và trên
// ô đó chứa một món quà có giá trị là aij (1 ≤ i ≤ m, 1 ≤ j ≤ n)
// Để nhận phần thưởng, ARSENAL1886 sẽ chọn 2 hình vuông kích thước k × k không giao nhau.
// Nhân ngày 20/10, anh ấy muốn tìm hai hình vuông sao cho tổng giá trị của các món quà trong hai
// hình vuông đó là lớn nhất (để có một món quà thật ý nghĩa tặng bạn gái, mà bạn đó là ai thì ... đến
// cả ARSENAL1886 còn không biết nữa :D)
// Yêu cầu: Cho m, n, k và giá trị các phần quà trên bảng. Hãy đưa ra tổng giá trị lớn nhất có thể được
// khi chọn hai hình vuông k × k
// Input:
// • Dòng thứ nhất chứa ba số nguyên dương m, n, k
// • Dòng thứ i trong số m dòng tiếp theo chứa n số nguyên dương, số thứ j là
// aij (1 ≤ aij ≤ 106
// )

// • k luôn thoả mãn có cách chọn 2 hình vuông
// Output:
// • Một số nguyên duy nhất là kết quả bài toán
#include <bits/stdc++.h>
using namespace std;
const int nmax = 100005;
vector<long long> h[nmax], h2[nmax], a[nmax];
long long ans = 0;
vector<long long> L[nmax], maxL[nmax];
vector<long long> R[nmax], maxR[nmax];
int m, n, k, x;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("KC2DIV1B.inp","r",stdin);
    //freopen("KC2DIV1B.out","w",stdout);
    cin >> m >> n >> k;
    for (int i = 0; i <= m + 1; i++)
    {
        a[i].resize(n + 2);
        h[i].resize(n + 2);
        h2[i].resize(n + 2);
        L[i].resize(n + 2);
        maxL[i].resize(n + 2);
        R[i].resize(n + 2);
        maxR[i].resize(n + 2);
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            a[i][j] = x;
            if (i > k)
                h[i][j] = h[i - 1][j] + a[i][j] - a[i - k][j];
            else
                h[i][j] = h[i - 1][j] + a[i][j];
        }
    for (int i = m; i >= 1; i--)
        for (int j = n; j >= 1; j--)
        {
            if (i + k <= m)
                h2[i][j] = h2[i + 1][j] + a[i][j] - a[i + k][j];
            else
                h2[i][j] = h2[i + 1][j] + a[i][j];
        }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (j > k)
                L[i][j] = L[i][j - 1] + h[i][j] - h[i][j - k];
            else
                L[i][j] = L[i][j - 1] + h[i][j];
        }
    maxL[k][k] = L[k][k];
    for (int i = k + 1; i <= n; i++)
        maxL[k][i] = max(maxL[k][i - 1], L[k][i]);
    for (int i = k + 1; i <= m; i++)
        for (int j = k; j <= n; j++)
            maxL[i][j] = max(maxL[i - 1][j], max(maxL[i][j - 1], L[i][j]));
    for (int i = m; i >= 1; i--)
        for (int j = n; j >= 1; j--)
        {
            if (j + k <= n)
                R[i][j] = R[i][j + 1] + h2[i][j] - h2[i][j + k];
            else
                R[i][j] = R[i][j + 1] + h2[i][j];
        }
    maxR[m - k + 1][n - k + 1] = R[m - k + 1][n - k + 1];
    for (int i = n - k + 1; i >= 1; i--)
        maxR[m - k + 1][i] = max(maxR[m - k + 1][i + 1], R[m - k + 1][i]);
    for (int i = m - k; i >= 1; i--)
        for (int j = n - k + 1; j >= 1; j--)
            maxR[i][j] = max(maxR[i + 1][j], max(maxR[i][j + 1], R[i][j]));
    for (int i = k; i <= m; i++)
        for (int j = k; j <= n; j++)
            ans = max(ans, maxL[i][j] + max(maxR[1][j + 1], maxR[i + 1][1]));
    cout << ans << endl;
}
