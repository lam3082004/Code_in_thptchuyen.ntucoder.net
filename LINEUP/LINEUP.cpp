// Cho
// n
//  thanh gỗ hãy sắp xếp các thành gỗ thành các hàng sao cho ít hàng nhất có thể, biết thanh gỗ có chiều rộng
// w
// 2
//  và chiều dài
// l
// 2
//  sắp được sau thanh gỗ có chiều rộng là
// w
// 1
//  chiều dài
// l
// 1
//  nếu
// w
// 2
// <
// w
// 1
//  và
// l
// 2
// <
// l
// 1

// Input:

// - Dòng đầu là số test t < 20.

// - Mỗi test gồm 2 dòng:

//       + Dòng đầu gồm 1 số nguyên dương
// n
//  (
// n
// ≤
// 20000
// ).

//       + Dòng tiếp theo chứa 2*
// n
//  số nguyên dương
// w
// i
//  và
// l
// i
//  bé hơn 20000.

// Output: In ra mỗi test một dòng là số hàng bé nhất tạo thành.
#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5 + 5;
struct ii
{
    int fi, se;
};
ii a[nmax];
bool cmp(ii a, ii b)
{
    if (a.fi < b.fi)
        return true;
    if (a.fi > b.fi)
        return false;
    return (a.se > b.se);
}
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].fi >> a[i].se;
        sort(a + 1, a + n + 1, cmp);
        deque<ii> dq;
        for (int i = 1; i <= n; i++)
            if (dq.empty() || a[i].se <= dq.back().se || a[i].fi == dq.back().fi)
                dq.push_back(a[i]);
            else
            {
                int l = 0, r = dq.size() - 1;
                while (l <= r)
                {
                    int mid = l + r >> 1;
                    if (a[i].se <= dq[mid].se)
                        l = mid + 1;
                    else
                        r = mid - 1;
                }
                dq[l] = a[i];
            }
        cout << dq.size() << endl;
    }
}
