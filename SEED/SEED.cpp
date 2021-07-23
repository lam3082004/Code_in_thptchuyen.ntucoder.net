// SEED
// Một SEED là một xâu chỉ gồm 2 loại ký tự “1” hoặc “*” thỏa điều kiện bắt đầu và kết thúc của
// SEED là “1”. Một SEED s được gọi là “hit” được xâu nhị phân x độ dài N nếu tồn tại một vị trí i
// trên xâu x thỏa mãn: Nếu ký tự thứ k của xâu s bằng “1” thì ký tự thứ i+k-1 của x cũng bằng “1”.
// Ví dụ: 1*1 có thể “hit” được các xâu 0101100, 1110000, 1010111 nhưng không “hit” được xâu
// 0100010.
// Yêu cầu: Cho N và một SEED s, đếm số lượng xâu nhị phân độ dài N mà s “hit” được.
// Input
// - Dòng 1: chứa số N (N≤50)
// - Dòng 2: ghi SEED s là một xâu chỉ gồm 2 loại ký tự “1” và “*”
// Output
// - Gồm một dòng, chứa một số là số lượng xâu nhị phân mà s có thể “hit” được.
#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5 + 5;
string s;
int n;
long long ans, dp[55][40000];
bool check(int A, int mask)
{
    while (mask > 0)
    {
        if (mask % 2 == 1 && A % 2 == 0)
            return false;
        mask /= 2;
        A /= 2;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;
    int lens = s.size();
    s = " " + s;
    int tmp = 0;
    for (int i = 1; i <= lens; i++)
    {
        tmp <<= 1;
        if (s[i] == '1')
            tmp++;
    }
    for (int i = lens; i <= n; i++)
        for (int j = 0; j < (1 << lens); j++)
            if (check(j, tmp))
                dp[i][j] = (1ll << i - lens);
            else
            {
                int res = j / 2;
                dp[i][j] = dp[i - 1][res] + dp[i - 1][res + (1 << lens - 1)];
            }
    for (int i = 0; i < (1 << lens); i++)
        ans += dp[n][i];
    cout << ans;
}
