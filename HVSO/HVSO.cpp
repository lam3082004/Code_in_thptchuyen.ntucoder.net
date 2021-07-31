// Mr Bin sau khi chán với dự định xây cầu, cậu quay lại với các con số. Cho số nguyên dương n, một hoán vị của tập {1,2,...,n} là một bộ sắp thứ tự (a1,a2,...,an) với ai khác aj khi i khác j. Bạn có thể đọc thêm về hoán vị tại đây: https://vi.wikipedia.org/wiki/Ho%C3%A1n_v%E1%BB%8B

// Vấn đề là Mr Bin muốn đếm số lượng hoán vị của n số nguyên dương đầu tiên mà ai khác i . Bạn hãy giúp Mr Bin nhé!

// Dữ liệu:

// Gồm một dòng duy nhất chứa số nguyên dương N(0<N<=106)
// Kết quả:  In ra kết quả bài toán khi chia lấy dư cho 109+7
#include <bits/stdc++.h>
#define l2 long long
using namespace std;
l2 n, c, t, mod = 1000000007;
int main()
{
    cin >> n;
    c = 1;
    t = (n % 2 ? -1 : 1);
    for (int i = n; i >= 1; i--)
    {
        c *= i;
        c %= mod;
        if (i % 2 == 0)
            t = (t - c + mod * mod) % mod;
        else
            t = (t + c) % mod;
    }

    cout << t;

    //  T= n!*C(0,n) - (n-1)!*C(1,n) + ... + 0!*C(n,n);
}
