// Phần tử thứ s
// Cho một dãy số gồm vô hạn các số nguyên đôi một khác nhau. Các phần tử của dãy số này có tính chất rất đặc biệt:

// Tất cả các phần tử của dãy số đều là bội của 3.
// Nếu cộng thêm 1 thì các phần tử này sẽ trở thành số chính phương.
// Yêu cầu: Hãy tìm phần tử thứ s của dãy số sau khi đã được sắp xếp tăng dần.
#include <bits/stdc++.h>
#define lo long long
#define KKH "I21052020F"
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
lo s, k;
lo na(lo a, lo b, lo mod)
{
    a %= mod;
    b %= mod;
    lo q = (long double)a * b / mod;
    return ((a * b - q * mod) % mod + mod) % mod;
}
int main()
{
    START();
    cin >> s >> k;
    lo dau = 1, cuoi = 2 * s, giua, t;
    while (dau <= cuoi)
    {
        giua = (dau + cuoi) >> 1;
        if (giua - giua / 3 >= s)
        {
            t = giua % k;
            cuoi = giua - 1;
        }
        else
            dau = giua + 1;
    }
    cout << (na(t, t, k) - 1) % k;
}
