// Sau giờ học căng thẳng nhưng cũng không kém phần vui vẻ về phép so sánh, Tèo và Tí cùng nhau
// chơi một trò chơi một trò chơi, Tèo và tí cùng tạo một dãy S độ dài N chỉ gồm các kí tự <, >.
// Sau đó, Tèo và Tí riêng phần mình lần lượt tạo ra một dãy đẹp độ dài N + 1. Một dãy A bất kì
// được gọi là dãy đẹp nếu:
// • Các phần tử dãy A đều là các số nguyên không âm
// • Nếu Si = ’<’, thì Ai < Ai+1
// • Nếu Si = ’>’, thì Ai > Ai+1
// Người chiến thắng trò chơi là người có tổng của phần tử trong dãy là bé nhất. Để kiểm tra đáp
// án của Tèo và Tí, từ dãy S, bạn hãy tính tổng bé nhất của dãy số đẹp có N + 1 phần tử.
// Dữ liệu
// • Gồm một dòng duy nhất chứa xâu S. (|S| ≤ 5 × 105
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define fi(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
string s;
ll l[500005], r[500005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("SEGMIN.inp", "r", stdin);
    freopen("SEGMIN.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> s;
    ll n = s.size();
    s = " " + s;
    if (s[1] == '<')
        l[0] = 0;
    if (s[n] == '>')
        r[n] = 0;
    fo(i, 1, n)
    {
        if (s[i] == '<')
            l[i] = l[i - 1] + 1;
        else
            l[i] = 0;
    }
    fi(i, n - 1, 0)
    {
        if (s[i + 1] == '>')
            r[i] = r[i + 1] + 1;
        else
            r[i] = 0;
    }
    ll t = 0;
    fo(i, 0, n) t += max(l[i], r[i]);
    cout << t;
}
