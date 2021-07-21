#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (long long i = a; i <= b; i++)
#define nmax 1000005
#define fi first
#define se second
#define ii pair<int, int>
const ll mod = 1e9 + 7;
using namespace std;
long long n, i, k, s, x;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    bool a[n];
    s = 0;
    for (i = 2; i <= n; i++)
        a[i] = true;
    x = 2;
    while (s < k)
    {
        if (a[x] == true)
            for (i = x; i <= n; i += x)
                if (a[i] == true)
                {
                    a[i] = false;
                    s++;
                    if (s == k)
                        break;
                }
        x++;
    }
    cout << i;
}
