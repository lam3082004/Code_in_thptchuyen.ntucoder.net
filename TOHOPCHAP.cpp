#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, x[10000], a[100009], k, i, j, dem;

void xuat()
{
    for (int i = 1; i <= k; i++)
        cout << a[x[i]] << " ";
    cout << endl;
    dem++;
}

void tohop(int i)
{
    for (int j = x[i - 1] + 1; j <= n - k + i; j++)
    {
        x[i] = j;
        if (i == k)
            xuat();
        else
            tohop(i + 1);
    }
}

int main()
{
    cin >> k >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    tohop(1);
    cout << dem;
}
