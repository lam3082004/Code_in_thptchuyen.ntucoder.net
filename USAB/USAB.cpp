// Một số nguyên dương được phân tích thành thừa số nguyên tố như sau:
// Cho , đếm số lượng ước của trong thuộc
// Input
// - Dòng đầu chứa số
// - dòng tiếp theo, dòng thứ chứa hai số và
// - 3 dòng cuối tương ứng với 3 truy vấn, mỗi dòng chứa hai số nguyên tương ứng
// với một truy vấn.
// Output
// - Gồm 3 dòng, mỗi dòng ghi ước số tìm được trả lời cho truy vấn tương ứng ở dữ liệu
#include <bits/stdc++.h>
#define ll long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;

void Init()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const int maxn = 1e9;
int m;
II p[101];
int D[101];
int A, B, res;

void BK(int d, int S)
{
    if (A <= S && S <= B)
        res++;
    for (int i = d; i <= m; ++i)
        if (S <= maxn / p[i].fi)
        {
            if (D[i] < p[i].se)
            {
                D[i]++;
                BK(i, S * p[i].fi);
                D[i]--;
            }
        }
        else
            return;
}

void Solve()
{
    cin >> m;
    for (int i = 1; i <= m; ++i)
        cin >> p[i].fi >> p[i].se;
    sort(p + 1, p + m + 1);
    for (int i = 1; i <= 3; ++i)
    {
        cin >> A >> B;
        res = 0;
        BK(1, 1);
        cout << res << endl;
    }
}

int main()
{
    Init();
    Solve();
}
