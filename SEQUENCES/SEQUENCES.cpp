//  Bạn được cho một xâu chỉ chứa ba kí tự 0, 1 và ?. Giả sử trong xâu có k kí tự ?. Khi đó, sẽ có 2
// k
// cách
// thay kí tự ? thành kí tự 0 hoặc kí tự 1, các cách thay này sẽ tạo thành 2
// k xâu 01 (xâu 01 là xâu chỉ
// chứa kí tự 0 và kí tự 1).
// Ta định nghĩa số nghịch thế của xâu 01 là số lần đổi chỗ hai kí tự liên tiếp trong xâu ít nhất
// để sắp xếp xâu theo thứ tự không giảm. Dễ dàng nhận thấy khi sắp xếp xâu 01 theo thứ tự không giảm,
// toàn bộ các số 0 của xâu sẽ ở bên trái và toàn bộ các số 1 của xâu sẽ ở bên phải. Ví dụ, số nghịch thế của
// xâu 11010 là 5. Ta có thể sắp xếp xâu này như sau: 11010 → 10110 → 01110 → 01101 → 01011 → 00111.
// Yêu cầu: Tính số dư khi chia tổng số nghịch thế của 2
// k xâu 01 tạo bởi xâu được cho với 109 + 7.
// Dữ liệu
// Gồm một dòng duy nhất chứa một xâu tạo bởi ba kí tự 0, 1 và ?.
// Kết quả
// Gồm một dòng duy nhất chứa một số nguyên là số dư khi chia tổng số nghịch thế của 2
// k xâu 01 được
// tạo bằng cách thay các kí tự ? trong xâu được cho bằng kí tự 0 hoặc kí tự 1 cho 109 + 7.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 500005
using namespace std;
const int mod = 1e9 + 7;
ll mu(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = mu(a, b / 2);
    t = (t * t) % mod;
    if (b & 1)
        t = (t * a) % mod;
    return t;
}
ll n, f[nmax], a[nmax], kq = 0, tmp;
string s;
int main()
{
    cin >> s;
    n = s.size();
    s = ' ' + s;
    fo(i, 1, n)
    {
        if (s[i] == '1')
            a[i] = a[i - 1] + 1;
        else
            a[i] = a[i - 1];
        if (s[i] == '?')
            f[i] = f[i - 1] + 1;
        else
            f[i] = f[i - 1];
    }
    fo(i, 2, n)
    {
        if (s[i] == '?' || s[i] == '0')
        {
            tmp = (f[i - 1] * mu(2, f[i - 1] - 1) % mod + mu(2, f[i - 1]) * a[i - 1]) % mod;
            kq = (kq + tmp * mu(2, f[n] - f[i]) % mod) % mod;
        }
    }
    cout << kq;
}
