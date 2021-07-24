// Cho n hạt, mỗi hạt chỉ mang một loại điện tích là điện tích dương hoặc điện tích âm.Hai hạt có cùng điện tích thì đẩy nhau, còn hai hạt khác điện tích thì hút nhau.Trong một thí nghiệm, có q yêu cầu được đặt ra.Các yêu cầu thuộc một trong hai loại sau :
// • Loại 1 : Người làm thí nghiệm đem hai hạt lại gần nhau để xem chúng đẩy hay hút nhau.
// • Loại 2 : Người làm thí nghiệm được cho hai hạt và được yêu cầu hãy xác định xem hai hạt đó sẽ đẩy hay hút nhau dựa vào kết quả từ các yêu cầu trước.Hãy in ra câu trả lời cho tất cả các yêu cầu loại 2. Dữ liệu
// • Dòng đầu tiên gồm hai số nguyên dương n và q(n, q ≤ 105).
// • Trong q dòng tiếp theo, mỗi dòng gồm một ký tự t và hai số nguyên dương a và b(a, b ≤ n) là hai hạt được dùng trong mỗi yêu cầu.Nếu t = ’A’, yêu cầu này là loại 1 và kết quả thí nghiệm cho thấy hai hạt này hút nhau.Nếu t = ’R’, yêu cầu này là loại 1 và kết quả thí nghiệm cho thấy hai hạt này đẩy nhau.Nếu t = ’Q’, đây là yêu cầu loại 2. Kết quả Với mỗi yêu cầu loại 2, in ra một dòng với duy nhất một ký tự là câu trả lời.
// • Nếu hai hạt đẩy nhau, in ra ’R’.
// • Nếu hai hạt hút nhau, in ra ’A’.
// • Nếu không thể xác định được câu trả lời dựa trên các kết quả thu được, in ra ’?’.
#include <bits/stdc++.h>
#define maxn 100005
#define F first
#define S second
#define pii pair<int, int>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define Task ""
using namespace std;
int n, q, d[maxn], root[maxn], ty[maxn], f[maxn];
vector<pii> ke[maxn];
struct dt
{
    char ch;
    int u, v;
} a[maxn];
int get(int u)
{
    if (!root[u])
        return u;
    return (root[u] = get(root[u]));
}
void dfs(int u)
{
    for (auto x : ke[u])
    {
        if (d[x.F])
            continue;
        if (d[x.S])
            d[x.F] = 3 - d[u], dfs(x.F);
        else
            d[x.F] = d[u], dfs(x.F);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //  freopen(Task".inp","r",stdin);
    //    freopen(Task".out","w",stdout);
    cin >> n >> q;

    for (int i = 1; i <= q; i++)
    {
        cin >> a[i].ch >> a[i].u >> a[i].v;
    }
    for (int i = 1; i <= q; i++)
    {
        if (a[i].ch != 'Q')
        {
            int u = a[i].u, v = a[i].v;
            if (a[i].ch == 'A')
            {

                ke[u].pb({v, 1});
                ke[v].pb({u, 1});
            }
            else
            {
                ke[u].pb({v, 0});
                ke[v].pb({u, 0});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!d[i])
            d[i] = 1, dfs(i);
    }
    // for(int i=1;i<=n;i++) cout << d[i] <<' ';
    // cout << endl;
    for (int i = 1; i <= q; i++)
    {
        if (a[i].ch == 'Q')
        {
            int u = get(a[i].u), v = get(a[i].v);
            if (u == v)
            {
                if (d[a[i].u] == d[a[i].v])
                    cout << "R\n";
                else
                    cout << "A\n";
                continue;
            }
            // if(!ty[u]||!ty[v]) {cout << "?\n"; continue;}
            cout << "?\n";
        }
        else
        {
            int u = get(a[i].u), v = get(a[i].v);
            if (v != u)
                root[v] = u;
            //  ty[u]=d[a[i].u] , ty[v]=d[a[i].v];
        }
    }
    return 0;
}
