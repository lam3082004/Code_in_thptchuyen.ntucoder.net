#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
using namespace std;
ll n, a[nmax];
int main()
{
    //  freopen("l.inp","r",stdin);
    //freopen("l.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    if (n % 2 == 0)
    {
        for (int i = 1; i < n; i += 2)
            cout << a[i] << ' ';
        for (int i = n; i > 1; i -= 2)
            cout << a[i] << ' ';
    }
    if (n % 2 == 1)
    {
        for (int i = 2; i < n; i += 2)
            cout << a[i] << ' ';
        for (int i = n; i >= 1; i -= 2)
            cout << a[i] << ' ';
    }
}
