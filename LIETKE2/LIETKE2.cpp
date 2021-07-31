// Cho số nguyên dương n(n ≤ 10), liệt kê tất cả cách khác nhau đặt n dấu ngoặc mở và n dấu ngoặc đóng đúng đắn Input :
//  Một dòng duy nhất là số nguyên dương n Output :
//  Gồm nhiều dòng, mỗi dòng là một cách xếp ngoặc đúng đắn
//  Các dãy ngoặc được sắp xếp theo thứ tự từ điển : ′(′ có thứ tự từ điển bé hơn ′)′
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 1000005
#define fi first
#define se second
#define ii pair<int, int>
const ll mod = 1e9 + 7;
using namespace std;
ll n, a[nmax], x[55], s = 0;
bool d[110];
void read()
{
    cin >> n;
}
void in()
{
    int dem = 0;
    fo(i, 1, n)
    {
        if (x[i] == 0)
            dem++;
        else
            dem--;
        if (dem < 0)
            break;
    }
    if (dem != 0)
        ;
    else
    {
        fo(i, 1, n) if (x[i] == 0) cout << "(";
        else cout << ")";
        cout << '\n';
    }
}
void np(int j)
{
    fo(i, 0, 1)
    {
        x[j] = i;
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
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE

    read();
    n = 2 * n;
    np(1);
    //cout<<dem;
}
