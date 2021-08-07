// Bài 2. HÒA HỢP
// Cho dãy số nguyên A = (a1, a2, . . ., an). Số ai được gọi là hòa hợp với dãy nếu nó là tổng của 3 số
// nào đó đứng trước nó trong dãy. Mỗi số có thể tham gia vào tổng nhiều lần.
// Ví dụ, với A = (1, 2, 3, 5, 7, 10), các số 3, 5, 7, 10 là hòa hợp với dãy (3 = 1+1+1, 5 = 1+2+2, 7 =
// 1+3+3, 10 = 2+3+5).
// Hãy xác định số lượng số hòa hợp trong dãy.
// Dữ liệu: Vào từ file văn bản HARMONY.INP:
//  Dòng đầu tiên chứa số nguyên n (1 ≤ n ≤ 5000),
//  Dòng thứ 2 chứa n số nguyên a1, a2, . . ., an (|ai
// | ≤ 105
// , i = 1 ÷ n).

// Kết quả: Đưa ra file văn bản HARMONY.OUT một số nguyên – số lượng số hòa hợp trong dãy.
#include <bits/stdc++.h>
#define fo(i, a, b) for (ll i = a; i <= b; i++)
#define ll long long
using namespace std;
const int base = 200005;
ll n, a[5005], f[500005], dem = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    memset(f, 0, sizeof(f));
    fo(i, 1, n)
        fo(j, 1, n) if (f[a[i] + a[j] + base] == 0)
            f[a[i] + a[j] + base] = max(i, j);
    else f[a[i] + a[j] + base] = min(f[a[i] + a[j] + base], max(i, j));
    fo(i, 2, n)
        fo(j, 1, i - 1)
    {
        if (f[a[i] - a[j] + base] != 0 && f[a[i] - a[j] + base] < i)
        {
            dem++;
            break;
        }
    }
    cout << dem;
}
