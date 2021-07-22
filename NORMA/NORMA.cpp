// NORMA 3s; 64MB
// Nam được bà tặng một dãy số nhân ngày sinh nhật, và cậu ta có thể bán dãy số
// cho một của hàng đồ chơi để lấy tiền mua đồ chơi mà cậu ta thích. Giá trị của
// một dãy số là tích min.max.L, trong đó min là số có giá trị nhỏ nhất, max là số có
// giá trị lớn nhất và L là số các số trong dãy. Nam dự định sẽ bán một dãy con các
// số liên tiếp từ dãy số cậu ta có. Hãy giúp Nam tính tổng giá trị của tất cả các dãy
// con mà cậu ta có thể bán.
// Dữ liệu vào từ file NORMA.INP
// - Dòng đầu tiên chứa một số N (1<= N <= 500 000).
// - Mỗi dòng trong N dòng sau chứa một số nguyên tương ứng trong dãy số
#include <bits/stdc++.h>
#define l unsigned long long
#define name "NORMA"
using namespace std;
l n, a[5005], mina[5005][5005], maxa[5005][5005], t = 0;
int main()
{
#ifndef ONLINE_JUDGE
    freopen(name ".INP", "r", stdin);
    freopen(name ".OUT", "w", stdout);
#endif // ONLINE_JUDGE*/

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - i + 1; j++)
        {
            if (j == 1)
                mina[i][1] = a[i];
            else
                mina[i][j] = min(mina[i][j - 1], a[i + j - 1]);
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - i + 1; j++)
        {
            if (j == 1)
                maxa[i][1] = a[i];
            maxa[i][j] = max(maxa[i][j - 1], a[i + j - 1]);
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - i + 1; j++)
        {
            t += j * mina[i][j] * maxa[i][j];
            t %= 1000000000;
        }
    cout << t;
}
