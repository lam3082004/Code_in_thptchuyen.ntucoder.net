// Ngày 31/10/2019, Halloween
// ARSENAL1886 cùng đám bạn đang đi “quẩy” khắp thành phố X để xin kẹo. Thành phố X có n ngôi nhà,
// đánh số từ 1 đến n, các ngôi nhà được liên kết với nhau bởi m con đường 1 chiều.
// Ban đầu, ARSENAL1886 và các bạn đang ở căn nhà được đánh số là S. Nhóm bạn muốn đến căn nhà
// đánh số là T bằng cách sau: mỗi lần di chuyển, họ sẽ đi qua liên tiếp, chính xác 3 căn nhà lần lượt trên
// đường đi, và họ sẽ đi theo các con đường có sẵn. Nói cách khác, khi họ đứng ở u, thì mỗi bước di
// chuyển sẽ là u → v1 → v2 → v3, kết thúc ở v3 (Tất nhiên là chỉ xét khi có đường đi nhé)
// Yêu cầu: Cho sơ đồ thành phố X và S, T, hãy xác định xem nhóm bạn có thể đến được căn nhà T bằng
// cách đó không, nếu có thì đưa ra số lần di chuyển ít nhất (đi nhanh về còn ngủ, )
// Input:
//  Dòng đầu gồm hai số n, m
//  m dòng tiếp theo là cặp số u, v, mô tả một con đường 1 chiều nối từ u đến v
//  Dòng cuối cùng là hai số S, T
// Output:
//  1 dòng duy nhất là số bước di chuyển ít nhất
//  Nếu không có kết quả thì in ra -1
// Ràng buộc:
//  2 ≤ n ≤ 105

// , 0 ≤ m ≤ min (105

// , n × (n − 1))

//  1 ≤ u, v ≤ n, u ≠ v
//  1 ≤ s,t ≤ n, s ≠ t
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (ll i = a; i <= b; i++)
#define nmax 100005
#define fi first
#define se second
#define oo 1e9
#define ii pair<ll, ll>
const ll mod = 1e9 + 7;
const ll base = 31;
using namespace std;
//---------------------------------------------------
void PBHH()
{
    //freopen("hoang.inp","r",stdin);
    //freopen("hoang.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
//---------------------------------------------------
ll n, m, s, t;
ll f[nmax][4];
vector<int> g[nmax];
queue<int> q;
//---------------------------------------------------
void BFS(int x)
{
    q.push(x);
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        int v = q.front();
        q.pop();
        for (auto i : g[u])
        {
            int t = f[u][v] + 1;
            if (f[i][t % 3] == -1 || f[i][t % 3] > t)
            {
                f[i][t % 3] = t;
                q.push(i);
                q.push(t % 3);
            }
        }
    }
}
//---------------------------------------------------
int main()
{
    PBHH();
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    cin >> s >> t;
    memset(f, -1, sizeof(f));
    f[s][0] = 0;
    BFS(s);
    if (f[t][0] > 0)
        cout << f[t][0] / 3;
    else
        cout << f[t][0];
}
//---------------------------------------------------
