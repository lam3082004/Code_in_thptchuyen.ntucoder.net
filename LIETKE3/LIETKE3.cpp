// LIETKE3 – LIỆT KÊ 3
// Một xâu X = x1x2 ... xm được gọi là xâu con của xâu Y = y1y2 ... yn nếu ta có thể nhận được xâu X từ
// xâu Y bằng cách xoá đi một số kí tự, tức là tồn tại một dãy các chỉ số
// 1 ≤ i1 < i2 < ⋯ < im ≤ n để x1 = yi1
// , x2 = yi2
// , ... , xm = yim
// Ví dụ: X = ′adz′ là xâu con của xâu Y = ′baczdtz′ với i1 = 2 < i2 = 5 < i3 = 7
// Yêu cầu: Nhập vào một xâu S (độ dài không quá 15, chỉ gồm các kí tự ′a′ đến ′z′), hãy liệt kê tất cả các
// xâu con khác nhau của S
// Input:
//  Một dòng duy nhất là xâu S
// Output:
//  In ra nhiều dòng, mỗi dòng là một xâu con của xâu S
//  Các xâu được in ra theo thứ tự từ điển
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 1000005
#define fi first
#define se second
#define ii pair<int, int>
const ll mod = 1e9 + 7;
using namespace std;
string s, a[nmax];
ll n, b[nmax + 5], k = 0;
void in()
{
    string x = "";
    fo(i, 1, n) if (b[i] == 0) x += s[i];
    a[++k] = x;
}
void np(int j)
{
    fo(i, 0, 1)
    {
        b[j] = i;
        if (j == n)
            in();
        else
            np(j + 1);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("lietke3.inp", "r", stdin);
    freopen("lietke3.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> s;
    n = s.size();
    s = ' ' + s;
    np(0);
    sort(a + 1, a + k + 1);
    fo(i, 1, k) if (a[i].size() != 0) if (a[i] != a[i + 1]) cout << a[i] << "\n";
}
