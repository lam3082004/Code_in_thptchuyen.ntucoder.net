#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
using namespace std;
ll n, res[1000005], dem;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("SUMPOW.inp", "r", stdin);
    freopen("SUMPOW.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    //ll tam = 0;
    if (n % 2 == 1)
        cout << 1 << ' ';
    while (n > 0)
    {
        res[dem++] = n % 2;
        n /= 2;
    }

    for (int i = 1; i <= dem; i++)
    {
        if (res[i] == 1)
        {
            cout << (ll)pow(2, i) << ' ';
        }
    }
}
