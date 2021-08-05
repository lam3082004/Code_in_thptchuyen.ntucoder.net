// Bạn có một từ gồm N chữ cái in thường và trong đó có M chữ cái bị mờ đi không thể đọc được.Ngoài ra, bạn còn có M dòng gợi ý dùng để khôi phục lại từ ban đầu.Dòng thứ i sẽ có K chữ cái là những chữ có thể xuất hiện ở vị trí chữ cái bị mờ thứ i.Từ những gợi ý này bạn có thể tạo ra được một dãy các từ, sắp xếp dãy các từ này tăng dần theo thứ tứ chữ cái và từ ban đầu bạn cần tìm sẽ nằm ở vị trí thứ X.Các bạn hãy viết một chương trình để khôi phục lại từ này nhé !Dữ liệu
// • Dòng đầu tiên gồm các số tự nhiên N, M, K và X(1 ≤ N ≤ 500, 1 ≤ M ≤ N, 1 ≤ K ≤ 26, 1 ≤ X ≤ 109).
// • Dòng thứ hai gồm một xâu gồm các chữ cái in thường và dấu #đại diện cho những vị trí bị mờ.
// • M dòng tiếp theo, mỗi dòng gồm K chữ cái mà bạn có thể điền vào vị trí bị mờ.Kết quả
// • Gồm một dòng duy nhất là từ mà bạn tìm được.Dữ liệu luôn đảm bảo bài toán có kết quả
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
#define ll long long
#define ii pair<ll, ll>
#define fifi first.first
#define fise first.second
#define se second
using namespace std;
const int mod = 1e9 + 7;
ll n, a, b, m, k, x, t = 0, dem = 0, kq = 0;
string q, s[505];
stack<char> f;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("NEW.inp", "r", stdin);
    freopen("NEW.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> x >> q;
    q = ' ' + q;
    fo(i, 1, m)
    {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
    }
    x--;
    for (int i = m; i >= 1; i--)
    {
        f.push(s[i][x % k]);
        x /= k;
    }
    fo(i, 1, n) if (q[i] == '#') cout << f.top(), f.pop();
    else cout << q[i];
}
