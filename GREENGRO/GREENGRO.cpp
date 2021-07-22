// GREENGROCER
// Vegeta là một người bán rau và rất yêu thích thuật toán. Mỗi ngày, anh ta chọn một dãy phố
// trong thành phố Satan và ghé thăm tất cả các căn nhà trong dãy phố đó để bán rau.
// Mỗi đường phố trong thành phố Satan có cùng số lượng nhà ở hai bên đường, và kích thước mỗi
// ngôi nhà như nhau.
// Nếu đang ở ngôi nhà X, Vegeta chỉ muốn di chuyển sang những ngôi nhà kề cạnh hoặc kề đỉnh
// với ngôi nhà X. Điều này đồng nghĩa với việc anh ta chỉ di chuyển ngang, dọc hoặc theo đường
// chéo. Mặt khác, Vegeta có thể bắt đầu bán rau tại bất kì ngôi nhà nào trong dãy phố, và sẽ không
// thăm lại các ngôi nhà đã được đi qua, vì chắc chắn anh ta không thể bán được rau tại các ngôi
// nhà đó.
// Biết số lượng ngôi nhà ở mỗi bên của dãy phố là n. Vegeta muốn biết số lượng đường đi thỏa mãn
// các điều kiện bên trên và đi qua tất cả các căn nhà trong dãy phố là bao nhiêu?
// Dữ liệu
// • Gồm một số nguyên dương n duy nhất là số lượng ngôi nhà ở mỗi bên của dãy phố
// (1 ≤ n ≤ 109
// )
// Kết quả
// • Đưa ra một số nguyên duy nhất là kết quả bài toán. Vì kết quả có thể rất lớn, bạn chỉ cần
// đưa ra kết quả theo modulo 1000000007
// Chấm điểm
// • 10% số test ứng với 10% số điểm có n ≤ 10.
// • 30% số test ứng với 30% số điểm có n ≤ 1000000.
// • 60% số test còn lại không có giới hạn gì thêm.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define __unique(V) (V).resize(unique((V).begin(), (V).end()) - (V).begin())
#define cntbit(X) __builtin_popcount((X))
#define bit(S, i) (((S) >> (i)) & 1)
#define PI acos(-1)
#define fi first
#define se second
#define LL long long
#define ii pair<int, int>
#define iii pair<int, ii>
#define eb emplace_back
#define TASK "greengrocer"
using namespace std;
struct matrix
{
    int x[20][20];
    matrix()
    {
        memset(x, 0, sizeof(x));
    }
};
const int mod = 1000000007;
matrix M, S;
int id[3][3][2];
///--------------------------
void init()
{
    int node = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 2; ++k)
                id[i][j][k] = ++node;
}
///--------------------------
void init_dp()
{
    ///010
    M.x[id[0][1][0]][id[1][2][1]] = 1;
    M.x[id[0][1][0]][id[2][1][1]] = 1;
    M.x[id[0][1][0]][id[0][1][0]] = 1;
    M.x[id[0][1][0]][id[1][0][0]] = 1;
    ///100
    M.x[id[1][0][0]][id[1][2][1]] = 1;
    M.x[id[1][0][0]][id[2][1][1]] = 1;
    M.x[id[1][0][0]][id[0][1][0]] = 1;
    M.x[id[1][0][0]][id[1][0][0]] = 1;
    ///110
    M.x[id[1][1][0]][id[1][0][0]] = 2;
    M.x[id[1][1][0]][id[0][1][0]] = 2;
    M.x[id[1][1][0]][id[1][1][0]] = 2;
    M.x[id[1][1][0]][id[1][2][1]] = 2;
    M.x[id[1][1][0]][id[2][1][1]] = 2;
    ///111
    M.x[id[1][1][1]][id[1][1][1]] = 2;
    M.x[id[1][1][1]][id[0][0][0]] = 2;
    ///121
    M.x[id[1][2][1]][id[1][1][1]] = 2;
    M.x[id[1][2][1]][id[0][0][0]] = 2;
    M.x[id[1][2][1]][id[0][1][0]] = 1;
    M.x[id[1][2][1]][id[1][0][0]] = 1;
    ///211
    M.x[id[2][1][1]][id[1][1][1]] = 2;
    M.x[id[2][1][1]][id[0][0][0]] = 2;
    M.x[id[2][1][1]][id[0][1][0]] = 1;
    M.x[id[2][1][1]][id[1][0][0]] = 1;
    ///221
    M.x[id[2][2][1]][id[0][0][0]] = 2;
    M.x[id[2][2][1]][id[0][1][0]] = 2;
    M.x[id[2][2][1]][id[1][0][0]] = 2;
    M.x[id[2][2][1]][id[1][1][1]] = 2;
}
///--------------------------
matrix operator*(matrix A, matrix B)
{
    matrix C;
    for (int i = 1; i < 20; ++i)
        for (int j = 1; j < 20; ++j)
            for (int k = 1; k < 20; ++k)
                C.x[i][j] = (C.x[i][j] + 1LL * A.x[i][k] * B.x[k][j]) % mod;
    return C;
}
///--------------------------
matrix operator^(matrix A, int B)
{
    matrix C;
    for (int i = 1; i < 20; ++i)
        C.x[i][i] = 1;
    for (; B; A = A * A, B >>= 1)
        if (B & 1)
            C = C * A;
    return C;
}
///--------------------------
void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 2 << '\n';
        exit(0);
    }
    init();
    init_dp();
    S.x[1][id[1][1][0]] = 1;
    S.x[1][id[2][2][1]] = 1;
    S = S * (M ^ (n - 1));
    int ans = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            ans = (ans + S.x[1][id[i][j][0]]) % mod;
    cout << (2 * ans % mod) << '\n';
}
///--------------------------
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef TLH2203
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif // TLH2203
    solve();
}
