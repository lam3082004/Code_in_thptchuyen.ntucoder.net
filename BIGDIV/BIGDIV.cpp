// Cho số nguyên dương 𝑁 là một hợp số.
// Yêu cầu: Tìm số nguyên dương 𝑘 thỏa mãn:
//  1 < 𝑘 < 𝑁.
//  𝑁 ⋮ 𝑘.
// Input:
//  Dòng đầu gồm một số nguyên dương 𝑇 (𝑇 ≤ 10) − số lượng testcase.
//  𝑇 dòng tiếp mỗi dòng là một số nguyên dương 𝑁 (𝑁 ≤ 1018).
// Output: Gồm 𝑇 dòng, mỗi dòng là một số nguyên dương 𝑘 thỏa mãn ứng với mỗi 𝑁, nếu có nhiều
// giá trị 𝑘 thỏa mãn, in ra một giá trị bất kì.
#include <bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define nmax 100005
#define ii pair<ll,ll>
#define fi first
#define se second
#define oo 1e9
using namespace std;
const int mod = 998244353;
ll t,n;
ll tich(ll a,ll b,ll c)
{
    a %= c,b %= c;
    ll q = (long double) a * b / c;
    return ((a * b - q * c) % c + c) % c;
}
ll Rand(ll l ,ll h)
{
    return l + ((ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX+1) +
            (ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
            (ll)rand() * (RAND_MAX + 1) +
            (ll)rand()) %  (h - l + 1);
}
ll f(ll x,ll n)
{
    return (tich(x,x,n) + 1) % n;
}
ll gcd(ll a,ll b)
{
    if(b == 0)
        return a;
    return gcd(b,a % b);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    srand(time(NULL));
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n <= 5000000)
        {
            fo(i,2,n-1)
            if(n % i == 0)
            {
                cout<<i<<'\n';
                break;
            }
        }
        else
        {
            ll x = Rand(2,n-1);
            ll y = x;
            ll p = 1;
            while(p == 1|| p == n)
            {
                x = f(x,n);
                y = f(f(y,n),n);
                p = gcd(abs(x-y),n);
            }
            cout<<p<<'\n';
        }
    }
}
    