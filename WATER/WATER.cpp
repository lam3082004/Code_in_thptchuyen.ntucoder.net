// Nền phẳng của một công trình xây dựng được chia thành lưới ô vuông đơn vị kích thước m × n
// ô. Trên mỗi ô (i, j) của lưới, người ta dựng một cột bê tông hình hộp có đáy là ô (i, j) và chiều
// cao là hij đơn vị. Sau khi dựng xong thì trời đổ mưa to và đủ lâu. Nhà thầu xây dựng muốn tính
// lượng nước đọng lại giữa các cột để có kế hoạch thi công tiếp theo. Giả thiết, nước ko thẩm thấu
// qua các cột bê tông cũng như ko rò rỉ qua các đường ghép giữa chúng.
// Nhiệm vụ của bạn là giúp nhà thầu tính toán lượng nước đọng lại giữa các cột
// Input
// • Dòng đầu tiên là hai số nguyên dương m, n
// • Dòng thứ i trong m dòng tiếp theo, mỗi dòng là n số nguyên dương hi1, hi2, ..., hin
// Output
// • Một số nguyên duy nhất là số đơn vị khối nước đọng lại
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define fod(i, a, b) for (int i = a; i >= b; i--)
#define nmax 1000005
#define nmax2 1000005
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e18
using namespace std;
const int mod = 1e9 + 7;
struct wat
{
    ll v, x, y;
};
struct cmp
{
    bool operator()(wat a, wat b)
    {
        return a.v > b.v;
    }
};
ll m, n, a[105][105], d[105][105];
int x[] = {1, 0, -1, 0};
int y[] = {0, 1, 0, -1};
bool vs[105][105];
priority_queue<wat, vector<wat>, cmp> q;
bool check(int u, int v)
{
    return (u > 0 && u <= m && v > 0 && v <= n);
}
void xuli()
{
    memset(vs, 1, sizeof vs);
    fo(i, 1, m)
        fo(j, 1, n)
            vs[i][j] = 0;
    fo(i, 1, m)
    {
        q.push({0, i, 0});
        q.push({0, i, n + 1});
    }
    fo(i, 1, n)
    {
        q.push({0, 0, i});
        q.push({0, m + 1, i});
    }
    while (!q.empty())
    {
        wat k = q.top();
        q.pop();
        fo(i, 0, 3)
        {
            int u = k.x + x[i];
            int v = k.y + y[i];
            if (!vs[u][v] && check(u, v))
            {
                if (a[u][v] >= k.v)
                    d[u][v] = a[u][v];
                else
                    d[u][v] = k.v;
                q.push({d[u][v], u, v});
                vs[u][v] = 1;
            }
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
    cin >> m >> n;
    fo(i, 1, m)
            fo(j, 1, n)
                cin >>
        a[i][j];
    xuli();
    ll ans = 0;
    //    fo(i,1,m)
    //    {
    //        fo(j,1,n)
    //            cout<<d[i][j]<<' ';
    //        cout<<'\n';
    //    }
    fo(i, 1, m)
        fo(j, 1, n)
            ans += d[i][j] - a[i][j];
    cout << ans;
}
