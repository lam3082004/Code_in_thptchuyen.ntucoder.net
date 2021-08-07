// Một hệ thống máy tính hiện đang lưu trữ N tập tin, tập tin thứ i được đặt tên là Si
// .
// Nhận thấy rằng có nhiều tập tin không cần thiết, người ta đã xóa đi một số tập tin của hệ thống
// máy tính. Cụ thể, người ta đã thực hiện Q thao tác xóa tập tin. Mỗi thao tác được biểu bởi một
// kí tự c, cho biết thao tác này xóa đi các tập tin có tên chứa ít nhất một kí tự c.
// Sau mỗi thao tác xóa, hãy cho biết còn lại bao nhiêu tập tin trong hệ thống máy tính.
// Dữ liệu
// • Dòng đầu tiên gồm hai số nguyên N và Q (1 ≤ N, Q ≤ 100000)
// • N dòng tiếp theo, dòng thứ i gồm xâu kí tự Si độ dài không vượt quá 8, chỉ gồm các kí tự
// latin in thường - tên của tập tin thứ i.
// • Q dòng tiếp theo, mỗi dòng gồm một kí tự latin in thường c - mô tả một thao tác xóa.
// Kết quả
// • In ra Q dòng, dòng thứ i gồm số tập tin còn lại trong hệ thống máy tính sau khi thực hiện
// thao tác xóa thứ i
#include <bits/stdc++.h>
#define fo(i, a, b) for (ll i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define task "filedel"
using namespace std;
const ll maxn = 1e5;
ll n, a[maxn + 5][35], b[maxn + 5], c[maxn + 5], q;
char x;
string s;
///----------------------------------------------
void read()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n >> q;
}
///----------------------------------------------
void solve()
{
    fo(i, 1, n)
    {
        cin >> s;
        fo(j, 0, s.size() - 1) a[i][s[j] - 96] = 1;
    }
    ll res = n;
    while (q--)
    {
        cin >> x;
        if (c[x - 96] == 1)
            cout << res << '\n';
        else
        {
            fo(i, 1, n)
            {
                if (b[i] == 0 && a[i][x - 96] == 1)
                {
                    --res;
                    b[i] = 1;
                }
            }
            cout << res << '\n';
            c[x - 96] = 1;
        }
    }
}
///----------------------------------------------
int main()
{
    read();
    solve();
}
