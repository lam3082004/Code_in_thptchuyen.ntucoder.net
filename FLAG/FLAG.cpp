// ARSENAL1886 có một lá cờ kích thước m × n, ban đầu mỗi ô được tô 1 trong các màu: ′a
// ′ ... ′z′
// Bây giờ anh ấy muốn tô lại một số ô của lá cờ bằng các màu trên, thoả mãn điều kiện không có 2 ô nào
// chung cạnh cùng màu và mỗi hàng chỉ dùng đúng 2 màu
// Hãy giúp ARSENAL1886 thay đổi màu của ít ô nhất để được một lá cờ thoả mãn yêu cầu
// Input:
//  Dòng đầu là 2 số m, n (1 ≤ m, n ≤ 50)
//  m dòng tiếp theo, mỗi dòng là n chữ cái thường (′a
// ′
// . . .
// ′
// z
// ′
// )

// Output:
//  Một dòng duy nhất là số ô ít nhất cần thay đổi
#include <bits/stdc++.h>
using namespace std;
const int nmax = 55;
const int oo = 1e9 + 7;
int dp[nmax][30][30], ans = oo;
char c[nmax][nmax];
int m, n;
int get(int a, int b, int pos)
{
    int dem = 0;
    for (int i = 1; i <= n; i++)
        if (i & 1)
        {
            if (c[pos][i] - 'a' != a)
                dem++;
        }
        else if (c[pos][i] - 'a' != b)
            dem++;
    return dem;
}
int main()
{
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    for (int i = 0; i <= 25; i++)
        for (int j = 0; j <= 25; j++)
            if (i == j)
                dp[1][i][j] = oo;
            else
                dp[1][i][j] = get(i, j, 1);
    for (int i = 2; i <= m; i++)
        for (int x = 0; x <= 25; x++)
            for (int y = 0; y <= 25; y++)
            {
                dp[i][x][y] = oo;
                if (x != y)
                {
                    int tmp = get(x, y, i);
                    for (int u = 0; u <= 25; u++)
                        for (int v = 0; v <= 25; v++)
                            if (x != u && y != v)
                                dp[i][x][y] = min(dp[i][x][y], dp[i - 1][u][v] + tmp);
                }
            }
    for (int i = 0; i <= 25; i++)
        for (int j = 0; j <= 25; j++)
            ans = min(ans, dp[m][i][j]);
    cout << ans;
}
