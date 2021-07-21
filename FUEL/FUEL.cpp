// Sau vài tháng không thể ra ngoài vì COVID-19, giờ đây Tèo đã có thể đi chơi thỏa thích. Tèo có
// một chiếc xe máy kỳ diệu, có thể chứa được lượng xăng tùy thích. Trước khi rời khỏi nhà, Tèo đã
// đổ vào chiếc xe của mình F lít xăng.
// Tèo muốn đi thăm một người bạn ở cách Tèo D km. Trên đường đi có N trạm xăng để Tèo đổ
// thêm xăng; trạm xăng thứ i cách nhà Tèo Xi km. Ở trạm xăng thứ i, Tèo có thể nạp thêm Ai
// lít
// xăng, nhưng chỉ khi lượng xăng ban đầu F không quá Bi
// .
// Hãy tìm lượng xăng ban đầu F nhỏ nhất sao cho Tèo có thể có đủ xăng để đến thăm bạn của
// mình.
// Dữ liệu
// • Dòng thứ nhất gồm hai số nguyên dương N và D (N ≤ 3 × 105
// , D ≤ 109
// )
// • Trong N dòng tiếp theo, mỗi dòng gồm ba số nguyên dương Xi
// , Ai
// , Bi (Xi < D, Ai
// , Bi ≤ 109
// )
// Kết quả
// • In ra một số nguyên dương duy nhất là đáp án của bài toán
#include <bits/stdc++.h>
using namespace std;
const int nmax = 3e5 + 5;
const int oo = 2e9;
typedef pair<int, int> ii;
struct iii
{
    int a, b, x;
};
int n;
int d, F[nmax];
int seg[4 * nmax], LAZY[4 * nmax];
iii s[nmax];
map<int, vector<iii>> vt;
void build(int l, int r, int pos)
{
    if (l == r)
    {
        seg[pos] = s[l].x;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, 2 * pos);
    build(mid + 1, r, 2 * pos + 1);
    seg[pos] = max(seg[2 * pos], seg[2 * pos + 1]);
}
bool cmp(iii A, iii B)
{
    return A.x < B.x;
}
void up(int pos)
{
    seg[2 * pos] += LAZY[pos];
    seg[2 * pos + 1] += LAZY[pos];
    LAZY[2 * pos + 1] += LAZY[pos];
    LAZY[2 * pos] += LAZY[pos];
    LAZY[pos] = 0;
}
void update(int l, int r, int u, int v, int val, int pos)
{
    if (r < u || l > v)
        return;
    if (l >= u && r <= v)
    {
        seg[pos] += val;
        LAZY[pos] += val;
        return;
    }
    up(pos);
    int mid = l + r >> 1;
    update(l, mid, u, v, val, 2 * pos);
    update(mid + 1, r, u, v, val, 2 * pos + 1);
    seg[pos] = max(seg[2 * pos], seg[2 * pos + 1]);
}
int get(int l, int r, int u, int v, int pos)
{
    if (r < u || l > v)
        return -oo;
    if (l >= u && r <= v)
    {
        up(pos);
        return seg[pos];
    }
    up(pos);
    int mid = l + r >> 1;
    return max(get(l, mid, u, v, 2 * pos), get(mid + 1, r, u, v, 2 * pos + 1));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> s[i].x >> s[i].a >> s[i].b;
    sort(s + 1, s + n + 1, cmp);
    s[n + 1].x = d;
    build(1, n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        F[i] = s[i].b;
        vt[F[i]].push_back({s[i].a, i, s[i].x});
    }
    sort(F + 1, F + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < vt[F[i]].size(); j++)
        {
            iii tmp = vt[F[i]][j];
            update(1, n + 1, tmp.b + 1, n + 1, -tmp.a, 1);
        }
        if (F[i] >= get(1, n + 1, 1, n + 1, 1))
        {
            cout << get(1, n + 1, 1, n + 1, 1);
            return 0;
        }
    }
    cout << d << '\n';
}
