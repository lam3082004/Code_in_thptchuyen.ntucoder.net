// SEQ
// Dãy số a gồm N số nguyên a1, a2, ..., aN . Tìm cách xóa bỏ K số trong N số sao cho: gọi X là
// chênh lệch cực đại, Y là chênh lệch cực tiểu trong dãy số sau khi xóa K số thì X + Y đạt giá trị nhỏ
// nhất.
// Dữ liệu
// • Dòng đầu tiên: chứa hai số nguyên dương N, K (3 ≤ N ≤ 106
// , 1 ≤ K ≤ N − 2).
// • Dòng thứ hai: chứa N số nguyên biểu diễn dãy a (|ai
// | ≤ 109
// ).
// Kết quả
// • Một số nguyên duy nhất là giá trị X + Y nhỏ nhất tìm được.
//KNSB
#include <bits/stdc++.h>
#define ll long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;

void Init()
{
    ios::sync_with_stdio(0ll);
    cin.tie(0ll);
    cout.tie(0ll);
}

int a[1000001];
deque<II> S;
int n, m, n2;
int s, res;

void Solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; ++i)
        a[i] = a[i + 1] - a[i];
    n2 = n - m - 1;
    s = 0;
    for (int i = 1; i <= n2; ++i)
    {
        s += a[i];
        while (!S.empty() && S.back().fi >= a[i])
            S.pop_back();
        S.push_back({a[i], i});
    }
    res = s + S.front().fi;
    for (int i = n2 + 1, j = 1; i < n; ++i, ++j)
    {
        while (!S.empty() && S.front().se <= j)
            S.pop_front();
        while (!S.empty() && S.back().fi >= a[i])
            S.pop_back();
        S.push_back({a[i], i});
        s += a[i] - a[j];
        res = min(res, s + S.front().fi);
    }
    cout << res;
}

int main()
{
    //MakeTest();
    Init();
    Solve();
}
