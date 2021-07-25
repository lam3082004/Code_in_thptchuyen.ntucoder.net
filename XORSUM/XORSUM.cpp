// Cho dãy số không âm có N phần tử, số thứ i có giá trị là Ai

// . Tìm số K lớn nhất sao cho:

// • B =
// P
// N
// i=1
// (Ai ⊕ K), với ⊕ là phép toán xor.
// • B ≤ M, với M là số nguyên không âm cho trước.
// Dữ liệu
// • Dòng đầu tiên chứa 2 số N và M.
// • Dòng thứ 2 hai chứa N số nguyên Ai
// .

// Kết quả
// • In ra một số K lớn nhất cần tìm, hoặc in ra -1 nếu không tìm ra số K thỏa mãn yêu cầu đề
// bài.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 300005
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e18
#define ar array
using namespace std;
const int mod = 1e9 + 7;
ll n, m, a[1005], cnt[2][55], f[55], k[55];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xorsum.inp", "r", stdin);
    freopen("xorsum.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    f[0] = 1;
    fo(i, 1, 50)
        f[i] = f[i - 1] * 2;
    fo(i, 1, n)
    {
        cin >> a[i];
        fo(j, 0, 50)
            cnt[(a[i] >> j) & 1][j]++;
    }
    ll res = 0;
    fo(i, 0, 50)
    {
        ll tmp = min(cnt[0][i], cnt[1][i]);
        if (cnt[0][i] < cnt[1][i])
            k[i] = 1;
        else
            k[i] = 0;
        res += tmp * f[i];
    }
    if (res > m)
    {
        cout << -1;
        return 0;
    }
    ll K = 0;
    fo(i, 0, 50) if (k[i] == 1)
        K += f[i];
    for (int i = 50; i >= 0; i--)
    {
        if (k[i] == 0)
        {
            K += f[i];
            res = 0;
            fo(j, 1, n)
                res += (K ^ a[j]);
            if (res > m)
                K -= f[i];
        }
    }
    cout << K;
}
