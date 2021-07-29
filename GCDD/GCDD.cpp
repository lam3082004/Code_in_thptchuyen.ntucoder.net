// GCD
// Cho một tập hợp rỗng, bạn sẽ lần lượt thực hiện N thao tác. Có hai loại thao tác được thực hiện:
// • Thao tác 1 có dạng 1 x: thêm số x vào tập hợp.
// • Thao tác 2 có dạng 2 x: loại bỏ một số x ra khỏi tập hợp, dữ liệu luôn đảm bảo tồn tại ít
// nhất một số x trước khi thực hiện thao thao tác này.
// Sau mỗi lần thực hiện thao tác, hãy đưa ra ước chung lớn nhất của tập hợp này. Với trường hợp
// tập hợp con rỗng hãy in ra số 1.
// Dữ liệu
// • Dòng đầu tiên một số tự nhiên N (1 ≤ N ≤ 105
// ).
// • N dòng tiếp theo, mỗi dòng là gồm 2 số t và x với t là loại thao tác và x là số cần được xử
// lí (1 ≤ t ≤ 2, 1 ≤ x ≤ 109
// ).
// Kết quả
// • Gồm N dòng là ước chung lớn nhất của tập hợp sau mỗi lần thực hiện một thao tác
#include <bits/stdc++.h>
#define ll long long
#define nmax 100005
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define ii pair<ll,ll>
#define fi first
#define se second
using namespace std;
const int mod=1e6+3;
ll n,m,a,x,st[4*nmax],p=0,tmp;
map<int,stack<int>>d;
void update(ll id,ll l,ll r,ll p,ll k)
{
    if(p<l||r<p)
        return ;
    if(l==r)
    {
        st[id]=k;
        return ;
    }
    ll mid=l+r>>1;
    update(2*id,l,mid,p,k);
    update(2*id+1,mid+1,r,p,k);
    st[id]=__gcd(st[2*id],st[2*id+1]);
}
ll getgcd(ll id,ll a,ll b,ll l,ll r)
{
    if(b<l||r<a)
        return 0;
    if(l<=a&&b<=r)
        return st[id];
    ll mid=a+b>>1;
    return __gcd(getgcd(2*id,a,mid,l,r),getgcd(2*id+1,mid+1,b,l,r));
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("TA.inp","r",stdin);
        freopen("TA.out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    fo(i,1,n)
    {
        cin>>x>>a;
        if(x==1)
        {
            d[a].push(i);
            update(1,1,n,i,a);
            cout<<getgcd(1,1,n,1,n)<<'\n';
        }
        else
        {
            update(1,1,n,d[a].top(),0);
            d[a].pop();
            cout<<getgcd(1,1,n,1,n)<<'\n';
        }
    }
}
    