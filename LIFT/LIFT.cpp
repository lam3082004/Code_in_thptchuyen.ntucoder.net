// LIFT – THANG MÁY
// Một trung tâm thương mại có N tầng, được đánh số từ 1 đến N theo thứ tự từ dưới lên
// trên. Tại mỗi tầng chỉ có duy nhất một nhân viên làm việc. Buổi sáng các nhân viên lái xe đến
// tầng hầm (ở dưới tầng 1 một tầng). Trung tâm thương mại được trang bị một thang máy có
// thể chứa số lượng người không giới hạn. Nhưng hôm nay người điều khiển thang máy khó
// tính chỉ cho phép đưa tất cả nhân viên lên cùng một lần lên cùng một tầng nào đó.
// Mỗi nhân viên có hai lựa chọn: Anh ta có thể đi cầu thang bộ, để đi bộ lên qua mỗi một
// tầng mất A giây; hoặc anh ta có thể đi thang máy đến tầng mà các nhân viên lựa chọn, sau đó
// ra khỏi thang máy và đi bộ lên hoặc xuống tầng của mình, đi bộ xuống qua mỗi tầng mất B
// giây. Thang máy đi qua mỗi tầng mất C giây.
// Bạn hãy xác định thời gian tối thiểu để tất cả các nhân viên đi đến vị trí làm việc của
// mình sau khi các nhân viên đã thống nhất chọn được tầng mà thang máy đi lên và xác định
// được lựa chọn của từng người (đi bộ hoặc đi thang máy sau đó đi bộ)
// Input: Dòng đầu tiên chứa số nguyên dương N là số tầng của trung tâm thương mại,
// tiếp theo 3 dòng chứa các số nguyên dương A, B, C – tương ứng là thời gian đi bộ lên một
// tầng, đi bộ xuống một tầng và thời gian thang máy đi lên qua một tầng.
// 0 < N, A,B, C ≤ 2. 109

// , A ≥ B, A ≥ C.

// Output: Một số nguyên dương thể hiện thời gian tối thiểu để tất cả các nhân viên đạt
// đến tầng của mình.
#include <bits/stdc++.h>
using namespace std;
const long long oo = 4 * 1e18;
long long n, a, b, c;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("LIFT.inp","r",stdin);
    //freopen("LIFT.out","w",stdout);
    cin >> n >> a >> b >> c;
    long long res = oo;
    long long l = 1, r = n;
    while (l <= r)
    {
        long long mid = l + r >> 1;
        long long tmp = c * mid + a * (n - mid);
        long long u = 0, v = mid;
        while (u <= v)
        {
            long long m = u + v >> 1;
            if (a * m > c * mid + b * (mid - m))
                v = m - 1;
            else
                u = m + 1;
        }
        long long tmp2, tmp3;
        if (u - 1 >= 0)
            tmp2 = max((u - 1) * a, c * mid + b * (mid - u));
        else
            tmp2 = oo;
        if (v + 1 < mid)
            tmp3 = max((v + 1) * a, c * mid + b * (mid - v - 2));
        else
        {
            if (v + 1 == mid)
                tmp3 = (v + 1) * a;
            else
                tmp3 = oo;
        }
        if (tmp > min(tmp2, tmp3))
        {
            res = min(res, tmp);
            l = mid + 1;
        }
        else
        {
            res = min(res, min(tmp2, tmp3));
            r = mid - 1;
        }
    }
    cout << res << '\n';
}
