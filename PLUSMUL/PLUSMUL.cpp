// Cho dãy số a1, a2, ... , an. Giữa hai số liền kề ta đặt một dấu ′ + ′ hoặc ′ × ′. Dễ
// thấy có 2
// n−1
// cách đặt như thế.
// Yêu cầu: Nếu viết hết tất cả 2

// n−1 biểu thức rồi cộng lại thì kết quả là bao nhiêu.

// Input:
//  Dòng đầu tiên chứa T − số test, các test được miêu tả như sau:
//  Dòng đầu tiên của mỗi test chứa n − số lượng số trong biểu thức
//  Dòng thứ hai của mỗi test chứa n số nguyên a1, a2, ... , an
// Output:
//  Với mỗi test, in ra kết quả bài toán. Do kết quả có thể rất lớn nên chỉ cần
// in ra phần dư của nó khi chia cho 109 + 7
// Ràng buộc:
//  1 ≤ T ≤ 10
//  1 ≤ n ≤ 100000
//  1 ≤ ai < 109
//  30% số test có n ≤ 20
#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
long long a[nmax], f[nmax], s[nmax], poww[nmax];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long res = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        poww[0] = 1;
        poww[1] = 2;
        s[1] = a[1] % mod;
        for (int i = 2; i <= n; i++)
        {
            poww[i] = (poww[i - 1] * 2) % mod;
            s[i] = (s[i - 1] * a[i] + a[i] * poww[i - 2]) % mod;
        }
        for (int i = 1; i <= n; i++)
        {
            f[i] = (res + s[i]) % mod;
            res = (res + f[i]) % mod;
        }
        cout << (f[n] % mod) << '\n';
    }
}
