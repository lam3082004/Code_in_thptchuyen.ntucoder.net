// Có n chiếc đồng hồ được xếp thành hàng ngang, đánh số từ 1 đến n. Mỗi đồng hồ chỉ có kim
// giờ và luôn chỉ giờ đúng
// Giữa mỗi cặp đồng hồ là một công tắc màu đỏ. Khi ấn công tắc nằm giữa đồng hồ i và i + 1,
// đồng hồ i quay tiến 1 giờ (nếu đang 12 giờ thì sẽ là 1 giờ), đồng hồ i + 1 quay lùi 1 giờ (nếu
// đang là 1 giờ thì sẽ là 12 giờ)
// Công tắc màu xanh bên trái cùng sẽ làm đồng hồ số 1 quay lùi 1 giờ, và công tắc màu xanh
// bên phải cùng sẽ làm đồng hồ số n quay tiến 1 giờ.

// Yêu cầu: Tìm số lần ấn công tắc ít nhất để tất cả các đồng hồ đều chỉ 12 giờ đúng
// Input:
//  Dòng đầu là số N (1 ≤ N ≤ 106

// ), là số lượng đồng hồ

//  Dòng thứ 2 là N số trong đoạn [1. .12] là giờ hiện tại của đồng hồ
// Output:
//  Một dòng duy nhất là kết quả bài toán
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define fi first
#define se second
#define LL long long
#define pb push_back
#define TASK "CLOCK"
using namespace std;
int n, a[1000010], ans;
///--------------------------
void readf()
{
    cin >> n;
    fo(i, 1, n) cin >> a[i];
}
///--------------------------
void solve()
{
    ans = INT_MAX;
    fo(i, 0, 11)
    {
        int tmp, x, m;
        x = i;
        tmp = i;
        m = a[1];
        m = ((m - i) % 12 + 12) % 12;
        fo(j, 1, n - 1)
        {
            if (m != 0)
                x = 12 - m;
            else
                x = 0;
            m = a[j + 1] % 12;
            m = ((m - x) % 12 + 12) % 12;
            tmp += x;
            //if (i==4) cout<<x<<endl;
        }
        x = (12 - m) % 12;
        tmp += x;
        ans = min(ans, tmp);
        //cout<<ans<<" "<<i<<endl;
    }
    cout << ans;
}
///--------------------------
int main()
{
#ifndef ONLINE_JUDGE
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    readf();
    solve();
}
