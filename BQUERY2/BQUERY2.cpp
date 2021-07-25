// Cho một lưới chữ nhật gồm N dòng và M cột, các dòng được đánh số từ 1 đến N từ trên xuống dưới, các cột được đánh số từ 1 đến M theo thứ tự từ trái sang phải.Mỗi ô sẽ được tô một màu xanh hoặc trắng.Nếu Sx, y = 1, ô nằm ở dòng x và cột y có màu xanh;
// nếu Sx, y = 0 thì ô đó có màu trắng.Từ một ô bất kì, có thể di chuyển sang một ô khác kề với nó(có chung cạnh) và có cùng màu với nó.Nói cách khác, từ một ô(x, y), ta có thể di chuyển sang ô(x 0, y0) khi và chỉ khi các điều kiện sau được thỏa mãn :
// • | x − x 0 | + | y − y 0 | = 1
// • Sx, y = Sx0, y0 Lưới chữ nhật đã cho có tính chất đặc biệt sau : với cặp ô xanh a và b bất kì, có tối đa một đường đi đơn(đường đi chỉ đi qua mỗi ô tối đa một lần) xuất phát từ a và kết thúc tại b.Có Q truy vấn, mỗi truy vấn được mô tả bởi bốn số nguyên x1, y1, x2, y2, yêu cầu :
// • Xét lưới chữ nhật con gồm các ô từ dòng x1 đến dòng x2, từ cột y1 đén cột y2.Cho biết có bao nhiêu thành phần liên thông gồm các ô màu xanh trong lưới chữ nhật con này.Hãy viết chương trình xử lí Q truy vấn trên.Dữ liệu
// • Dòng đầu tiên gồm ba số nguyên N, M, Q(1 ≤ N, M ≤ 2000, 1 ≤ Q ≤ 200000) - số dòng, số cột của lưới chữ nhật và số truy vấn cần xử lý.
// • N dòng tiếp theo, mỗi dòng gôm một xâu M kí tự, mỗi kí tự có giá trị ’0’ hoặc ’1’ - mô tả lưới chữ nhật.Dữ liệu vào đảm bảo có tối đa một đường đi đơn giữa hai ô màu xanh bất kì.
// • Q dòng tiếp theo, mỗi dòng gồm bốn số nguyên x1, y1, x2, y2(1 ≤ x1 ≤ x2 ≤ N, 1 ≤ y1 ≤ y2 ≤ M) - mô tả một truy vấn.
#include <bits/stdc++.h>
using namespace std;
const int nmax = 2005;
int n, m;
int f[nmax][nmax], s[nmax][nmax], hang[nmax][nmax], cot[nmax][nmax];
char a[nmax][nmax];
int t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    cin >> m >> n >> t;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + (a[i][j] == '1');
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (a[i][j] == '1' && a[i - 1][j] == '1') + (a[i][j] == '1' && a[i][j - 1] == '1');
        }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            hang[i][j] = hang[i][j - 1] + (a[i][j] == a[i - 1][j] && a[i][j] == '1');
            cot[i][j] = cot[i - 1][j] + (a[i][j] == a[i][j - 1] && a[i][j] == '1');
        }
    while (t--)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        cout << (f[u][v] - f[x - 1][v] - f[u][y - 1] + f[x - 1][y - 1]) - (s[u][v] - s[x - 1][v] - s[u][y - 1] + s[x - 1][y - 1]) + (hang[x][v] - hang[x][y - 1] + cot[u][y] - cot[x - 1][y]) << '\n';
    }
}
