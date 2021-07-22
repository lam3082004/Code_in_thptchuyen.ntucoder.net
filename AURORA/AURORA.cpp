// AURORA
// Maleficent kể về câu chuyện của bà tiên xinh đẹp xứ Moors với đôi cánh mạnh mẽ và quyền năng
// diệu kì. Cuộc sống nơi thần tiên xứ sở của bà lẽ ra cũng đã được yên vui và tươi đẹp như biết
// bao bà tiên khác nếu như bà không gặp gỡ và yêu phải một người phàm. Bị lòng tham lam và ích
// kỷ của con người lừa lọc và lấy đi thứ tài sản quý giá nhất đời mình, Maleficent từ buồn bã, đau
// đớn, dần dẫn đã rở nên căm phẫn và hận thù loài người. Con tim bà cũng dần trở lên sắt đá và
// lạnh lùng hơn, khiến xứ Moors rơi vào thời kì tối tăm chưa từng có.
// Khi biết được kẻ phản bội mình, Stefan đã lên làm vua của xứ láng giềng và có một cô con gái
// mới sinh Aurora, Maleficent đã quyết định đến và trả thù cho chính mình bằng môt món quá bất
// ngờ. Tuy nhiên, người nhận món quà định mệnh đó không phải là vị vua ích kỷ, mà lại là cô công
// chúa xinh đẹp còn nằm trong nôi. Mãi tận 16 năm sau, Maleficent mới kịp nhận ra và hối hận sự
// mù quáng nhất thời của mình. Từ đó, bà tìm mọi cách để bù đắp và gỡ bỏ lời nguyền cho công
// chúa nhưng không tìm được.
// Trong lúc tuyệt vọng nhất thì con quạ Davis của bà đã vô tình thấy được một chiếc mũ ma thuật,
// ẩn chứa một sức mạnh tiềm tàng hơn cả sức mạnh hiện tại của bà. Và nếu không nhầm thì ma
// thuật từ chiếc mũ này có thể phá vỡ được lời nguyền mà bà đã đặt lên người cô công chúa Aurora
// bé bỏng của chúng ta.
// Nhưng sức mạnh nào cũng cần sự đánh đổi, bên trong chiếc mũ có ghi lại một bài toán và giải
// được bài toán đó là điều kiện để Maleficent có thể sử dụng được ma thuật từ chiếc mũ. Chiếc mũ
// sẽ hiện ra N con số có M chữ số (có thể có số 0 ở đầu), Maleficent cần thay đổi ít nhất số lượng
// chữ số sao cho N số mới tạo thành 1 dãy không giảm. Ví dụ, có 3 số theo thứ tự là 100, 001, 000,
// chúng ta cần 2 bước để biến số 101 thành 201 và 000 thành 400 để thu được 3 số 100, 201 và 400
// không giảm.
// Maleficent không giỏi về những con số nên đã nhờ các bạn giúp đỡ để cứu lấy cô công chúa Aurora
// đáng yêu của mình.
// Dữ liệu
// • Dòng đầu tiên chứa hai số nguyên dương N, M là số lượng số xuất hiện và số lượng chữ số
// của mỗi số.
// • Dòng thứ i trong N dòng tiếp theo, mỗi dòng chứa một số nguyên dương x có chính xác M
// chứ số (tính cả số 0 ở đầu).
// Kết quả
// • Ghi ra một số nguyên duy nhất là số bước thay đổi ít nhất để Maleficent có thể sử dụng
// được mũ phép và cứu được Aurora.
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
#define TASK "aurora"
using namespace std;
const int maxm = 405;
const int maxn = 45;
const int oo = 1e9;
int n, m, s[maxm][maxn][15], a[maxn][maxm];
int f[maxm][maxn][maxn][15];
///--------------------------
void readf()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            char c;
            cin >> c;
            a[i][j] = c - '0';
            for (int k = 0; k < 10; ++k)
                s[j][i][k] = s[j][i - 1][k];
            s[j][i][a[i][j]]++;
        }
}
///--------------------------
inline void op(int &A, int B)
{
    A = min(A, B);
}
///--------------------------
inline int cost(int k, int i, int j, int c)
{
    return j - i + 1 - s[k][j][c] + s[k][i - 1][c];
}
///--------------------------
void solve()
{
    for (int k = m; k > 0; --k)
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j)
            {
                f[k][i][j][0] = cost(k, i, j, 0) + f[k + 1][i][j][9];
                for (int c = 1; c < 10; ++c)
                {
                    int &rs = f[k][i][j][c];
                    rs = f[k][i][j][c - 1];
                    for (int t = i; t <= j; ++t)
                        op(rs, f[k][i][t - 1][c - 1] + cost(k, t, j, c) + f[k + 1][t][j][9]);
                }
            }
    cout << f[1][1][n][9] << '\n';
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
    readf();
    solve();
}
