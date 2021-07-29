// Cho N người (2≤N≤32), mỗi người có một số ai (1 ≤ ai ≤ 109) được gọi là độ tin cậy.

// Cần phân chia n người này vào 2 nhóm sao cho:

// Mỗi người thuộc đúng một nhóm
// Chênh lệch tổng độ tin cậy của 2 nhóm là bé nhất
// Dữ liệu

// Dòng đầu chứa số nguyên 
// Dòng tiếp theo chứa N số : số thứ i là độ tin cậy của người thứ i
// Kết quả

// Ghi ra hai số u và v với u là độ chênh lệch nhỏ nhất và v là số cách phân chia
//    KHAz
#include <bits/stdc++.h>
#define maxn 35
#define Task ""
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define pii pair< int , int >
#define reset(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
int n,a[maxn];
long long s,l[1<<17], r[1<<17],cnt=1;
long long ans=1e18;
void lam()
{
    int n1=n/2,n2=n-n1;
    for(int x=0; x<(1<<n1); x++)
    {
        for(int i=0; i<n1; i++)
            if((x>>i)&1==1)
                l[x]+=a[i];
    }
    for(int x=0; x<(1<<n2); x++)
    {
        for(int i=0; i<n2; i++)
            if((x>>i)&1==1)
                r[x]+=a[n1+i];
    }
    int k , k1;
    sort(r,r+(1<<n2));
    for(int x=0; x<(1<<n1); x++)
    {
        if(l[x]>s/2)
            continue;
        k=upper_bound(r,r+(1<<n2),s/2-l[x])-r;
        k1=lower_bound(r,r+(1<<n2),r[k-1])-r;
        long long xx=l[x]+r[k-1];
        xx=s-xx*2;
        if(xx<ans)
            ans=xx,cnt=k-k1;
        else if(ans==xx)
            cnt+=k-k1;
        //   cout << x<<' '<< xx << endl;
}
if(ans==0)
    cnt/=2;
//cout << n1 <<n2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(Task".inp","r",stdin);
    //freopen(Task".out","w",stdout);
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i],s+=a[i];
    lam();
    cout << ans << ' ' << cnt;
    return 0;
}
    