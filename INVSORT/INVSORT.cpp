// Cho một dãy số 𝑎1, 𝑎2, … , 𝑎𝑛. Cần sắp xếp dãy theo thứ tự không giảm chỉ với thao tác: Chọn 1 ≤
// 𝑖 < 𝑗 ≤ 𝑛 sau đó đảo ngược đoạn từ 𝑖 đến 𝑗.
// Yêu cầu: Cho dãy số 𝑎1, 𝑎2, … , 𝑎𝑛, hãy sắp xếp dãy với số thao tác không vượt quá 3 × 𝑛.
// Input
// - Dòng đầu chứa số nguyên dương 𝑛;
// - Dòng thứ hai gồm 𝑛 số nguyên 𝑎1, 𝑎2, … , 𝑎𝑛.
// Output
// - Dòng đầu ghi số nguyên 𝑠 là số thao tác cần thực hiện;
// - Tiếp theo là 𝑠 dòng, mỗi dòng ghi hai số 𝑖,𝑗 mô tả thao tá
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
ll n, a[1005], p[1005], q[1005], t = 0;
ll dao(ll x, ll y)
{
    ll l = 1, r = n;
    while (l < r)
    {
        while (a[l] != y)
            l++;
        while (a[r] != x)
            r--;
        if (l < r)
        {
            p[++t] = l, q[t] = r;
            fo(i, 0, (r - l) / 2)
                swap(a[l + i], a[r - i]);
        }
    }
}
int main()
{
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    dao(0, 2);
    dao(0, 1);
    dao(1, 2);
    cout << t << '\n';
    fo(i, 1, t)
            cout
        << p[i] << ' ' << q[i] << '\n';
}
