// Cho hai đường thẳng song song nằm ngang a và b. Trên mỗi đường thẳng, người ta chọn lấy n
// điểm phân biệt và gán cho mỗi điểm một số nguyên dương là nhãn của điểm đó:
// • Trên đường thẳng a, điểm thứ i (theo thứ tự từ trái qua phải) được gắn nhãn là ai
// • Trên đường thẳng b, điểm thứ j (theo thứ tự từ trái qua phải) được gắn nhãn là bj
// Ở đây, (a1, ..., an), (b1, ..., bn) là các hoán vị của dãy số (1, 2, ..., n).
// Yêu cầu: Hãy chỉ ra một số tối đa các đoạn thẳng thoả mãn:
// • Mỗi đoạn thẳng phải nối hai điểm có chênh lệch nhãn không vượt quá k: Một điểm trên đường
// thẳng a và một điểm trên đường thẳng b. Nói cách khác, nếu ai và bj được nối với nhau, thì
// |ai − bj
// | ≤ k

// • Các đoạn thẳng đôi một không có điểm chung

// Input
// • Dòng đầu tiên là hai số nguyên n, k
// • Dòng thứ hai là n số nguyên - a1, ..., an
// • Dòng thứ ba là n số nguyên - b1, ..., bn
// Output
// • Một số nguyên duy nhất là số đoạn thẳng nối được
// Giới hạn
// • 1 ≤ n ≤ 100000
// • 0 ≤ k ≤ 4
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define fod(i, a, b) for (int i = a; i >= b; i--)
#define nmax 100005
#define ii pair<int, int>
#define fi first
#define se second
#define oo 1e18
using namespace std;
const int mod = 1e8 + 7;
ll n, k, a[nmax], b[nmax], t[nmax], pos[nmax], d[10];
void up(int m, ll val)
{
    while (m < nmax)
    {
        t[m] = max(t[m], val);
        m += m & -m;
    }
}
ll get(int m)
{
    ll tmp = 0;
    while (m > 0)
    {
        tmp = max(tmp, t[m]);
        m -= m & -m;
    }
    return tmp;
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
    cin >> n >> k;
    fo(i, 1, n)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    fo(i, 1, n)
            cin >>
        b[i];
    ll ans = 0;
    fo(i, 1, n)
    {
        fo(j, -k, k)
        {
            ll x = b[i] + j;
            if (x < 1 || x > n)
                continue;
            ll res = get(pos[x] - 1);
            d[j + k + 1] = res;
            ans = max(ans, res + 1);
        }
        fo(j, -k, k)
        {
            ll x = b[i] + j;
            if (x < 1 || x > n)
                continue;
            up(pos[x], d[j + k + 1] + 1);
        }
    }
    cout << ans;
}
