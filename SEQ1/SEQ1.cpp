// Yêu cầu: Tìm giá trị lớn nhất của biểu thức aj - ai  (1<=i<j<=n)

// Dữ liệu:

// Dòng đầu tiên chứa hai số nguyên n (0<n<=106)

// Dòng thứ 2 là các số nguyên a1, a2, ..., an

// Kết quả:

// Một dòng duy nhất ghi giá trị lớn nhất của biểu thức
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 1000005
#define ii pair<ll, ll>
#define fi first
#define se second
const ll mod = 111539786;
using namespace std;
ll n, a[nmax], maxx = -1e9, b[nmax];
;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    fo(i, 2, n)
        b[i] = min(b[i - 1], a[i]);
    fo(i, 1, n)
        maxx = max(maxx, a[i] - b[i]);
    cout << maxx;
}
