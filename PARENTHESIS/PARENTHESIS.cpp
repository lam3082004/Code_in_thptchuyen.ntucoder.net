// Cho xâu S có độ dài N chỉ bao gồm các ký tự ’(’, ’)’ và ’*’.
// Ta định nghĩa một dãy ngoặc đúng như sau:
// • Nếu dãy không có ký tự nào thì được gọi là một dãy ngoặc đúng.
// • Nếu A là một dãy ngoặc đúng thì (A) cũng là một dãy ngoặc đúng.
// • Nếu A và B là các dãy ngoặc đúng thì AB là một dãy ngoặc đúng.
// Hãy kiểm tra xem có tồn tại một cách nào thay thế các ký tự ’*’ của xâu S thành ký tự ’(’ hoặc
// ’)’ sao cho xâu S trở thành một dãy ngoặc đúng hay không.
// Dữ liệu
// • Dòng đầu tiên chứa số nguyên dương T tương ứng với số lượng bộ test.
// • T dòng tiếp theo, mỗi dòng chứa một xâu S chỉ bao gồm các ký tự ’(’, ’)’ và ’*’ có độ dài
// không quá N (chi tiết giới hạn của N xem ở phần giới hạn).
// Kết quả
// • In ra T dòng, mỗi dòng in ra "YES" hoặc "NO" (không bao gồm dấu ngoặc kép) tương ứng
// với có hay không có cách thay thế các ký tự ’*’ thành ký tự ’(’ hoặc ’)’ để xâu S trở thành
// một dãy ngoặc đúng.
#pragma GCC optimize("Ofast,unroll-loops,-ffloat-store")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define __unique(V) (V).resize(unique((V).begin(), (V).end()) - (V).begin())
#define cntbit(X) __builtin_popcount((X))
#define bit(S, i) (((S) >> (i)) & 1)
#define PI acos(-1)
#define fi first
#define se second
#define LL long long
#define ii pair<int, int>
#define iii pair<int, ii>
#define eb emplace_back
#define TASK "parenthesis"
using namespace std;
const int maxn = 1e4 + 5;
int n, a[maxn], delta, star;
string s;
///--------------------------
void readf()
{
    cin >> s;
    n = s.size();
    s = " " + s;
    delta = 0;
    star = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == '(')
            a[i] = 1;
        if (s[i] == ')')
            a[i] = -1;
        if (s[i] == '*')
            a[i] = 0;
        delta -= a[i];
        star += (a[i] == 0);
    }
}
///--------------------------
void solve()
{
    if ((delta + star) & 1)
    {
        cout << "NO\n";
        return;
    }
    int x = delta + star >> 1;
    for (int i = 1; i <= n; ++i)
        if (a[i] == 0)
        {
            if (x > 0)
            {
                a[i] = 1;
                x--;
            }
            else
                a[i] = -1;
        }
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += a[i];
        if (sum < 0)
        {
            cout << "NO\n";
            return;
        }
    }
    if (sum != 0)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
///--------------------------
int main()
{
    srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef TLH2203
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif // TLH2203
    int T;
    cin >> T;
    while (T--)
    {
        readf();
        solve();
    }
}
