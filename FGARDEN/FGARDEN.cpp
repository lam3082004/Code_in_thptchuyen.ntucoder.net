// Nhân dịp đến thành phố Buôn Ma Thuột tham dự hội nghị của Bộ GD, Mr
// Toàn đến thăm nhà Mr Nhân là giáo viên Toán Tin của chuyên Nguyễn Du – Đắc
// Lắc. Mr Nhân dẫn Mr Toàn tới xem một hàng cà phê có n cây được đánh số theo thứ
// tự từ 1 đến n. Cây thứ i có độ cao là ℎ𝑖 ( 1 ≤ 𝑖 ≤ 𝑛). Một dãy các cây cà phê liên
// tiếp từ cây l đến cây r được gọi là “đặc biệt” nếu chúng thỏa mãn điều kiện sau: Với
// hai cây i, j bất kỳ trong dãy thì |ℎ𝑖 − ℎ𝑗
// | ≤ 𝑡 (0 ≤ t ≤ 2.109
// ) . Chủ vườn cà phê là một
// con người hào phóng đã yêu cầu Mr Toàn chỉ ra một dãy các cây cà phê dài nhất có
// tính chất “đặc biệt”. Nếu chỉ ra đúng Mr Toàn sẽ được mang số cà phê hái được trên
// dãy đó về làm quà.
// Yêu cầu: Hãy lập trình tính số lượng các cây cà phê trong dãy các cây cà phê dài
// nhất có tính chất “đặc biệt”.
// Input:
// • Dòng đầu chứa số nguyên dương 𝑛 và số nguyên không âm 𝑡.
// • Dòng thứ hai chứa 𝑛 số nguyên tương ứng với độ cao của từng cây.
// • Các số trên một dòng cách nhau bởi ít nhất một dấu cách.
// Output: ghi ra một số nguyên duy nhất là số lượng các cây cà phê trong dãy dài
// nhất có tính chất “đặc biệt”.
// KHAz
#include <bits/stdc++.h>
#define maxn 3000002
#define F first
#define S second
#define PB push_back
#define mp make_pair
#define reset(x) memset(x, 0, sizeof(x))
#define Task ""
#define pii pair<int, int>
#define ll long long
using namespace std;
int mi[maxn], ma[maxn];
int a[maxn], f[maxn];
int n, l = 1, l1 = 1, r, r1, k;
int ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //   freopen(Task".inp","r",stdin);
    //  freopen(Task".out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = f[i - 1]; j <= i; j++)
        {
            //  while(mi.size()&&mi.front()<j) mi.pop_front();
            while (l <= r && mi[l] < j)
                l++;
            //  while(ma.size()&&ma.front()<j) ma.pop_front();
            while (l1 <= r1 && ma[l1] < j)
                l1++;
            //  while(mi.size()&&a[mi.back()]>a[i]) mi.pop_back();
            while (l <= r && a[mi[r]] > a[i])
                r--;
            //  while(ma.size()&&a[ma.back()]<a[i]) ma.pop_back();
            while (l1 <= r1 && a[ma[r1]] < a[i])
                r1--;
            //   mi.push_back(i),ma.push_back(i);
            mi[++r] = i, ma[++r1] = i;
            // if(a[ma.front()]-a[mi.front()]<=k) { f[i]=j;break;}
            if (a[ma[l1]] - a[mi[l]] <= k)
            {
                f[i] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        //  cout << f[i] <<' ';
        ans = max(ans, i - f[i] + 1);
    }
    //  for(int i=l;i<=r;i++) cout << ma[i] <<' ';
    // cout << r <<' '<< r1;
    cout << ans;
}
