// MAHOA2 – MÃ HOÁ 2
// Nam rất thích thú với việc mã hoá dữ liệu. Trong buổi thảo luận ở lớp, Nam đã trình bày 1 ý tưởng rất
// thú vị rằng bạn ấy vừa phát minh ra một cách mã hoá mới, có thể mã hoá các thông tin mà không ai
// có thể giải mã. Cách mã hoá đó là: Với một số nguyên N, xoá các chữ số từ con số này bằng mọi cách
// có thể, ta sẽ nhận được các số mới. Sau đó tìm tổng của tất cả các con số mới thu được. Tổng này chính
// là mã hoá của N.
// Một bạn trong lớp đã ý kiến “Mình nghĩ cách mã hoá của cậu trên máy tính sẽ thực hiện mất nhiều
// thời gian với số có nhiều chữ số, chẳng hạn số có 1000000 chữ số. Không thể chờ để có một mã số
// cho số có 1000000 chữ số. Cách mã hoá này của cậu không thể áp dụng trên thực tế”. Nam đã trả lời:
// “ Không! Ngày mai mình sẽ đưa ra chương trình thực hiện cách mã hoá này, và sẽ mã hoá cho số có
// 1000000 chữ số trong thời gian không quá 1 giây”
// Yêu cầu: Cho số nguyên N (1 ≤ N ≤ 101000000), xác định số nguyên S là mã hoá của N theo phương
// pháp mã hoá của Nam
// Input:
//  Một dòng duy nhất là số nguyên N (không có chữ số 0 ở đầu)
// Output:
//  Một số duy nhất là phần dư của S khi chia cho 109 + 7
#include <bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define nmax 1000005
using namespace std;
const int mod=1e9+7;
ll n,t=0,a[nmax],b[nmax];
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;
    n=s.size();s=" "+s;
    a[0]=1,b[0]=1;
    fo(i,1,1000000)
    {
        a[i]=(a[i-1]*2)%mod;
        b[i]=(b[i-1]*11)%mod;
    }
    fo(i,1,n)
        t=(t+(s[i]-'0')*(b[n-i]*a[i-1])%mod)%mod;
    cout<<t;
}
    