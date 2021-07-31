// Cho một bảng gồm m dòng và n cột, các dòng được đánh số từ 1 đến m (từ trên xuống dưới), các
// cột được đánh số từ 1 đến n (từ trái qua phải). Ô ở dòng i và cột j được gọi là ô (i, j). Tại mỗi ô
// (i, j) có ghi một kí tự chữ cái la tinh thường hoặc một kí tự ‘#’. Có một con Robot đặt tại ô (1, 1).
// Robot có nhiệm vụ phải di chuyển đến ô (m, n). Quy tắc di chuyển của Robot như sau:
// - Robot đang đứng tại ô (i, j) thì có thể di chuyển đến một trong hai ô: (i, j+1), (i+1, j). Tất
// nhiên, Robot không di chuyển ra ngoài bảng.
// - Robot không di chuyển đến ô có kí tự ‘#’.
// Gọi St là xâu kí tự tạo thành bằng cách ghép lần lượt các kí tự mà Robot đi qua.
// Yêu cầu 1: Tìm cho Robot một cách di chuyển từ ô (1, 1) đến ô (m, n) sao cho xâu St bé nhất.
// Yêu cầu 2: Tìm cho Robot một cách di chuyển từ ô (1, 1) đến ô (m, n) sao cho xâu St lớn nhất.
// Dữ liệu vào từ file văn bản MOVEBOARD.INP như sau:
//  Dòng đầu ghi hai số nguyên dương m, n.
//  m dòng sau, mỗi dòng ghi một xâu gồm n kí tự, hoặc là kí tự chữ cái la tinh thường, hoặc
// là kí tự ‘#’.
// Kết quả ghi ra file văn bản MOVEBOARD.OUT gồm:
//  Dòng thứ nhất đưa ra xâu St bé nhất tìm được.
//  Dòng thứ hai đưa ra xâu St lớn nhất tìm được.
// Nếu không có cách di chuyển thì ghi -1.
#include <bits/stdc++.h>
using namespace std;

void Init()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, m;
char A[1002][1002];
bool C[1002][1002];
bool Cn[1002][1002];
bool Cx[1002][1002];

void Solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> A[i][j];
    {
        C[n][m + 1] = 1;
        C[n + 1][m] = 1;
        for (int i = n; i >= 1; --i)
            for (int j = m; j >= 1; --j)
                if (A[i][j] == '#')
                    C[i][j] = 0;
                else
                    C[i][j] = max(C[i + 1][j], C[i][j + 1]);
        if (C[1][1] == 0)
        {
            cout << -1;
            return;
        }
    }
    string S1 = "", S2 = "";
    char Min = 'z', Max = 'a';
    Cn[1][1] = 1;
    Cx[1][1] = 1;
    for (int a = 1, b = 1; a <= n && b <= m;)
    {
        Min = 'z', Max = 'a';
        for (int i = a, j = b; i <= n && j >= 1; ++i, --j)
        {
            if (Cn[i][j])
                Min = min(Min, A[i][j]);
            if (Cx[i][j])
                Max = max(Max, A[i][j]);
        }
        for (int i = a, j = b; i <= n && j >= 1; ++i, --j)
        {
            if (Cn[i][j] && A[i][j] == Min)
            {
                Cn[i + 1][j] = min(true, C[i + 1][j]);
                Cn[i][j + 1] = min(true, C[i][j + 1]);
            }
            if (Cx[i][j] && A[i][j] == Max)
            {
                Cx[i + 1][j] = min(true, C[i + 1][j]);
                Cx[i][j + 1] = min(true, C[i][j + 1]);
            }
        }
        S1 += Min;
        S2 += Max;
        if (b < m)
            ++b;
        else
            ++a;
    }
    cout << S1 << '\n'
         << S2;
}
int main()
{
    Init();
    Solve();
}
