
// Cho ma trận n đỉnh được đánh số từ 1 đến n, chọn m đỉnh ai,ai,..,am;

// Giữa 2 đỉnh được chọn khác nhau bất kì luôn có 1 đường đi 2 chiều;

// Đếm số cách đi từ đỉnh a đến đỉnh b qua k bước

// Giới Hạn:

// n,a,b,k<=1e18;

// m<=50;

// PS: a có thể bằng b

// Dữ liệu vào:

// - Dòng 1: n,m,a,b,k;

// - Dòng 2: m đỉnh được chọn

// Dữ liệu ra:

// - Kết quả của bài toán theo modul 1e9+7;
#include <bits/stdc++.h>
#define base 1000000007
using namespace std;
const int nmax = 1e5 + 5;
long long n, k, a, b;
int m;
int t;
struct matran
{
    long long c[51][51];
    matran()
    {
        memset(c, 0, sizeof c);
    }
};
matran operator*(matran a, matran b)
{
    matran res;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
        {
            res.c[i][j] = 0;
            for (int t = 0; t < m; t++)
                res.c[i][j] = (res.c[i][j] + (a.c[i][t] * b.c[t][j])) % base;
        }
    return res;
}
matran mu(matran a, long long n)
{
    matran B;
    for (int i = 0; i < m; i++)
        B.c[i][i] = 1;
    for (; n > 0; a = a * a, n >>= 1)
        if (n % 2 == 1)
            B = B * a;
    return B;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    cin >> n >> m >> a >> b >> k;
    bool c1 = false, c2 = false;
    int l = 0, r = 0;
    for (int i = 1; i <= m; i++)
    {
        long long x;
        cin >> x;
        if (x == a)
        {
            l = i;
            c1 = true;
        }
        if (x == b)
        {
            r = i;
            c2 = true;
        }
    }
    if (!c1 || !c2)
    {
        cout << 0 << ' ';
        return 0;
    }
    matran A, B;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            if (i != j)
                B.c[i][j] = 1;
    A.c[0][l - 1] = 1;
    B = mu(B, k);
    A = A * B;
    cout << A.c[0][r - 1] << '\n';
}
