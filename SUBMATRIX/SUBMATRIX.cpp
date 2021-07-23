// Bạn được cho một ma trận số tự nhiên kích thước
// ×
// . Nhiệm vụ của bạn là xác định độ
// dài cạnh lớn nhất của một ma trận vuông con thỏa mãn, số lượng phần tử phân biệt trong ma
// trận vuông con đó không vượt quá
// .

// Input
// Dòng đầu là 3 số tự nhiên
// ,
// ,
// .
// dòng sau, mỗi dòng gồm

// số tự nhiên, mô tả ma trận.

// 1 <=
// <=
// ×

// Các phần tử của ma trận không vượt quá
// ×

// Output
// Cạnh của ma trận vuông con lớn nhất thỏa mãn bài toán.
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 400005
#define ii pair<int, int>
#define fi first
#define se second
#define oo 1e18
#define ar array
using namespace std;
const int mod = 1e9 + 7;
ll m, n, k, a[305][305], d[90005];
bool ok = 0;
bool check(int x)
{
    fo(i, 1, m)
        fo(j, 1, n)
            d[a[i][j]] = 0;
    ll res = 0;
    fo(i, 1, x)
        fo(j, 1, x)
    {
        if (d[a[i][j]] == 0)
        {
            res++;
        }
        d[a[i][j]]++;
    }
    if (res <= k)
        return true;
    fo(j, 1, n - x + 1)
    {
        if (j & 1)
        {
            fo(i, 2, m - x + 1)
            {
                fo(t, j, j + x - 1)
                {
                    if (d[a[i - 1][t]] == 1)
                        res--;
                    d[a[i - 1][t]]--;
                }

                fo(t, j, j + x - 1)
                {
                    if (!d[a[i + x - 1][t]])
                        res++;
                    d[a[i + x - 1][t]]++;
                }
                if (res <= k)
                    return true;
            }
            if (j == n - x + 1)
                continue;
            fo(i, m - x + 1, m)
            {
                if (d[a[i][j]] == 1)
                    res--;
                d[a[i][j]]--;
            }
            fo(i, m - x + 1, m)
            {
                if (!d[a[i][j + x]])
                    res++;
                d[a[i][j + x]]++;
            }
            if (res <= k)
                return true;
        }
        else
        {
            for (int i = m - 1; i >= x; i--)
            {
                fo(t, j, j + x - 1)
                {
                    if (d[a[i + 1][t]] == 1)
                        res--;
                    d[a[i + 1][t]]--;
                }
                fo(t, j, j + x - 1)
                {
                    if (!d[a[i - x + 1][t]])
                        res++;
                    d[a[i - x + 1][t]]++;
                }
                if (res <= k)
                    return true;
            }
            if (j == n - x + 1)
                continue;
            fo(i, 1, x)
            {
                if (d[a[i][j]] == 1)
                    res--;
                d[a[i][j]]--;
            }
            fo(i, 1, x)
            {
                if (!d[a[i][j + x]])
                    res++;
                d[a[i][j + x]]++;
            }
            if (res <= k)
                return true;
        }
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("submatrix.inp", "r", stdin);
    freopen("submatrix.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> k;
    fo(i, 1, m)
            fo(j, 1, n)
                cin >>
        a[i][j];
    ll l = 1, r = min(m, n), ans = 0;
    while (l <= r)
    {
        ll mid = l + r >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans;
}
