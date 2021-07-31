// Cho lưới ô vuông kích thước m × n. Mỗi ô trong bảng chứa 1 chữ số từ 0 đến 9. Có k ngôi nhà nằm tại
// các ô (xi
// , yi
// ) (1 ≤ i ≤ k). Với mỗi ngôi nhà, ta cần tìm độ dài đường đi ngắn nhất từ một ô bất kì trên
// bảng đến ngôi nhà đó và đi qua các ô chứa các giá trị từ 0 đến 9 (không cần đúng thứ tự), nếu không
// có đường đi thì in ra -1 (mỗi ô được phép đi qua nhiều lần)
// Chú ý là tại mỗi ô thì chúng ta chỉ được phép đi đến các ô kề cạnh với ô đang đứng
// Input:
// • Dòng đầu ghi 3 số m, n, k
// • m dòng tiếp theo, mỗi dòng có n số là giá trị các ô trong bảng
// • k dòng tiếp theo, mỗi dòng hai số xi
// , yi
// là toạ độ ngôi nhà
// • Các hàng được đánh số từ 1, từ trên xuống dưới
// • Các cột được đánh số từ 1, từ trái sang phải
// Output:
// • In ra k dòng, dòng thứ i là độ dài đường đi ngắn nhất đến được ngôi nhà thứ i mà thoả mãn
// đề bài hoặc in ra -1 nếu không có
// • Độ dài đường đi là số ô đã đi qua trên hành trình đó (Tính cả ô xuất phát)
// Giới hạn:
// • Subtask 1 (50% số điểm): m, n ≤ 100, k = 1
// • Subtask 2 (50% số điểm): m, n ≤ 100, k ≤ m × n
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 400005
#define ii pair<int, int>
#define fi first
#define se second
#define oo 1e18
#define ar array
using namespace std;
const int mod = 1e9 + 7;
struct ziza
{
    ll x, y, mask;
};
ll m, n, k, x, y, a[105][105], d[105][105][1025];
bool vs[105][105][1025];
int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};
bool check(int x, int y)
{
    return (x > 0 && y > 0 && x <= m && y <= n);
}
queue<ziza> q;
void bfs()
{
    fo(i, 1, m)
        fo(j, 1, n)
    {
        q.push({i, j, (1 << a[i][j])});
        vs[i][j][(1 << a[i][j])] = 1;
        d[i][j][(1 << a[i][j])] = 1;
    }
    while (!q.empty())
    {
        ziza c = q.front();
        q.pop();
        fo(i, 0, 3)
        {
            int u = c.x + X[i];
            int v = c.y + Y[i];
            if (check(u, v))
            {
                int mask2 = c.mask | (1 << a[u][v]);
                if (!vs[u][v][mask2])
                {
                    d[u][v][mask2] = d[c.x][c.y][c.mask] + 1;
                    vs[u][v][mask2] = 1;
                    q.push({u, v, mask2});
                }
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("new.inp", "r", stdin);
    freopen("new.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> k;
    fo(i, 1, m)
            fo(j, 1, n)
                cin >>
        a[i][j];
    bfs();
    int mask = (1 << 10) - 1;
    while (k--)
    {
        cin >> x >> y;
        if (d[x][y][mask] == 0)
            cout << -1 << '\n';
        else
            cout << d[x][y][mask] << '\n';
    }
}
