#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (long long i = a; i <= b; i++)
#define nmax 1000005
#define fi first
#define se second
#define ii pair<int, int>
const ll mod = 1e9 + 7;
using namespace std;
ll n, w, h, a[nmax], t;
// bool doixung(string k)
// {
//     ll s = 0;
//     fo(i, 0, k.size() / 2 - 1)
//     {
//         if (k[i] == k[k.size() - i - 1])
//             s = 1;
//         else
//             s = 0;
//     }
//     if (s == 1)
//         return true;
//     else
//         return false;
// }
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("SIBICE.inp", "r", stdin);
    freopen("ERASECHAR.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n >> w >> h;
    ll s = int(sqrt(w * w + h * h));
    while (n--)
    {
        cin >> t;
        if (s >= t)
            cout << "DA" << '\n';
        else
            cout << "NE" << '\n';
    }
}
