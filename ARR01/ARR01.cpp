// Cho một dãy A gồm n phần tử. Mỗi phần tử có thể là 0 hoặc 1
// Gọi f(A) là dãy con liên tiếp dài nhất của A mà chỉ chứa số 1. Long có không quá k lần để
// thực hiện thao tác: Chọn vị trí 1 ≤ i ≤ n và chuyển giá trị của Ai

// : 0 → 1, 1 → 0

// Long muốn tối đa hoá f(A), hãy giúp Long.
// Input
// • Dòng đầu tiên là hai số n, k
// • Dòng tiếp theo là n số Ai
// Output
// • Một dòng duy nhất giá trị f(A) tối đa có thể
// Giới hạn
// • 1 ≤ n ≤ 100000
// • 0 ≤ k ≤ n
// • 0 ≤ Ai ≤ 1
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 1000005
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e18
using namespace std;
const int mod = 1e9 + 7;
ll t, n, k, a[nmax], f[nmax];
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
        f[i] = f[i - 1];
        if (a[i] == 0)
            f[i]++;
    }
    ll j = 0, ans = 0;
    fo(i, 1, n)
    {
        while (f[j + 1] - f[i - 1] <= k && j < n)
            j++;
        if (f[j] - f[i - 1] <= k)
            ans = max(ans, (ll)j - i + 1);
    }
    cout << ans;
}
