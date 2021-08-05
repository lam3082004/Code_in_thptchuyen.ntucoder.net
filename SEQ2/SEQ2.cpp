// Yêu cầu: Tìm giá trị lớn nhất của biểu thức ai + aj - ak (1<=i<j<k<=n)

// Dữ liệu:

// Dòng đầu tiên chứa hai số nguyên n (0<n<=106)

// Dòng thứ 2 là các số nguyên a1, a2, ..., an

// Kết quả:

// Một dòng duy nhất ghi giá trị lớn nhất của biểu thức.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 1000005
#define ii pair<ll, ll>
#define fi first
#define se second
const ll mod = 111539786;
using namespace std;
ll n, a[nmax], maxx = -1e9, b[nmax], c[nmax], s[nmax];
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
    fo(i, 1, n)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    b[1] = a[1];
    c[1] = a[1];
    fo(i, 2, n)
    {
        b[i] = max(b[i - 1], a[i]);
        c[i] = max(c[i - 1], a[i] + b[i - 1]);
    }
    fo(i, 1, n)
        maxx = max(maxx, c[i - 1] - a[i]);
    cout << maxx;
}
