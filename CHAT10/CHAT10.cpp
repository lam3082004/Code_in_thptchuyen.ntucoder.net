// Cho dãy số nguyên gồm 𝑁 phần tử 𝑎1, 𝑎2, … , 𝑎𝑁.Yêu cầu : Gồm 𝑄 truy vấn, mỗi truy vấn là một số nguyên 𝑥, hãy in ra giá trị min 1≤𝑖≤𝑁{ | 𝑥 − 𝑎𝑖 | }.Input :
// • Dòng đầu gồm một số nguyên dương 𝑁(𝑁 ≤ 105);
// • Dòng thứ hai là 𝑁 số nguyên 𝑎1, 𝑎2, … , 𝑎𝑁(| 𝑎𝑖 | ≤ 109);
// • Dòng thứ ba là số nguyên dương 𝑄(𝑄 ≤ 105);
// • 𝑄 dòng tiếp theo, mỗi dòng là một số nguyên 𝑥(| 𝑥 | ≤ 109).Output : Gồm 𝑄 dòng, mỗi dòng là kết quả bài toán với 𝑥 tương ứng
#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<ll, ll>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define fn(i, a, b) for (int i = a; i >= b; i ==)
#define nmax 100005
using namespace std;
const ll mod = 1e9 + 7;
ll n, a[nmax], q, x;
ll f(ll k)
{
    ll l = 1, r = n, mid, pos = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] <= k)
        {
            pos = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return pos;
}
int main()
{
    // freopen("height.inp","r",stdin);
    //freopen("height.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    cin >> q;
    fo(i, 1, q)
    {
        cin >> x;
        ll s = f(x);
        if (x <= a[1])
            cout << a[1] - x << endl;
        if (x > a[1])
        {
            if (s == n)
                cout << x - a[n] << endl;
            if (s < n)
                cout << min(x - a[s], a[s + 1] - x);
            cout << endl;
        }
    }
}
