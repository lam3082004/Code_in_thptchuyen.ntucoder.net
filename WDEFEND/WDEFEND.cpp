// Trước cuộc xâm chiếm của zombies, người dân thành phố FC đã thành lập một đội hộ vệ thành
// phố gồm K tổ tuần tra.
// Thành phố được chia thành M × N khu phố dưới dạng lưới chứ nhật M × N như hình vẽ bên
// dưới. Chủ tịch thành phố FC muốn phân các tổ tuần tra về các khu phố theo ràng buộc sau:
// • Mỗi mặt trong số 4 mặt ngoài của thành phố luôn có ít nhất một tổ tuần tra (xem phần tô
// đậm của hình minh họa). Lưu ý rằng nếu một tổ tuần tra nằm ở một khu phố là góc của
// lưới chứ nhật, cả 2 mặt ngoài chung góc đó đều được xem như đã có một tổ tuần tra.
// • Mỗi khu phố có nhiều nhất một tổ tuần tra.
// • Mỗi tổ tuần tra đều được phân về một khu phố nào đó.
// Chủ tịch thành phố FC muốn biết rằng có tất cả bao nhiêu cách sắp xếp các tổ tuần tra thoả
// mãn tất cả các điều kiện trên. Mặt khác, số lượng cách sắp xếp có thể rất lớn, vì thế ông ta chỉ
// muốn biết phần dư của số lượng cách sắp xếp theo modulo 1000000007
// Dữ liệu
// • Dòng đầu tiên chứa số nguyên dương T (T ≤ 50) là số lượng bộ test bạn cần giải quyết
// • T dòng tiếp theo, mỗi dòng chứa 3 số nguyên không âm M, N, K lần lượt là số lượng
// hàng, số lượng cột của lưới chữ nhật và số lượng tổ tuần tra cần phân về các khu phố
// (2 ≤ M, N ≤ 20, K ≤ 500)
// Kết quả
// • Đưa ra kết quả trên T dòng ứng với T bộ test cần giải quyết
//KNSB
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void Init()
{
    ios::sync_with_stdio(0ll);
    cin.tie(0ll);
    cout.tie(0ll);
}

const int D[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
const ll MOD = 1e9 + 7;
ll C[401][401];
int n, m, k, n2, m2;
int res = 0;

void Cal(int a, int b, int c, int d, int e)
{
    int g = (a == 0) + (b == 0) + (c == 0) + (d == 0);
    ll h = 0;
    if (e == 0 && g == 0)
        h = 1;
    if (e == 1)
    {
        if (g == 0)
            h = 4;
        if (g == 1)
            h = 2;
        if (g == 2 && ((a == 0) != (c == 0)))
            h = 1;
    }
    if (e == 2)
    {
        if (g == 0)
            h = 6;
        if (g == 1)
            h = 5;
        if (g == 2)
            h = 4;
        if (g == 3)
            h = 3;
        if (g == 4)
            h = 2;
    }
    if (e >= 3)
        h = C[e][4];
    if (h == 0)
        return;
    ll t = h * C[a][m2] * C[b][n2] % MOD * C[c][m2] % MOD * C[d][n2] % MOD * C[k - a - b - c - d - e][n2 * m2] % MOD;
    if (t == 0)
        return;
    res = (res + t) % MOD;
}

void Solve()
{
    for (int i = 0; i <= 400; ++i)
        for (int j = i; j <= 400; ++j)
            if (i == 0)
                C[i][j] = 1;
            else
                C[i][j] = (C[i][j - 1] + C[i - 1][j - 1]) % MOD;
    cin >> n;
    while (cin >> n >> m >> k)
    {
        if (n * m < k)
        {
            cout << 0 << '\n';
            continue;
        }
        n2 = n - 2;
        m2 = m - 2;
        res = 0;
        for (int a = 0; a <= m2; ++a)
            for (int b = 0; b <= n2; ++b)
                for (int c = 0; c <= m2; ++c)
                    for (int d = 0; d <= n2; ++d)
                        for (int e = 0; e <= 4; ++e)
                            if (a + b + c + d + e <= k)
                                Cal(a, b, c, d, e);
        cout << res << '\n';
    }
}

int main()
{
    Init();
    Solve();
}
