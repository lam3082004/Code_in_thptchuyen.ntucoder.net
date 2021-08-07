// Bạn có một bức tranh hình chữ nhật có kích cỡ m × n. Bức tranh này được chia thành m × n ô
// vuông bằng nhau, mỗi ô sẽ là một ô trống, hoặc là một quả táo, hoặc là một chướng ngại vật nào đó.
// Bạn muốn biết sau khi tất cả các quả táo đã rơi hết xuống mặt đất hoặc chướng ngại vật, bức tranh
// cuối cùng sẽ trông như thế nào. Để việc tìm bức tranh cuối cùng trở nên đơn giản, bạn quyết định sử
// dụng hai định luật sau, gọi là Định luật Táo rơi I và Định luật Táo rơi II:
// • Chướng ngại vật luôn đứng yên.
// • Nếu có một ô trống ở dưới một quả táo, quả táo sẽ di chuyển vào ô trống đó.
// Hãy in ra bức tranh cuối cùng sau khi tất cả các quả táo đều đã rơi xong. Lưu ý rằng nếu bạn mô phỏng
// lại toàn bộ quá trình táo rơi, bạn sẽ không có đủ thời gian.
// Dữ liệu
// • Dòng đầu tiên chứa hai số nguyên dương m và n (1 ≤ m ≤ 50000, 1 ≤ n ≤ 10) cho biết số lượng
// dòng và cột của bức tranh.
// • m dòng tiếp theo, mỗi dòng gồm n kí tự mô tả bức tranh. Các ô trống được mô tả bằng kí tự ’.’,
// các ô chứa quả táo được mô tả bằng kí tự ’a’, các ô chứa chướng ngại vật được mô tả bằng kí tự
// ’#’.
// Kết quả
// • Gồm m dòng, mỗi dòng chứa n kí tự mô tả bức tranh cuối cùng sau khi tất cả các quả táo đã rơi
// xong.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
ll m, n, t;
char a[50005][15];
int main()
{
    cin >> m >> n;
    fo(i, 1, m)
            fo(j, 1, n)
                cin >>
        a[i][j];
    fo(j, 1, n)
    {
        t = m;
        for (int i = m; i >= 1; i--)
            if (a[i][j] == '#')
                t = i - 1;
            else
            {
                if (a[i][j] == 'a')
                {
                    a[t][j] = 'a';
                    if (t != i)
                    {
                        a[i][j] = '.';
                        t--;
                    }
                    else
                        t = i - 1;
                }
            }
    }
    fo(i, 1, m)
    {
        fo(j, 1, n) cout << a[i][j];
        cout << '\n';
    }
}
