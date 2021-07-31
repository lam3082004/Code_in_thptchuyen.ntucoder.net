// Cho dãy số nguyên gồm n phần tử a1, a2, ... ,an.
// ( n < 1000 và |ai|< 109

// ). Cho trước số nguyên dương K, hãy tìm cách
// thêm bớt mỗi phần tử ai (1 < i < n) một lượng tối đa là K sao cho dãy
// số vừa mới được tạo ra có độ dài của dãy con không giảm đơn điệu dài
// nhất là lớn nhất.
// Dữ liệu vào: SEQ14.inp
// _ Dòng đầu nhập hai số nguyên dương n và k.
// _ Dòng thứ hai chứa n số nguyên a1, a2, ... ,an.
// Kết quả: SEQ14.out
// _ In ra kết quả là độ dài lớn nhất của dãy con không giảm đơn điệu dài
// nhất theo yêu cầu đề.
#include <bits/stdc++.h>
#define ll long long
#define nmax 100005
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;
ll n, k, a[1005], h[1005], b[1005], res, kq = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    fo(i, 1, n)
            cin >>
        a[i];
    b[0] = -1e9;
    b[1] = a[1] - k;
    res = 1;
    fo(i, 2, n)
    {
        if (a[i] + k >= b[res])
        {
            res++;
            b[res] = max(a[i] - k, b[res - 1]);
        }
        for (int j = res; j >= 1; j--)
        {
            if (a[i] - k <= b[j - 1] && b[j - 1] <= a[i] + k)
                b[j] = b[j - 1];
            else if (b[j - 1] < a[i] - k)
                b[j] = min(b[j], a[i] - k);
        }
    }
    cout << res;
}
