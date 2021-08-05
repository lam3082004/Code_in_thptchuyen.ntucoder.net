// Một cách tách xâu 𝑆 thành nhiều xâu con khác rỗng 𝑤1, 𝑤2, … , 𝑤𝑘 mà 𝑤1 = 𝑤𝑘, 𝑤2 = 𝑤𝑘−1, …
// được gọi là PALPAR bậc 𝑘.
// Yêu cầu: Cho xâu 𝑆 tìm cách tách PALPAR có bậc lớn nhất.
// Input
// - Dòng đầu chứa số nguyên 𝑇 (𝑇 ≤ 10);
// // - Tiếp theo là 𝑇 dòng, mỗi dòng chứa một xâu chỉ gồm các kí tự ‘a’ đến ‘z’
#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e6 + 5;
const long long B = 1000000007;
const int A = 26;
long long poww[nmax], hashs[nmax];
int t;
string s;
int gethash(int i, int j)
{
    return (hashs[j] - hashs[i - 1] * poww[j - i + 1] + B * B) % B;
}
int kqua(string s)
{
    int n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++)
        hashs[i] = (hashs[i - 1] * A + s[i] - 'a') % B;
    int l = 1, r = n, dem = 0;
    while (l <= r)
    {
        int res = 0;
        for (int i = 1; i <= (r - l + 1) / 2; i++)
            if (gethash(l, l + i - 1) == gethash(r - i + 1, r))
            {
                res = i;
                break;
            }
        if (res == 0)
            return dem + 1;
        else
        {
            l = l + res;
            r = r - res;
            dem += 2;
        }
    }
    return dem;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    cin >> t;
    poww[0] = 1;
    for (int i = 1; i < nmax; i++)
        poww[i] = (poww[i - 1] * A) % B;
    while (t--)
    {
        cin >> s;
        cout << kqua(s) << '\n';
    }
}
