#include <bits/stdc++.h>
using namespace std;

/*Weird define*/
#define int ll
#define endl '\n'
#define fou(i, l, r) for(ll i = l; i <= r; i++)
#define fod(i, l, r) for(ll i = l; i >= r; i--)
#define UWU ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define FAST UWU UWU UWU UWU UWU
#define ll long long
#define task ""
#define nmax 200007

/*push-pos define*/
#define pb push_back
#define pob pop_back

/*some const*/
const int d4i[4] = { -1 , 0 , 1 , 0 }, d4j[4] = { 0 , 1 , 0 , -1 };
const int d8i[8] = { -1 , -1 , 0 , 1 , 1 , 1 , 0 , -1 }, d8j[8] = { 0 , 1 , 1 , 1 , 0 , -1 };
const int base = 1e9 + 7;
int MOD = 1e9 + 7;
int add(int x, int y) { return (x % MOD + y % MOD) % MOD; }
int mul(int x, int y) { return ((x % MOD) * (y % MOD)) % MOD; }
int lcm(int x, int y) { return mul(x / __gcd(x, y), y); }
int _pow(ll x, ll y) { if (y == 0) return 1; if (y % 2 == 0) return _pow(mul(x, x), y / 2) % MOD; else return mul(x, _pow(mul(x, x), y / 2)) % MOD; }

/*Function :3*/
ll t, n, a[nmax];

signed main()
{
    FAST;
    cin >> t;
    a[0] = 1;
    fou(i, 1, nmax - 1) a[i] = mul(a[i - 1], i);
    while(t--)
    {
        cin >> n;
        cout << mul(a[n * 2], _pow(mul(a[n], a[n + 1]), MOD - 2)) << endl;
    }
}