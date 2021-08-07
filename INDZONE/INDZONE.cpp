// Bước đầu hoạt động Khu công nghiệp có hình vuông diện tích 1. Sau một thời gian hoạt động
// có hiệu quả Khu công nghiệp mở rộng thêm một hình vuông diện tích 1 kề cạnh với diện tích
// cũ, tạo thành hình chữ nhật kích thước 1×2. Lần mở rộng thứ i – bổ sung thêm một hình vuông
// có cạnh bằng cạnh lớn của hình chữ nhật ở bước trước và toàn bộ diện tích luôn là một hình chữ nhật.
// Hãy xác định diện tích của Khu công nghiệp sau lần mở rộng thứ n theo module 998244353.
// Input
// • Một dòng duy nhất là số nguyên N
// Output
// • Một dòng duy nhất là diện tích tìm được theo module 998244353
// Giới hạn
// • 1 ≤ N ≤ 1018
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
using namespace std;
const int mod = 998244353;
struct matrix
{
    ll x[15][15];
};
ll n;
matrix nhan(matrix a, matrix b)
{
    matrix c;
    fo(i, 0, 1)
        fo(j, 0, 1)
    {
        c.x[i][j] = 0;
        fo(t, 0, 1)
            c.x[i][j] = (c.x[i][j] + (a.x[i][t] * b.x[t][j]) % mod) % mod;
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
matrix A, B, C;
int main()
{
    cin >> n;
    B.x[0][0] = 0;
    B.x[0][1] = 1;
    B.x[1][0] = 1;
    B.x[1][1] = 1;
    A = mu(B, n);
    C = mu(B, n + 1);
    cout << (A.x[1][1] * C.x[1][1]) % mod;
}
