// Cho xâu 𝑠 gồm 𝑛 kí tự latinh thường.
// Với mỗi vị trí 𝑖 ∈ [1, 𝑛] bạn hãy tô một màu lên kí tự 𝑠𝑖
// (các kí tự giống nhau có thể tô màu giống
// hoặc khác nhau).
// Sau khi tô màu, bạn có thể thực hiện 𝑠𝑤𝑎𝑝 hai kí tự liền kề nếu như nó được tô màu khác nhau.
// Yêu cầu: Bạn hãy tô ít màu khác nhau nhất thỏa mãn sau khi tô màu, bằng các thao tác 𝑠𝑤𝑎𝑝, bạn
// có thể sắp xếp các kí tự trên xâu 𝑠 theo thứ tự không giảm.
// Input:
//  Dòng đầu chứa số nguyên dương 𝑛 (𝑛 ≤ 2.105).
//  Dòng thứ hai chứa xâu 𝑠.
// Output: In ra kết quả bài toán với phương thức sau:
//  Dòng đầu chứa một số nguyên dương 𝑟𝑒𝑠 − số lượng màu ít nhất cần tô và các màu lúc
// này được đánh số từ 1 đến 𝑟𝑒𝑠.
//  Dòng thứ hai chứa 𝑛 giá trị 𝑐1, 𝑐2, … , 𝑐𝑛 − trong đó 𝑐𝑖
// là màu tô lên vị trí �
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 200005
#define ii pair<int, int>
#define fi first
#define se second
#define oo 1e9
using namespace std;
const int mod = 1e9 + 7;
ll n, c[30], f[nmax][30];
bool p[30][30], ok[30];
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    s = ' ' + s;
    fo(i, 1, 26)
        c[i] = i;
    memset(p, 0, sizeof(p));
    fo(i, 1, n)
    {
        fo(j, 1, 26)
        {
            f[i][j] = f[i - 1][j] + (j == s[i] - 'a' + 1);
        }
    }
    fo(i, 1, n)
        fo(j, 1, s[i] - 'a')
    {
        if (f[n][j] - f[i][j] > 0)
        {
            p[s[i] - 'a' + 1][j] = 1;
        }
    }
    fo(i, 1, 26)
    {
        memset(ok, 0, sizeof(ok));
        fo(j, 1, i) if (p[i][j] == 1)
        {
            ok[c[j]] = 1;
        }
        fo(j, 1, 26) if (ok[j] == 0)
        {
            c[i] = j;
            break;
        }
    }
    memset(ok, 0, sizeof(ok));
    int dem = 0;
    fo(i, 1, n)
        ok[c[s[i] - 'a' + 1]] = 1;
    fo(i, 1, 26) if (ok[i])
        dem++;
    cout << dem << '\n';
    fo(i, 1, n)
            cout
        << c[s[i] - 'a' + 1] << ' ';
}
