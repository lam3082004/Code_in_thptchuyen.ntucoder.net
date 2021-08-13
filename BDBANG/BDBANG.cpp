// Bạn có một bảng số m hàng, n cột, mỗi ô có giá trị là 0 hoặc 1.
// Bạn có quyền chọn một hàng hoặc một cột và đổi giá trị các số trên đó, 0 thành 1, 1 thành 0.
// Bạn có quyền thực hiện việc đó nhiều lần.
// Hỏi bạn có thể chuyển bảng đó về thành toàn 0 hoặc 1 hay không.
// Input:
//  Dòng đầu là hai số m, n (1 ≤ m, n ≤ 1000)
//  m dòng tiếp theo, mỗi dòng gồm n số, mỗi số có giá trị là 0 hoặc 1.
// Output:
//  In ra 1 nếu biến đổi được bảng đó, in ra 0 nếu ngược lại
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int mod = 1e9 + 7;
ll m, n, k, x, y, v, a[1005][1005], f[1005], kq = 0;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("NEW.inp", "r", stdin);
    freopen("NEW.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    fo(i, 1, m)
            fo(j, 1, n)
                cin >>
        a[i][j];
    memset(f, 0, sizeof(f));
    fo(i, 1, n)
    {
        if (a[1][i] == 1)
            fo(j, 1, m)
                a[j][i] = 1 - a[j][i];
    }
    fo(i, 2, m)
    {
        fo(j, 1, n) if (a[i][j] == 1)
            f[i] = 1;
    }
    fo(i, 2, m)
    {
        if (f[i] == 1)
            fo(j, 1, n)
                a[i][j] = 1 - a[i][j];
    }
    fo(i, 1, m)
    {
        fo(j, 1, n) if (a[i][j] == 1)
        {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}
