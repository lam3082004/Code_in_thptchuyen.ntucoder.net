// Nam rất thích ăn kẹo mút nên ngày nào đi học cậu ta cũng đến các quán kẹo để tận hưởng
//     những cảm giác ngọt ngào của những chiếc kẹo.Trong thành phố có 𝑛 quán có bán kẹo
//         mút với nhiều hương vị và giá thành khác nhau,
//     giá bán ở quán thứ 𝑖 là 𝑥𝑖(1 ≤ 𝑖 ≤ 𝑛).Nam lên kế hoạch mua kẹo trong 𝑞 ngày tiếp theo, ngày thứ 𝑗(1 ≤ 𝑗 ≤ 𝑞) không được sử dụng quá số tiền 𝑡𝑗 để mua kẹo.Yêu cầu : hãy xác định số lượng quán khác nhau Nam có thể đến mua kẹo trong ngày thứ 𝑗.Dữ liệu vào : tệp văn bản MUAKEO.INP có cấu trúc như sau :
// • Dòng đầu ghi số nguyên dương 𝑛;
// • Dòng thứ hai ghi 𝑛 số nguyên dương 𝑥1, 𝑥2, … , 𝑥𝑛(1 ≤ 𝑥𝑖 ≤ 100.000.000);
// • Dòng thứ ba ghi số nguyên dương 𝑞(1 ≤ 𝑞 ≤ 100.000);
// • Dòng thứ 𝑗 trong 𝑞 dòng tiếp theo ghi số nguyên 𝑡𝑗(1 ≤ 𝑡𝑗 ≤ 1.000.000.000)
//     Kết quả : ghi ra tệp MUAKEO.OUT gồm 𝑞 dòng,
//     dòng thứ 𝑗 ghi số lượng quán khác nhau
//     cả ngày thứ 𝑗 Nam có thể mua kẹo.
#include <bits/stdc++.h>
#define ii pair<ll, ll>
#define fi first
#define se second
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define fn(i, a, b) for (int i = a; i >= b; i ==)
#define nmax 10000005
const ll mod = 1e9 + 7;
using namespace std;
ll n, a[nmax], dem = 0, t, k;
int main()
{
    //  freopen("muakeo.inp","r",stdin);
    //freopen("muakeo.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    cin >> t;
    while (t--)
    {
        cin >> k;
        ll l = 1, r = n, pos = 0;
        while (l <= r)
        {
            ll mid = l + r >> 1;
            if (a[mid] <= k)
            {
                pos = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        if (pos == 0)
            cout << "0" << '\n';
        else
            cout << pos << '\n';
    }
}
