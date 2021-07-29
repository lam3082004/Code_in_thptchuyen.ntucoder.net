// Cho dãy số nguyên dương gồm 𝑛 phần tử 𝑎1, 𝑎2, … , 𝑎𝑛.
// Mỗi thao tác, bạn có thể chọn một vị trí 𝑖 (1 ≤ 𝑖 ≤ 𝑛 − 2) và thay thế [𝑎𝑖
// , 𝑎𝑖+1, 𝑎𝑖+2
// ] bởi
// [𝑎𝑖+2, 𝑎𝑖
// , 𝑎𝑖+1
// ].
// Yêu cầu: Bạn hãy sắp xếp dãy 𝑎1, 𝑎2, … , 𝑎𝑛 thành dãy số không giảm với không quá 𝑛
// 2
// thao tác.
// Input:
//  Dòng đầu chứa một số nguyên dương 𝑛 (3 ≤ 𝑛 ≤ 500).
//  Dòng thứ hai chứa 𝑛 số nguyên dương 𝑎1, 𝑎2, … , 𝑎𝑛
// (𝑎𝑖 ≤ 500).
// Output: Nếu không thể thực hiện theo yêu cầu bài toán, bạn hãy in ra −1. Nếu có thể, bạn hãy in
// ra theo cách sau:
//  Dòng đầu chứa số nguyên dương 𝑘 (𝑘 ≤ 𝑛
// 2
// ) − số thao tác cần thực hiện.
//  Dòng thứ hai gồm 𝑘 số nguyên dương 𝑖𝑑1, 𝑖𝑑2, … , 𝑖𝑑𝑘 (1 ≤ 𝑖𝑑𝑖 ≤ 𝑛 − 2) với 𝑖𝑑𝑖
// là vị trí
// bạn chọn ở thao tác thứ 𝑖.
#include <bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define nmax 500005
#define ii pair<int,int>
#define fi first
#define se second
#define oo 1e9
using namespace std;
const int mod = 1e9+7;
ll n,a[505],b[505],dem = 0,t = 0,d[250005];
ii c[505];
bool ok = 1;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    fo(i,1,n)
    {
        cin>>a[i];
        c[i] = ii(a[i],i);
    }
    sort(c+1,c+1+n);
    fo(i,1,n)
        b[c[i].se] = i;
    fo(i,1,n)
    fo(j,i+1,n)
    if(a[i] > a[j])
        dem++;
    if(dem & 1)
    {
        dem = 0;
        fo(i,1,n)
        if(ok)
        {
            fo(j,i+1,n)
            if(a[i] == a[j] && ok)
            {
                swap(b[i],b[j]);
                ok = 0;
            }
        }
        fo(i,1,n)
        fo(j,i+1,n)
        if(b[i] > b[j])
            dem++;
        if(dem & 1)
        {
            cout<<-1;
            return 0;
        }
    }
//    fo(i,1,n)
//        cout<<b[i]<<' ';
//    cout<<'\n';
    while(1)
    {
        int minn = oo, pos = 0;
        fo(i,1,n)
        if(b[i] < i && minn > b[i])
        {
            minn = b[i];
            pos = i;
        }
        if(pos - minn == 1)
        {
            d[++t] = pos-1;
            d[++t] = pos-1;
            int x = b[pos];
            b[pos] = b[pos+1];
            b[pos+1] = b[pos-1];
            b[pos-1] = x;
        }
        else
        {
            d[++t] = pos-2;
            int x = b[pos];
            b[pos] = b[pos-1];
            b[pos-1] = b[pos-2];
            b[pos-2] = x;
        }
        ok = 1;
        fo(i,2,n)
        if(b[i-1] > b[i])
            ok = 0;
        if(ok)
            break;
    }
    cout<<t<<'\n';
    fo(i,1,t)
        cout<<d[i]<<' ';
}
    