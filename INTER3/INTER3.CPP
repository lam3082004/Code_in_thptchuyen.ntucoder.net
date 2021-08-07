// Cho ba số nguyên dương 𝑎, 𝑏, 𝑐.
// Trong một bước, bạn có thể chọn một trong ba biến 𝑎 hoặc 𝑏 hoặc 𝑐 và thực hiện tăng hoặc giảm
// 1 đơn vị.
// Lưu ý bạn phải luôn giữ cho các giá trị 𝑎, 𝑏, 𝑐 luôn nguyên dương.
// Yêu cầu: In ra số bước ít nhất để 𝑏 ⋮ 𝑎 và 𝑐 ⋮ 𝑏.
// Input:
//  Dòng đầu tiên gồm một số nguyên dương 𝑡 (𝑡 ≤ 100) − số lượng testcase.
//  Mỗi dòng trong 𝑡 dòng tiếp theo chứa ba số nguyên dương 𝑎, 𝑏, 𝑐 (1 ≤ 𝑎 ≤ 𝑏 ≤ 𝑐 ≤ 104).
// Output: Gồm 𝑡 dòng, mỗi dòng là kết quả bài toán ứng với mỗi testcase.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 400005
#define ii pair<int, int>
#define fi first
#define se second
#define oo 1e9
using namespace std;
const int mod = 1e9 + 7;
ll t, n, m, a, b, c, tmpb, tmpc;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        ll ans = 1e18;
        cin >> a >> b >> c;
        fo(i, 1, 10000)
        {
            for (int j = i; j <= 10000; j += i)
            {
                if (c >= j)
                    ans = min(ans, abs(a - i) + abs(b - j) + abs(c % j));
                ans = min(ans, abs(a - i) + abs(b - j) + abs(j - c % j));
            }
        }
        cout << ans << '\n';
    }
}
