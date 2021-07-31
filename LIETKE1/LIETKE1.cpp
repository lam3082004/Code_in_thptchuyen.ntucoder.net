// Cho số nguyên dương n(n ≤ 20), hãy liệt kê các xâu độ dài n chỉ gồm hai kí tự ′A′ hoặc ′B′ mà không có hai kí tự ′B′ nào đứng cạnh nhau Input :
//  Một dòng duy nhất là số nguyên n Output :
//  Gồm nhiều dòng, mỗi dòng là một xâu thoả mãn bài toán, các xâu được sắp xếp tăng dần theo thứ tự từ điển
#include <bits/stdc++.h>
#define nmax 1000005
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
ll x[30], n, d = 0;
void check()
{
    fo(i, 1, n)
    {
        if (x[i] == 1)
            cout << "B";
        else
            cout << "A";
    }
    cout << '\n';
}
void Try(int k)
{
    fo(i, 0, 1)
    {
        x[k] = i;
        if (k == n)
        {
            ll dem = 0;
            fo(j, 2, n) if (x[j - 1] == 1 && x[j] == 1) dem++;
            if (dem < 1)
            {
                check();
            }
        }
        else
            Try(k + 1);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    Try(1);
}
