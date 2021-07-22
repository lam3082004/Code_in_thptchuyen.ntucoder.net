// Ta gọi xâu nhị phân độ dài N là dãy gồm N kí hiệu, mỗi kí hiệu chỉ là 1 hoặc 0. Như
// đã biết, có tất cả 2N xâu như vậy. Trong bài toán này, ta chỉ quan tâm đến những
// xâu nhị phân độ dài N chứa đoạn gồm K số 1 liên tiếp. Vì con số này là rất lớn khi N
// và K lớn, nên chỉ cần đưa ra phần dư trong phép chia của số này cho 1000007.
// Cho trước hai số nguyên dương N và K, hãy tìm phần dư trong phép chia của số
// lượng xâu nhị phân độ dài N chứa đoạn gồm K số 1 liên tiếp cho 1000007.

// Dữ liệu:
//  Dòng 1: Gồm hai số nguyên dương N và K (1 ≤ N ≤ 100000, 1 ≤ K ≤100)
// Kết quả: In ra phần dư trong phép chia của số lượng xâu nhị phân thỏa mãn cho
// 1000007.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define fi first
#define se second
#define LL long long
#define pb push_back
#define eb emplace_back
#define bit(s, i) ((s >> i) & 1)
#define off(s, i) (s & (~(1 << i)))
#define ii pair<int, int>
#define TASK "BITSTR"
using namespace std;
LL n, k, f[100010], pw[100010];
const int base = 1e6 + 7;
///--------------------------
void readf()
{
    cin >> n >> k;
}
///--------------------------
void solve()
{
    pw[0] = 1;
    fo(i, 1, n) pw[i] = (pw[i - 1] * 2) % base;
    LL s;
    f[k] = s = 1;
    fo(i, k + 1, n)
    {
        f[i] = s;
        f[i] = (f[i] + pw[i - k]) % base;
        s = ((s + f[i] - f[max(0 * 1LL, i - k)]) % base + base) % base;
    }
    cout << f[n];
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
