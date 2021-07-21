// Khi mới bắt đầu code online, chắc hẳn ai cũng sẽ tìm bài A + B để nộp (Ví dụ
// như bài POST trên VOJ hay bài TONG trên NTUCoder). Tuy nhiên hôm nay bài
// A + B của chúng ta sẽ có chút khác biệt
// Cho 3 số nguyên dương A,B, C thoả mãn A + B = C. Chúng ta có thể xáo trộn
// ngẫu nhiên các bit trong A và B (một cách độc lập giữa hai số). Nhưng điều thú
// vị là tổng vẫn bằng C sau khi xáo trộn
// Yêu cầu: Cho A,B, C, có bao nhiêu cách mà khi xáo trộn các bit của A và B thì
// tổng của chúng vẫn bằng C. Gọi các số nguyên thu được khi xáo trộn các bit của
// A và B lần lượt là As và Bs

// . Hai cách (As1,Bs1) và (As2,Bs2) là khác nhau nếu

// As1 ≠ As2 hoặc Bs1 ≠ Bs2
// Bạn được phép thêm số lượng số 0 tuỳ ý vào đầu (có thể không thêm), tức là
// thêm số bit 0 bất kì vào A và vào B trước khi xáo trộn các bit
// Input:
//  Dòng đầu tiên chứa số nguyên T – số test. Mỗi test được miêu tả như sau:
//  Dòng đầu tiên và cũng là duy nhất của mỗi test chứa 3 số nguyên A,B, C
// Output:
//  Với mỗi test, in ra trên một dòng là số cách xáo trộn các bit thoả mãn4
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e18
#define ar array
using namespace std;
const int mod = 1e9 + 7;
ll t, a, b, c, f[32][32][32][3];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        ll p = __builtin_popcount(a);
        ll q = __builtin_popcount(b);
        memset(f, 0, sizeof(f));
        f[0][0][0][0] = 1;
        fo(i, 0, 30)
            fo(l, 0, p)
                fo(r, 0, q)
        {
            if ((c >> i) & 1)
            {
                f[i + 1][l][r][0] += f[i][l][r][1];
                f[i + 1][l + 1][r][0] += f[i][l][r][0];
                f[i + 1][l][r + 1][0] += f[i][l][r][0];
                f[i + 1][l + 1][r + 1][1] += f[i][l][r][1];
            }
            else
            {
                f[i + 1][l][r][0] += f[i][l][r][0];
                f[i + 1][l + 1][r][1] += f[i][l][r][1];
                f[i + 1][l][r + 1][1] += f[i][l][r][1];
                f[i + 1][l + 1][r + 1][1] += f[i][l][r][0];
            }
            //            if(f[i][l][r][0] || f[i][l][r][1])
            //            cout<<i<<' '<<l<<' '<<r<<' '<<f[i][l][r][0]<<' '<<f[i][l][r][1]<<'\n';
        }
        cout << f[30][p][q][0] << '\n';
    }
}
