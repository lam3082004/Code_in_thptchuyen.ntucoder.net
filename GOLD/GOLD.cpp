// Có A + B + C em bé được nhận quà. Các em bé được đánh số thứ tự từ 1 đến A + B + C.
// Em bé thứ i được nhận Ui đồng tiền “Vàng”, Vi đồng tiền “Bạc” và Ei đồng tiền “Đồng”. Sau khi
// nhận được quà xong, các em chơi trò chơi gộp đội:
// Đội thứ nhất gồm A em, điểm của đội bằng tổng số đồng tiền “Vàng” mà các em nhận
// được.
// Đội thứ hai gồm B em, điểm của đội bằng tổng số đồng tiền “Bạc” mà các em nhận được.
// Đội thứ ba gồm C em, điểm của đội bằng tổng số đồng tiền “Đồng” mà các em nhận được.
// Tổng điểm của trò chơi là tổng điểm của cả ba đội. Chú ý rằng, mỗi em chỉ thuộc duy nhất
// một đội.
// Yêu cầu: Tính xem, tổng điểm lớn nhất của trò chơi có thể đạt được là bao nhiêu.
// Dữ liệu cho trong file COINS.INP gồm:
//  Dòng đầu ghi 3 số nguyên A, B, C.
//  Dòng thứ i trong A+B+C dòng tiếp theo, mỗi dòng ghi ba số nguyên Ui, Vi, Ei (0 ≤ Ui, Vi, Ei
// ≤ 106
// )
// Kết quả ghi ra file COINS.OUT là tổng điểm lớn nhất có thể đạt được.
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 300005
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e18
#define ar array
using namespace std;
const int mod = 1e9 + 7;
struct ta
{
    ll a, b, c;
};
ll m, n, p, l[nmax], r[nmax];
ta d[nmax];
priority_queue<ll, vector<ll>, greater<ll>> q;
ll cmp(ta x, ta y)
{
    return x.a - x.b > y.a - y.b;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("hackathon.inp", "r", stdin);
    freopen("hackathon.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> p;
    ll ans = 0;
    fo(i, 1, m + n + p)
    {
        cin >> d[i].a >> d[i].b >> d[i].c;
        ans += d[i].c;
        d[i].a -= d[i].c;
        d[i].b -= d[i].c;
        d[i].c = 0;
    }
    sort(d + 1, d + 1 + m + n + p, cmp);
    ll tmp = 0;
    fo(i, 1, m + n + p)
    {
        if (q.size() < m)
        {
            q.push(d[i].a);
            tmp += d[i].a;
            l[i] = tmp;
        }
        else
        {
            if (d[i].a > q.top())
            {
                tmp -= q.top();
                tmp += d[i].a;
                q.pop();
                q.push(d[i].a);
            }
            l[i] = tmp;
        }
    }
    //    fo(i,1,m+n+p)
    //        cout<<d[i].a<<' '<<d[i].b<<' '<<d[i].c<<'\n';
    while (!q.empty())
        q.pop();
    tmp = 0;
    for (int i = m + n + p; i >= 1; i--)
    {
        if (q.size() < n)
        {
            q.push(d[i].b);
            tmp += d[i].b;
            r[i] = tmp;
        }
        else
        {
            if (d[i].b > q.top())
            {
                tmp -= q.top();
                tmp += d[i].b;
                q.pop();
                q.push(d[i].b);
            }
            r[i] = tmp;
        }
    }
    tmp = -oo;
    fo(i, m, m + p)
        tmp = max(tmp, l[i] + r[i + 1]);
    cout << ans + tmp;
}
