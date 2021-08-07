// Dãy Fibonacci là dãy vô hạn các số tự nhiên bắt đầu bằng hai phần tử 0 và 1, các
// phần tử sau đó được thiết lập theo quy tắc mỗi phần tử luôn bằng tổng hai phần tử trước
// nó. Dãy số Fibonacci rất đặc biệt này được Leonardo Fibonacci (hay còn có tên tên khác
// là Leonarda da Pisa) là một nhà toán học người Ý công bố vào năm 1202 trong cuốn sách
// Liber Abacci - Sách về toán đố qua 2 bài toán: Bài toán con thỏ và bài toán số các "cụ tổ"
// của một ong đực. Dãy số này hầu như biến hóa vô tận. Chính đều đó làm cho bao nhà
// toán học (chuyên nghiệp lẫn nghiệp dư) say mê nghiên cứu, khám phá về nó. Ta xét một
// biến thể như sau:
// Xét dãy số fib3 là một biến thể của dãy số Fibonacci, với ba số nguyên không âm
// a,b,c ta xây dựng dãy số theo quy tắc sau:

// ( )
// {
// ( ) ( ) ( )
// ( ) ( ) ( )
// ( ) ( ) ( )

// Yêu cầu: Cho 5 số nguyên không âm . Hãy tính số ( ) .
// Input
// - Gồm nhiều bộ dữ liệu (có không quá 30 bộ), mỗi bộ trên một dòng, mỗi dòng chứa 5 số
// nguyên không âm (

// )

// Output
// - Gồm nhiều dòng, mỗi dòng chứa một số là kết quả tìm được tương ứng với dữ liệu vào.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
struct matrix
{
    ll x[15][15];
};
ll a, b, c, n, k;
matrix nhan(matrix a, matrix b)
{
    matrix c;
    fo(i, 1, 3)
        fo(j, 1, 3)
    {
        c.x[i][j] = 0;
        fo(t, 1, 3)
            c.x[i][j] = (c.x[i][j] + (a.x[i][t] * b.x[t][j]) % k) % k;
    }
    return c;
}
matrix mu(matrix a, ll n)
{
    if (n == 1)
        return a;
    matrix t = mu(a, n / 2);
    t = nhan(t, t);
    if (n % 2 == 1)
        t = nhan(t, a);
    return t;
}
matrix A, B, C, M;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("3FIB.inp", "r", stdin);
    freopen("3FIB.out", "w", stdout);
#endif // ONLINE_JUDGE
    while (cin >> a >> b >> c >> k >> n)
    {
        A.x[1][2] = 1;
        A.x[2][3] = 1;
        A.x[3][1] = c;
        A.x[3][2] = b;
        A.x[3][3] = a;
        B.x[1][2] = 1;
        B.x[2][3] = 1;
        B.x[3][1] = a;
        B.x[3][2] = c;
        B.x[3][3] = b;
        C.x[1][2] = 1;
        C.x[2][3] = 1;
        C.x[3][1] = b;
        C.x[3][2] = a;
        C.x[3][3] = c;
        M.x[1][3] = 1;
        M.x[2][3] = 2;
        M.x[3][3] = 3;
        if (n <= 3)
            cout << n % k << '\n';
        else
        {
            ll x = n / 3 - 1, y = n % 3;
            if (x > 0)
            {
                M = nhan(mu(nhan(C, nhan(B, A)), x), M);
            }
            if (y >= 1)
                M = nhan(A, M);
            if (y >= 2)
                M = nhan(B, M);
            cout << M.x[3][3] << '\n';
        }
    }
}
//42477898
//74301270
