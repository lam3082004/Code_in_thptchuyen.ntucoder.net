// Cho một dãy số nguyên gồm 𝑁 phần tử 𝑎1, 𝑎2, … , 𝑎𝑁. Gọi 𝑓(𝐴) là giá trị của dãy con liên tiếp có
// tổng lớn nhất của dãy 𝐴. Ví dụ: 𝐴 = (5, −1,2, −3) → 𝑓(𝐴) = 5 + (−1) + 2 = 6.
// Yêu cầu: Cho một số nguyên 𝑥, hãy tìm cách tăng mỗi phần tử trong tối đa một dãy con liên
// tiếp của dãy 𝐴 lên 𝑥 lần sao cho 𝑓(𝐴) lớn nhất có thể.
// Input: Vào từ file SEQ.INP
// • Dòng đầu tiên chứa số hai số nguyên 𝑁 và 𝑥 (𝑁 ≥ 1, |𝑥| ≤ 100);
// • Dòng thứ hai chứa 𝑁 số nguyên 𝑎1, 𝑎2, … , 𝑎𝑁 (|𝑎𝑖
// | ≤ 100);
// Output: Ghi ra file SEQ.OUT kết quả bài toán là giá trị lớn nhất của 𝑓(𝐴).
#include        <bits/stdc++.h>
#define     fo(i, a, b) for (int i = a; i <= b; ++i)
#define     fd(i, a, b) for (int i = a; i >= b; --i)
#define     ll long long
#define     ii pair <int, int>
#define     fi first
#define     se second
#define     task "findper"
using namespace std;
const ll maxn = 3*1e5;
int  n, a[maxn+5], f[maxn+5][5], res, x;
///----------------------------------------------
void                read()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
    #endif // ONLINE_JUDGE
    cin >> n >> x;
    fo(i, 1, n) cin >> a[i];
}
///----------------------------------------------
void                solve()
{
    fo(i, 1, n)
    {
        f[i][1] = max(f[i-1][1], 0) + a[i];
        f[i][2] = max(0, max(f[i-1][1], f[i-1][2])) + a[i]*x;
        f[i][3] = max(0, max(f[i-1][2], f[i-1][3])) + a[i];
        res = max(res, max(f[i][1], max(f[i][2], f[i][3])));
    }
    cout << res;
}
///----------------------------------------------
int main()
{         
    read();
    solve();
}
    