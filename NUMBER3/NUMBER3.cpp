// Number
// Cho số nguyên dương 𝑛, hãy tìm số nguyên dương 𝑚 nhỏ nhất để 𝑛 × 𝑚 là một số mà trong biểu
// diễn của nó chỉ gồm một loại chữ số.
// Ví dụ: 𝑛 = 37 thì 𝑚 = 3 vì 37 × 3 = 111.
// Input
// - Gồm nhiều dòng, mỗi dòng chứa một số nguyên dương 𝑛 (𝑛 ≤ 106
// ).
// Output
// - Gồm nhiều dòng, mỗi dòng là kết quả tương ứng với bộ dữ liệu vào, chứa một số nguyên
// dương 𝑚 tìm được, nếu không tồn tại 𝑚 ghi -1.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
using namespace std;
void TA()
{
#ifndef ONLINE_JUDGE
    freopen("NUMBER3.inp", "r", stdin);
    freopen("NUMBER3.out", "w", stdout);
#endif // ONLINE_JUDGE
}
bool ok;
ll n, x, y, t;
string s, p;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    TA();
    while (cin >> n)
    {
        ok = false;
        t = 1;
        fo(i, 0, n) if (!ok)
        {
            t = (t * 10) % (9 * n);
            fo(j, 1, 9) if ((j * (t - 1)) % (9 * n) == 0)
            {
                x = j, y = i + 1;
                ok = true;
                break;
            }
        }
        else break;
        if (!ok)
            cout << -1;
        else
        {
            t = 0;
            p = "";
            s = "";
            n /= __gcd(n, x);
            fo(i, 1, y)
                s += '1';
            s = ' ' + s;
            fo(i, 1, y)
            {
                t = t * 10 + s[i] - '0';
                p += (t / n + '0');
                t %= n;
            }
            fo(i, 0, p.size() - 1) if (p[i] != '0')
            {
                x = i;
                break;
            }
            fo(i, x, p.size() - 1) cout << p[i];
        }
        cout << '\n';
    }
}
