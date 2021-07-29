// John là 1 học sinh khá giỏi về toán. Hôm nay anh ta được giao 1 bài tập toán về nhà. Bài toán
// như sau:
// Cho 2 dãy số A và B, dãy A gồm N số và dãy B gồm M số. Hãy tìm 1 ma trận N × M sao cho
// hàng thứ i (1 ≤ i ≤ N) có tổng các phép xor bằng giá trị của Ai và cột thứ j (1 ≤ j ≤ M) có
// tổng các phép xor bằng giá trị của Bj
// .
// John thắc mắc liệu có ma trận nào phù hợp với bài toán hay không. Các bạn hãy giúp John giải
// bài toán này.
// Nếu bạn chưa biết về phép toán xor hãy tham khảo tại đây
// Dữ liệu
// • Dòng đầu tiên gồm 2 số nguyên N, M (1 ≤ N ≤ M ≤ 103
// ).
// • Dòng tiếp theo gồm N số nguyên Ai (0 ≤ Ai ≤ 108
// ).
// • Dòng cuối cùng gồm M số nguyên Bi (0 ≤ Bi ≤ 108
// ).
// Kết quả
// • Dòng đầu tiên là câu trả lời YES nếu có hoặc NO nếu không.
// • Nếu tồn tại ma trận hãy xuất ra ma trận đó. Nếu có nhiều ma trận phù hợp bạn chỉ cần
// xuất ra 1 ma trận bất kì.
// • Các phần tử của ma trận C là số nguyên không âm và không quá 109
// tức 0 ≤ Cij ≤ 109
#include <bits/stdc++.h>
#define ll long long
#define nmax 100005
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define ii pair<ll,ll>
#define fi first
#define se second
using namespace std;
const int mod=1e6+3;
ll n,m,k,q,u,v,a[10005],b[10005],x=0,y=0,kq=0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>m>>n;
    fo(i,1,m)
        cin>>a[i];
    fo(i,1,m-1)
        x=(x^a[i]);
    fo(i,1,n)
        cin>>b[i];
    fo(i,1,n-1)
        y=(y^b[i]);
    x=(x^b[n]);
    y=(y^a[m]);
    if(x!=y)
        cout<<"NO";
    else
    {
        cout<<"YES"<<'\n';
        fo(i,1,m-1)
        {
            fo(j,1,n-1)
                cout<<0<<' ';
            cout<<a[i];
            cout<<'\n';
        }
        fo(i,1,n-1)
            cout<<b[i]<<' ';
        cout<<x;
    }
}
    