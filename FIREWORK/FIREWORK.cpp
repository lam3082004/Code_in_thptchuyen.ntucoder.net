// Tại một xưởng sản xuất pháo hoa, các kỹ sư nghiên cứu cách liên kết các
// thành phần pháo hoa với nhau. Sơ đồ kết nối các thành phần quả pháo có cấu
// trúc cây, vì rằng quả pháo lớn khi nổ sẽ kích nổ các thành phần con bên trong
// sẽ nổ theo, tạo ra hoa mới, các kỹ sư đưa ra phép toán lũy thừa trên cây.
// Cây có thể bao gồm 1 hoặc nhiều đỉnh. Một đỉnh được gọi là đỉnh gốc. Các
// đỉnh còn lại có đúng một đỉnh gọi là đỉnh cha, khi đó từ mỗi đỉnh có thể đi đến
// gốc của cây bằng cách lần lượt đi từ đỉnh đến cha của nó. Đỉnh mà
// không có con gọi là lá. Đỉnh cha và con được kết nối bởi một cạnh
// của cây.
// Hình bên thể hiện ví dụ cây gồm 4 đỉnh, đỉnh 1 là gốc. Đỉnh 1
// là cha của đỉnh 2 và đỉnh 3, đỉnh 2 là cha của đỉnh 4. Các đỉnh 3 và
// 4 là các đỉnh lá.
// Một quả pháo hoa được mô tả bằng cây cơ sở T và sức mạnh m. Cây của
// quả pháo hoa được tạo thành bằng cách lũy thừa cây cơ sở T với m. Toán tử lũy
// thừa cây được xây dựng như sau: nếu m = 1 thì T

// 1 = T. Với m>1, cần xem xét

// cây T
// m−1
// , và thực hiện các hành động: mỗi lá x của cây T

// m−1 được thay thế bởi

// cây cơ sở T, với x là đỉnh gốc. Ví dụ trong như hình dưới đây:

// Đường đi trong cây là dãy có thứ tự của các đỉnh phân biệt,
// trong đó 2 đỉnh liền nhau trong dãy có nối với nhau bởi cạnh.
// Vẻ đẹp của pháo hoa được tính bằng số đỉnh nhiều nhất có
// thể trong đường đi của cây pháo hoa. Hình bên cho thấy đường đi
// dài nhất trong cây T
// 2
// . Vẻ đẹp của cây T

// 2 với cây cơ sở T, sức mạnh

// là 10.

// Cần viết chương trình dựa vào cây T và số tự nhiên m xác định vẻ đẹp của
// pháo hoa.
// Đầu vào: gồm hai dòng phân biệt, dòng một chứa 2 số tự nhiên n và m, lần
// lượt là số đỉnh của cây cơ sở T và sức mạnh (3 ≤ n ≤ 200 000, 1 ≤ m ≤
// 200 000). Dòng thứ 2 mô tả cây T bằng (n − 1) số nguyên dương p2, p3, . . . , pn
// là số hiệu (nhãn) tương ứng đỉnh cha của lần lượt các đỉnh 2,3, . . n (1 ≤ pi ≤
// i − 1).
// Đầu ra: một số nguyên dương thể hiện giá trị vẻ đẹp của pháo hoa có cấu
// trúc cây T
// m.
#include <bits/stdc++.h>
#define stat akjcjalsjcjalscj
#define hash ajkscjlsjclajsc
#define next ackjalscjaowjico
#define prev ajcsoua0wucckjsl
#define y1 alkscj9u20cjeijc
#define left lajcljascjljl
#define right aucouasocjolkjl
#define y0 u9cqu3jioajc
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define fore(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define __unique(V) (V).resize(unique((V).begin(), (V).end()) - (V).begin())
#define cntbit(X) __builtin_popcount((X))
#define bit(S, i) (((S) >> (i)) & 1)
#define PI acos(-1)
#define fi first
#define se second
#define LL long long
#define ii pair<int, int>
#define iii pair<int, ii>
#define TASK "firework"
using namespace std;
const int maxn = 2e5 + 5;
int n, m, U, d[maxn];
LL F[maxn], ans = 0;
vector<int> adj[maxn];
///--------------------------
void readf()
{
    cin >> n >> m;
    fo(i, 2, n)
    {
        cin >> U;
        adj[U].push_back(i);
    }
}
///--------------------------
void DFS(int u)
{
    d[u] = 1;
    fore(it, adj[u])
    {
        DFS(*it);
        d[u] = max(d[u], d[*it] + 1);
    }
}
///--------------------------
void DFS_end(int u)
{
    if (adj[u].empty())
    {
        F[u] = 1LL * (m - 1) * d[1] + 1;
        return;
    }
    vector<LL> V;
    fore(it, adj[u])
    {
        DFS_end(*it);
        V.push_back(F[*it]);
        F[u] = max(F[u], F[*it] + 1);
    }
    sort(V.rbegin(), V.rend());
    if (V.size() == 1)
        ans = max(ans, V[0] + 1);
    else
        ans = max(ans, V[0] + V[1] + 1);
}
///--------------------------
void solve()
{
    DFS(1);
    ans = 0;
    DFS_end(1);
    cout << ans << '\n';
}
///--------------------------
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif // ONLINE_JUDGE
    readf();
    solve();
}
