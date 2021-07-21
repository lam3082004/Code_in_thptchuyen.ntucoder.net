// Điều khiển mức màu – ĐỀ THI HSG TỈNH NGHỆ AN NĂM 2020
// Vinh mới mua một màn hình LCD của công ty công nghệ StarTech mới thiết kế có độ phân
// giải màu sắc gồm 𝑀 mức màu, đó là mức 1, mức 2, ..., mức 𝑀. Thiết bị điều khiển của màn
// hình gồm 2 nút bấm điều khiển. Nút bấm thứ nhất được gọi là nút “Inc”. Khi bấm vào nút này,
// nếu màn hình đang ở mức màu 𝑖 (𝑖 < 𝑀) thì sẽ chuyển lên mức màu 𝑖 + 1, nếu 𝑖 = 𝑀 thì
// sẽ chuyển về mức màu 1. Nút bấm thứ 2 được gọi là nút “favorite”, khi bấm vào nút này mức
// màu của màn hình sẽ chuyển về mức 𝑋, với 𝑋 là một thông số được thiết lập trước.
// Màn hình thì rất đẹp, chiếc điều khiển cũng rất đẹp. Vinh muốn thử chiếc điều khiển và
// kiểm tra các mức màu của màn hình. Vinh đưa ra một dãy mức màu 𝐴1, 𝐴2 … , 𝐴𝑁 (1 ≤ 𝐴𝑖 ≤
// 𝑀, 𝐴𝑖 ≠ 𝐴𝑖+1) và sẽ điều khiển để màn hình từ mức 𝐴𝑖 chuyển sang mức 𝐴𝑖+1 (𝑖 =
// 1, 2, . . . , 𝑁 − 1) bằng cách bấm vào các nút bấm. Ban đầu màn hình ở mức màu 𝐴1. Gọi 𝑆(𝑋)
// là tổng số lần bấm ít nhất để chuyển từ mức màu 𝐴1 sang 𝐴2, từ 𝐴2 sang 𝐴3, ..., từ 𝐴𝑁−1 sang
// 𝐴𝑁 ứng với thông số thiết lập là mức 𝑋.
// Yêu cầu: Tìm giá trị nhỏ nhất của 𝑆(𝑋) khi 𝑋 thay đổi từ 1 đến 𝑀.
// Dữ liệu cho trong file văn bản LCD.Inp gồm:
// • Dòng thứ nhất ghi 2 số nguyên dương 𝑁 và 𝑀.
// • Dòng thứ hai ghi 𝑁 số nguyên 𝐴1, 𝐴2 … , 𝐴𝑁 (1 ≤ 𝐴𝑖 ≤ 𝑀).
// Kết quả ghi ra file văn bản LCD.Out gồm một số nguyên là giá trị nhỏ nhất của 𝑆(𝑋) khi 𝑋
// thay đổi từ 1 đến 𝑀.
#include <bits/stdc++.h>
using namespace std;

long long n, m, i, j, k, l, r;
long long a[100005];
long long ans, tmp, ans_sum, sum1[200005], sum2[200005];

int main()
{
    //freopen("LCD.INP","r",stdin);
    //freopen("LCD.OUT","w",stdout);
    cin >> n >> m;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    for (i = 1; i < n; ++i)
    {
        l = a[i];
        r = a[i + 1];
        if (r < l)
            r += m;
        ans_sum += r - l;
        if (l + 1 < r)
        {
            ++sum1[l + 2];
            sum2[l + 2] -= l + 1;
            --sum1[r + 1];
            sum2[r + 1] += l + 1;
        }
    }
    for (i = 1; i <= m + m; ++i)
        sum1[i] += sum1[i - 1], sum2[i] += sum2[i - 1];
    for (i = 1; i <= m; ++i)
    {
        tmp = sum1[i] * i + sum2[i] + sum1[i + m] * (i + m) + sum2[i + m];
        if (tmp > ans)
            ans = tmp;
    }
    cout << ans_sum - ans;
}
