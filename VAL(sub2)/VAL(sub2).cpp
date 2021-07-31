// Ta định nghĩa giá trị của một xâu T độ dài k là value(T) được tính bằng số cặp (i, j)
// (1 ≤ i < j ≤ k) sao cho Ti = a và Tj = b.
// Cho xâu S gồm toàn chữ cái Latin in thường độ dài N và một số nguyên C. Bạn hãy
// tìm một giá trị X lớn nhất có thể sao cho tồn tại một xâu con Sx độ dài X của xâu S có
// value(Sx) ≤ C.
// Dữ liệu
// • Dòng đầu tiên chứa hai số nguyên dương N, C (1 ≤ N ≤ 106

// , 0 ≤ C ≤ 1018).

// • Dòng thứ hai chứa xâu S độ dài N.
#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int nmax=2e5+5;
const int oo=1e9+7;
typedef pair<int,int> ii;
int n,m,k,p[nmax],F[nmax][20],q,maxx;
ii a[nmax];
struct doi
{
    int l,r;
};
doi b[nmax];
bool cmp(doi a, doi b)
{
    if (a.l<b.l)
        return true;
    if (a.l>b.l)
        return false;
    return a.r>b.r;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>b[i].l>>b[i].r;
    sort(b+1,b+n+1,cmp);
    for (int i=1;i<=n;i++)
        if (b[i].r>maxx)
        {
            maxx=b[i].r;
            a[++k].fi=b[i].l;
            a[k].se=b[i].r;
        }
    n=k;
    for (int i=1;i<=n;i++)
    {
        int l=i+1,r=n,pos=0;
        while(l<=r)
        {
            int mid=l+r>>1;
            if (a[mid].fi<=a[i].se+1)
            {
                pos=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        p[i]=pos;
    }
    a[0]=ii(oo,oo);
    for (int i=1;i<=n;i++)
        F[i][0]=p[i];
    for (int k=1;(1<<k)<=n;k++)
        for (int i=1;i+(1<<k)-1<=n;i++)
            F[i][k]=F[F[i][k-1]][k-1];
    cin>>q;
    while(q--)
    {
        int L,R;
        cin>>L>>R;
        int l=1,r=n,pos=0;
        while(l<=r)
        {
            int mid=l+r>>1;
            if (a[mid].fi<=L)
            {
                pos=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        if (pos==0)
        {
            cout<<-1<<'\n';
            continue;
        }
        if (a[pos].se>=R)
        {
            cout<<1<<'\n';
            continue;
        }
        int ans=1;
        for (int i=17;i>=0;i--)
            if (a[F[pos][i]].se<R)
            {
                ans+=(1<<i);
                pos=F[pos][i];
            }
        if (a[F[pos][0]].se>=R && a[F[pos][0]].se!=oo)
        {
            cout<<ans+1<<'\n';
            continue;
        }
        cout<<-1<<'\n';
    }
}
    