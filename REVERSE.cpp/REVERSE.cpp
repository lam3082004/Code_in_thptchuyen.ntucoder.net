// Trong lúc buồn chán, Dũng đã tìm một xâu s gồm |s| kí tự là các chữ cái tiếng Anh in thường
// và đảo ngược một số xâu con liên tiếp của xâu s. Hãy viết chương trình tìm xâu s sau khi Dũng thực
// hiện lần lượt m lần đảo.
// Dữ liệu
// • Dòng đầu tiên gồm một xâu s mà Dũng tìm được (2 ≤ |s| ≤ 2 × 105
// ).

// • Dòng thứ hai gồm một số nguyên m (1 ≤ m ≤ 105

// ) là số lần Dũng đảo một xâu con liên tiếp của

// xâu s.
// • Dòng thứ bai gồm m số nguyên ai (1 ≤ ai ≤
// |s|
// 2
// ), mỗi số mô tả lần đảo một xâu con liên tiếp từ kí
// tự thứ ai đến kí tự thứ |s| − ai + 1 của Dũng. Các kí tự trong xâu s được đánh số từ 1 đến |s|.
// Kết quả
// • Gồm một dòng duy nhất chứa một xâu là xâu s sau khi Dũng thực hiện lần lượt m lần đảo.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
using namespace std;
string s, l, r, x;
ll n, m, a[nmax], f[nmax], k;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("REVERSE.inp", "r", stdin);
    freopen("REVERSE.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> s >> n;
    m = s.size();
    s = " " + s;
    l = "";
    r = "";
    fo(i, 1, n)
    {
        cin >> a[i];
        f[a[i]]++;
    }
    fo(i, 2, m / 2) f[i] = f[i] + f[i - 1];
    fo(i, 1, m / 2) if (f[i] % 2 == 1) f[i] = 1;
    else f[i] = 0;
    fo(i, 1, m / 2) l += to_string(f[i]);
    r = l;
    reverse(r.begin(), r.end());
    if (m % 2 == 1)
        x = l + to_string(f[m / 2]) + r;
    else
        x = l + r;
    x = " " + x;
    fo(i, 1, m) if ((x[i] - '0') % 2 == 0) cout << s[i];
    else cout << s[m - i + 1];
}
