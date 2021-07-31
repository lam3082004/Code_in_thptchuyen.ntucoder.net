// Cho lưới n×m. Xác định số lượng hình chữ nhật có các đỉnh là điểm nguyên trên lưới.
// Dữ liệu: Vào từ file văn bản RECTANGLES.INP gồm một dòng duy nhất chứa 2 số
// nguyên dương m, n (2 ≤ m, n ≤ 400).
// Kết quả: Ghi ra file văn bản RECTANGLES.INP một số nguyên duy nhất là số lượng
// hình chữ nhật đếm được.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
ll n, m, kq = 0, s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    kq += (m * (m - 1) / 2) * (n * (n - 1) / 2);
    fo(x, 1, n)
        fo(z, 1, n)
            fo(y, 1, m)
    {
        ll t = -(x * z) / y;
        if (x * z + t * y == 0)
        {
            kq += max(n - x - z, 0LL) * max(m - y + t, 0LL);
        }
    }
    cout << kq;
}
