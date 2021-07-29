// Bạn An có một dãy số gồm N phần tử nguyên dương a1, a2, ..., aN . An muốn tính tổng các số
// trong dãy. Vấn đề ở đây là chiếc máy tính của An khá chậm nên cậu ta muốn tìm cách tính tổng
// các số nguyên dương trong dãy sao cho thời gian máy tính hoạt động nhỏ nhất có thể. Biết rằng
// thời gian để tính tổng hai số nguyên dương x và y là (x + y)
// 2
// .
// Yêu cầu: Bạn hãy đưa ra thời gian ít nhất để máy tính có thể tính được tổng cả dãy số mà An
// muốn tính.
// Dữ liệu
// • Dòng đầu tiên gồm số nguyên dương N (N ≤ 3000);
// • Dòng thứ hai chứa N số nguyên dương a1, a2, ..., aN (ai ≤ 104
// ).
#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
using namespace std;
ll n,a[3005],r[3005][3005],s[3005],dp[3005][3005];
int main()
{
    cin>>n;
    fo(i,1,n)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    memset(dp,0x3f,sizeof(dp));
    fo(i,1,n)
    {
        dp[i][i]=0;
        r[i][i]=i;
    }
    for(int i=n;i>=1;i--)
    fo(j,i+1,n)
    {
        fo(k,r[i][j-1],r[i+1][j])
        {
            ll tmp=dp[i][k]+dp[k+1][j]+(s[j]-s[i-1])*(s[j]-s[i-1]);
            if(tmp<dp[i][j])
            {
                dp[i][j]=tmp;
                r[i][j]=k;
            }
        }
    }
    cout<<dp[1][n];
}
    