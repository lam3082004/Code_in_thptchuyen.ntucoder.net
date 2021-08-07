// Quốc vương muốn tổ chức một nhánh kỵ binh, vì vậy ông muốn bắt
// k
//  con rồng để chuẩn bị cho nhánh kỵ binh ấy. Quốc vương đem theo
// n
//  kỵ sĩ và chuẩn bị cho mỗi người nhiệm vụ bắt một con rồng. Mỗi kỵ sĩ chỉ bắt được con rồng có chỉ số sức mạnh thấp hơn họ. Mỗi con rồng có một chỉ số
// D
// i
//  là sức mạnh của nó, mỗi kỵ sĩ
// i
//  thì có chỉ số sức mạnh là
// H
// i
// . Quốc vương muốn biết là có thể bắt được tất cả các con rồng hay không, nếu có hãy cho quốc vương biết tổng sức mạnh thấp nhất của các kỵ sĩ dùng để bắt rồng. Cho số liệu của các con rồng và kỵ sĩ, tính tổng sức mạnh nhỏ nhất trong trường hợp bắt được hoặc trả lời không.

// INPUT

// Dòng đầu gồm 2 số
// n
// ,
// k

// (
// 1
// ≤
// n
// ,
// k
// ≤
// 10
// 5
// )
// .

// Dòng thứ 2 chứa
// n
//  số
// h
// i

// (
// 1
// ≤
// h
// i
// ≤
// 10
// 5
// )
// .

// Dòng thứ 3 chứa
// k
//  số
// d
// i

// (
// 1
// ≤
// d
// i
// ≤
// 10
// 5
// )
// .

// OUTPUT

// In ra tổng sức mạnh nhỏ nhất hoặc in ra "No"

// Ví dụ
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 10000005
#define fi first
#define se second
#define ii pair<int, int>
const ll mod = 1000000007;
using namespace std;
ll n, k, a[nmax], b[nmax], s = 0, dem = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n >> k;
    fo(i, 1, n) cin >> a[i];
    fo(i, 1, k) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + k + 1);
    ll j = 1;
    fo(i, 1, k)
    {
        while (a[j] < b[i] && j <= n)
            j++;
        if (a[j] >= b[i] && j <= n)
        {
            dem++;
            s += a[j];
            j++;
        }
    }
    if (dem == k)
        cout << s;
    else
        cout << "No";
}
