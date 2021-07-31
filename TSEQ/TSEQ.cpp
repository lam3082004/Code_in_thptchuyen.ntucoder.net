#include <bits/stdc++.h>
#define ll long long
#define nmax 100005
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;
ll n, k, m, u, v, a[2005], b[2005], t = 0, kq = 0;
vector<ll> p;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n)
            cin >>
        a[i];
    fo(i, 1, n)
            cin >>
        b[i];
    fo(i, 2, n - 1)
    {
        ll tmp1 = 0, tmp2 = 0;
        fo(j, 1, i - 1) if (a[j] < a[i] && b[j] > b[i])
            tmp1++;
        fo(j, i + 1, n) if (a[j] > a[i] && b[j] < b[i])
            tmp2++;
        kq += tmp1 * tmp2;
    }
    cout << kq;
}
