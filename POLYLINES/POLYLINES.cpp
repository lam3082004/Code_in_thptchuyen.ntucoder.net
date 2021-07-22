// Trên mặt phẳng toạ độ, cho điểm gốc O có toạ độ là (0,0) và điểm đích A có toạ độ là (n, n), trong đó
// n là số nguyên. Ngoài ra, ta có tập S gồm m điểm có toạ độ nguyên (xi, yi) thoả mãn 0 ≤ xi, yi ≤ n
// Một đường gấp khúc X1X2 ... Xk được gọi là đường gấp khúc tăng nếu mọi i ta có xi ≤ xi+1 và yi ≤
// yi+1, k > 2
// Đếm số lượng đường gấp khúc tăng X1X2 ... Xk mà X1 = O, Xk = A và các điểm X2 ... Xk−1 thuộc tập S
// Input:
// • Dòng đầu là hai số nguyên n, m
// • m dòng tiếp theo, mỗi dòng ghi hai số nguyên xi và yi

// là toạ độ điểm Xi

// Output:
// • In ra số đường gấp khúc tăng thoả mãn theo modulo 109 + 7
// Giới hạn:
// • Subtask 1 (20%): n, m ≤ 20
// • Subtask 2 (20%): n, m ≤ 100
// • Subtask 3 (20%): n, m ≤ 104
// • Subtask 4 (20%): n, m ≤ 2 × 105
// • Subtask 5 (20%): n ≤ 109
// , m ≤ 106
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
const ll nmax = 1e6 + 5, mod = 1e9 + 7;
pair<ll, ll> a[nmax];
ll b[nmax], n, ans = 0, F[nmax], BIT[10 * nmax], m;
void update(ll x, ll val)
{
    for (; x <= nmax; x += -x & x)
        BIT[x] = (BIT[x] + val) % mod;
}

ll get(ll x)
{
    ll kq = 0;
    for (; x > 0; x -= -x & x)
        kq = (kq + BIT[x]) % mod;
    return kq;
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> a[i].fi >> a[i].se;
        b[i] = a[i].se;
    }

    sort(b + 1, b + n + 1);
    sort(a + 1, a + n + 1);
    for (ll i = 1; i <= n; ++i)
    {
        a[i].se = lower_bound(b + 1, b + n + 1, a[i].se) - b;
        //cout << a[i].se << '\n';
        F[i] = 1;
    }

    for (ll i = 1; i <= n; ++i)
    {
        F[i] = (F[i] + get(a[i].se)) % mod;
        ans = (F[i] + ans) % mod;
        update(a[i].se, F[i]);
        // cout << F[i] << ' ';
    }

    cout << ans;
}
