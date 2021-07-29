// Hình khối
// Từ một hình lập phương ban đầu (gọi là hình khối bậc 0) người ta dán vào các mặt của nó hình
// lập phương cùng kích thước và được hình khối bậc 1. Từ hình khối bậc 1 người ta dán các hình
// lập phương vào các mặt trống của nó và được hình khối bậc 2. Từ hình khối bậc 𝑖 người ta tạo ra
// hình khối bậc 𝑖 + 1 bằng cách dán các hình lập phương vào các mặt trống của nó.
// Yêu cầu: Cho số nguyên 𝑛 ( 0 ≤ 𝑛 ≤ 109
// ). Gọi 𝐾 là số khối lập phương tạo ra hình khối bậc
// 𝑛, tính 𝐾 mod 111539786.
// Input
// Gồm nhiều Tests, mỗi test cho bởi số nguyên 𝑛, ghi trên một dòng.
// Output
// Mỗi test là một số nguyên, ghi trên một dòng
#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define nmax 1000005
#define ii pair<ll,ll>
#define fi first
#define se second
const ll mod=111539786;
using namespace std;
ll n;
int main()
{
     #ifndef ONLINE_JUDGE
    freopen("l.inp","r",stdin);
    freopen("l.out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
     while(cin>>n)
    {
        ll a=n,b=n+1,c=a+b;
        if(a%3==0)
            a/=3;
        if(b%3==0)
            b/=3;
        if(c%3==0)
            c/=3;
        cout<<(1+((2*a*b)%mod*c)%mod+2*n)%mod<<'\n';
    }
}
    