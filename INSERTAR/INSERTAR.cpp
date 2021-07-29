// An và Bình trong lúc rảnh rỗi đã nghĩ ra một trò chơi như sau: Mỗi người nghĩ ra một dãy số
// gồm có N phần tử, dãy số của An gọi là A, dãy số của Bình gọi là B, sau đó hai người sẽ bốc thăm lượt
// chơi, hai người sẽ có một chương trình random ra số 1 hoặc 2, nếu là 1 An sẽ là người chơi, và nếu là 2
// Bình sẽ là người chơi, luật chơi của mỗi lượt chơi như sau:
// • Nếu là lượt chơi của An: An sẽ chọn ra ba số x, y, k, An sẽ thay đổi đoạn trong dãy B của Bình từ
// By đến By+k−1 bằng đoạn trong dãy A của An từ Ax đến Ax+k−1.
// • Nếu là lượt chơi của Bình: Bình sẽ được chọn 1 con số x bất kì từ 1 đến N và phải đưa ra câu trả
// lời số thứ x trong dãy B của mình là số nào.
// Do dãy B đã bị An thay đổi qua mỗi lượt chơi của An nên Bình gặp khó khăn trong mỗi lượt chơi của
// mình. Các bạn hãy giúp Bình nhé.
// Dữ liệu
// • Dòng đầu tiên: chứa hai số nguyên dương N và Q (1 ≤ N, Q ≤ 105
// ) trong đó N là số lượng số của
// dãy số mà mỗi người được chọn, Q là số lượt chơi.
// • Dòng thứ hai: N số nguyên biểu diễn dãy A (|Ai
// | ≤ 109
// ).
// • Dòng thứ ba: N số nguyên biểu diễn dãy B (|Bi
// | ≤ 109
// ).
// • Q dòng tiếp theo: mỗi dòng là một lượt chơi. Nếu là lượt chơi của An, số đầu tiên sẽ là 1 và có 3
// số x, y, k (1 ≤ x, y ≤ N, k ≤ min(N − x + 1, N − y + 1)). Nếu là lượt chơi của Bình, sẽ có số 2 và
// số nguyên x (1 ≤ x ≤ N).
#include <bits/stdc++.h>
using namespace std;
const int nmax=1e6+5;
const int mod=1e9+7;
int q,a[nmax],b[nmax],n;
long long seg[4*nmax];
bool check[4*nmax];
void down(int pos)
{
    seg[2*pos]=seg[pos];
    seg[2*pos+1]=seg[pos];
    seg[pos]=0;
    check[2*pos]=check[pos];
    check[2*pos+1]=check[pos];
    check[pos]=0;
}
void update(int l, int r, int u, int v, int k ,int pos)
{
    if (r<u || l>v)
        return;
    if (l>=u && r<=v)
    {
        seg[pos]=k;
        check[pos]=1;
        return;
    }
    if (check[pos])
        down(pos);
    int mid=l+r>>1;
    update(l,mid,u,v,k,2*pos);
    update(mid+1,r,u,v,k,2*pos+1);
}
int get(int l, int r, int k, int pos)
{
    if (l>k || r<k)
        return 0;
    if (l==k && r==k)
        return seg[pos];
    if (check[pos])
        down(pos);
    int mid=l+r>>1;
    return get(l,mid,k,2*pos)+get(mid+1,r,k,2*pos+1);
}
int get2(int l, int r, int k, int pos)
{
    if (l>k || r<k)
        return 0;
    if (l==k && r==k)
        return check[pos];
    if (check[pos])
        down(pos);
    int mid=l+r>>1;
    return get2(l,mid,k,2*pos)+get2(mid+1,r,k,2*pos+1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        cin>>b[i];
    while(q--)
    {
        int type;
        cin>>type;
        if (type==1)
        {
            int x, y, k;
            cin>>x>>y>>k;
            update(1,n,y,y+k-1,x-y,1);
        }
        else
        {
            int x;
            cin>>x;
            int kc=get(1,n,x,1);
            int st=get2(1,n,x,1);
            if (st==0)
                cout<<b[x]<<'\n';
            else cout<<a[x+kc]<<'\n';
        }
    }
}
    