#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 500005
using namespace std;
ll n, s = 1;
int lam(int j)
{
    ll s1 = j / 6;
    return sqrt(s1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("2106B.inp", "r", stdin);
    freopen("2106B.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ll s1 = n / 6;
    ll s2 = sqrt(s1);
    while (s2 * s2 * 6 <= n)
        s2++;
    cout << s2 * s2 * 6 - n;
}
