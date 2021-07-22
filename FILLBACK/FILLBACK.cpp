// Cho N dòng, dòng thứ i chứa ai ô trống. Và M xâu kí tự, xâu thứ j chứa 2
// bj kí tự.
// Bạn cần điền các xâu kí tự vào trong N dòng sao cho:
// • Một dòng có thể chứa nhiều xâu. Nhưng một xâu chỉ được điền vào một dòng duy nhất.
// • Các kí tự của một xâu phải được điền vào một đoạn các ô trống liên tiếp.
// • Một ô trống chỉ được chứa một kí tự duy nhất.
// Yêu cầu tìm số lượng xâu kí tự lớn nhất có thể điền.
// Dữ liệu
// • Gồm 3 dòng: dòng đầu chứa 2 số nguyên dương N và M, hai dòng tiếp theo lần lượt chứa
// hai dãy số nguyên a và b.
// Kết quả
// • In ra số lượng xâu kí tự lớn nhất có thể điền được.
// Giới hạn
// • N, M ≤ 106
// .
// • 1 ≤ ai ≤ 109
// .
// • 1 ≤ 2
// bi ≤ 109
// .
#include <bits/stdc++.h>
#define ll long long
#define task "test"
using namespace std;

void Init()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll D[30];
int b[1000001];
int n, m, i, j, p, x;

void Solve()
{
    cin >> n >> m;
    for (i = 1; i <= n; ++i)
    {
        cin >> x;
        for (j = 1, p = 0; j <= x; j <<= 1, ++p)
            D[p] += x / j;
    }
    for (i = 1; i <= m; ++i)
        cin >> b[i];
    sort(b + 1, b + m + 1);
    for (i = 1; i <= m; ++i)
        for (j = b[i], x = 1; j >= 0; x <<= 1, --j)
        {
            D[j] -= x;
            if (D[j] < 0)
            {
                cout << i - 1;
                return;
            }
        }
    cout << m;
}

int main()
{
    Init();
    Solve();
}
