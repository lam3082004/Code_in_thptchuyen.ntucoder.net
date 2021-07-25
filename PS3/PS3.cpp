// Phân số 3 Với hai phân số x
//         y
//             và u
//                 v
//                     người ta tạo ra phân số x +
//     u
//         y +
//     v
//         .Bắt đầu từ hai phân số 0 1 và 1 0,
//     tiến hành tao ra

//         các phân số.Lượt đầu tiên tạo được các phân số 0 1;
// 1 1;
// 1 0;
// Lượt thứ hai tạo được các phân số 0 1;
// 1 2;
// 1 1;
// 2 1;
// 1 0;

// ... Việc tạo các phân số có thể biểu diễn bằng cây như sau :

//     Đánh số thứ tự các nút trên cây,
//     từ trên xuống dưới,
//     từ trái sang phải,
//     bắt đầu từ phân số 1 1 là nút

//         gốc có thứ tự là 1,
//     tiếp theo là phân số 1 2;
// 2 1;
// ...

//     Yêu cầu : Cho số nguyên dương t,
//               hãy cho biết phân số được đánh thứ t là phân số nào
//               ? Input - Gồm một dòng chứa 2 số nguyên t,
//               M(M ≤ 109);

// Output - Gồm một dòng chứa hai số x, y, giả sử p, q là phân số tìm được thì x = p MOD M và y = q MOD M.
#include <bits/stdc++.h>
using namespace std;
string s;
long long mod, n, t, dong, poww[100], temp, k = 0, lens, p = 1, q = 1, ul = 0, vl = 1, ur = 1, vr = 0, tmp, tmp2;
long long nhan(long long a, long long b)
{
    if (b == 0)
        return 0;
    long long t = nhan(a, b / 2);
    t = (t + t) % mod;
    if (b % 2 == 1)
        t = (t + a) % mod;
    return t;
}
long long mu(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long t = mu(a, b / 2);
    t = (t * t) % mod;
    if (b % 2 == 1)
        t = (t * a) % mod;
    return t;
}
int main()
{
    cin >> t >> mod;
    long long tmp = t;
    while (tmp > 1)
    {
        dong++;
        tmp /= 2;
    }
    poww[0] = 1;
    for (int i = 1; i <= 64; i++)
        poww[i] = poww[i - 1] * 2;
    for (int i = dong; i >= 1; i--)
    {
        if ((t - poww[i] + 1) * 2 <= poww[i])
        {
            s += 'L';
            t = t - poww[i - 1];
        }
        else
        {
            s += 'R';
            t = t - poww[i];
        }
    }
    lens = s.size();
    s = " " + s;
    for (int i = 1; i <= lens; i++)
    {
        if (s[i] == 'L')
        {
            tmp = p;
            tmp2 = q;
            p = (p + ul) % mod;
            q = (q + vl) % mod;
            ur = tmp;
            vr = tmp2;
        }
        else
        {
            tmp = p;
            tmp2 = q;
            p = (p + ur) % mod;
            q = (q + vr) % mod;
            ul = tmp;
            vl = tmp2;
        }
    }
    cout << p << " " << q;
}
