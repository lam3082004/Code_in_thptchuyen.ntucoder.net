// Dãy số Fibonacci là một trong những dãy số nổi tiếng nhất trong toán học. Dãy Fibonacci có
// nhiều tính chất liên quan đến các quy luật tự nhiên như sự xếp các cánh hoa trên một bông hoa,
// số lượng các đường xoáy ốc. . . Dãy được định nghĩa: F1 = 1, F2 = 2, Fi = Fi−1 + Fi−2 với i ≥ 3.
// Trong toán học, người ta chứng minh được với mọi số nguyên dương m đều có thể biểu diễn qua
// tổng các số Fibonacci khác nhau.
// Ví dụ: với m = 10, ta có: 10 = 8 + 2 = 2 + 3 + 5; với m = 4, ta có: 4 = 3 + 1.
// Nhưng ta nhận thấy, việc biểu diễn thành tổng này không duy nhất với mọi số nguyên dương m.
// Yêu cầu: Cho số nguyên dương m, đếm số cách biểu diễn khác nhau của m thành tổng các số
// Fibonaci khác nhau. Hai các biểu diễn được gọi là khác nhau nếu có một số hạng thuộc biểu diễn
// này nhưng không thuộc biểu diễn kia.
// Dữ liệu
// • Dòng đầu ghi số nguyên dương T là số bộ dữ liệu (T ≤ 105
// ).
// • T dòng tiếp theo, mỗi dòng ghi số nguyên dương m (m ≤ 1018).
// Kết quả
// • Gồm T dòng, mỗi dòng là số cách biểu diễn m thành tổng các số Fibonacci khác nhau
#include<bits/stdc++.h>
using namespace std;
const int nmax=100;
const long long oo=1e13+7;
int t,n,p[nmax],last[nmax];
long long f[nmax],F[nmax][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    f[1]=1;
    f[2]=2;
    for (int i=3;i<=86;i++)
        f[i]=f[i-1]+f[i-2];
    cin>>t;
    while(t--)
    {
        long long m;
        int n=1;
        cin>>m;
        memset(p,0,sizeof p);
        for (int i=86;i>=1;i--)
            if (m>=f[i])
            {
                n=max(n,i);
                p[i]=1;
                m-=f[i];
            }
        for (int i=1;i<=n;i++)
            if (p[i]==1)
                last[i]=i;
            else last[i]=last[i-1];
        for (int i=1;i<=n;i++)
        {
            int pos=last[i-1];
            if (pos==0)
            {
                F[i][1]=1;
                F[i][0]=(i-1)/2;
            }
            else
            {
                F[i][1]=F[pos][1]+F[pos][0];
                F[i][0]=F[pos][1]*((i-pos-1)/2)+F[pos][0]*((i-pos)/2);
            }
        }
        cout<<F[n][0]+F[n][1]<<'\n';
    }
}
    