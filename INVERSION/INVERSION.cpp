// Cho mảng n phần tử là a1, a2, ..., an.Tìm số đoạn con có số cặp nghịch thế ít nhất là k.Một cặp nghịch thế được định nghĩa là một cặp số u, v với u<v và au> av Input :
//  Dòng đầu tiên là hai số n, k
//  Dòng thứ hai là n số ai Output :
//  Một dòng duy nhất là kết quả bài toán Giới hạn :
//  0 ≤ ai ≤ 109, 0 ≤ k ≤ n×(n−1)2

//  Subtask 1(30 % số điểm) : 1 ≤ n ≤ 100
//  Subtask 2(30 % số điểm) : n ≤ 1000
//  Subtask 3(40 % số điểm) : n ≤ 100000
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e18
#define ar array
using namespace std;
const int mod = 1e9 + 7;
ll n, k, a[nmax], t[nmax], t2[nmax], h[nmax];
void update(int m, int val)
{
    while (m > 0)
    {
        t[m] += val;
        m -= m & -m;
    }
}
void update2(int m, int val)
{
    while (m < nmax)
    {
        t2[m] += val;
        m += m & -m;
    }
}
ll get(int m)
{
    ll tmp = 0;
    while (m < nmax)
    {
        tmp += t[m];
        m += m & -m;
    }
    return tmp;
}
ll get2(int m)
{
    ll tmp = 0;
    while (m > 0)
    {
        tmp += t2[m];
        m -= m & -m;
    }
    return tmp;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("new.inp", "r", stdin);
    freopen("new.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    fo(i, 1, n)
    {
        cin >> a[i];
        h[i] = a[i];
    }
    if (k == 0)
    {
        cout << n * (n + 1) / 2;
        return 0;
    }
    sort(h + 1, h + 1 + n);
    fo(i, 1, n)
        a[i] = lower_bound(h + 1, h + 1 + n, a[i]) - h;
    int j = 0;
    ll res = 0, tmp = 0, ans = 0;
    fo(i, 1, n)
    {
        while (res < k && j < n)
        {
            res += get(a[j + 1] + 1);
            update(a[j + 1], 1);
            update2(a[j + 1], 1);
            ++j;
        }
        if (res >= k)
            ans += (n - j + 1);
        res -= get2(a[i] - 1);
        update(a[i], -1);
        update2(a[i], -1);
    }
    cout << ans;
}
