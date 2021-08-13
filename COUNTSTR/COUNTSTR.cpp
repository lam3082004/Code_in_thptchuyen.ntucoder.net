// Cho một xâu ký tự S gồm toàn chữ cái alphabet in thường (‘a‘ − ‘z‘). Bạn hãy đếm số cặp chỉ số
// (l, r) với l < r sao cho:
// • Sl 6= Sr
// • Sl 6= Si ∀i ∈ (l, r)
// • Sr 6= Si ∀i ∈ (l, r)
// Dữ liệu
// • Một dòng duy nhất chứa xâu ký tự S (2 ≤ |S| ≤ 100000).
// Kết quả
// • Một số nguyên duy nhất là số cặp chỉ số (l, r) đếm đư
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
using namespace std;
string s;
ll n, f[100005][30], t[30], dem = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.size();
    s = " " + s;
    fo(i, 1, n) s[i] = s[i] - 'a' + 1;
    fo(i, 1, n)
    {
        fo(j, 1, 26) if (s[i] == j) f[i][j] = f[i - 1][j] + 1;
        else f[i][j] = f[i - 1][j];
    }
    fo(i, 1, n) t[s[i]] = n + 1;
    for (int i = n; i >= 1; i--)
    {
        if (t[s[i]] > i)
            dem += t[s[i]] - i - 1;
        fo(j, 1, 26) if (j != s[i])
        {
            ll k = min(t[s[i]], n);
            if (f[k][j] - f[i][j] > 1)
                dem -= (f[k][j] - f[i][j] - 1);
        }
        t[s[i]] = i;
    }
    cout << dem;
}
