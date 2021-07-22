// BRACKET-Dãy ngoặc

// Một dãy ngoặc được hợp lệ là 1 chuỗi các kí tự chỉ bao gồm những kí tự ngoặc đóng, ngoặc mở và thỏa mãn một trong những điều kiện sau:

// Là dãy ngoặc rỗng
// Nếu nó có thể biểu diển dưới dạng (S), [S] và {S} với S là một dãy ngoặc hợp lệ
// Nếu nó là một chuỗi được tạo ra bằng cách ghép 2 dãy ngoặc hợp lệ. Ví dụ A và B là dãy ngoặc hợp lệ thì AB cũng được coi là hợp lệ
// Long được thầy cho 1 dãy ngoặc hợp lệ để học thuộc, nhưng vì quậy phá nên đã lở làm dính mực 1 vài kí tự trong dãy. Để phạt Long, thầy bắt Long phải đếm số cách có thể để tạo ra dãy ngoặc hợp lệ bằng cách thay thế những kí tự bị dính mực.

// Bạn hãy giúp Long trả lời thầy nhé. Vì kết quả có thể rất lớn, nên bạn chỉ cần output ra 5 chữ số cuối của kết quả.

// Dữ liệu vào:

// Dòng đầu tiên là N (N<=20) thể hiện độ dài của dãy ngoặc.

// Dòng thứ 2 thể hiện dãy ngoặc với các kí tự ngoặc (, ), [, ], {, } và dấu ? thể hiện những kí tự bị lem mực.

// Dữ liệu ra:

// In ra 5 chữ số cuối của số cách có thể để tạo ra những dãy ngoặc hợp lệ từ dãy ngoặc lem mực ban đầu.

#include <bits/stdc++.h>
using namespace std;
const string Fname = "DAUNGOAC";
/*void files() {
	if(fopen((Fname + ".inp").c_str(), "r")) {
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	}
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}*/
#define ll long long
const ll N = 205;
const ll mod = 1e5;
ll n, dp[N][N];
bool vis[N][N];
string st;
ll CapNgoac(char x, char y)
{
    if (x == '(' && y == ')')
        return 1;
    if (x == '{' && y == '}')
        return 1;
    if (x == '[' && y == ']')
        return 1;
    if (x == '?' && y == '?')
        return 3;
    if (x == '?' && y == ')')
        return 1;
    if (x == '?' && y == '}')
        return 1;
    if (x == '?' && y == ']')
        return 1;
    if (x == '(' && y == '?')
        return 1;
    if (x == '{' && y == '?')
        return 1;
    if (x == '[' && y == '?')
        return 1;
    return 0;
}
ll setup(ll l, ll r)
{
    if (l >= r)
    {
        dp[l][r] = 1;
        return dp[l][r];
    }
    if (vis[l][r])
        return dp[l][r];
    if (l + 1 == r)
    {
        dp[l][r] = CapNgoac(st[l], st[r]);
        vis[l][r] = true;
        //		cout << l << ' ' << r << ' ' << dp[l][r] << '\n';
        return dp[l][r];
    }
    ll s = 0;
    for (ll i = l + 1; i <= r; i += 2)
    {
        setup(l + 1, i - 1);
        setup(i + 1, r);
        s += CapNgoac(st[l], st[i]) * dp[l + 1][i - 1] * dp[i + 1][r];
        s %= mod;
    }
    dp[l][r] = s;
    dp[l][r] %= mod;
    //	cout << l << ' ' << r << ' ' << dp[l][r] << '\n';
    vis[l][r] = true;
    return dp[l][r];
}
void solve()
{
    memset(vis, false, sizeof vis);
    cin >> n >> st;
    st = " " + st;
    cout << setup(1, n);
    ;
}
int main()
{
    //	files();
    solve();
}
