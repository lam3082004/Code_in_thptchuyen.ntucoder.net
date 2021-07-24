// Trong mặt phẳng Oxy có hai đường thẳng song song với nhau là L1, L2 và có n đoạn thẳng
// nối giữa chúng. Mỗi đoạn thẳng có hai đầu mút là (xi
// , yi) và (x
// 0
// i
// , y
// 0
// i
// ) với (xi
// , yi) ∈ L1 và (x
// 0
// i
// , y
// 0
// i
// ) ∈ L2
// Yêu cầu: Cho toạ độ các đoạn thẳng, tìm số đoạn thẳng không giao nhau nhiều nhất
// Input
// • Dòng đầu tiên là n - số đoạn thẳng
// • n dòng tiếp theo chứa 4 số nguyên xi
// , yi
// , x
// 0
// i
// , y
// 0
// i
// là toạ độ các đầu mút của từng đoạn thẳng

// Output
// • Một dòng duy nhất là số đoạn thẳng thu được
// Giới hạn
// • 1 ≤ n ≤ 100000
// • −109 ≤ xi
// , yi
// , x
// 0
// i
// , y
// 0
// i ≤ 109

// • Dữ liệu đảm bảo rằng các đầu mút của các đoạn thẳng là các điểm phân biệt
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define nmax 1000001
#define se second
#define fi first
ll x, y, z, n, c[nmax];
pair<ll, ll> a[nmax], b[nmax];
map<pair<ll, ll>, ll> p;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    bool check = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> b[i].fi >> a[i].se >> b[i].se;
        p[{b[i].fi, b[i].se}]++;
        if (p[{b[i].fi, b[i].se}] > 1)
            check = 1;
    }
    if (check == 0)
    {
        sort(b + 1, b + 1 + n);
        x = y = z = 0;
        for (ll i = 1; i <= n; i++)
        {
            x = lower_bound(c + 1, c + y + 1, b[i].se) - c;
            // cout<<y<<' '<<x<<'\n';
            c[x] = b[i].se;
            y = max(y, x);
        }
        cout << y;
        return 0;
    }
    sort(a + 1, a + 1 + n);
    x = y = z = 0;
    for (ll i = 1; i <= n; i++)
    {
        x = lower_bound(c + 1, c + y + 1, a[i].se) - c;
        // cout<<y<<' '<<x<<'\n';
        c[x] = a[i].se;
        y = max(y, x);
    }
    cout << y;
}
