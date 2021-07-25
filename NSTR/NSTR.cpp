// Với số nguyên

// cho trước, hãy xác định số xâu độ dài

// từ các kí tự trong tập {A, B, C} và không

// chứa xâu con ‘AB’.
// Dữ liệu: Một dòng chứa số nguyên
// .
// Kết quả: Một dòng là số xâu độ dài

// cần tìm. Do kết quả có thể rất lớn, nên chỉ cần in ra phần dư của nó

// cho 10
// + 7.
#include <bits/stdc++.h>
using namespace std;
const int nmax = 55;
const int mod = 1e9 + 7;
struct matran
{
    long long c[3][3];
    matran()
    {
        memset(c, 0, sizeof c);
    }
};
matran operator*(matran A, matran B)
{
    matran res;
    for (int i = 0; i <= 2; i++)
        for (int j = 0; j <= 2; j++)
        {
            res.c[i][j] = 0;
            for (int k = 0; k <= 2; k++)
                res.c[i][j] = (res.c[i][j] + A.c[i][k] * B.c[k][j]) % mod;
        }
    return res;
}
matran mu(matran A, int n)
{
    matran B;
    for (int i = 0; i <= 2; i++)
        B.c[i][i] = 1;
    for (; n > 0; A = A * A, n >>= 1)
        if (n & 1)
            B = B * A;
    return B;
}
int main()
{
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    int n;
    cin >> n;
    matran A, B;
    A.c[0][0] = 1;
    A.c[0][1] = 0;
    A.c[0][2] = 1;
    A.c[1][0] = 1;
    A.c[1][1] = 1;
    A.c[1][2] = 1;
    A.c[2][0] = 1;
    A.c[2][1] = 1;
    A.c[2][2] = 1;
    B.c[0][0] = B.c[0][1] = B.c[0][2] = 1;
    A = mu(A, n - 1);
    B = B * A;
    cout << (B.c[0][0] + B.c[0][1] + B.c[0][2]) % mod;
}
