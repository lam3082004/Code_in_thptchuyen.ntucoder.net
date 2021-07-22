// Cho một dãy nhị phân a gồm N bit và một dãy nhị phân b gồm M bit. Bạn phải tính giá trị của biểu
// thức sau đây:
// max
// 1≤i≤N−M+1
// X
// i≤j≤i+M−1
// (a[j] × b[j − i + 1])
// Dữ liệu
// • Dòng đầu tiên ghi hai số N và M (1 ≤ M ≤ N ≤ 100000).
// • Dòng hai gồm N phần tử của dãy a, mỗi số có giá trị 0 hoặc 1, phân cách với nhau bởi dấu cách.
// • Dòng cuối gồm M phần tử của dãy b, mỗi số có giá trị 0 hoặc 1, phân cách với nhau bởi dấu cách.
// Kết quả
// In ra giá trị của biểu thức cần tính.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define fi first
#define se second
#define LL long long
#define uint unsigned int
#define pb push_back
#define eb emplace_back
#define bit(s, i) ((s >> i) & 1)
#define off(s, i) (s & (~(1 << i)))
#define ii pair<int, int>
#define iii1 pair<ii, int>
#define iii2 pair<int, ii>
#define TASK "BINARY"
using namespace std;
int n, m;
bitset<100010> A, B;
///--------------------------
void readf()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        A[i] = x;
    }
    for (int i = 1; i <= m; ++i)
    {
        int x;
        cin >> x;
        B[i] = x;
    }
}
///--------------------------
void solve()
{
    int ans = 0;
    for (int i = 1; i <= n - m + 1; ++i)
        ans = max(ans, ((int)(A & (B << i)).count()));
    cout << ans;
}
///--------------------------
int main()
{
#ifdef BDP0509
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    readf();
    solve();
}
