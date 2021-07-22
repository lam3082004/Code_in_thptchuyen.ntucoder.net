// Đếm số cách đặt 𝑘 quân tượng lên bàn cờ 𝑛 × 𝑛 sao cho không có con tượng
// nào ăn được nhau (luật cờ vua).
// INPUT
// - 1 dòng chứa 2 số nguyên dương 𝑛, 𝑘 (2 ≤ 𝑛, 𝑘 ≤ 1000).
// OUTPUT
// - 1 dòng in kết quả bài toán module 109 + 7.
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define nfor(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second

using namespace std;

const int e = 1e9 + 7;

int squares(int i)
{
    if (i & 1)
        return i / 4 * 2 + 1;
    else
        return (i - 1) / 4 * 2 + 2;
}

long long bishop_placements(int N, int K)
{
    if (K > 2 * N - 1)
        return 0;

    vector<vector<long long>> D(N * 2, vector<long long>(K + 1));
    for (int i = 0; i < N * 2; ++i)
        D[i][0] = 1;
    D[1][1] = 1;
    for (int i = 2; i < N * 2; ++i)
        for (int j = 1; j <= K; ++j)
            D[i][j] = (D[i - 2][j] + D[i - 2][j - 1] * (squares(i) - j + 1)) % e;

    long long ans = 0;
    for (int i = 0; i <= K; ++i)
        ans = (ans + D[N * 2 - 1][i] * D[N * 2 - 2][K - i]) % e;
    return ans;
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    cout << bishop_placements(n, k);
    return 0;
}
