// Cho một dãy số a1, a2, ..., an gồm n số nguyên dương không lớn hơn n. Xét một số nguyên dương
// x bất kì có giá trị từ 1 đến n, ta thực hiện phép gán x = ax và lặp lại phép gán cho đến khi giá
// trị của x sau khi gán không thay đổi thì quá trình được dừng lại.
// Ví dụ, nếu dãy a là [1, 4, 2, 1] và x = 3 thì:
// - Ở bước đầu tiên, với x = 3 thì a3 = 2 nên ta gán x = 2.
// - Ở bước thứ hai, với x = 2 thì a2 = 4 nên ta gán x = 4.
// - Ở bước thứ ba, với x = 4 thì a4 = 1 nên ta gán x = 1.
// - Ở bước thứ tư, với x = 1 thì a1 = 1 nên ta gán x = 1.
// - Do giá trị x không đổi sau bước thứ tư nên quá trình biến đổi được dừng lại.
// Cho q truy vấn, mỗi truy vấn yêu cầu: cho một số x ban đầu, hãy in ra số phép biến đổi được
// thực hiện (trong trường hợp số phép biến đổi là vô hạn thì in ra −1).
// Dữ liệu
// • Dòng đầu tiên gồm một số nguyên dương n là độ dài của dãy số (3 ≤ n ≤ 2 × 105
// ).
// • Dòng thứ hai gồm n số nguyên dương không lớn hơn n là các số a1, a2, ..., an.
// • Dòng thứ ba gồm một số nguyên dương q là số truy vấn (1 ≤ q ≤ 2 × 105
// ).
// • Dòng thứ tư gồm q số nguyên dương không lớn hơn n, tương ứng với q truy vấn.
// Kết quả
// • In ra 1 dòng gồm q số nguyên dương là đáp án tương ứng của q truy vấn.
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
void HOANG()
{
    //freopen("hoang.inp","r",stdin);
    //freopen("hoang.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
//---------------------------------------------------
ll n, a[nmax], q, x;
ll f[nmax];
bool ok[nmax];
vector<int> g[nmax];
//---------------------------------------------------
void DFS(int x, int u, int val)
{
    for (auto v : g[u])
    {
        if (x == v)
            continue;
        if (f[v] == 0)
            f[v] = val;
        DFS(u, v, val + 1);
    }
}
//---------------------------------------------------
int main()
{
    HOANG();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == i)
            f[i] = 1;
        else
        {
            g[a[i]].push_back(i);
            g[i].push_back(a[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 1)
            DFS(0, i, 2);
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 0)
            f[i] = -1;
    }
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;
        cout << f[k] << " ";
    }
}
//---------------------------------------------------
