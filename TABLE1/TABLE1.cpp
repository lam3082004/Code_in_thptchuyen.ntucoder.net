// TABLE
// Mirko mới mua một căn hộ và muốn mời thật nhiều người tới ăn bữa tối cùng mình để
// tổ chức liên hoan. Để làm điều này, anh ấy cần một chiếc bàn gỗ hình chữ nhật. Tổng số
// người chiếc bàn này có thể chứa bằng với chu vi của nó (tổng các độ dài của bốn mặt).
// Mirko muốn mua một chiếc bàn để chứa được càng nhiều người càng tốt nhưng cần phải
// vừa với căn hộ của mình. Chiếc bàn phải được xếp sao cho các cạnh của nó song song với
// các mặt tường của căn hộ.
// Cho bản đồ căn hộ, tính ra số người mà Mirko có thể mời tới bữa tối. Chú ý rằng trong
// bữa tiệc nhất định phải có Mirko.
// Input: file văn bản TABLE.INP gồm
//  Dòng đầu tiên chứa hai số nguyên R và C (1 ≤ R, C ≤ 400), là các kích thước của
// căn hộ.
//  Mỗi dòng trong R dòng tiếp theo chứa chính xác C kí tự (không có khoảng trống)
// là các ô vuông còn trống (‘.’) hoặc là đã bị chặn (‘X’) bởi các bức tường hoặc đồ
// vật nào đó.
// Output: file văn bản TABLE.OUT cho ra số khách Mirko có thể mời tới bữa tối sau khi
// mua bàn trên một dòng. Lưu ý rằng Mirko cũng tham gia bữa tiệc.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define nmax 1000005
using namespace std;
int r, c, u[405][405], d[405][405], kq = 0;
char a[405][405];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c;
    fo(i, 1, r)
            fo(j, 1, c)
                cin >>
        a[i][j];
    fo(j, 1, c)
        fo(i, 1, r)
    {
        if (a[i][j] == '.')
        {
            if (a[i - 1][j] == '.')
                u[i][j] = u[i - 1][j] + 1;
            else
                u[i][j] = 0;
        }
    }
    fo(j, 1, c) for (int i = r; i >= 1; i--)
    {
        if (a[i][j] == '.')
        {
            if (a[i + 1][j] == '.')
                d[i][j] = d[i + 1][j] + 1;
            else
                d[i][j] = 0;
        }
    }
    fo(i, 1, r)
    {
        fo(j, 1, c)
        {
            int U = u[i][j], D = d[i][j];
            fo(t, j, c)
            {
                if (a[i][t] == '.')
                {
                    U = min(U, u[i][t]);
                    D = min(D, d[i][t]);
                    kq = max(kq, ((D + U + 1) + (t - j + 1)) * 2);
                }
                else
                    break;
            }
        }
    }
    cout << kq - 1;
}
