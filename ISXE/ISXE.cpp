// Cho hai dãy số nguyên dương gồm 𝑁 phần tử 𝑎1, 𝑎2, … , 𝑎𝑁 và 𝑏1, 𝑏2, … , 𝑏𝑁. Đặt 𝑐𝑖 = {𝑎𝑖
// , 𝑏𝑖
// }, tức
// là khi sắp xếp lại dãy 𝐶 theo một thứ tự nào đó, giá trị 𝑏𝑖
// luôn theo kèm và phụ thuộc với giá trị
// 𝑎𝑖
// . Trọng số của dãy 𝐶 được tính bằng giá trị 𝑃(𝐶) = ∑1≤ (2 × 𝑏𝑖 × 𝑎𝑗).
// 𝑖<𝑗≤𝑁
// Yêu cầu: Bạn hãy sắp xếp dãy 𝐶 sao cho 𝑃(𝐶) đạt giá trị nhỏ nhất, in ra giá trị 𝑃(𝐶).
// Input:
//  Dòng đầu chứa một số nguyên dương 𝑁 (𝑁 ≤ 105);
//  𝑁 dòng tiếp theo, dòng thứ 𝑖 chứa cặp số nguyên dương 𝑎𝑖 và 𝑏𝑖
// (𝑎𝑖 ≤ 2.109
// ; 𝑏𝑖 ≤ 100).
// Output: In ra kết quả bài toán.
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<ll, ll>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 1000005
const ll mod = 1e9 + 7;
using namespace std;
bool cmp(ii a, ii b)
{
    return a.fi * b.se > a.se * b.fi;
}
ll n;
ii p[nmax];
ll s = 0, s1 = 0;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n) cin >> p[i].fi >> p[i].se;
    sort(p + 1, p + n + 1, cmp);
    fo(i, 1, n)
    {
        s += 2 * p[i].fi * s1;
        s1 += p[i].se;
    }
    cout << s;
}
