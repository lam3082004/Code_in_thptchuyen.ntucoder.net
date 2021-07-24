// FENCE - HÀNG RÀO
// Để tránh bị tuần lộc ăn hết cà rốt trong vườn, ông già Noel muốn xây một hàng rào để che
// mảnh vườn đó.
// Ông già Noel có N thanh gỗ, thanh thứ i có độ dài i. Ông muốn sắp xếp hàng rào sao cho
// không có vị trí nào mà thanh gỗ tại đó cao hơn thanh gỗ ở cả hai bên. Hỏi có bao nhiêu cách xếp
// Input
// • Một số nguyên duy nhất là số N - số thanh hàng rào
// Output
// • Một số duy nhất là số cách xếp hàng rào. Do kết quả có thể rất lớn nên chỉ cần in ra số dư
// cho 100000007
// Giới hạn
// • 1 ≤ N ≤ 106
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 10000005
#define fi first
#define se second
#define ii pair<int, int>
const ll mod = 1e8 + 7;
using namespace std;
ll mu(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tam = mu(a, b / 2);
    tam = (tam * tam) % mod;
    if (b % 2 == 1)
        tam = (tam * a) % mod;
    return tam;
}
int n;
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
    cout << mu(2, n - 1) % mod;
}
