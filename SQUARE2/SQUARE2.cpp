// Không khí Noel đang bắt đầu xuất hiện dần dần ở thị trấn Free Contest. Trong thị trấn có
// một chàng trai trẻ tên là Nhân đang thầm thích một cô gái bằng tuổi. Nhân băn khoăn không
// biết nên mua gì tặng cho cô ấy. Trong một khoảnh khắc lóe sáng trong đầu, Nhân nảy ra ý
// tưởng tặng một tấm thiệp chúc mừng Giáng sinh siêu lớn có kích thước H × W thõa mãn
// Hmin ≤ H ≤ Hmax, Wmin ≤ W ≤ Wmax.
// Khi Nhân đến cửa hàng Free Shoptest để mua thiệp thì mợi nhận ra là cửa hàng chỉ có bán những
// tấm thiệp hình vuông kích thước T ×T. Trong lúc đang buồn vì có thể không mua được tấm thiệp
// ưng ý của mình, Nhân bắt gặp Khoa, một người bạn học của Nhân, đang cũng đang ở trong cửa
// hàng này và đang mua giấy về xếp hạc giấy. Nhân vô tình nhớ lại câu chuyện một nghìn con hạc
// giấy và quyết định làm một điều tương tự.
// Nhân quyết định mua những tấm thiệp có cùng kích thước với nhau sao cho khi ghép chúng sát
// vào nhau sẽ thu được siêu thiệp Giáng sinh kích thước H ×W. Hay nói cách khác, nếu Nhân mua
// loại thiệp có kích thước T × T thì phải thõa mãn H
// .
// .
// .T và W
// .
// .
// .T. (x
// .
// .
// .y có nghĩa là x chia hết cho y)
// Để chứng tỏ tình cảm mình giành cho cô ấy, Nhân quyết định sẽ mua tấm thiệp có kích thước lớn
// nhất có thể, tiền bạc là không quan trọng đối với Nhân khi sử dụng trong chuyện tình cảm.
// Bạn hãy giúp nhân tìm ra giá trị T lớn nhất thõa mãn để Nhân tặng bạn gái ấy nhé.
// Dữ liệu
// • Dòng đầu tiên là số nguyên dương N là số lượng trường hợp mà Nhân nghĩ đến.
// • N dòng tiếp theo, mỗi dòng gồm 4 số nguyên dương Hmin, Hmax, Wmin, Wmax
// Kết quả
// • Ghi ra N dòng, dòng thứ i là kết quả của trường hợp thứ i mà Nhân nghĩ đến.
#include <bits/stdc++.h>
using namespace std;
const int nmax = 1005;
const int maxn = 1e9;
int a[nmax], n, hmin, hmax, wmin, wmax, p = sqrt(maxn) + 1, ans, t;
bool check(int t)
{
    if (t == 0)
        return 0;
    if (hmax / t * t >= hmin && wmax / t * t >= wmin)
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> hmin >> hmax >> wmin >> wmax;
        ans = 1;
        for (int j = 1; j <= p; j++)
            if (check(j))
                ans = j;
        for (int j = 1; j <= p; j++)
        {
            t = hmax / j;
            if (check(t))
                ans = max(ans, t);
        }
        for (int j = 1; j <= p; j++)
        {
            t = wmax / j;
            if (check(t))
                ans = max(ans, t);
        }
        cout << ans << '\n';
    }
}
