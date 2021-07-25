// Cho một dãy số nguyên gồm N phần tử a1, a2, ... , aN. Một đoạn con liên tiếp của dãy từ vị trí i
// đến vị trí j (1 ≤ i ≤ j ≤ N) là dãy con gồm các phần tử ai

// , ai+1, ... , aj
// .

// Yêu cầu: Chọn hai đoạn con liên tiếp không giao nhau có độ dài là K, gọi hai đoạn con đó là
// X = {x1, x2, ... , xK} và Y = {y1, y2, ... , yK}. Sau đó tính hàm f(X, Y) = x1. yK + x2. yK−1 + ⋯ +
// xK. y1. Hãy xác định giá trị S lớn nhất có thể trên dãy số nguyên A cho trước.
// Input:
//  Dòng đầu gồm duy nhất một số nguyên dương N (N ≤ 3000);
//  Dòng tiếp theo gồm N số nguyên a1, a2, ... , aN (|ai
// | ≤ 106
// ).

// Output: In ra kết quả bài toán.
#include <bits/stdc++.h>
#define ll long long
#define nmax 2000005
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;
ll n, f[3005][3005], a[3005];
ll maxx = -1e9;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n)
            cin >>
        a[i];
    fo(i, 1, n)
        fo(j, i + 1, n)
    {
        f[i][j] = max(a[i] * a[j], f[i - 1][j + 1] + a[i] * a[j]);
        maxx = max(maxx, f[i][j]);
    }
    cout << maxx;
}
