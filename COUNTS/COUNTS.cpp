// Cho hai xâu
// A
// ,
// B
//  chỉ gồm các kí tự latin thường (𝑎→𝑧). Hãy đếm xem có bao nhiêu xâu con liên tiếp trong xâu
// B
//  mà “tương đương”  với xâu
// A
// . Xâu con liên tiếp
// B
// i
// B
// i
// +
// 1
// .
// .
// .
// B
// j
//  được gọi là “tương đương”  với xâu
// A
//  nếu chúng khi được thay thế không quá
// K
//  kí tự thì tạo được một xâu mới chính là xâu
// A
// . Như vậy, nhiệm vụ của bạn là đếm số cặp
// (
// i
// ,
// j
// )
//  như vậy.

// Dữ liệu vào:

// - Dòng đầu chứa số nguyên dương
// K

// (
// K
// ≤
// 5
// ,
// K
// ≤
// |
// A
// |
// )
// .

// - Dòng thứ hai chứa xâu
// A
// .

// - Dòng thứ ba chứa xâu
// B
// .

// (
// |
// A
// |
// ≤
// |
// B
// |
// ≤
// 10
// 5
// )
// .

// *) Kí hiệu
// |
// S
// |
//  là độ dài xâu
// S
// .

// Kết quả:

// - gồm một số nguyên dương duy nhất chính là số lượng xâu con liên tiếp “tương đương” với xâu
// A
//  trong xâu
// B
// .
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
using namespace std;
const int mod = 1e9 + 7;
ll n, m, k, hasha, hashb[nmax], poww[nmax], dem = 0;
string a, b;
ll gett(ll l, ll r)
{
    return ((hashb[r] - hashb[l - 1] * poww[r - l + 1]) % mod + mod) % mod;
}
void sub1()
{
    fo(i, 1, m - n + 1)
    {
        ll tmp = 0;
        fo(j, 1, n) if (a[j] != b[i + j - 1]) tmp++;
        if (tmp <= k)
            dem++;
    }
    cout << dem;
}
void sub2()
{
    poww[0] = 1;
    fo(i, 1, n)
        hasha = (hasha * 31 + a[i] - 'a' + 1) % mod;
    fo(i, 1, m)
    {
        hashb[i] = (hashb[i - 1] * 31 + b[i] - 'a' + 1) % mod;
        poww[i] = (poww[i - 1] * 31) % mod;
    }
    fo(i, 1, m - n + 1) if (gett(i, i + n - 1) == hasha)
        dem++;
    cout << dem;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("COUNTS.inp", "r", stdin);
    freopen("COUNTS.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> a >> b;
    n = a.size();
    a = ' ' + a;
    m = b.size();
    b = ' ' + b;
    if (k == 0)
        sub2();
    else
        sub1();
}
