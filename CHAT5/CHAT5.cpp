// Cho n đoạn dây điện (1 ≤  n ≤ 105). Đoạn dây thứ i có độ dài ai (0 <ai≤ 109). Cần phải cắt các đoạn đã cho thành các đoạn sao cho có được K đoạn dây bằng nhau có độ dài nguyên. Có thể không cần cắt hết các đoạn dây đã cho. Mỗi đoạn dây bị cắt có thể có phần còn thừa khác 0.

// Yêu cầu: Xác định độ dài lớn nhất của đoạn dây có thể nhận được. Nếu không có cách cắt thì đưa ra số 0.

// Dữ liệu:

// Dòng đầu tiên chứa hai số nguyên N, K

// Dòng thứ i trong N dòng tiếp theo chứa số nguyên ai

// Kết quả:

// Một dòng duy nhất ghi độ dài lớn nhất có thể nhận được.
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<ll, ll>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 1000005
using namespace std;
ll m, n, s = 0, k, a[nmax];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    fo(i, 1, n)
    {
        cin >> a[i];
        s += a[i];
    }
    ll t = s / k;
    ll l = 1, r = t;
    while (l <= r)
    {
        ll mid = l + r >> 1;
        s = 0;
        fo(i, 1, n) s += a[i] / mid;
        if (s >= k)
        {
            t = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << t;
}
