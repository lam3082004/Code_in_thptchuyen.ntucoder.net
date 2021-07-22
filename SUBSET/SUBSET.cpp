// Cho dãy số nguyên gồm 𝑛 phần tử 𝑎1, 𝑎2, … , 𝑎𝑛 thỏa mãn 𝑖 − 𝑛 ≤ 𝑎𝑖 ≤ 𝑖 − 1 (∀𝑖 ∈ [1, 𝑛]).
// Yêu cầu: Tìm tập hợp gồm một số phần tử trên dãy 𝐴 có tổng bằng 0.
// Input:
//  Dòng đầu chứa số nguyên dương 𝑛 (𝑛 ≤ 105).
//  Dòng thứ hai chứa 𝑛 số nguyên 𝑎1, 𝑎2, … , 𝑎𝑖
// (𝑖 − 𝑛 ≤ 𝑎𝑖 ≤ 𝑖 − 1).
// Output: Nếu không tồn tại tập hợp thỏa mãn, in ra −1. Nếu tồn tại, in ra kết quả bài toán theo
// cách thức sau:
//  Dòng đầu chứa số nguyên dương 𝑠 (1 ≤ 𝑠 ≤ 𝑛) − số lượng phần tử trong tập hợp được
// chọn.
//  Dòng thứ hai chứa 𝑛 giá trị nguyên dương phân biệt 𝑖1, 𝑖2, … , 𝑖𝑠
// (1 ≤ 𝑖𝑘 ≤ 𝑛) thỏa mãn
// 𝑎𝑖1 + 𝑎𝑖2 + ⋯ + 𝑎𝑖𝑠 = 0.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
#define ii pair<int, int>
#define fi first
#define se second
#define oo 1e9
using namespace std;
const int mod = 1e9 + 7;
ll n, a[nmax], f[nmax], pos, dem = 1;
vector<int> p[nmax];
void dfs(int u)
{
    for (auto v : p[u])
    {
        if (f[v] == 0)
        {
            f[v] = 1;
            dfs(v);
        }
        else
            pos = v;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n)
    {
        cin >> a[i];
        p[i].push_back(i - a[i]);
    }
    f[1] = 1;
    dfs(1);
    int s = p[pos][0];
    while (s != pos)
    {
        dem++;
        s = p[s][0];
    }
    cout << dem << '\n'
         << pos << ' ';
    s = p[pos][0];
    while (s != pos)
    {
        cout << s << ' ';
        s = p[s][0];
    }
}
