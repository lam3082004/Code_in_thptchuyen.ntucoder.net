// Nrd (Người ra đề) có bài toán sau: Cho một xâu s chỉ gồm |s| chữ cái tiếng Anh in thường
// được đánh số từ 1 đến |s|, hãy đếm số lượng xâu palindrome là xâu con liên tiếp của xâu s.
// Kc97 nhận thấy bài toán này quá dễ so với trình độ thí sinh Free Contest, vì vậy sau khi nhận
// được bài này từ Nrd, anh quyết định nâng cấp bài toán như sau: Cho một xâu s chỉ gồm |s| chữ cái
// tiếng Anh in thường và q truy vấn, truy vấn thứ i gồm hai số nguyên li

// , ri (1 ≤ li ≤ ri ≤ |s|). Với mỗi
// truy vấn i, hãy in ra số lượng xâu palindrome liên tiếp là xâu con liên tiếp của xâu con liên tiếp từ chữ
// cái li đến chữ cái ri của xâu s.
// Dữ liệu
// • Dòng đầu tiên chứa xâu s (1 ≤ |s| ≤ 5000).
// • Dòng thứ hai chứa một số nguyên dương q là số lượng truy vấn (1 ≤ q ≤ 106
// ).

// • q dòng tiếp theo, dòng thứ i chứa hai số nguyên li
// , ri (1 ≤ li
// , ri ≤ |s|) mô tả truy vấn thứ i.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define fi first
#define se second
#define LL long long
#define TASK "PALIND"
using namespace std;
string s;
int f[5010][5010], u, v, q, lens;
///--------------------------
void readf()
{
    cin >> s;
}
///--------------------------
void solve()
{
    lens = s.size();
    s = " " + s;
    fd(i, lens, 1)
        fo(j, i, lens)
    {
        if (i == j)
            f[i][j]++;
        else if (i + 1 == j && s[i] == s[j])
            f[i][j]++;
        else if (f[i + 1][j - 1] > 0 && s[i] == s[j])
            f[i][j]++;
    }
    fd(i, lens, 1)
        fo(j, i + 1, lens)
    {
        if (i + 1 == j && s[i] == s[j])
            f[i][j] += 2;
        else if (i != j)
            f[i][j] += f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1];
    }
    cin >> q;
    fo(i, 1, q)
    {
        cin >> u >> v;
        cout << f[u][v] << '\n';
    }
}
///--------------------------
int main()
{
#ifndef ONLINE_JUDGE
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    readf();
    solve();
}
