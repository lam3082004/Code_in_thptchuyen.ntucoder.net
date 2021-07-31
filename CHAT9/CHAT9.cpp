// Cho hàm 𝑓(𝑛) = 𝑛 3 − 2𝑛 + 5. Yêu cầu : Gồm 𝑄 truy vấn, mỗi truy vấn là một số nguyên dương 𝐾, giải phương trình nghiệm nguyên dương 𝑓(𝑛) = 𝐾, in ra giá trị 𝑛 đó hoặc in ra −1 nếu phương trình vô nghiệm.Input :
// • Dòng đầu là số nguyên dương 𝑄(𝑄 ≤ 105);
// • 𝑄 dòng tiếp theo, mỗi dòng là một số nguyên dương 𝐾(𝐾 ≤ 1018).Output : Gồm 𝑄 dòng, mỗi dòng là số nguyên dương 𝑛 thỏa mãn 𝑓(𝑛) = 𝐾 tương ứng hoặc in ra
// −1 nếu không tồn tại �
#include <bits/stdc++.h>
#define ll long long
#define nmax 1000005
#define fi first
#define se second
#define ii pair<ll, ll>
#define fo(i, a, b) for (ll i = a; i <= b; i++)
const ll mod = 1e9 + 7;
using namespace std;
bool tg(ll x, ll y, ll z)
{
    if (x > 0 && y > 0 && z > 0 && x + y > z && y + z > x && z + x > y)
        return true;
    else
        return false;
}
ll pt(ll x)
{
    return x * x * x - 2 * x + 5;
}
ll n, k;
int main()
{
    //  freopen("height.inp","r",stdin);
    //freopen("height.out","r",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n--)
    {
        cin >> k;
        ll l = 1, r = 1e6, pos = 0;
        while (l <= r)
        {
            ll mid = l + r >> 1;
            if (pt(mid) <= k)
            {
                pos = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        if (pt(pos) == k)
            cout << pos << '\n';
        else
            cout << "-1" << '\n';
    }
}
