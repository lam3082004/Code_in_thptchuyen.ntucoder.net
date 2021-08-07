// Alice là một người thích đi du lịch. Cô thường đi lang thang khắp nơi, khám phá những miền
// đất mới lạ.
// Một ngày nọ, Alice đến quốc gia X, và khám phá ra một điều đặc biệt: Có n trung tâm du lịch
// ở đây, và các trung tâm du lịch đều nằm trên một đường thẳng. Tưởng tượng rằng Alice xuất
// phát ở kilomet thứ 0, thì các trung tâm du lịch này nằm ở kilomet thứ a[1], ... , a[n]. Biết rằng,
// không có hai trung tâm nào nằm cùng một toạ độ.
// Alice lên kế hoạch tham quan toàn bộ các trung tâm này. Cô sẽ xuất phát từ kilomet thứ 0, đi
// tham quan mỗi trung tâm đúng 1 lần theo thứ tự tuỳ ý, và sẽ dừng lại sau khi thăm xong trung
// tâm cuối cùng.
// Để đi từ kilomet thứ x tới kilomet thứ y, Alice cần phải đi một quãng đường dài |x − y| km
// Alice muốn viết ra tất cả các kế hoạch có thể có để tính độ dài trung bình cho chuyến tham
// quan của mình.
// Yêu cầu: Cho n và a[1], ... , a[n], tính độ dài trung bình cho chuyến tham quan
// Input:
//  Dòng đầu chứa 1 số nguyên n – số trung tâm du lịch
//  Dòng thứ 2 là n số nguyên a[1], ... , a[n] (1 ≤ a[i] ≤ 107
// )

// Output:
//  Độ dài trung bình cho chuyến tham quan của Alice
//  Dễ thấy, độ dài này có thể viết dưới dạng phân số tối giản A/B (A, B là các số nguyên,
// B > 0, gcd(A, B) = 1), vì thế nên chỉ cần in ra A và B
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int mod = 1e9 + 7;
ll t, n, k, a[nmax], f[nmax], x, y, d, s, kq = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n)
    {
        cin >> a[i];
        s += a[i];
    }
    sort(a + 1, a + 1 + n);
    fo(i, 1, n)
        f[i] = f[i - 1] + a[i];
    fo(i, 1, n)
        kq += f[n] - f[i] - (n - i) * a[i];
    x = 2 * kq + s;
    y = n;
    d = __gcd(x, y);
    cout << x / d << ' ' << y / d;
}
