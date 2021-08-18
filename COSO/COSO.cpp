#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
int main()
{
    ll n, k, r[65], t = 0;
    cin >> n >> k;
    while (n > 0)
    {
        r[++t] = n % k;
        n /= k;
    }
    for (int i = t; i >= 1; i--)
        cout << r[i];
}
