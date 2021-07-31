// Xét dãy số nguyên dương khác nhau từng đôi một a1, a2, . . . an, trong đó 1 ≤ ai ≤ 106
// , 1 ≤
// n ≤ 105
// ). Với số nguyên x cho trước (1 ≤ x ≤ 200 000) hãy xác định số cặp (ai, aj) thỏa mãn
// các điều kiện:
// • ai + aj = x,
// • 1 ≤ i<j ≤ n.
// Dữ liệu: Vào từ file văn bản SUMX.INP:
// • Dòng đầu tiên chứa số nguyên n,
// • Dòng thứ 2 chứa n số nguyên a1, a2, . . . an,
// • Dòng thứ 3 xhứa số nguyên x.
// Kết quả: Đưa ra file văn bản SUMX.OUT một số nguyên – số cặp tìm được.
#include <bits/stdc++.h>
#define ll long long
#define nmax 1000005
#define fi first
#define se second
#define ii pair<ll, ll>
#define fo(i, a, b) for (int i = a; i <= b; i++)
const ll mod = 1e9 + 7;
using namespace std;
ll n, a[nmax], x, dem = 0;
ii p[nmax];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("l.inp","r",stdin);
    // freopen("l.out","w",stdout);
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    cin >> x;
    fo(i, 1, n - 1)
    {
        ll l = i + 1, r = n, pos = 0;
        while (l <= r)
        {
            ll mid = l + r >> 1;
            if (a[i] + a[mid] >= x)
            {
                pos = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        //cout<<pos; return 0;
        if ((a[pos] + a[i]) == x && pos > i)
            dem++;
    }
    cout << dem;
}
