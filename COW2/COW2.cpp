// FJ xây
// (2 ≤
// ≤ 100000) chuồng bò. Các chuồng nằm trên một đường thẳng với tọa độ

// ,
// , ... ,
// (0 ≤
// ≤ 10
// )

// FJ có
// (2 ≤
// ≤
// ) con bò và ông muốn nhốt các con bò này vào các chuồng sao cho khoảng cách nhỏ

// nhất của 2 con bò là lớn nhất có thể.
// Dữ liệu:
// Dòng 1 gồm hai số
// và
// .
// Dòng 2 đến dòng

// + 1: dòng

// + 1 gồm một số nguyên là tọa độ

// của chuồng bò

// Kết quả: Một dòng duy nhất là khoảng cách lớn nhất có thể được
#include <bits/stdc++.h>
#define ll long long
#define nmax 100005
#define fo(i, a, b) for (ll i = a; i <= b; i++)
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int mod = 1e9 + 7;
ll m, n, t, a[nmax], ans, kq = 0;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("NEW.inp", "r", stdin);
    freopen("NEW.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    fo(i, 1, n)
            cin >>
        a[i];
    sort(a + 1, a + 1 + n);
    ll l = 1, r = 1e9;
    while (l <= r)
    {
        ll mid = l + r >> 1;
        ll dem = 0;
        t = a[1];
        fo(i, 2, n) if (a[i] - t >= mid)
        {
            dem++;
            t = a[i];
        }
        if (dem + 1 >= m)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans << '\n';
}
