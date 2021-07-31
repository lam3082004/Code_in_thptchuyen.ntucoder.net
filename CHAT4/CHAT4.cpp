// Cho bảng số mxn phần tử, phần tử ở hàng i, cột j có giá trị là i*j. Tìm phần tử nhỏ thứ k trong bảng số này.

// Dữ liệu:

// -  Một dòng duy nhất ghi 3 số m, n, k (0<k<=mxn, 0<m,n<=105).

// Kết quả:

// -  Một dòng ghi giá trị của phần tử nhỏ thứ k trong bảng số
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define fi first
#define se second
#define ii pair<ll, ll>
#define maxn 1000005
#define ll long long
const int base = 31;
const ll mod = 1e9 + 7;
using namespace std;
ll m, n, k;
int main()
{
    // freopen("string2.inp","r",stdin);
    //freopen("string2.out","w",stdout);
    cin >> m >> n >> k;
    ll l = 1, r = m * n;
    while (l <= r)
    {
        ll mid = l + r >> 1, ans = 0;
        fo(i, 1, n) ans += min(mid / i, m);
        if (ans >= k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << r + 1;
}
