// 2 : RECMIN.cpp
// Cho hình chữ nhật gồm m dòng và n cột. Các dòng được đánh số từ 1 đến m (từ
// trên xuống dưới), các cột đánh số từ 1 đến n (từ trái sang phải). Trên mỗi ô vuông
// nhỏ có ghi một số nguyên dương.
// Yêu cầu: Tìm một hình chữ nhật có các cạnh song song (hoặc trùng ) với các cạnh
// hình chữ nhật sao cho:
//  Tổng các số trong hình chữ nhật bằng đúng k (k là số nguyên dương cho
// trước)
//  Diện tích hình chữ nhật là nhỏ nhất có thể.
// Dữ liệu ghi trong file RECMIN.INP như sau:
//  Dòng đầu ghi ba số nguyên dương m, n, k
//  m dòng tiếp theo, mỗi dòng ghi n số nguyên dương (thuộc phạm vi số
// Longint) là các số trên các ô vuông nhỏ của hình chữ nhật.
// Kết quả ghi ra file RECMIN.OUT gồm một số duy nhất là diện tích nhỏ nhất của
// hình chữ nhật tìm được, nếu không có hình chữ nhật nào thỏa mãn thì ghi -1.
#include <bits/stdc++.h>
#define l2 long long
using namespace std;
l2 m, n, k, a, f[205][1005], t = 1e9, g[1005], s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> k;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a;
            f[i][j] = f[i - 1][j] + a;
        }
    g[0] = 0;
    l2 x, y;
    for (int i = 1; i <= m; i++)
        for (int j = i; j <= m; j++)
        {
            for (int z = 1; z <= n; z++)
                g[z] = f[j][z] - f[i - 1][z];
            x = y = 1;
            s = 0;
            while (x <= y && y <= n)
            {
                s += g[y];
                while (s > k)
                {
                    s -= g[x];
                    x++;
                }
                if (s == k)
                {
                    //  cout<<i<<" "<<j<<" "<<x<<" "<<y<<endl;
                    t = min(t, (j - i + 1) * (y - x + 1));
                }
                y++;
            }
        }
    cout << (t == 1e9 ? -1 : t);
}
