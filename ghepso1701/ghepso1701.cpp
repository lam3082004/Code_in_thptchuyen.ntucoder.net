#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 1000005
#define fi first
#define se second
#define ii pair<int, int>
const ll mod = 1000000007;
using namespace std;
ll n, a[nmax], dem = 0;
bool nt(ll n)
{
    if (n < 2)
        return false;
    fo(i, 2, sqrt(n)) if (n % i == 0) return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("ghepso1701.inp", "r", stdin);
    freopen("ghepso1701.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    do
    {
        ll s = 0;
        fo(i, 1, n) s = s * 10 + a[i];
        if (nt(s))
        {
            cout << s << '\n';
            dem++;
        }
    } while (next_permutation(a + 1, a + n + 1));
    if (dem == 0)
        cout << "-1";
}