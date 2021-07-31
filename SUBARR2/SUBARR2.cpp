// SUBARR2 – SUBARRAY 2
// Cho một dãy số nguyên a1, a2, ... , an và số nguyên dương k.
// Dãy con ai

// , ai+1, ... , aj

// (1 ≤ i ≤ j ≤ n) là dãy được tạo từ các phần tử liên tiếp của dãy A, bắt đầu từ

// phần tử i và kết thúc ở phần tử j
// Yêu cầu: Cho dãy a và số k, tìm số lượng dãy con của a có ít nhất k phần tử khác nhau
// Input:
//  Dòng đầu chứa hai số nguyên dương n, k (1 ≤ k ≤ n ≤ 4 × 105
// )
//  Dòng thứ hai chứa n số nguyên a1, a2, ... , an (ai ≤ 109
// )
#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
void LSH()
{
#ifndef ONLINE_JUDGE
    freopen("SUBARR.INP", "r", stdin);
    freopen("SUBARR.OUT", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
long long n, a[400005], j = 0, ans = 0, k, so = 0, b[400005], dem, d[400005];
ii gt[400005];
bool check = false;
int main()
{
    LSH();
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        gt[i].fi = a[i];
        gt[i].se = i;
    }
    sort(gt + 1, gt + n + 1);
    b[gt[1].se] = 1;
    dem = 1;
    for (int i = 2; i <= n; ++i)
        if (gt[i - 1].fi != gt[i].fi)
            b[gt[i].se] = ++dem;
        else
            b[gt[i].se] = dem;
    for (int i = 1; i <= n; ++i)
    {
        while (so < k && j < n)
        {
            j++;
            if (d[b[j]] == 0)
                so++;
            //cout<<d[a[j]]<<" "<<i<<" "<<j<<" "<<so<<" "<<k<<'\n';;
            d[b[j]]++;
        }
        //cout<<i<<" "<<j<<" "<<so<<'\n';
        if (j == n && so < k)
            break;
        else
        {
            ans += n - j + 1;
        }
        d[b[i]]--;
        if (d[b[i]] == 0)
            so--;
        //cout<<i<<" "<<j<<" "<<so<<'\n';
    }
    cout << ans;
}
