// BISHOPS – QUÂN TƯỢNG
// Cho bàn cờ vua kích thước n × n. Hãy đếm số cách đặt k quân tượng trên bàn cờ sao cho không có hai
// quân tượng nào khống chế nhau
// Quy tắc đi của quân tượng theo luật cờ vua

// T1

// T2 T3

// Ví dụ như ở hình trên, hai quân tượng ở T1 và T2 là khống chế nhau, còn tượng ở T1 và T3, T2 và T3
// không khống chế nhau
// Input:
//  Một dòng duy nhất ghi hai số n, k (1 ≤ n ≤ 10, 1 ≤ k ≤ Min(n, 7))
// Output:
//  Một dòng duy nhất là kết quả bài toán
#include <bits/stdc++.h>
#define lo long long
#define KKH "BISHOP"
#define fi first
#define se second
#define BIT(x, k) (((x) >> (k - 1)) & 1)
#define rs(x, a) memset(x, (a), sizeof x)
#define off(x, k) ((x) ^ (1 << (i - 1)))
using namespace std;
void START()
{
#ifdef toilagun2004
    freopen(KKH ".inp", "r", stdin);
    freopen(KKH ".out", "w", stdout);
#endif // toilagun2004
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const int gh = 16;
int n, k, w[gh], b[gh], f[gh], x[gh], be;
lo kq;
inline bool check(int i, int j, int u, int v)
{
    return abs(j - v) != abs(u - i);
}
bool ok(int pos, int v)
{
    if (v == 0)
        return true;
    for (int i = 1; i < pos; ++i)
        if (f[i] > 0 && !check(x[i], f[i], x[pos], v))
            return false;
    return true;
}
void whitetr(int pos, int &sz)
{
    if (pos > sz)
    {
        w[sz]++;
        return;
    }
    for (x[pos] = x[pos - 1]; x[pos] <= n; ++x[pos])
    {
        be = 1;
        if (x[pos - 1] == x[pos] && f[pos - 1] != 0)
            be = f[pos - 1] + 2;
        for (int j = be; j <= n; ++j)
        {
            if (((x[pos] + j) & 1) || !ok(pos, j))
                continue;
            f[pos] = j;
            whitetr(pos + 1, sz);
        }
    }
}
void blacktr(int pos, int &sz)
{
    if (pos > sz)
    {
        b[sz]++;
        return;
    }
    for (x[pos] = x[pos - 1]; x[pos] <= n; ++x[pos])
    {
        be = 1;
        if (x[pos - 1] == x[pos] && f[pos - 1] != 0)
            be = f[pos - 1] + 2;
        for (int j = be; j <= n; ++j)
        {
            if ((x[pos] + j) % 2 == 0 || !ok(pos, j))
                continue;
            f[pos] = j;
            blacktr(pos + 1, sz);
        }
    }
}
int main()
{
    START();
    cin >> n >> k;
    x[0] = 1;
    for (int i = 0; i <= k; ++i)
    {
        whitetr(1, i);
        blacktr(1, i);
    }
    for (int i = 0; i <= k; ++i)
        kq += 1LL * w[i] * b[k - i];
    cout << kq;
}
