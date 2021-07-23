// N cậu bé rủ nhau đá bóng trong vòng M ngày (N chẵn).
// Ngày thứ i, chúng chia làm hai đội, mỗi đội có N/2 cầu thủ.
// Chúng tự hỏi liệu mọi cặp đều đấu với nhau trong một trận nào đó không.
// Input
// Dòng đầu tiên là số nguyên N và M (4 ≤N≤ 40000, 1 ≤ M ≤ 50).
// M dòng tiếp theo, mỗi dòng gồm N số, trong đó N/2 số đầu tiên là một đội, N/2 số còn lại là
// một đội. (Các cậu bé được đánh số từ 1 tới N).
// Output
// In ra "YES"nếu mọi cặp trong số các cậu bé đều đấu với nhau ở một trận nào đó. Ngược lại in
// ra "NO".
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (ll i = a; i <= b; i++)
#define nmax 1000000
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
ll n, m, maxx = -oo, f[nmax], t[55][50000];
ll a[nmax];
//---------------------------------------------------
int main()
{
    PBHH();
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> t[i][j];
            if (j <= n / 2)
                f[t[i][j]] = f[t[i][j]] * 2;
            else
                f[t[i][j]] = f[t[i][j]] * 2 + 1;
        }
    }
    sort(f + 1, f + 1 + n);
    for (int i = 1; i <= n - 1; i++)
    {
        if (f[i] == f[i + 1])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
