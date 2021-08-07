// Các nhà khoa học có kế hoạch tiến hành một khảo sát quan trọng trên hành tinh X-2019 bằng
// cách sử dụng một mô-đun khảo sát. Trong quá trình khảo sát, hai phép đo sẽ được thực hiện:
// phép đo chính và phép đo điều khiển. Mỗi phép đo tiến hành trong đúng một giờ và giờ bắt
// đầu là một số nguyên tính từ thời điểm mô-đun bắt đầu hoạt động.
// Các phép đo truyền số liệu ngay lập tức đến một trạm ở trên quỹ đạo (trạm quỹ đạo). Một
// kênh liên lạc với trạm quỹ đạo sẽ được thiết lập từ giờ thứ m đến giờ thứ n kể từ khi mô-đun
// khảo sát bắt đầu hoạt động. Ngoài ra, theo kế hoạch, thời gian giữa các phép đo phải đủ cho
// hành tinh xoay một số nguyên số vòng quanh trục của nó. Biết rằng, hành tinh X-2019 xoay
// một vòng quanh trục của nó mất a giờ.
// Như vậy, giả sử các phép đo được thực hiện ở giờ thứ i và j, thì cần phải có m ≤ i < j ≤ n và
// (j − i) phải chia hết cho a. Các nhà khoa học muốn biết có bao nhiêu cách khác nhau để tiến
// hành các phép đo.
// Input:
//  3 số nguyên mỗi số trên 1 dòng, tương ứng với m, n, a
//  1 ≤ m < n ≤ 109

// , 1 ≤ a ≤ 109

// Output:
//  Một số nguyên thể hiện số cách khác nhau để tiến hành các phép đo
using namespace std;
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 1000000
#define mod 1000000007
ll m, n, a, k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //   freopen("l.inp","r",stdin);
    //    freopen("l.out","w",stdout);
    cin >> m >> n >> a;
    k = (n - m) / a;
    cout << (n - m + 1) * k - a * (k + 1) * k / 2;
    ;
}
