// N bóng đèn được đặt trên con đường từ cánh đồng của FJ đến nông trại, được đánh số từ 0 tới
// N − 1.
// Ban đầu, mỗi bóng đèn ở một trong hai trạng thái tắt hoặc mở, bóng đèn thứ i nếu được bật thì
// có độ sáng là ai

// , và có độ sáng là 0 nếu đang tắt.

// Hệ thống điều khiển các bóng đèn hoạt động như sau: Mỗi bước có thể thay đổi trạng thái của
// K bóng đèn liên tiếp. Vừa xem phim Lights Out, Bessie muốn tối đa hóa độ sáng của con đường
// (tổng độ sáng của các bóng đèn). Cô có thể thực hiện số bước bất kỳ.
// Input
// Dòng đầu tiên là số nguyên N (1 ≤N≤ 2500).
// Dòng thứ hai gồm một xâu có độ dài N, mô tả trạng thái ban đầu của các bóng đèn (00
// 0
// là tắt,

// 01
// 0
// là mở).
// Dòng thứ ba gồm N số nguyên dương không quá 1000, mô tả độ sáng của các bóng đèn.
// Cuối cùng là số K (1 ≤ K ≤ N).
// Output
// In ra độ sáng tối đa.
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define l2 long long
#define st first
#define nd second
#define ll2 pair<l2, l2>
#define lim 2500
#define limar lim + 5
using namespace std;
l2 n, a[limar], k, b[limar], t[limar], mn[limar];
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> k;

    s = " " + s;
    for (int i = 0; i <= lim; i++)
        mn[i] = 1e9;
    for (int i = 1; i <= n; i++)
    {
        b[i % k] += !(s[i] - 48);
        t[i % k] += a[i];
        mn[i % k] = min(mn[i % k], a[i]);
    }
    l2 T, T2;
    T = T2 = 0;
    for (int i = 0; i < k; i++)
    {
        T += (b[i] % 2 == 0 ? t[i] : t[i] - mn[i]);
        T2 += (b[i] % 2 ? t[i] : t[i] - mn[i]);
    }
    cout << max(T, T2);
}
