// Công ti của anh Kiên đang thí nghiệm nuôi cấy một loại vi sinh vật trong đĩa XYZ. Đối tượng
// nghiên cứu là n con vi sinh vật được đánh số từ 1 đến n. Các vi sinh vật sau khi thả xuống đĩa
// đều ngay lập tức thả một lượng chất độc có hại tên là axi. Sau đó, toàn bộ lượng chất độc sẽ được
// các vi sinh vật đó hấp thụ lại toàn bộ với một lượng như nhau. Mỗi vi sinh vật có một khả năng
// hấp thụ axi nhất định, nếu hấp thụ quá ngưỡng cho phép, nó sẽ chết. Cụ thể, vi sinh vật thứ i
// thả ra ai milligram axi và có thể hấp thụ tối đa bi miligram axi. Như vậy nếu cho k vi sinh vật
// i1, i2, . . . , ik vào đĩa thì mỗi vi sinh vật sẽ phải hấp thụ ai1+ai2+. . . +aik
// k miligram axi. Với vi sinh
// vật i nào đó hấp thụ nhiều hơn bi miligram axi, nó sẽ chết. Bạn hãy xác định số lượng vi sinh vật
// tối đa có thể cho vào đĩa mà không có con nào chết do hấp thụ quá nhiều axi.
#include<bits/stdc++.h>
using namespace std;
const int nmax=3e5+5;
struct ii
{
    int a, b;
};
bool cmp(ii A, ii B)
{
    return (A.b<B.b);
}
int n;
ii s[nmax];
bool check(int mid)
{
    int tong=0;
    priority_queue<int> q;
    for (int i=n;i>=n-mid+2;i--)
    {
        tong+=s[i].a;
        q.push(s[i].a);
    }
    for (int i=n-mid+1;i>=1;i--)
    {
        tong+=s[i].a;
        q.push(s[i].a);
        if (tong<=s[i].b*mid)
            return true;
        tong-=q.top();
        q.pop();
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>s[i].a>>s[i].b;
    sort(s+1,s+n+1,cmp);
    int l=1,r=n;
    while(l<=r)
    {
        int mid=l+r>>1;
        if (check(mid))
            l=mid+1;
        else r=mid-1;
    }
    cout<<l-1;
}
    