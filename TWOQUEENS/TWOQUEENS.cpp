// Trên bàn cờ vua kích thước m × n có hai quân hậu – 1 quân hậu trắng và 1 quân hậu đen.
// Ngoài ra, có 1 quân tốt cũng nằm trên bàn cờ ở vị trí (r, c) (1 ≤ r ≤ m, 1 ≤ c ≤ n).
// Như đã biết trong luật cờ vua, mỗi quân hậu có thể ăn được các quân cờ nằm cùng hàng
// ngang, hàng dọc và đường chéo với điều kiện là giữa quân hậu và quân cờ đó không có quân
// cờ nào khác chặn đường.
// Yêu cầu: Cho biết m, n, r, c. Tính số cách đặt quân hai quân hậu sao cho chúng không ăn nhau.
// Hai cách đặt khác nhau khi vị trí của hậu trắng khác nhau hoặc vị trí của hậu đen khác nhau.
// Input:
//  Dòng đầu là T – số lượng test (1 ≤ T ≤ 1000).
//  T dòng tiếp theo, mỗi dòng là 4 số nguyên m, n, x, y
// Output:
//  Với mỗi test, in ra trên một dòng chứa một số nguyên – số cách xếp 2 quân hậu
#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5 + 5;
int t, n, m, r, c;
long long ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("TWOQUEENS.inp","r",stdin);
    //freopen("TWOQUEENS.out","w",stdout);
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> m >> n >> r >> c;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (i != r || j != c)
                {
                    ans += (m - 1) * (n - 1);
                    ans -= (min(n - j, m - i) + min(i - 1, j - 1) + min(i - 1, n - j) + min(j - 1, m - i) + 1);
                    if (j == c)
                    {
                        if (i < r)
                            ans += m - r + 1;
                        else
                            ans += r;
                    }
                    if (i == r)
                    {
                        if (j < c)
                            ans += n - c + 1;
                        else
                            ans += c;
                    }
                    if (abs(i - r) == abs(j - c))
                    {
                        if (i < r)
                        {
                            if (j > c)
                                ans += min(m - r, c - 1) + 1;
                            else
                                ans += min(m - r, n - c) + 1;
                        }
                        else
                        {
                            if (j > c)
                                ans += min(r - 1, c - 1) + 1;
                            else
                                ans += min(r - 1, n - c) + 1;
                        }
                    }
                }
        cout << ans << endl;
    }
}
