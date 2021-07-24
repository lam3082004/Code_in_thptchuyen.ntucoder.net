// Cho mảng a gồm n số, số thứ i là ai

// . Bạn có một phép biến đổi như sau

// • Chọn hai số ai và aj (i 6= j), nếu ai ≥ aj thì xoá aj ra khỏi mảng và ai = ai + 1
// Yêu cầu: Hãy biến đổi để số lượng số lớn hơn hoặc bằng một giá trị k cho trước là nhiều nhất
// có thể
// Input
// • Dòng đầu tiên là hai số nguyên n và q - số phần tử của mảng và số truy vấn
// • Dòng thứ hai là N số nguyên dương a1, ...an là các phần tử của mảng a
// • Dòng thứ i trong q dòng tiếp theo là các giá trị ki
// Output
// • In ra q dòng, dòng thứ i là số phần tử lớn hơn hoặc bằng giá trị ki nhiều nhất có thể thu
// được sau khi biến đổi
#include <bits/stdc++.h>
#define lo long long
#define KKH "BDSO"
#define fi first
#define se second
#define BIT(x, k) ((x >> k) & 1)
using namespace std;
void START()
{
#ifdef toilagun2004
    freopen(KKH ".inp", "r", stdin);
    freopen(KKH ".out", "w", stdout);
#endif // toilagun2004
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int n, k, q, a[100006];
int main()
{
    START();
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    while (q--)
    {
        cin >> k;
        if (k <= a[1])
        {
            cout << n << '\n';
            continue;
        }
        if (k > a[n] + n - 1)
        {
            cout << 0 << '\n';
            continue;
        }
        int dau = 1, cuoi = n, dem = n, id;
        while (dau <= cuoi)
        {
            int giua = (dau + cuoi) >> 1;
            if (a[giua] < k)
            {
                id = giua;
                dem = giua - 1;
                dau = giua + 1;
            }
            else
                cuoi = giua - 1;
        }
        int kq = n - id;
        for (int i = id; i > 0; --i)
            if (a[i] + dem < k)
                break;
            else
                dem -= k - a[i] + 1, kq++;
        cout << kq << '\n';
    }
}
