#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fn(i,a,b) for(int i=a;i>=b;i==)
#define nmax 1000005
using namespace std;
ll k,n,mod,t[nmax],g[nmax],x,kq=1;
ll mu(ll a,ll b)
{
    if(b==0) return 1;
    ll t=mu(a,b/2);
    t=(t*t)%mod;
    if(b&1) t=(t*a)%mod;
    return t;
}
void sang()
{
    memset(g,0,sizeof(g));
    g[1]=1;
    fo(i,2,nmax)
    if(g[i]==0)
        for(int j=i;j<=nmax;j+=i)
        g[j]=i;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    sang();
    cin>>k>>n>>mod;
    fo(i,n-k+1,n)
    {
        x=i;
        while(x>1)
            t[g[x]]++,x/=g[x];
    }
    fo(i,1,k)
    {
        x=i;
        while(x>1)
            t[g[x]]--,x/=g[x];
    }
    fo(i,1,1000000)
    {
        kq=(kq*mu(i,t[i]))%mod;
    }
    cout<<kq;
}
    
// #include <bits/stdc++.h>
// #define ll long long
// #define fo(i, a, b) for (long long i = a; i <= b; i++)
// #define nmax 1005
// #define fi first
// #define se second
// #define ii pair<int, int>
// const ll mod = 1e9 + 7;
// using namespace std;
// ll n, k, f[nmax];
// ll mu(ll a, ll b)
// {
//     if (b == 0)
//         return 1;
//     ll tam = mu(a, b / 2);
//     tam = (tam * tam) % mod;
//     if (b % 2 == 1)
//         tam = (tam * a) % mod;
//     return tam;
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("LES20F.inp", "r", stdin);
//     freopen("LES20F.out", "w", stdout);
// #endif // ONLINE_JUDGE
//     cin >> k >> n;
//     f[0] = 1;
//     fo(i, 1, n)
//     {
//         f[i] = (f[i - 1] * i) % mod;
//     }
//     cout << (f[n] * mu(f[k], mod - 2)) % mod * mu(f[n - k], mod - 2) % mod;
// }
