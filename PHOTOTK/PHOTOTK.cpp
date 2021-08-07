// PHOTO
// Bất chấp cái nắng gay gắt ở thành phố Tam Kỳ, các bạn học sinh vẫn muốn chụp ảnh lưu niệm
// với các thầy cô giáo. Sau khi bàn bạc chiến thuật chụp ảnh, mọi người thống nhất như sau:
// 1. Tất cả mọi người sẽ đứng thành một hàng ngang.
// 2. Có ba loại người: học sinh nữ, học sinh nam, giáo viên. Ta kí hiệu học sinh nữ bằng số 0, học sinh
// nam bằng số 1, giáo viên bằng số 2.
// 3. Đứng đầu hàng là một giáo viên (“2”), đứng cuối hàng là một giáo viên (“2”).
// 4. Để bức ảnh đẹp, khoảng cách giữa hai giáo viên liên tiếp là 2 (ví dụ “202”) hoặc 3 (ví dụ “2012”).
// Như một hệ quả, không có hai giáo viên nào đứng kề nhau (ví dụ “22” là không hợp lệ), và không
// có hai giáo viên liên tiếp nào có nhiều hơn 2 học sinh ở giữa (ví dụ “20102” là không hợp lệ).
// 5. Nếu khoảng cách giữa hai giáo viên liên tiếp là 2, thì học sinh ở giữa phải là nữ (ví dụ “202”).
// 6. Nếu khoảng cách giữa hai giáo viên liên tiếp là 3, thì hai học sinh ở giữa phải có giới tính khác
// nhau (ví dụ “2012”, “2102”).
// 7. Hai bức ảnh được coi là khác nhau nếu chuỗi tam phân tương ứng là khác nhau. Như một hệ quả,
// nếu ta đổi chỗ hai giáo viên (hoặc hai học sinh nam, hoặc hai học sinh nữ) cho nhau thì bức ảnh
// được cho là không thay đổi.
// Ví dụ: “2021020202”, “210201202012” là các bức ảnh hợp lệ. “0”, “01”, không hợp lệ do vi phạm quy định
// số 3. “2020102”, “2202” không hợp lệ do vi phạm quy định số 4. “212”, “201212” không hợp lệ do vi phạm
// quy định số 5. “200202”, “211202” không hợp lệ do vi phạm quy định số 6.
// Yêu cầu: Cho biết số lượng giáo viên, học sinh nam, học sinh nữ. Đếm số bức ảnh có thể tạo ra. Vì kết
// quả có thể rất lớn, in phần dư khi chia kết quả cho 109 + 7.
// Dữ liệu
// Dữ liệu gồm một dòng duy nhất chứa ba số nguyên dương N0, N1, N2 lần lượt là số học sinh nữ, số học
// sinh nam, và số giáo viên (1 ≤ N0, N1, N2 ≤ 106
// ).
// Kết quả
// In ra phần dư khi chia số lượng bức ảnh có thể tạo được cho 109 + 7.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 1000005
using namespace std;
const int mod = 1e9 + 7;
ll n, x = 0, a, b, c, gt[nmax], inv[nmax];
ll mu(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = mu(a, b / 2);
    t = (t * t) % mod;
    if (b % 2 == 1)
        t = (t * a) % mod;
    return t;
}
int main()
{
    gt[0] = 1;
    fo(i, 1, 1000000) gt[i] = (gt[i - 1] * i) % mod;
    inv[1000000] = mu(gt[1000000], mod - 2);
    for (int i = 999999; i >= 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    cin >> a >> b >> c;
    {
        if (a + 1 != c || a < b)
            cout << 0;
        else
        {
            cout << (((gt[a] * inv[b]) % mod * inv[a - b]) % mod * mu(2, b)) % mod;
        }
    }
}
