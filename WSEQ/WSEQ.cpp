// WSEQ
// Trọng số bậc 𝑘 của một dãy số nguyên không âm 𝑎1, 𝑎2, . . , 𝑎𝑛 được tính bằng:
// ∑ 𝑎𝑖
// 𝑛
// 𝑖=1 − ∑ 𝑎𝑗×𝑘
// [
// 𝑛
// 𝑘
// ]
// 𝑗=1
// Ta có phép biến đổi dãy số như sau: Lấy ra không quá 𝑚 phần tử ở vị trí 𝑖1 < 𝑖2 < ⋯ < 𝑖𝑠 (𝑠 ≤
// 𝑚) rồi lần lượt xếp các phẩn tử đó vào cuối dãy, để nhận được một dãy số mới.
// Yêu cầu: Cho dãy số nguyên không âm 𝑎1, 𝑎2, . . , 𝑎𝑛 và hai số nguyên 𝑘, 𝑚, hãy biến đổi dãy để
// nhận được dãy số có trọng số nhỏ nhất.
// Input
// - Dòng đầu chứa ba số nguyên 𝑛, 𝑚, 𝑘;
// - Dòng thứ hai chứa 𝑛 số nguyên không âm mô tả dãy 𝑎1, 𝑎2, . . , 𝑎𝑛.
// Output
// - Gồm một dòng chứa một số là trọng số nhỏ nhất của dãy tìm được
#include <bits/stdc++.h>
#define ll long long
#define II pair<int, int>
#define fi first
#define se second
#define task "test"
using namespace std;

void Init()
{
#ifndef ONLINE_JUDGE
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, m, k, N;
int a[8001];
vector<int> b;
int F[401][401];
int S = 0, res;

void Solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        S += a[i];
    }
    if (n > 400)
    {
        int N = n % k;
        int l = n - ((m - N) / k * k) + (k - N - 1);
        b.push_back(0);
        if (l < n)
            for (int i = k; i < l; ++i)
                b.push_back(a[i]);
        else
            for (int i = N + 1; i < n; ++i)
                b.push_back(a[i]);
        b.push_back(a[n]);
        if (l < n)
        {
            for (int i = 1; i < k; ++i)
                b.push_back(a[i]);
            for (int i = l; i < n; ++i)
                b.push_back(a[i]);
        }
        else
            for (int i = 1; i <= N; ++i)
                b.push_back(a[i]);

        for (int i = 1; i < b.size(); ++i)
            if (i % k == 0)
                res += b[i];
        cout << S - res;
        return;
    }
    for (int x = n - m; x <= n; ++x)
    {
        memset(F, 0, sizeof F);
        for (int i = 1; i <= n; ++i)
        {
            if (i - n + x <= 0)
            {
                F[i][0] = F[i - 1][0] + ((x + i) % k == 0 ? a[i] : 0);
                //if(F[i][0])cout<<i<<' '<<0<<' '<<F[i][0]<<'\n';
                res = max(res, F[i][0]);
            }
            for (int j = max(i - n + x, 1); j < i && j <= x; ++j)
            {
                F[i][j] = max(F[i - 1][j] + ((x + i - j) % k == 0 ? a[i] : 0), F[i - 1][j - 1] + (j % k == 0 ? a[i] : 0));
                //if(F[i][j])cout<<i<<' '<<j<<' '<<F[i][j]<<' '<<F[i-1][j]<<'\n';
                res = max(res, F[i][j]);
            }
            if (i <= x)
            {
                F[i][i] = F[i - 1][i - 1] + (i % k == 0 ? a[i] : 0);
                //if(F[i][i])cout<<i<<' '<<i<<' '<<F[i][i]<<'\n';
                res = max(res, F[i][i]);
            }
        }
    }
    cout << S - res;
}

void MakeTest()
{
}

int main()
{
    MakeTest();
    Init();
    Solve();
}
