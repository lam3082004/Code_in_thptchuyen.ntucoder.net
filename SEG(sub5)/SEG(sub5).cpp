// SEGMENT
// Trên một hệ trục tọa độ Ox, có N đoạn thẳng. Các đoạn thẳng được đánh số từ 1 đến N. Đoạn
// thẳng thứ i có đầu mút bên trái tại Li và đầu mút bên phải tại Ri
// .

// Ta nói rằng, một điểm có tọa độ x được phủ bởi đoạn thẳng i khi và chỉ khi x nằm giữa hai đầu
// mút của i (tức là Li ≤ x ≤ Ri).
// Có Q truy vấn, mỗi truy vấn được mô tả bởi hai số nguyên a và b, yêu cầu:
// • Trong số N đoạn thẳng đã cho, cần chọn ra một số đoạn thẳng, sao cho tất cả các điểm có
// tọa độ từ a đến b đều được bao phủ bởi ít nhất một đoạn thẳng trong các đoạn thẳng được
// lựa chọn. Hãy in ra số lượng đoạn thẳng ít nhất cần lựa chọn.
// Yêu cầu: Viết chương trình trả lời Q truy vấn trên.
// Dữ liệu
// • Dòng đầu tiên gồm số nguyên N (1 ≤ N ≤ 200000) - số đoạn thẳng.
// • N dòng tiếp theo, dòng thứ i gồm hai số nguyên Li và Ri (0 ≤ Li ≤ Ri ≤ 109

// ) - tọa độ hai

// đầu mút của đoạn thẳng thứ i.
// • Dòng tiếp theo gồm số nguyên Q (1 ≤ Q ≤ 200000) - số truy vấn cần xử lí.
// • Q dòng tiếp theo, mỗi dòng gồm hai số nguyên a và b (0 ≤ a ≤ b ≤ 109

// ) mô tả một truy

// vấn.
// Kết quả
// • Với mỗi truy vấn, in ra một dòng gồm một số nguyên duy nhất là số đoạn thẳng ít nhất cần
// lựa chọn. Trong trường hợp không có cách chọn, hãy in ra -1.
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int nmax = 2e5 + 5;
const int oo = 1e9 + 7;
typedef pair<int, int> ii;
int n, m, k, p[nmax], F[nmax][20], q, maxx;
ii a[nmax];
struct doi
{
    int l, r;
};
doi b[nmax];
bool cmp(doi a, doi b)
{
    if (a.l < b.l)
        return true;
    if (a.l > b.l)
        return false;
    return a.r > b.r;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i].l >> b[i].r;
    sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        if (b[i].r > maxx)
        {
            maxx = b[i].r;
            a[++k].fi = b[i].l;
            a[k].se = b[i].r;
        }
    n = k;
    for (int i = 1; i <= n; i++)
    {
        int l = i + 1, r = n, pos = 0;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (a[mid].fi <= a[i].se + 1)
            {
                pos = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        p[i] = pos;
    }
    a[0] = ii(oo, oo);
    for (int i = 1; i <= n; i++)
        F[i][0] = p[i];
    for (int k = 1; (1 << k) <= n; k++)
        for (int i = 1; i + (1 << k) - 1 <= n; i++)
            F[i][k] = F[F[i][k - 1]][k - 1];
    cin >> q;
    while (q--)
    {
        int L, R;
        cin >> L >> R;
        int l = 1, r = n, pos = 0;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (a[mid].fi <= L)
            {
                pos = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (pos == 0)
        {
            cout << -1 << '\n';
            continue;
        }
        if (a[pos].se >= R)
        {
            cout << 1 << '\n';
            continue;
        }
        int ans = 1;
        for (int i = 17; i >= 0; i--)
            if (a[F[pos][i]].se < R)
            {
                ans += (1 << i);
                pos = F[pos][i];
            }
        if (a[F[pos][0]].se >= R && a[F[pos][0]].se != oo)
        {
            cout << ans + 1 << '\n';
            continue;
        }
        cout << -1 << '\n';
    }
}
