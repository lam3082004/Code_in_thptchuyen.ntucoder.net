// Di chuyển robot
// Cuộc thi ROBOCON năm 2013 có chủ đề “Gặp gỡ”. Các robot sẽ thi đấu trên một bản đồ gồm n
// điểm dừng được đánh số từ 1 đến n và m đoạn đường một chiều nối các cặp điểm dừng. Mỗi điểm
// dừng được tô bằng một trong ba màu 1, 2, 3. Mỗi đoạn đường cũng được tô bằng một trong ba màu
// 1, 2, 3 nhưng sẽ bị biến đổi màu theo thời gian. Cụ thể, nếu ở thời điểm t, đoạn đường có màu là c
// thì ở thời điểm t + 1 đoạn đường sẽ có màu là (c mod 3)+1.
// Mỗi đội chơi phải điều khiển hai robot cùng di chuyển trên bản đồ để hai robot gặp nhau sớm nhất
// tại một điểm dừng. Ban đầu (tại thời điểm 0), robot thứ nhất đứng ở điểm dừng 1, robot thứ hai
// đứng ở điểm dừng 2, quy tắc di chuyển của hai robot là:
//  Mỗi đơn vị thời gian, cả hai robot cùng phải di chuyển qua một đoạn đường;
//  Giả sử ở thời điểm t robot thứ nhất đang đứng ở điểm dừng i, robot thứ hai đang đứng ở
// điểm dừng j, khi đó robot thứ nhất buộc phải di chuyển theo một trong các đoạn đường có
// màu ở thời điểm t cùng màu với màu ở điểm dừng j, robot thứ hai buộc phải di chuyển theo
// một trong các đoạn đường có màu ở thời điểm t cùng màu với màu ở điểm dừng i.
// Yêu cầu: Cho thông tin về bản đồ với màu ban đầu của các đoạn đường, hãy xác định thời điểm hai
// robot gặp nhau sớm nhất.
// Input
// Dòng đầu tiên chứa Q là số lượng bộ dữ liệu. Tiếp đến là Q nhóm dòng, mỗi nhóm cho thông tin về
// một bộ dữ liệu theo khuôn dạng sau đây:
//  Dòng thứ nhất chứa hai số nguyên dương n, m;
//  Dòng thứ hai ghi n số nguyên, số thứ i là màu của điểm dừng thứ i;
//  m dòng sau, mỗi dòng mô tả một đoạn đường gồm ba số nguyên u, v (u ≠ v) và c chỉ đoạn
// đường từ điểm dừng u đến điểm dừng v có màu tại thời điểm 0 là c.
// Output
// Gồm Q dòng, mỗi dòng chứa một số nguyên là thời điểm gặp nhau sớm nhất của hai robot (ghi -1
// nếu không tồn tại cách di chuyển để hai robot gặp nhau) tương ứng với bộ dữ liệu vào.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 40005
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e18
#define ar array
using namespace std;
const int mod = 1e9 + 7;
struct fiv
{
    ll id, x, y, t, cx;
};
ll q, n, m, u, v, a[205], k, ans;
ll f[3][205][205][3][3];
vector<ii> p[205];
queue<fiv> pq;
void bfs()
{
    while (!pq.empty())
        pq.pop();
    pq.push({1, 1, 2, 0, a[1]});
    f[1][1][2][0][a[1]] = 0;
    while (!pq.empty())
    {
        fiv u = pq.front();
        pq.pop();
        if (u.id == 1)
        {
            if (u.x == u.y)
            {
                ans = f[u.id][u.x][u.y][u.t][u.cx];
                return;
            }
            for (auto v : p[u.x])
                if (!f[2][v.fi][u.y][u.t][u.cx] && (v.se + u.t - 1) % 3 + 1 == a[u.y])
                {
                    f[2][v.fi][u.y][u.t][u.cx] = f[u.id][u.x][u.y][u.t][u.cx];
                    pq.push({2, v.fi, u.y, u.t, u.cx});
                }
        }
        else
        {
            for (auto v : p[u.y])
                if (!f[1][u.x][v.fi][u.t % 3 + 1][a[u.x]] && (v.se + u.t - 1) % 3 + 1 == u.cx)
                {
                    f[1][u.x][v.fi][u.t % 3 + 1][a[u.x]] = f[u.id][u.x][u.y][u.t][u.cx] + 1;
                    pq.push({1, u.x, v.fi, u.t % 3 + 1, a[u.x]});
                }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("robot.inp", "r", stdin);
    freopen("robot.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    while (q--)
    {
        cin >> n >> m;
        fo(i, 1, n)
                cin >>
            a[i];
        fo(i, 1, n)
            p[i]
                .clear();
        fo(i, 1, m)
        {
            cin >> u >> v >> k;
            p[u].push_back(ii(v, k));
        }
        ans = -1;
        memset(f, 0, sizeof(f));
        bfs();
        cout << ans << '\n';
    }
}
