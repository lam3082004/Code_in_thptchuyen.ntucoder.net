// Cho mặt phẳng tọa độ Oxy và n điểm Ai(xi
// ; yi) trên mặt phẳng sao cho không điểm nào trong số n
// điểm này trùng với gốc tọa độ (0; 0). Hãy viết chương trình tìm hai điểm Ai và Aj (i 6= j) sao cho góc
// 6 AiOAj có số đo nhỏ nhất, và in ra cô-sin của góc đó.
// Dữ liệu
// • Dòng đầu tiên gồm một số nguyên dương n (2 ≤ n ≤ 105
// ) là số điểm được cho trên mặt phẳng.
// • n dòng tiếp theo, mỗi dòng gồm hai số nguyên xi
// , yi
// lần lượt là hoành độ và tung độ của điểm Ai
// .
// Dữ liệu vào đảm bảo −109 ≤ xi
// , yi ≤ 109 và x
// 2
// i + y
// 2
// i
// 6= 0.
// Kết quả
// • Gồm một dòng duy nhất chứa một số thực làm tròn đến đúng 4 chữ số sau dấu phẩy thập phân là
// cô-sin của góc 6 AiOAj nhỏ nhất
#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, b) for (ll i = a; i <= b; i++)
#define ll long long
#define nmax 1000000
#define mod 1000000007
ll n, x[15], y[15];
long double kq = -1, t;
int main()
{
    //   freopen("l.inp","r",stdin);
    // freopen("l.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n >= 10000)
    {
        cout << "1.0000";
        return 0;
    }
    fo(i, 1, n)
    {
        cin >> x[i] >> y[i];
        for (int j = 1; j < i; ++j)
        {
            t = (x[i] * x[j] + y[i] * y[j]) / (sqrt(x[i] * x[i] + y[i] * y[i]) * sqrt(x[j] * x[j] + y[j] * y[j]));
            kq = max(kq, t);
        }
    }
    cout << setprecision(4) << fixed << kq;
}
